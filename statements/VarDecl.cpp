#include "statements/VarDecl.h"
#include "expressions/Expression.h"
#include "objects/NilObject.h"
#include "driver.hh"
#include <ostream>

VarDecl::VarDecl(const std::string& name) : name(name), value() {}

VarDecl::VarDecl(const std::string& name, std::unique_ptr<Expression> value)
    : name(name), value(std::move(value)) {}

void VarDecl::print(std::ostream& out, int indent) const {
    out << "VarDecl(" << std::endl
        << std::string(indent + INDENT_WIDTH, ' ') << "name=\"" << name << "\"," << std::endl
        << std::string(indent + INDENT_WIDTH, ' ') << "value=";
    if (value) {
        value->print(out, indent + INDENT_WIDTH);
    } else {
        out << "null";
    }
    out << std::endl
        << std::string(indent, ' ') << ")";
}

void VarDecl::exec(Driver& driver) {
    if (value) {
        driver.variables[name] = value->eval(driver);
    } else {
        driver.variables[name] = std::make_shared<const NilObject>();
    }
}

VarDecl::~VarDecl() = default;
