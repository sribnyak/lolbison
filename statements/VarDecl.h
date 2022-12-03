#ifndef LOLBISON_STATEMENTS_VAR_DECL_H_
#define LOLBISON_STATEMENTS_VAR_DECL_H_

#include "statements/Statement.h"
#include "expressions/Expression.h"
#include <memory>
#include <ostream>
#include <string>

class VarDecl : public Statement {
    std::string name;
    std::unique_ptr<Expression> value;

public:
    VarDecl(const std::string& name);
    VarDecl(const std::string& name, std::unique_ptr<Expression> value);
    void print(std::ostream& out, int indent) const override;
    ~VarDecl() override;
};

#endif  // LOLBISON_STATEMENTS_VAR_DECL_H_
