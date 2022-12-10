#ifndef LOLBISON_EXPRESSIONS_BINARY_OPS_BINARY_SUB_H_
#define LOLBISON_EXPRESSIONS_BINARY_OPS_BINARY_SUB_H_

#include "expressions/binary_ops/BinaryOp.h"
#include <iosfwd>

class Object;
class Driver;

class BinarySub : public BinaryOp {
public:
    using BinaryOp::BinaryOp;
    void print(std::ostream& out, int indent) const override;
    std::shared_ptr<const Object> eval(Driver& driver) override;
    ~BinarySub() override;
};

#endif  // LOLBISON_EXPRESSIONS_BINARY_OPS_BINARY_SUB_H_
