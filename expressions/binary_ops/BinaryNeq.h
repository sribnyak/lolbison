#ifndef LOLBISON_EXPRESSIONS_BINARY_OPS_BINARY_NEQ_H_
#define LOLBISON_EXPRESSIONS_BINARY_OPS_BINARY_NEQ_H_

#include "expressions/binary_ops/BinaryOp.h"
#include <ostream>

class BinaryNeq : public BinaryOp {
public:
    using BinaryOp::BinaryOp;
    void print(std::ostream& out, int indent) const override;
    ~BinaryNeq() override;
};

#endif  // LOLBISON_EXPRESSIONS_BINARY_OPS_BINARY_NEQ_H_
