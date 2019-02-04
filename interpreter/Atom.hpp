//
//  Atom.hpp
//  interpreter
//
//  Created by Bertalan Kormendy on 2018. 05. 12..
//  Copyright © 2018. Bertalan Kormendy. All rights reserved.
//

#ifndef Atom_hpp
#define Atom_hpp

#include <string>

#include "Expression.hpp"

class Atom : public Expression {
public:
    virtual bool boolean() const = 0;
};

#endif /* Atom_hpp */
