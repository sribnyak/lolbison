#include "statements/loop_components/LoopCondition.h"
#include "expressions/Expression.h"

LoopCondition::LoopCondition(std::unique_ptr<Expression> condition)
    : condition(std::move(condition)) {}
