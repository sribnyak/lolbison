#include "expressions/binary_ops/BinarySub.h"
#include "objects/NumberObject.h"
#include <limits>
#include <stdexcept>

void BinarySub::print(std::ostream& out, int indent) const {
    print_binary_op("BinarySub", out, indent);
}

std::shared_ptr<const Object> BinarySub::eval(Driver& driver) {
    int lhs_value = lhs->eval(driver)->to_number()->value;
    int rhs_value = rhs->eval(driver)->to_number()->value;
    long long result = static_cast<long long>(lhs_value) - rhs_value;
    if (result > std::numeric_limits<int>::max() ||
        result < std::numeric_limits<int>::min()) {
        throw std::runtime_error("Integer overflow in subtraction");
    }
    return std::make_shared<const NumberObject>(static_cast<int>(result));
}

BinarySub::~BinarySub() = default;
