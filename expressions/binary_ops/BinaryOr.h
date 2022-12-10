#ifndef LOLBISON_EXPRESSIONS_BINARY_OPS_BINARY_OR_H_
#define LOLBISON_EXPRESSIONS_BINARY_OPS_BINARY_OR_H_

#include "expressions/binary_ops/BinaryOp.h"
#include <ostream>

class Object;
class Driver;

class BinaryOr : public BinaryOp {
public:
    using BinaryOp::BinaryOp;
    void print(std::ostream& out, int indent) const override;
    std::shared_ptr<const Object> eval(Driver& driver) override;
    ~BinaryOr() override;
};

#endif  // LOLBISON_EXPRESSIONS_BINARY_OPS_BINARY_OR_H_
