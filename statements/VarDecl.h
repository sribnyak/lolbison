#ifndef LOLBISON_STATEMENTS_VAR_DECL_H_
#define LOLBISON_STATEMENTS_VAR_DECL_H_

#include "statements/Statement.h"
#include <iosfwd>
#include <memory>
#include <string>

class Expression;
class Driver;

class VarDecl : public Statement {
    std::string name;
    std::unique_ptr<Expression> value;

public:
    VarDecl(const std::string& name);
    VarDecl(const std::string& name, std::unique_ptr<Expression> value);
    void print(std::ostream& out, int indent) const override;
    void exec(Driver& driver) override;
    ~VarDecl() override;
};

#endif  // LOLBISON_STATEMENTS_VAR_DECL_H_
