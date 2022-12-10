#include "statements/loop_components/LoopHead.h"
#include "objects/NumberObject.h"
#include "driver.hh"

LoopHead::LoopHead(const std::string& counter,
                   std::unique_ptr<LoopCondition> condition)
    : counter(counter), condition(std::move(condition)) {}

bool LoopHead::check_condition(Driver& driver) {
    return !condition || condition->check(driver);
}

void LoopHead::init(Driver& driver) {
    driver.variables[counter] = std::make_shared<const NumberObject>(0);
}
