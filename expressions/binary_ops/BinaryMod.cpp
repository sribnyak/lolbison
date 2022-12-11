#include "expressions/binary_ops/BinaryMod.h"
#include "objects/NumberObject.h"
#include <stdexcept>

void BinaryMod::print(std::ostream& out, int indent) const {
    print_binary_op("BinaryMod", out, indent);
}

std::shared_ptr<const Object> BinaryMod::eval(Driver& driver) {
    int lhs_value = lhs->eval(driver)->to_number()->value;
    int rhs_value = rhs->eval(driver)->to_number()->value;
    if (rhs_value == 0) {
        throw std::runtime_error("Division by zero");
    }
    return std::make_shared<const NumberObject>(lhs_value % rhs_value);
}

BinaryMod::~BinaryMod() = default;
