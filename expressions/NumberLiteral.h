#ifndef LOLBISON_EXPRESSIONS_NUMBER_LITERAL_H_
#define LOLBISON_EXPRESSIONS_NUMBER_LITERAL_H_

#include "expressions/Expression.h"
#include <ostream>
#include <string>

class NumberLiteral : public Expression {
    int value;

public:
    NumberLiteral(int value);
    void print(std::ostream& out, int indent) const override;
    ~NumberLiteral() override;
};

#endif  // LOLBISON_EXPRESSIONS_NUMBER_LITERAL_H_
