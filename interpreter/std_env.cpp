//
//  std_env.cpp
//  interpreter
//
//  Created by Bertalan Kormendy on 2018. 05. 12..
//  Copyright © 2018. Bertalan Kormendy. All rights reserved.
//

#include <string>
#include <functional>

#include "Expression.hpp"
#include "Number.hpp"
#include "Procedure.hpp"
#include "Variable.hpp"
#include "InterpreterException.hpp"

template <typename OPTYPE>
class UnaryOp : public Procedure {
    std::function<ExpressionPtr(std::shared_ptr<OPTYPE>)> op_;
    
public:
    UnaryOp(std::function<ExpressionPtr(std::shared_ptr<OPTYPE>)> op) : Procedure({"#"}), op_{op} {}
    
    ExpressionPtr eval(EnvPtr env) const {
        std::shared_ptr<OPTYPE> arg = std::dynamic_pointer_cast<OPTYPE>((*env)[params_[0]]);
        
        if (arg == nullptr)
            throw InterpreterException("Argument type does not match parameter type");
        
        return op_(arg);
    }
};

template <typename OP1, typename OP2>
class BinaryOp : public Procedure {
    std::function<ExpressionPtr(std::shared_ptr<OP1>, std::shared_ptr<OP2>)> op_;

public:
    BinaryOp(std::function<ExpressionPtr(std::shared_ptr<OP1>, std::shared_ptr<OP2>)> op) : Procedure({"#", "@"}), op_{op} {}
    
    ExpressionPtr eval(EnvPtr env) const {
        std::shared_ptr<OP1> arg1 = std::dynamic_pointer_cast<OP1>((*env)[params_[0]]);
        std::shared_ptr<OP2> arg2 = std::dynamic_pointer_cast<OP2>((*env)[params_[1]]);
        
        if (arg1 == nullptr || arg2 == nullptr)
            throw InterpreterException("Argument type does not match parameter type");
        
        return op_(arg1, arg2);
    }
};
