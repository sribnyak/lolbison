#include "statements/IfThen.h"

IfThen::IfThen(std::vector<std::unique_ptr<Statement>> true_statements)
    : true_statements(std::move(true_statements)), false_statements() {}

IfThen::IfThen(std::vector<std::unique_ptr<Statement>> true_statements,
               std::vector<std::unique_ptr<Statement>> false_statements)
    : true_statements(std::move(true_statements)),
      false_statements(std::move(false_statements)) {}

void IfThen::print(std::ostream& out, int indent) const {
    out << "IfThen(" << std::endl
        << std::string(indent + INDENT_WIDTH, ' ') << "true_statements=[" << std::endl;
    for (const auto& statement : true_statements) {
        out << std::string(indent + INDENT_WIDTH * 2, ' ');
        statement->print(out, indent + INDENT_WIDTH * 2);
        out << "," << std::endl;
    }
    out << std::string(indent + INDENT_WIDTH, ' ') << "]," << std::endl
        << std::string(indent + INDENT_WIDTH, ' ') << "false_statements=[" << std::endl;
    for (const auto& statement : false_statements) {
        out << std::string(indent + INDENT_WIDTH * 2, ' ');
        statement->print(out, indent + INDENT_WIDTH * 2);
        out << "," << std::endl;
    }
    out << std::string(indent + INDENT_WIDTH, ' ') << "]" << std::endl
        << std::string(indent, ' ') << ")";
}

IfThen::~IfThen() = default;
