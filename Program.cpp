#include "Program.h"

Program::Program(std::string version,
                 std::vector<std::unique_ptr<Statement>> statements)
    : version(version), statements(std::move(statements)) {}

void Program::print(std::ostream& out, int indent) const {
    out << "Program(" << std::endl
        << std::string(indent + INDENT_WIDTH, ' ') << "version=\"" << version << "\"," << std::endl
        << std::string(indent + INDENT_WIDTH, ' ') << "statements=[" << std::endl;
    for (const auto& statement : statements) {
        out << std::string(indent + INDENT_WIDTH * 2, ' ');
        if (statement) {
            statement->print(out, indent + INDENT_WIDTH * 2);
        } else {
            out << "null";
        }
        out << "," << std::endl;
    }
    out << std::string(indent + INDENT_WIDTH, ' ') << "]" << std::endl
        << std::string(indent, ' ') << ")";
}
