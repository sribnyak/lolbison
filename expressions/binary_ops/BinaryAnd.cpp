#include "expressions/binary_ops/BinaryAnd.h"
#include "objects/BooleanObject.h"

void BinaryAnd::print(std::ostream& out, int indent) const {
    print_binary_op("BinaryAnd", out, indent);
}

std::shared_ptr<const Object> BinaryAnd::eval(Driver& driver) {
    bool lhs_value = lhs->eval(driver)->to_boolean()->value;
    if (!lhs_value) {
        return std::make_shared<const BooleanObject>(false);
    }
    bool result = rhs->eval(driver)->to_boolean()->value;
    return std::make_shared<const BooleanObject>(result);
}

BinaryAnd::~BinaryAnd() = default;
