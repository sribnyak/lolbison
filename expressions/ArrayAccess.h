#ifndef LOLBISON_EXPRESSIONS_ARRAY_ACCESS_H_
#define LOLBISON_EXPRESSIONS_ARRAY_ACCESS_H_

#include "expressions/Expression.h"
#include <memory>
#include <ostream>
#include <string>

class ArrayAccess : public Expression {
    std::string array_name;
    std::unique_ptr<Expression> index;

public:
    ArrayAccess(const std::string& array_name, std::unique_ptr<Expression> index);
    void print(std::ostream& out, int indent) const override;
    ~ArrayAccess() override;
};

#endif // LOLBISON_EXPRESSIONS_ARRAY_ACCESS_H_
