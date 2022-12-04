#include "expressions/binary_ops/BinaryDiv.h"

void BinaryDiv::print(std::ostream& out, int indent) const {
    print_binary_op("BinaryDiv", out, indent);
}

BinaryDiv::~BinaryDiv() = default;
