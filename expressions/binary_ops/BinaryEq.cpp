#include "expressions/binary_ops/BinaryEq.h"
#include "objects/BooleanObject.h"

void BinaryEq::print(std::ostream& out, int indent) const {
    print_binary_op("BinaryEq", out, indent);
}

std::shared_ptr<const Object> BinaryEq::eval(Driver& driver) {
    auto lhs_value = lhs->eval(driver);
    auto rhs_value = rhs->eval(driver);
    return std::make_shared<const BooleanObject>(lhs_value->equals(rhs_value));
}

BinaryEq::~BinaryEq() = default;
