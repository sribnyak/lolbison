#ifndef LOLBISON_STATEMENTS_VARASSIGN_H_
#define LOLBISON_STATEMENTS_VARASSIGN_H_

#include "statements/Statement.h"
#include "expressions/Expression.h"
#include <memory>
#include <ostream>
#include <string>

class VarAssign : public Statement {
    std::string name;
    std::unique_ptr<Expression> value;

public:
    VarAssign(std::string name, std::unique_ptr<Expression> value);
    void print(std::ostream& out, int indent) const override;
    ~VarAssign() override;
};

#endif  // LOLBISON_STATEMENTS_VARASSIGN_H_
