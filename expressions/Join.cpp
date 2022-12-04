#include "expressions/Join.h"

Join::Join(std::vector<std::unique_ptr<Expression>> arguments)
    : arguments(std::move(arguments)) {}

void Join::print(std::ostream& out, int indent) const {
    out << "Join(" << std::endl
        << std::string(indent + INDENT_WIDTH, ' ') << "arguments=[" << std::endl;
    for (const auto& argument : arguments) {
        out << std::string(indent + INDENT_WIDTH * 2, ' ');
        argument->print(out, indent + INDENT_WIDTH * 2);
        out << "," << std::endl;
    }
    out << std::string(indent + INDENT_WIDTH, ' ') << "]" << std::endl
        << std::string(indent, ' ') << ")";
}

Join::~Join() = default;
