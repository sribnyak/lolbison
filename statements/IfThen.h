#ifndef LOLBISON_STATEMENTS_IF_THEN_H_
#define LOLBISON_STATEMENTS_IF_THEN_H_

#include "statements/Statement.h"
#include <memory>
#include <ostream>
#include <string>
#include <vector>

class IfThen : public Statement {
    std::vector<std::unique_ptr<Statement>> true_statements;
    std::vector<std::unique_ptr<Statement>> false_statements;

public:
    IfThen(std::vector<std::unique_ptr<Statement>> true_statements);
    IfThen(std::vector<std::unique_ptr<Statement>> true_statements,
           std::vector<std::unique_ptr<Statement>> false_statements);
    void print(std::ostream& out, int indent) const override;
    ~IfThen() override;
};

#endif  // LOLBISON_STATEMENTS_IF_THEN_H_
