#include "statements/ExprStatement.h"

ExprStatement::ExprStatement(std::unique_ptr<Expression> expression)
    : expression(std::move(expression)) {}

void ExprStatement::print(std::ostream& out, int indent) const {
    out << "ExprStatement(" << std::endl
        << std::string(indent + INDENT_WIDTH, ' ') << "expression=";
    if (expression) {
        expression->print(out, indent + INDENT_WIDTH);
    } else {
        out << "null";
    }
    out << std::endl
        << std::string(indent, ' ') << ")";
}

ExprStatement::~ExprStatement() = default;
