//
//  parser.hpp
//  interpreter
//
//  Created by Bertalan Kormendy on 2018. 04. 30..
//  Copyright © 2018. Bertalan Kormendy. All rights reserved.
//

#ifndef parser_hpp
#define parser_hpp

#include <deque>
#include <vector>
#include <map>
#include <string>
#include <functional>

#include "token.hpp"
#include "Expression.hpp"

class Parser {
    static std::deque<char> SIG_TOKENS;
    static std::deque<char> WHITESPACE;
    static std::deque<char> RESERVED;
public:
    static std::shared_ptr<std::deque<Token>> tokenize(std::string input);
    static ExpressionPtr read_from(std::shared_ptr<std::deque<Token>> tokens);
    static ExpressionPtr read(std::string input);
};

#endif /* parser_hpp */
