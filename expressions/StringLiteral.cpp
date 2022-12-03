#include "expressions/StringLiteral.h"

StringLiteral::StringLiteral(std::string value) : value(value) {}

void StringLiteral::print(std::ostream& out, int indent) const {
    out << "StringLiteral(value=\"" << value << "\")";
}

StringLiteral::~StringLiteral() = default;
