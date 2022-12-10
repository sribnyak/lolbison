#include "statements/loop_components/LoopUntil.h"
#include "expressions/Expression.h"
#include "objects/BooleanObject.h"
#include "driver.hh"
#include <memory>
#include <string>

void LoopUntil::print(std::ostream& out, int indent) const {
    out << "LoopUntil(" << std::endl
        << std::string(indent + INDENT_WIDTH, ' ') << "condition=";
    condition->print(out, indent + INDENT_WIDTH);
    out << std::endl
        << std::string(indent, ' ') << ")";
}

bool LoopUntil::check(Driver& driver) {
    return !condition || !(condition->eval(driver)->to_boolean()->value);
}

LoopUntil::~LoopUntil() = default;
