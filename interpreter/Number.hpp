//
//  Number.hpp
//  interpreter
//
//  Created by Bertalan Kormendy on 2018. 05. 12..
//  Copyright © 2018. Bertalan Kormendy. All rights reserved.
//

#ifndef Number_hpp
#define Number_hpp

#include "Atom.hpp"

class Number : public Atom {
    double value_;
public:
    Number(double value) : value_{value} {};
    
    ExpressionPtr eval(EnvPtr) const;
    std::string print() const;
    bool boolean() const;
    
    std::shared_ptr<Number> operator+(Number) const;
    std::shared_ptr<Number> operator-(Number) const;
    std::shared_ptr<Number> operator/(Number) const;
    std::shared_ptr<Number> operator*(Number) const;
    bool operator>(Number) const;
};

using NumberPtr = std::shared_ptr<Number>;

#endif /* Number_hpp */
