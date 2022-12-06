#ifndef LOLBISON_EXPRESSIONS_BINARY_OPS_BINARY_MAX_H_
#define LOLBISON_EXPRESSIONS_BINARY_OPS_BINARY_MAX_H_

#include "expressions/binary_ops/BinaryOp.h"
#include <ostream>

class BinaryMax : public BinaryOp {
public:
    using BinaryOp::BinaryOp;
    void print(std::ostream& out, int indent) const override;
    ~BinaryMax() override;
};

#endif  // LOLBISON_EXPRESSIONS_BINARY_OPS_BINARY_MAX_H_