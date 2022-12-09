#include "expressions/Join.h"
#include "objects/StringObject.h"
#include <string>

Join::Join(std::vector<std::unique_ptr<Expression>> arguments)
    : arguments(std::move(arguments)) {}

std::shared_ptr<const Object> Join::eval(Driver& driver) {
    return std::make_shared<const StringObject>(""); // TODO: implement
}

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
