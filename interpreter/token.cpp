#include <string>
#include <stdlib.h>

#include "token.hpp"
#include "tokentypes.hpp"

bool is_numeric(std::string str){
    int i = 0;
    bool decimal = false;
    if (str[0] == '-' && str.size() > 1)
        i = 1;
    for (; i < str.length(); i++){
        if (! ( isdigit(str[i]) || str[i] == '.'))
            return false;
        if (str[i] == '.'){         // 11.2.3 elkerülése
            if (decimal == true)
                return false;
            decimal = true;
            }
        }
    return true;
}

Token::Token(std::string s) : token{s} {
    setType(token);
}

Token::Token(char c) : token(std::string(1, c)){
    setType(token);
}

void Token::setType(std::string s){
    if (s == "(")
        type = TOKENTYPES::LIST_OPEN;
    else if (s == ")")
        type = TOKENTYPES::LIST_CLOSE;
    else if (s == "`")
        type = TOKENTYPES::QUOTE;
    else if (is_numeric(s))
        type = TOKENTYPES::NUMBER;
    else
        type = TOKENTYPES::SYMBOL;
}
