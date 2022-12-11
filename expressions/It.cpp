#include "expressions/It.h"
#include "driver.hh"
#include <ostream>

std::shared_ptr<const Object> It::eval(Driver& driver) {
    return driver.variables.at("IT");
}

void It::print(std::ostream& out, int indent) const {
    out << "It()";
}

It::~It() = default;
