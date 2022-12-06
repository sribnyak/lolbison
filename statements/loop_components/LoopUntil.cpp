#include "statements/loop_components/LoopUntil.h"
#include <memory>
#include <string>

void LoopUntil::print(std::ostream& out, int indent) const {
    out << "LoopUntil(" << std::endl
        << std::string(indent + INDENT_WIDTH, ' ') << "condition=";
    condition->print(out, indent + INDENT_WIDTH);
    out << std::endl
        << std::string(indent, ' ') << ")";
}

LoopUntil::~LoopUntil() = default;
