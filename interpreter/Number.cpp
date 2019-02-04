//
//  Number.cpp
//  interpreter
//
//  Created by Bertalan Kormendy on 2018. 05. 12..
//  Copyright © 2018. Bertalan Kormendy. All rights reserved.
//

#include <strstream>

#include "Number.hpp"

ExpressionPtr Number::eval(EnvPtr env) const {
    return std::make_shared<Number>(*this);
}

std::string Number::print() const {
    std::strstream stream;
    stream << value_;
    return stream.str();
}

bool Number::boolean() const {
    if (value_ > 0)
        return true;
    return false;
}

std::shared_ptr<Number> Number::operator+(Number other) const {
    return std::make_shared<Number>(value_ + other.value_);
}

std::shared_ptr<Number> Number::operator-(Number other) const {
    return std::make_shared<Number>(value_ - other.value_);
}

std::shared_ptr<Number> Number::operator*(Number other) const {
    return std::make_shared<Number>(value_ * other.value_);
}

std::shared_ptr<Number> Number::operator/(Number other) const {
    return std::make_shared<Number>(value_ / other.value_);
}

bool Number::operator>(Number other) const {
    return value_ > other.value_;
}


