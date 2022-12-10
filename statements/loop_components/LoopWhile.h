#ifndef LOLBISON_STATEMENTS_LOOP_COMPONENTS_LOOP_WHILE_H_
#define LOLBISON_STATEMENTS_LOOP_COMPONENTS_LOOP_WHILE_H_

#include "statements/loop_components/LoopCondition.h"
#include <iosfwd>

class Driver;

class LoopWhile : public LoopCondition {
public:
    using LoopCondition::LoopCondition;
    void print(std::ostream& out, int indent) const override;
    bool check(Driver& driver) override;
    ~LoopWhile() override;
};

#endif  // LOLBISON_STATEMENTS_LOOP_COMPONENTS_LOOP_WHILE_H_
