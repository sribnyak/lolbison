#include "statements/loop_components/DecrementLoopHead.h"
#include <memory>
#include <string>

void DecrementLoopHead::print(std::ostream& out, int indent) const {
    out << "DecrementLoopHead(" << std::endl
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

DecrementLoopHead::~DecrementLoopHead() = default;
