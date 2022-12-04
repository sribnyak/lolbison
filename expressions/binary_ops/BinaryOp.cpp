#include "expressions/binary_ops/BinaryOp.h"

void BinaryOp::print_binary_op(const std::string& class_name, std::ostream& out,
                               int indent) const {
    out << class_name << "(" << std::endl
        << std::string(indent + INDENT_WIDTH, ' ') << "lhs=";
    lhs->print(out, indent + INDENT_WIDTH);
    out << "," << std::endl
        << std::string(indent + INDENT_WIDTH, ' ') << "rhs=";
    rhs->print(out, indent + INDENT_WIDTH);
    out << std::endl
        << std::string(indent, ' ') << ")";
}

BinaryOp::BinaryOp() = default;

void BinaryOp::init_args(std::unique_ptr<Expression> lhs,
                         std::unique_ptr<Expression> rhs) {
    this->lhs = std::move(lhs);
    this->rhs = std::move(rhs);
}
