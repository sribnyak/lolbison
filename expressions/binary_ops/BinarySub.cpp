#include "expressions/binary_ops/BinarySub.h"

void BinarySub::print(std::ostream& out, int indent) const {
    print_binary_op("BinarySub", out, indent);
}

BinarySub::~BinarySub() = default;
