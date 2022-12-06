#include "Program.h"

Program::Program(const std::string& version,
                 std::vector<std::unique_ptr<Statement>> statements)
    : version(version), statements(std::move(statements)) {}

void Program::print(std::ostream& out, int indent) const {
    out << "Program(" << std::endl
        << std::string(indent + INDENT_WIDTH, ' ') << "version=\"" << version << "\"," << std::endl
        << std::string(indent + INDENT_WIDTH, ' ') << "statements=[" << std::endl;
    for (const auto& statement : statements) {
        out << std::string(indent + INDENT_WIDTH * 2, ' ');
        statement->print(out, indent + INDENT_WIDTH * 2);
        out << "," << std::endl;
    }
    out << std::string(indent + INDENT_WIDTH, ' ') << "]" << std::endl
        << std::string(indent, ' ') << ")";
}

void Program::exec(Driver& driver) {
    for (auto& statement : statements) {
        statement->exec(driver);
    }
}
