#ifndef LOLBISON_STATEMENTS_LOOP_COMPONENTS_LOOP_UNTIL_H_
#define LOLBISON_STATEMENTS_LOOP_COMPONENTS_LOOP_UNTIL_H_

#include "statements/loop_components/LoopCondition.h"
#include <iosfwd>

class Driver;

class LoopUntil : public LoopCondition {
public:
    using LoopCondition::LoopCondition;
    void print(std::ostream& out, int indent) const override;
    bool check(Driver& driver) override;
    ~LoopUntil() override;
};

#endif  // LOLBISON_STATEMENTS_LOOP_COMPONENTS_LOOP_UNTIL_H_
