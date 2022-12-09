#include "expressions/LogicalNot.h"
#include "objects/Object.h"
#include "objects/BooleanObject.h"
#include <string>

LogicalNot::LogicalNot(std::unique_ptr<Expression> operand)
    : operand(std::move(operand)) {}

std::shared_ptr<const Object> LogicalNot::eval(Driver& driver) {
    auto operand_value = operand->eval(driver);
    bool bool_value = operand_value->to_boolean()->value;
    return std::make_shared<const BooleanObject>(!bool_value);
}

void LogicalNot::print(std::ostream& out, int indent) const {
    out << "LogicalNot(" << std::endl
        << std::string(indent + INDENT_WIDTH, ' ') << "operand=";
    operand->print(out, indent + INDENT_WIDTH);
    out << std::endl
        << std::string(indent, ' ') << ")";
}

LogicalNot::~LogicalNot() = default;
