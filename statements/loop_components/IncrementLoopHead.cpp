#include "statements/loop_components/IncrementLoopHead.h"
#include <memory>
#include <string>

void IncrementLoopHead::print(std::ostream& out, int indent) const {
    out << "IncrementLoopHead(" << std::endl
        << std::string(indent + INDENT_WIDTH, ' ') << "counter=\"" << counter << "\"," << std::endl
        << std::string(indent + INDENT_WIDTH, ' ') << "condition=";
    if (condition) {
        condition->print(out, indent + INDENT_WIDTH);
    } else {
        out << "null";
    }
    out << std::endl
        << std::string(indent, ' ') << ")";
}

IncrementLoopHead::~IncrementLoopHead() = default;
