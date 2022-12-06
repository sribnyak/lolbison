#include "statements/VarAssign.h"

VarAssign::VarAssign(const std::string& name, std::unique_ptr<Expression> value)
    : name(name), value(std::move(value)) {}

void VarAssign::print(std::ostream& out, int indent) const {
    out << "VarAssign(" << std::endl
        << std::string(indent + INDENT_WIDTH, ' ') << "name=\"" << name << "\"," << std::endl
        << std::string(indent + INDENT_WIDTH, ' ') << "value=";
    value->print(out, indent + INDENT_WIDTH);
    out << std::endl
        << std::string(indent, ' ') << ")";
}

void VarAssign::exec(Driver& driver) {
    // TODO: implement
}

VarAssign::~VarAssign() = default;
