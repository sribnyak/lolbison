#ifndef LOLBISON_EXPRESSIONS_BINARY_OPS_BINARY_EQ_H_
#define LOLBISON_EXPRESSIONS_BINARY_OPS_BINARY_EQ_H_

#include "expressions/binary_ops/BinaryOp.h"
#include <memory>
#include <ostream>
#include <string>

class BinaryEq : public BinaryOp {
public:
    using BinaryOp::BinaryOp;
    void print(std::ostream& out, int indent) const override;
    ~BinaryEq() override;
};

#endif  // LOLBISON_EXPRESSIONS_BINARY_OPS_BINARY_EQ_H_
