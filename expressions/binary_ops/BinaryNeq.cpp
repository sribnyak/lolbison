#include "expressions/binary_ops/BinaryNeq.h"
#include "objects/BooleanObject.h"

void BinaryNeq::print(std::ostream& out, int indent) const {
    print_binary_op("BinaryNeq", out, indent);
}

std::shared_ptr<const Object> BinaryNeq::eval(Driver& driver) {
    auto lhs_value = lhs->eval(driver);
    auto rhs_value = rhs->eval(driver);
    return std::make_shared<const BooleanObject>(!lhs_value->equals(rhs_value));
}

BinaryNeq::~BinaryNeq() = default;
