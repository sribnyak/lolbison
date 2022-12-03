#include "expressions/BooleanLiteral.h"

BooleanLiteral::BooleanLiteral(bool value) : value(value) {}

void BooleanLiteral::print(std::ostream& out, int indent) const {
    out << "BooleanLiteral(value=" << (value ? "true" : "false") << ")";
}

BooleanLiteral::~BooleanLiteral() = default;
