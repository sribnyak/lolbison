#include "statements/IfThen.h"
#include "objects/BooleanObject.h"
#include "driver.hh"
#include <string>

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

void IfThen::exec(Driver& driver) {
    bool condition = driver.variables["IT"]->to_boolean()->value;
    if (condition) {
        for (auto& statement : true_statements) {
            statement->exec(driver);
        }
    } else {
        for (auto& statement : false_statements) {
            statement->exec(driver);
        }
    }
}

IfThen::~IfThen() = default;
