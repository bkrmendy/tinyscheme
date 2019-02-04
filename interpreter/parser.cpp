#include <deque>
#include <iostream>
#include <stdlib.h>

#include "token.hpp"
#include "parser.hpp"
#include "List.hpp"
#include "Number.hpp"
#include "Variable.hpp"
#include "InterpreterException.hpp"

template <typename T>
bool contains(std::deque<T> v, T t){
    for (int i = 0; i < v.size(); i++)
        if (v[i] == t)
            return true;
    return false;
}

std::deque<char> Parser::SIG_TOKENS = { '\'', ')', '(', ']', '[' };
std::deque<char> Parser::WHITESPACE = { ' ', '\t', '\n' };
std::deque<char> Parser::RESERVED = {'@', '#', '~'};

std::shared_ptr<std::deque<Token>> Parser::tokenize(std::string input) {
    std::deque<Token> tokens;
    for (int i = 0; i < input.size(); i++) {
        if (!contains<char>(Parser::WHITESPACE, input[i])){
            if (contains(Parser::RESERVED, input[i]))
                throw InterpreterException("Cannot use reserved token as variable name");
            if (contains<char>(Parser::SIG_TOKENS, input[i]))
                tokens.push_back(Token{input[i]});
            else {
                int j = 0;
                while (!(contains<char>(Parser::SIG_TOKENS, input[i+j+1]) || contains<char>(Parser::WHITESPACE, input[i+j+1]))) {
                    j++;
                }
                tokens.push_back(Token(std::string{input.substr(i, j+1)}));
                i += j;
            }
        }
    }
    return std::make_shared<std::deque<Token>>(tokens);
}

ExpressionPtr Parser::read_from(std::shared_ptr<std::deque<Token>> tokens){
    Token current = tokens->front();
    tokens->pop_front();
    if (current.type == TOKENTYPES::LIST_OPEN) {
        std::vector<ExpressionPtr> exprs;
        while (tokens->front().type != TOKENTYPES::LIST_CLOSE) {
            exprs.push_back(Parser::read_from(tokens));
        }
        tokens->pop_front();
        return std::make_shared<List>(exprs);
    }
    if (current.type == TOKENTYPES::SYMBOL)
        return std::make_shared<Variable>(current.token);
    if (current.type == TOKENTYPES::NUMBER)
        return std::make_shared<Number>(std::stod(current.token));
    if (current.type == TOKENTYPES::QUOTE)
        return nullptr; // to be impemented
    else
        throw InterpreterException("Unknown token type");
}

ExpressionPtr Parser::read(std::string input) {
    std::shared_ptr<std::deque<Token>> tokens = tokenize(input);
    ExpressionPtr expr = read_from(tokens);
    return expr;
}
