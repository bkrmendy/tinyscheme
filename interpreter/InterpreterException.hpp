//
//  InterpreterException.hpp
//  interpreter
//
//  Created by Bertalan Kormendy on 2018. 05. 13..
//  Copyright © 2018. Bertalan Kormendy. All rights reserved.
//

#ifndef InterpreterException_hpp
#define InterpreterException_hpp

#include <stdio.h>
#include <string>

class InterpreterException {
    std::string msg_;
    
public:
    InterpreterException(std::string msg) : msg_{msg} {}
    
    std::string what() const;
};

#endif /* InterpreterException_hpp */
