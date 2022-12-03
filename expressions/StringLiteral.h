#ifndef LOLBISON_EXPRESSIONS_STRINGLITERAL_H_
#define LOLBISON_EXPRESSIONS_STRINGLITERAL_H_

#include "expressions/Expression.h"
#include <ostream>
#include <string>

class StringLiteral : public Expression {
    std::string value;

public:
    StringLiteral(std::string value);
    void print(std::ostream& out, int indent) const override;
    ~StringLiteral() override;
};

#endif  // LOLBISON_EXPRESSIONS_STRINGLITERAL_H_
