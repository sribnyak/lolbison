#ifndef LOLBISON_STATEMENTS_LOOP_COMPONENTS_INCREMENT_LOOP_HEAD_H_
#define LOLBISON_STATEMENTS_LOOP_COMPONENTS_INCREMENT_LOOP_HEAD_H_

#include "statements/loop_components/LoopHead.h"
#include <ostream>

class Driver;

class IncrementLoopHead : public LoopHead {
public:
    using LoopHead::LoopHead;
    void print(std::ostream& out, int indent) const override;
    void step(Driver& driver) override;
    ~IncrementLoopHead() override;
};

#endif  // LOLBISON_STATEMENTS_LOOP_COMPONENTS_INCREMENT_LOOP_HEAD_H_
