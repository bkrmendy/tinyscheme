#include <iostream>
#include <string>
#include <map>

#include "Environment.hpp"
#include "Number.hpp"
#include "parser.hpp"

#include "std_env.cpp"

void init(EnvPtr env){
    env->add("PI", std::make_shared<Number>(3.14));
    env->add("e", std::make_shared<Number>(2.71));
    env->add("+", std::make_shared<BinaryOp<Number, Number>>([](NumberPtr a, NumberPtr b){
        return *a + *b;
    }));
    env->add("-", std::make_shared<BinaryOp<Number, Number>>([](NumberPtr a, NumberPtr b){
        return *a - *b;
    }));
    env->add("*", std::make_shared<BinaryOp<Number, Number>>([](NumberPtr a, NumberPtr b){ return *a * *b; }));
    env->add("/", std::make_shared<BinaryOp<Number, Number>>([](NumberPtr a, NumberPtr b){ return *a / *b; }));
    env->add(">", std::make_shared<BinaryOp<Number, Number>>([](NumberPtr a, NumberPtr b){
        return *a > *b ? std::make_shared<Number, Number>(1.0) : std::make_shared<Number>(-1.0);
    }));
    env->add("<", std::make_shared<BinaryOp<Number, Number>>([](NumberPtr a, NumberPtr b){
        return *b > *a ? std::make_shared<Number, Number>(1.0) : std::make_shared<Number>(-1.0);
    }));
    env->add("=", std::make_shared<BinaryOp<Number, Number>>([](NumberPtr a, NumberPtr b){
        return (!(*a > *b) && !( *b > *a)) ? std::make_shared<Number>(1.0) : std::make_shared<Number>(-1.0);
    }));
    env->add("car", std::make_shared<UnaryOp<List>>([](std::shared_ptr<List> list){return list->head();}));
    env->add("cdr", std::make_shared<UnaryOp<List>>([](std::shared_ptr<List> list){return list->tail();}));
    env->add("cons", std::make_shared<BinaryOp<Expression, List>>([](ExpressionPtr ex, std::shared_ptr<List> list){return list->cons(ex); }));
}

/*
 
 példák:
 
 
 (+ 3 2)    =>  5
 
 (define a 3)   =>  a
 
 (- a 2)    =>  1
 
 (define sqr (lambda (x) (* x x)))  =>  sqr
 
 (sqr 3)    =>  9
 
 (sqr a)    =>  9
 
 (define a 6)   =>  a
 
 (sqr a)    =>  36
 
 (define fact (lambda (n) (if (= n 0) 1 (* n (fact (- n 1)))))) => fact

 (fact a)   =>  720 ;
 
 */

std::string interpret(std::string input, EnvPtr env) {
    try {
        return Parser::read(input)->eval(env)->print();
    }
    catch (InterpreterException ex){
        return "ERROR: " + ex.what();
    }
}

int main(int argc, const char * argv[]) {
    EnvPtr env = std::make_shared<Environment>();

    init(env);
    
    std::string input;

    while(true){
        std::cout << "> ";
        std::getline(std::cin, input);
        if (input != ""){
            std::cout << interpret(input, env);
        }
    }
    return 0;
}
