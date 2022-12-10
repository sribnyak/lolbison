#ifndef LOLBISON_EXPRESSIONS_BINARY_OPS_BINARY_AND_H_
#define LOLBISON_EXPRESSIONS_BINARY_OPS_BINARY_AND_H_

#include "expressions/binary_ops/BinaryOp.h"
#include <iosfwd>

class Object;
class Driver;

class BinaryAnd : public BinaryOp {
public:
    using BinaryOp::BinaryOp;
    void print(std::ostream& out, int indent) const override;
    std::shared_ptr<const Object> eval(Driver& driver) override;
    ~BinaryAnd() override;
};

#endif  // LOLBISON_EXPRESSIONS_BINARY_OPS_BINARY_AND_H_
