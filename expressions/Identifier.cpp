#include "expressions/Identifier.h"

Identifier::Identifier(const std::string& name) : name(name) {}

void Identifier::print(std::ostream& out, int indent) const {
    out << "Identifier(name=\"" << name << "\")";
}

Identifier::~Identifier() = default;
