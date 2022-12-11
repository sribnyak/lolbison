#include "expressions/binary_ops/BinaryXor.h"
#include "objects/BooleanObject.h"

void BinaryXor::print(std::ostream& out, int indent) const {
    print_binary_op("BinaryXor", out, indent);
}

std::shared_ptr<const Object> BinaryXor::eval(Driver& driver) {
    bool lhs_value = lhs->eval(driver)->to_boolean()->value;
    bool rhs_value = rhs->eval(driver)->to_boolean()->value;
    return std::make_shared<const BooleanObject>(lhs_value ^ rhs_value);
}

BinaryXor::~BinaryXor() = default;
