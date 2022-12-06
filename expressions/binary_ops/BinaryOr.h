#ifndef LOLBISON_EXPRESSIONS_BINARY_OPS_BINARY_OR_H_
#define LOLBISON_EXPRESSIONS_BINARY_OPS_BINARY_OR_H_

#include "expressions/binary_ops/BinaryOp.h"
#include <ostream>

class BinaryOr : public BinaryOp {
public:
    using BinaryOp::BinaryOp;
    void print(std::ostream& out, int indent) const override;
    ~BinaryOr() override;
};

#endif  // LOLBISON_EXPRESSIONS_BINARY_OPS_BINARY_OR_H_
