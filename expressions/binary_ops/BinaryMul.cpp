#include "expressions/binary_ops/BinaryMul.h"

void BinaryMul::print(std::ostream& out, int indent) const {
    print_binary_op("BinaryMul", out, indent);
}

BinaryMul::~BinaryMul() = default;
