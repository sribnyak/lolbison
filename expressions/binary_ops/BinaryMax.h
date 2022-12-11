#ifndef LOLBISON_EXPRESSIONS_BINARY_OPS_BINARY_MAX_H_
#define LOLBISON_EXPRESSIONS_BINARY_OPS_BINARY_MAX_H_

#include "expressions/binary_ops/BinaryOp.h"
#include <iosfwd>

class Object;
class Driver;

class BinaryMax : public BinaryOp {
public:
    using BinaryOp::BinaryOp;
    void print(std::ostream& out, int indent) const override;
    std::shared_ptr<const Object> eval(Driver& driver) override;
    ~BinaryMax() override;
};

#endif  // LOLBISON_EXPRESSIONS_BINARY_OPS_BINARY_MAX_H_
