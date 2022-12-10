#include "expressions/BooleanLiteral.h"
#include "objects/BooleanObject.h"
#include <memory>
#include <ostream>

BooleanLiteral::BooleanLiteral(bool value) : value(value) {}

std::shared_ptr<const Object> BooleanLiteral::eval(Driver& driver) {
    return std::make_shared<const BooleanObject>(value);
}

void BooleanLiteral::print(std::ostream& out, int indent) const {
    out << "BooleanLiteral(value=" << (value ? "true" : "false") << ")";
}

BooleanLiteral::~BooleanLiteral() = default;
