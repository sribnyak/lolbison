#include "expressions/binary_ops/BinaryOr.h"
#include "objects/BooleanObject.h"

void BinaryOr::print(std::ostream& out, int indent) const {
    print_binary_op("BinaryOr", out, indent);
}

std::shared_ptr<const Object> BinaryOr::eval(Driver& driver) {
    bool lhs_value = lhs->eval(driver)->to_boolean()->value;
    if (lhs_value) {
        return std::make_shared<const BooleanObject>(true);
    }
    bool result = rhs->eval(driver)->to_boolean()->value;
    return std::make_shared<const BooleanObject>(result);
}

BinaryOr::~BinaryOr() = default;
