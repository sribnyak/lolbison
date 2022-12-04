#include "expressions/binary_ops/BinaryAnd.h"

void BinaryAnd::print(std::ostream& out, int indent) const {
    print_binary_op("BinaryAnd", out, indent);
}

BinaryAnd::~BinaryAnd() = default;
