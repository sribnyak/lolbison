#include "statements/ArrayAssign.h"

ArrayAssign::ArrayAssign(const std::string& array_name,
                         std::unique_ptr<Expression> index,
                         std::unique_ptr<Expression> value)
    : array_name(array_name),
      index(std::move(index)),
      value(std::move(value)) {}

void ArrayAssign::print(std::ostream& out, int indent) const {
    out << "ArrayAssign(" << std::endl
        << std::string(indent + INDENT_WIDTH, ' ') << "array_name=\"" << array_name << "\"," << std::endl
        << std::string(indent + INDENT_WIDTH, ' ') << "index=";
    index->print(out, indent + INDENT_WIDTH);
    out << "," << std::endl
        << std::string(indent + INDENT_WIDTH, ' ') << "value=";
    value->print(out, indent + INDENT_WIDTH);
    out << std::endl
        << std::string(indent, ' ') << ")";
}

void ArrayAssign::exec(Driver& driver) {
    // TODO: implement
}

ArrayAssign::~ArrayAssign() = default;
