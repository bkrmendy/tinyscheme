//
//  Environment.hpp
//  interpreter
//
//  Created by Bertalan Kormendy on 2018. 05. 07..
//  Copyright © 2018. Bertalan Kormendy. All rights reserved.
//

#ifndef Environment_hpp
#define Environment_hpp

#include <map>
#include <string>

#include "Expression.hpp"

using ExpressionPtr = std::shared_ptr<Expression>;

class Environment {
public:
    std::shared_ptr<Environment> outer_;
    std::map<std::string, ExpressionPtr> inner_ = std::map<std::string, ExpressionPtr>{};
    
    Environment() {}
    Environment(std::shared_ptr<Environment> outer) : outer_{outer} {}
    
    void declare(std::string, ExpressionPtr);
    void add(std::string, ExpressionPtr);
    ExpressionPtr operator[](const std::string&);
};

using EnvPtr = std::shared_ptr<Environment>;

#endif /* Environment_hpp */
