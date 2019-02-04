//
//  Environment.cpp
//  interpreter
//
//  Created by Bertalan Kormendy on 2018. 05. 07..
//  Copyright © 2018. Bertalan Kormendy. All rights reserved.
//

#include <map>

#include "Environment.hpp"

ExpressionPtr Environment::operator[](const std::string& query){
    if (inner_.count(query) > 0){
        return inner_[query];
    }
    if (outer_ != nullptr)
        return (*outer_)[query];
    return nullptr;
}

void Environment::add(std::string key, ExpressionPtr value){
    inner_[key] = value;
}

void Environment::declare(std::string key, ExpressionPtr value) {
    outer_->add(key, value);
}
