#include "expressions/binary_ops/BinaryMax.h"

void BinaryMax::print(std::ostream& out, int indent) const {
    print_binary_op("BinaryMax", out, indent);
}

BinaryMax::~BinaryMax() = default;
