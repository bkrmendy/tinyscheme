//
//  Variable.hpp
//  interpreter
//
//  Created by Bertalan Kormendy on 2018. 05. 12..
//  Copyright © 2018. Bertalan Kormendy. All rights reserved.
//

#ifndef Variable_hpp
#define Variable_hpp

#include <string>

#include "Expression.hpp"

class Variable : public Expression {
    std::string symbol_;
public:
    Variable(std::string symbol) : symbol_{symbol} {}
    ExpressionPtr eval(EnvPtr) const;
    std::string print() const;
};

#endif /* Variable_hpp */
