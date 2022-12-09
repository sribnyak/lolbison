#ifndef LOLBISON_EXPRESSIONS_BOOLEAN_LITERAL_H_
#define LOLBISON_EXPRESSIONS_BOOLEAN_LITERAL_H_

#include "expressions/Expression.h"
#include <ostream>

class Object;
class Driver;

class BooleanLiteral : public Expression {
    bool value;

public:
    BooleanLiteral(bool value);
    std::shared_ptr<const Object> eval(Driver& driver) override;
    void print(std::ostream& out, int indent) const override;
    ~BooleanLiteral() override;
};

#endif  // LOLBISON_EXPRESSIONS_BOOLEAN_LITERAL_H_
