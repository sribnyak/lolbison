#include "expressions/binary_ops/BinaryEq.h"

void BinaryEq::print(std::ostream& out, int indent) const {
    print_binary_op("BinaryEq", out, indent);
}

BinaryEq::~BinaryEq() = default;
