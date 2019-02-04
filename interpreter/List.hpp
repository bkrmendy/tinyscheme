#ifndef List_hpp
#define List_hpp

#include <vector>
#include <string>

#include "Expression.hpp"
#include "Environment.hpp"

using ExpressionPtr = std::shared_ptr<Expression>;

class List : public Expression {
    std::vector<ExpressionPtr> values_;
public:
    List(std::vector<ExpressionPtr> exprs) : values_{exprs} {}
    
    ExpressionPtr eval(EnvPtr) const;
    std::string print() const;
    
    std::vector<ExpressionPtr> getValues() const;
    
    ExpressionPtr head() const;
    std::shared_ptr<List> tail() const;
    std::shared_ptr<List> cons(ExpressionPtr) const;
};


#endif /* List_hpp */
