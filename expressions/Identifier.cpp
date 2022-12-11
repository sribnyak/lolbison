#include "expressions/Identifier.h"
#include "driver.hh"
#include <ostream>

Identifier::Identifier(const std::string& name) : name(name) {}

std::shared_ptr<const Object> Identifier::eval(Driver& driver) {
    try {
        return driver.variables.at(name);
    } catch (const std::out_of_range&) {
        throw std::runtime_error("Variable " + name + " does not exist");
    }
}

void Identifier::print(std::ostream& out, int indent) const {
    out << "Identifier(name=\"" << name << "\")";
}

Identifier::~Identifier() = default;
