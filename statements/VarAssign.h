#ifndef LOLBISON_STATEMENTS_VAR_ASSIGN_H_
#define LOLBISON_STATEMENTS_VAR_ASSIGN_H_

#include "statements/Statement.h"
#include <iosfwd>
#include <memory>
#include <string>

class Expression;
class Driver;

class VarAssign : public Statement {
    std::string name;
    std::unique_ptr<Expression> value;

public:
    VarAssign(const std::string& name, std::unique_ptr<Expression> value);
    void print(std::ostream& out, int indent) const override;
    void exec(Driver& driver) override;
    ~VarAssign() override;
};

#endif  // LOLBISON_STATEMENTS_VAR_ASSIGN_H_
