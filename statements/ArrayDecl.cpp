#include "statements/ArrayDecl.h"

ArrayDecl::ArrayDecl(std::string name) : name(name) {}

void ArrayDecl::print(std::ostream& out, int indent) const {
    out << "ArrayDecl(" << "name=\"" << name << "\")";
}

ArrayDecl::~ArrayDecl() = default;
