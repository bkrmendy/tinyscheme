#include <string>
#include <vector>

#include "Procedure.hpp"
#include "Expression.hpp"
#include "List.hpp"

std::string Procedure::print() const {
    return "<procedure 06283912731>";
}

ExpressionPtr Procedure::eval(EnvPtr env) const {
    return body_->eval(env);
}

std::vector<std::string> Procedure::getParams() const {
    return params_;
}
