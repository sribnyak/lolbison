#ifndef LOLBISON_EXPRESSIONS_IDENTIFIER_H_
#define LOLBISON_EXPRESSIONS_IDENTIFIER_H_

#include "expressions/Expression.h"
#include <ostream>
#include <string>

class Object;
class Driver;

class Identifier : public Expression {
    std::string name;

public:
    Identifier(const std::string& name);
    std::shared_ptr<const Object> eval(Driver& driver) override;
    void print(std::ostream& out, int indent) const override;
    ~Identifier() override;
};

#endif  // LOLBISON_EXPRESSIONS_IDENTIFIER_H_
