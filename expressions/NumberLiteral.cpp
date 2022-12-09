#include "expressions/NumberLiteral.h"
#include "objects/NumberObject.h"
#include <memory>

NumberLiteral::NumberLiteral(int value) : value(value) {}

std::shared_ptr<const Object> NumberLiteral::eval(Driver& driver) {
    return std::make_shared<const NumberObject>(value);
}

void NumberLiteral::print(std::ostream& out, int indent) const {
    out << "NumberLiteral(value=" << value << ")";
}

NumberLiteral::~NumberLiteral() = default;
