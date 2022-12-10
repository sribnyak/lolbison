#ifndef LOLBISON_STATEMENTS_LOOP_COMPONENTS_LOOP_HEAD_H_
#define LOLBISON_STATEMENTS_LOOP_COMPONENTS_LOOP_HEAD_H_

#include "AstNode.h"
#include "statements/loop_components/LoopCondition.h"
#include <memory>
#include <string>

class Driver;

class LoopHead : public AstNode {
protected:
    std::string counter;
    std::unique_ptr<LoopCondition> condition;

public:
    LoopHead(const std::string& counter, std::unique_ptr<LoopCondition> condition);
    bool check_condition(Driver& driver);
    void init(Driver& driver);
    virtual void step(Driver& driver) = 0;
    virtual ~LoopHead() {}
};

#endif  // LOLBISON_STATEMENTS_LOOP_COMPONENTS_LOOP_HEAD_H_
