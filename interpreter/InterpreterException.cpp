//
//  InterpreterException.cpp
//  interpreter
//
//  Created by Bertalan Kormendy on 2018. 05. 13..
//  Copyright © 2018. Bertalan Kormendy. All rights reserved.
//

#include "InterpreterException.hpp"

std::string InterpreterException::what() const {
    return msg_;
}
