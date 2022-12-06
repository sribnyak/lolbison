#include "statements/loop_components/LoopHead.h"

LoopHead::LoopHead(const std::string& counter,
                   std::unique_ptr<LoopCondition> condition)
    : counter(counter), condition(std::move(condition)) {}
