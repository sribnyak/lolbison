#ifndef LOLBISON_STATEMENTS_LOOP_COMPONENTS_LOOP_CONDITION_H_
#define LOLBISON_STATEMENTS_LOOP_COMPONENTS_LOOP_CONDITION_H_

#include "AstNode.h"
#include <memory>

class Expression;
class Driver;

class LoopCondition : public AstNode {
protected:
    std::unique_ptr<Expression> condition;

public:
    LoopCondition(std::unique_ptr<Expression> condition);
    virtual bool check(Driver& driver) = 0;
    virtual ~LoopCondition() {}
};

#endif  // LOLBISON_STATEMENTS_LOOP_COMPONENTS_LOOP_CONDITION_H_
