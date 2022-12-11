#include "expressions/Join.h"
#include "objects/StringObject.h"
#include <ostream>
#include <string>

Join::Join(std::vector<std::unique_ptr<Expression>> arguments)
    : arguments(std::move(arguments)) {}

std::shared_ptr<const Object> Join::eval(Driver& driver) {
    std::string result;
    for (auto& argument : arguments) {
        result += argument->eval(driver)->to_string()->value;
    }
    return std::make_shared<const StringObject>(result);
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
