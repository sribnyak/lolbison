#ifndef LOLBISON_EXPRESSIONS_BINARY_OPS_BINARY_OP_H_
#define LOLBISON_EXPRESSIONS_BINARY_OPS_BINARY_OP_H_

#include "expressions/Expression.h"
#include <memory>
#include <ostream>
#include <string>

class BinaryOp : public Expression {
protected:
    std::unique_ptr<Expression> lhs;
    std::unique_ptr<Expression> rhs;

    void print_binary_op(const std::string& class_name, std::ostream& out,
                         int indent) const;

public:
    BinaryOp();
    void init_args(std::unique_ptr<Expression> lhs,
                   std::unique_ptr<Expression> rhs);
    virtual ~BinaryOp() {}
};

#endif  // LOLBISON_EXPRESSIONS_BINARY_OPS_BINARY_OP_H_
