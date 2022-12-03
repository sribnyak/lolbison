#ifndef LOLBISON_EXPRESSIONS_STRING_LITERAL_H_
#define LOLBISON_EXPRESSIONS_STRING_LITERAL_H_

#include "expressions/Expression.h"
#include <ostream>
#include <string>

class StringLiteral : public Expression {
    std::string value;

public:
    StringLiteral(const std::string& value);
    void print(std::ostream& out, int indent) const override;
    ~StringLiteral() override;
};

#endif  // LOLBISON_EXPRESSIONS_STRING_LITERAL_H_
