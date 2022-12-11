#include "expressions/binary_ops/BinaryMax.h"
#include "objects/NumberObject.h"

void BinaryMax::print(std::ostream& out, int indent) const {
    print_binary_op("BinaryMax", out, indent);
}

std::shared_ptr<const Object> BinaryMax::eval(Driver& driver) {
    int lhs_value = lhs->eval(driver)->to_number()->value;
    int rhs_value = rhs->eval(driver)->to_number()->value;
    int result = (lhs_value > rhs_value) ? lhs_value : rhs_value;
    return std::make_shared<const NumberObject>(result);
}

BinaryMax::~BinaryMax() = default;
