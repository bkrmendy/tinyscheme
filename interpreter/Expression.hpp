//
//  Expression.hpp
//  interpreter
//
//  Created by Bertalan Kormendy on 2018. 05. 12..
//  Copyright © 2018. Bertalan Kormendy. All rights reserved.
//

#ifndef Expression_hpp
#define Expression_hpp

#include <stdlib.h>
#include <string>

class Environment;
using EnvPtr = std::shared_ptr<Environment>;

class Expression {
public:
    virtual std::shared_ptr<Expression> eval(EnvPtr) const = 0;
    virtual std::string print() const = 0;
};

using ExpressionPtr = std::shared_ptr<Expression>;

#endif /* Expression_hpp */
