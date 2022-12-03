#include "expressions/LogicalNot.h"

LogicalNot::LogicalNot(std::unique_ptr<Expression> operand)
    : operand(std::move(operand)) {}

void LogicalNot::print(std::ostream& out, int indent) const {
    out << "LogicalNot(" << std::endl
        << std::string(indent + INDENT_WIDTH, ' ') << "operand=";
    operand->print(out, indent + INDENT_WIDTH);
    out << std::endl
        << std::string(indent, ' ') << ")";
}

LogicalNot::~LogicalNot() = default;
