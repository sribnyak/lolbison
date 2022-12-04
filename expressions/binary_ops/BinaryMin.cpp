#include "expressions/binary_ops/BinaryMin.h"

void BinaryMin::print(std::ostream& out, int indent) const {
    print_binary_op("BinaryMin", out, indent);
}

BinaryMin::~BinaryMin() = default;
