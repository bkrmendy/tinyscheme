//
//  token.hpp
//  interpreter
//
//  Created by Bertalan Kormendy on 2018. 04. 29..
//  Copyright © 2018. Bertalan Kormendy. All rights reserved.
// (defun funky [x] [(defvar a 5) (+ a x)])

#ifndef token_hpp
#define token_hpp

#include <string>
#include "tokentypes.hpp"

struct Token {
    Token(std::string s);
    Token(char c);
    TOKENTYPES type;
    std::string token;
private:
    void setType(std::string s);
};

#endif /* token_hpp */
