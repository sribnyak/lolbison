#include "statements/Loop.h"

Loop::Loop(const std::string& name, std::unique_ptr<LoopHead> head,
           std::vector<std::unique_ptr<Statement>> statements)
    : name(name), head(std::move(head)), statements(std::move(statements)) {}

void Loop::print(std::ostream& out, int indent) const {
    out << "Loop(" << std::endl
        << std::string(indent + INDENT_WIDTH, ' ') << "name=\"" << name << "\"," << std::endl
        << std::string(indent + INDENT_WIDTH, ' ') << "head=";
    if (head) {
        head->print(out, indent + INDENT_WIDTH);
    } else {
        out << "null";
    }
    out << "," << std::endl
        << std::string(indent + INDENT_WIDTH, ' ') << "statements=[" << std::endl;
    for (const auto& statement : statements) {
        out << std::string(indent + INDENT_WIDTH * 2, ' ');
        statement->print(out, indent + INDENT_WIDTH * 2);
        out << "," << std::endl;
    }
    out << std::string(indent + INDENT_WIDTH, ' ') << "]" << std::endl
        << std::string(indent, ' ') << ")";
}

void Loop::exec(Driver& driver) {
    // TODO: implement
}

Loop::~Loop() = default;
