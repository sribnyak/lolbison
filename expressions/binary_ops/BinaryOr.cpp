#include "expressions/binary_ops/BinaryOr.h"

void BinaryOr::print(std::ostream& out, int indent) const {
    print_binary_op("BinaryOr", out, indent);
}

BinaryOr::~BinaryOr() = default;
