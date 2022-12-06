#ifndef LOLBISON_EXPRESSIONS_BOOLEAN_LITERAL_H_
#define LOLBISON_EXPRESSIONS_BOOLEAN_LITERAL_H_

#include "expressions/Expression.h"
#include <ostream>
#include <string>

class BooleanLiteral : public Expression {
    bool value;

public:
    BooleanLiteral(bool value);
    void print(std::ostream& out, int indent) const override;
    ~BooleanLiteral() override;
};

#endif  // LOLBISON_EXPRESSIONS_BOOLEAN_LITERAL_H_
