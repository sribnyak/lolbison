#include "statements/ArrayDecl.h"

ArrayDecl::ArrayDecl(const std::string& name) : name(name) {}

void ArrayDecl::print(std::ostream& out, int indent) const {
    out << "ArrayDecl(" << "name=\"" << name << "\")";
}

void ArrayDecl::exec(Driver& driver) {
    // TODO: implement
}

ArrayDecl::~ArrayDecl() = default;
