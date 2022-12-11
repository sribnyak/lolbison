#include "expressions/binary_ops/BinaryMin.h"
#include "objects/NumberObject.h"

void BinaryMin::print(std::ostream& out, int indent) const {
    print_binary_op("BinaryMin", out, indent);
}

std::shared_ptr<const Object> BinaryMin::eval(Driver& driver) {
    int lhs_value = lhs->eval(driver)->to_number()->value;
    int rhs_value = rhs->eval(driver)->to_number()->value;
    int result = (lhs_value < rhs_value) ? lhs_value : rhs_value;
    return std::make_shared<const NumberObject>(result);
}

BinaryMin::~BinaryMin() = default;
