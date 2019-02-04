//
//  Variable.cpp
//  interpreter
//
//  Created by Bertalan Kormendy on 2018. 05. 12..
//  Copyright © 2018. Bertalan Kormendy. All rights reserved.
//
#include "Variable.hpp"
#include "Environment.hpp"
#include "InterpreterException.hpp"

ExpressionPtr Variable::eval(EnvPtr env) const{
    ExpressionPtr ex = (*env)[symbol_];
    if (ex == nullptr)
        throw InterpreterException("Variable not yet defined");
    return ex;
}

std::string Variable::print() const {
    return symbol_;
}
