#ifndef LOLBISON_EXPRESSIONS_LOGICAL_NOT_H_
#define LOLBISON_EXPRESSIONS_LOGICAL_NOT_H_

#include "expressions/Expression.h"
#include <memory>
#include <ostream>

class Object;
class Driver;

class LogicalNot : public Expression {
    std::unique_ptr<Expression> operand;

public:
    LogicalNot(std::unique_ptr<Expression> operand);
    std::shared_ptr<const Object> eval(Driver& driver) override;
    void print(std::ostream& out, int indent) const override;
    ~LogicalNot() override;
};

#endif  // LOLBISON_EXPRESSIONS_LOGICAL_NOT_H_
