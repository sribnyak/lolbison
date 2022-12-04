#ifndef LOLBISON_EXPRESSIONS_BINARY_OPS_BINARY_DIV_H_
#define LOLBISON_EXPRESSIONS_BINARY_OPS_BINARY_DIV_H_

#include "expressions/binary_ops/BinaryOp.h"
#include <memory>
#include <ostream>
#include <string>

class BinaryDiv : public BinaryOp {
public:
    using BinaryOp::BinaryOp;
    void print(std::ostream& out, int indent) const override;
    ~BinaryDiv() override;
};

#endif  // LOLBISON_EXPRESSIONS_BINARY_OPS_BINARY_DIV_H_
