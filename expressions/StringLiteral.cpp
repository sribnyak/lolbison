#include "expressions/StringLiteral.h"
#include "objects/StringObject.h"
#include <memory>

StringLiteral::StringLiteral(const std::string& value) : value(value) {}

std::shared_ptr<const Object> StringLiteral::eval(Driver& driver) {
    return std::make_shared<const StringObject>(value);
}

void StringLiteral::print(std::ostream& out, int indent) const {
    out << "StringLiteral(value=\"" << value << "\")";
}

StringLiteral::~StringLiteral() = default;
