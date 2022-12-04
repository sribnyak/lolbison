#include "expressions/binary_ops/BinaryXor.h"

void BinaryXor::print(std::ostream& out, int indent) const {
    print_binary_op("BinaryXor", out, indent);
}

BinaryXor::~BinaryXor() = default;
