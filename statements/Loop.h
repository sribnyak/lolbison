#ifndef LOLBISON_STATEMENTS_LOOP_H_
#define LOLBISON_STATEMENTS_LOOP_H_

#include "statements/Statement.h"
#include "statements/loop_components/LoopHead.h"
#include <iosfwd>
#include <memory>
#include <string>
#include <vector>

class Driver;

class Loop : public Statement {
    std::string name;
    std::unique_ptr<LoopHead> head;
    std::vector<std::unique_ptr<Statement>> statements;

public:
    Loop(const std::string& name, std::unique_ptr<LoopHead> head,
         std::vector<std::unique_ptr<Statement>> statements);
    void print(std::ostream& out, int indent) const override;
    void exec(Driver& driver) override;
    ~Loop() override;
};

#endif  // LOLBISON_STATEMENTS_LOOP_H_
