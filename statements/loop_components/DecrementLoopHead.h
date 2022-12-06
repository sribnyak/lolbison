#ifndef LOLBISON_STATEMENTS_LOOP_COMPONENTS_DECREMENT_LOOP_HEAD_H_
#define LOLBISON_STATEMENTS_LOOP_COMPONENTS_DECREMENT_LOOP_HEAD_H_

#include "statements/loop_components/LoopHead.h"
#include <memory>
#include <ostream>
#include <string>

class DecrementLoopHead : public LoopHead {
public:
    using LoopHead::LoopHead;
    void print(std::ostream& out, int indent) const override;
    ~DecrementLoopHead() override;
};

#endif  // LOLBISON_STATEMENTS_LOOP_COMPONENTS_DECREMENT_LOOP_HEAD_H_
