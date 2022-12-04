#include "expressions/binary_ops/BinarySum.h"

void BinarySum::print(std::ostream& out, int indent) const {
    print_binary_op("BinarySum", out, indent);
}

BinarySum::~BinarySum() = default;
