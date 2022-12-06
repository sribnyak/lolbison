#ifndef LOLBISON_STATEMENTS_PRINT_H_
#define LOLBISON_STATEMENTS_PRINT_H_

#include "statements/Statement.h"
#include "expressions/Expression.h"
#include <memory>
#include <ostream>
#include <vector>

class Print : public Statement {
    std::vector<std::unique_ptr<Expression>> arguments;
    bool suppress_newline;

public:
    Print(std::vector<std::unique_ptr<Expression>> arguments,
          bool suppress_newline);
    void print(std::ostream& out, int indent) const override;
    void exec(Driver& driver) override;
    ~Print() override;
};

#endif  // LOLBISON_STATEMENTS_PRINT_H_
