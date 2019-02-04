#include <string>
#include <vector>

#include "List.hpp"
#include "Procedure.hpp"
#include "InterpreterException.hpp"
#include "Variable.hpp"
#include "Atom.hpp"

ExpressionPtr List::head() const {
    return values_[0];
}

std::shared_ptr<List> List::tail() const {
    if (values_.size() < 2)
        return nullptr;
    return std::make_shared<List>(std::vector<ExpressionPtr>(values_.begin() + 1, values_.end()));
}

std::shared_ptr<List> List::cons(ExpressionPtr ex) const {
    std::vector<ExpressionPtr> new_values;
    new_values.push_back(ex);
    for (ExpressionPtr exptr : values_)
        new_values.push_back(exptr);
    return std::make_shared<List>(new_values);
}

std::vector<ExpressionPtr> List::getValues() const {
    return values_;
}

std::string List::print() const {
    std::string res = "(" + values_[0]->print();
    for (int i = 1; i < values_.size(); i++)
         res += " " + values_[i]->print();
    res += ")";
    return res;
}

ExpressionPtr List::eval(EnvPtr env) const {
    std::string form = values_[0]->print();
    if (form == "quote"){
        return values_[1];
    }
    else if (form == "defmacro") {
        throw InterpreterException("Not implemented");
    }
    else if (form == "define"){
        env->add(values_[1]->print(), values_[2]->eval(env));
        return values_[1];
    }
    else if (form == "if") {
        std::shared_ptr<Atom> cond = std::dynamic_pointer_cast<Atom>(values_[1]->eval(env));
        if (cond->boolean())
            return values_[2]->eval(env);
        return values_[3]->eval(env);
    }
    else if (form == "lambda") {
        std::shared_ptr<List> pars = std::dynamic_pointer_cast<List>(values_[1]);
        
        if (pars == nullptr)
            throw InterpreterException("Expected argument to be a list");
        
        std::vector<std::string> params_string{};
        
        for (ExpressionPtr expr : pars->getValues()){
            std::shared_ptr<Variable> atom;
            if ((atom = std::dynamic_pointer_cast<Variable>(expr)) != nullptr)
                params_string.push_back(atom->print());
            else
                throw InterpreterException("Expected argument to be type of atom");
        }
        
        return std::make_shared<Procedure>(params_string, values_[2]);
    }
    else if (form == "eval") {
        ExpressionPtr ex = values_[1]->eval(env);
        return ex->eval(env);
    }
    else {
        ExpressionPtr expr = values_[0]->eval(env);
        std::shared_ptr<Procedure> proc = std::dynamic_pointer_cast<Procedure>(expr);
    
        EnvPtr inner = std::make_shared<Environment>(env);
    
        std::vector<std::string> params = proc->getParams();
        if (params.size() != values_.size() - 1)
            throw InterpreterException("Cannot call function with given number of arguments");
    
        for (int i = 0; i < values_.size() - 1; i++)
            inner->add(proc->getParams()[i], values_[i+1]->eval(env));
    
        return proc->eval(inner);
    }
}

