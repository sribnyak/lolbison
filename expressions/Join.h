#ifndef LOLBISON_EXPRESSIONS_JOIN_H_
#define LOLBISON_EXPRESSIONS_JOIN_H_

#include "expressions/Expression.h"
#include <memory>
#include <ostream>
#include <vector>

class Join : public Expression {
    std::vector<std::unique_ptr<Expression>> arguments;

public:
    Join(std::vector<std::unique_ptr<Expression>> arguments);
    void print(std::ostream& out, int indent) const override;
    ~Join() override;
};

#endif  // LOLBISON_EXPRESSIONS_JOIN_H_