#ifndef LOLBISON_EXPRESSIONS_ARRAY_ACCESS_H_
#define LOLBISON_EXPRESSIONS_ARRAY_ACCESS_H_

#include "expressions/Expression.h"
#include <iosfwd>
#include <memory>
#include <string>

class Object;
class Driver;

class ArrayAccess : public Expression {
    std::string array_name;
    std::unique_ptr<Expression> index;

public:
    ArrayAccess(const std::string& array_name, std::unique_ptr<Expression> index);
    std::shared_ptr<const Object> eval(Driver& driver) override;
    void print(std::ostream& out, int indent) const override;
    ~ArrayAccess() override;
};

#endif  // LOLBISON_EXPRESSIONS_ARRAY_ACCESS_H_
