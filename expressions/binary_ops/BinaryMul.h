#ifndef LOLBISON_EXPRESSIONS_BINARY_OPS_BINARY_MUL_H_
#define LOLBISON_EXPRESSIONS_BINARY_OPS_BINARY_MUL_H_

#include "expressions/binary_ops/BinaryOp.h"
#include <ostream>

class BinaryMul : public BinaryOp {
public:
    using BinaryOp::BinaryOp;
    void print(std::ostream& out, int indent) const override;
    ~BinaryMul() override;
};

#endif  // LOLBISON_EXPRESSIONS_BINARY_OPS_BINARY_MUL_H_
