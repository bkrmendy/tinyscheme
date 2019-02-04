//
//  Procedure.hpp
//  interpreter
//
//  Created by Bertalan Kormendy on 2018. 05. 12..
//  Copyright © 2018. Bertalan Kormendy. All rights reserved.
//

#ifndef Procedure_hpp
#define Procedure_hpp

#include <string>
#include <vector>

#include "Expression.hpp"
#include "List.hpp"

class Procedure : public Expression {
protected:
    std::vector<std::string> params_;
    ExpressionPtr body_ = nullptr;
    EnvPtr inner_env = nullptr;
public:
    Procedure(std::vector<std::string> params) : params_{params} {} 
    Procedure(std::vector<std::string> params, ExpressionPtr body) : params_{params}, body_{body} {}
    
    std::string print() const;
    ExpressionPtr eval(EnvPtr) const;
    std::vector<std::string> getParams() const;
};

#endif /* Procedure_hpp */
