#include "expressions/binary_ops/BinaryMod.h"

void BinaryMod::print(std::ostream& out, int indent) const {
    print_binary_op("BinaryMod", out, indent);
}

BinaryMod::~BinaryMod() = default;
