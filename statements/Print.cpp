#include "statements/Print.h"

Print::Print(std::vector<std::unique_ptr<Expression>> arguments,
             bool suppress_newline)
    : arguments(std::move(arguments)), suppress_newline(suppress_newline) {}

void Print::print(std::ostream& out, int indent) const {
    out << "Print(" << std::endl
        << std::string(indent + INDENT_WIDTH, ' ') << "arguments=[" << std::endl;
    for (const auto& argument : arguments) {
        out << std::string(indent + INDENT_WIDTH * 2, ' ');
        argument->print(out, indent + INDENT_WIDTH * 2);
        out << "," << std::endl;
    }
    out << std::string(indent + INDENT_WIDTH, ' ') << "]," << std::endl
        << std::string(indent + INDENT_WIDTH, ' ') << "suppress_newline=" << (suppress_newline ? "true" : "false") << std::endl
        << std::string(indent, ' ') << ")";
}

Print::~Print() = default;
