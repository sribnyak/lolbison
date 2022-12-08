#include "statements/ArrayDecl.h"
#include "driver.hh"
#include <stdexcept>

ArrayDecl::ArrayDecl(const std::string& name) : name(name) {}

void ArrayDecl::print(std::ostream& out, int indent) const {
    out << "ArrayDecl(" << "name=\"" << name << "\")";
}

void ArrayDecl::exec(Driver& driver) {
    if (driver.arrays.find(name) != driver.arrays.end()) {
        throw std::runtime_error("Array " + name + " already exists");
    }
    driver.arrays[name] = {};
}

ArrayDecl::~ArrayDecl() = default;
