#ifndef LOLBISON_STATEMENTS_EXPR_STATEMENT_H_
#define LOLBISON_STATEMENTS_EXPR_STATEMENT_H_

#include "statements/Statement.h"
#include "expressions/Expression.h"
#include <memory>
#include <ostream>

class ExprStatement : public Statement {
    std::unique_ptr<Expression> expression;

public:
    ExprStatement(std::unique_ptr<Expression> expression);
    void print(std::ostream& out, int indent) const override;
    void exec(Driver& driver) override;
    ~ExprStatement() override;
};

#endif  // LOLBISON_STATEMENTS_EXPR_STATEMENT_H_
