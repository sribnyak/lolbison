#include "statements/loop_components/LoopWhile.h"
#include "expressions/Expression.h"
#include "objects/BooleanObject.h"
#include "driver.hh"
#include <memory>
#include <string>

void LoopWhile::print(std::ostream& out, int indent) const {
    out << "LoopWhile(" << std::endl
        << std::string(indent + INDENT_WIDTH, ' ') << "condition=";
    condition->print(out, indent + INDENT_WIDTH);
    out << std::endl
        << std::string(indent, ' ') << ")";
}

bool LoopWhile::check(Driver& driver) {
    return !condition || condition->eval(driver)->to_boolean()->value;
}

LoopWhile::~LoopWhile() = default;
