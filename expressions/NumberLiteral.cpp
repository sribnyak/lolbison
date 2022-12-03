#include "expressions/NumberLiteral.h"

NumberLiteral::NumberLiteral(int value) : value(value) {}

void NumberLiteral::print(std::ostream& out, int indent) const {
    out << "NumberLiteral(value=" << value << ")";
}

NumberLiteral::~NumberLiteral() = default;
