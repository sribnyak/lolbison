#include "statements/loop_components/LoopWhile.h"
#include <memory>
#include <string>

void LoopWhile::print(std::ostream& out, int indent) const {
    out << "LoopWhile(" << std::endl
        << std::string(indent + INDENT_WIDTH, ' ') << "condition=";
    condition->print(out, indent + INDENT_WIDTH);
    out << std::endl
        << std::string(indent, ' ') << ")";
}

LoopWhile::~LoopWhile() = default;
