#include "expressions/binary_ops/BinaryNeq.h"

void BinaryNeq::print(std::ostream& out, int indent) const {
    print_binary_op("BinaryNeq", out, indent);
}

BinaryNeq::~BinaryNeq() = default;
