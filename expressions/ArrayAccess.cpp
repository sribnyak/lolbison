#include "expressions/ArrayAccess.h"

ArrayAccess::ArrayAccess(const std::string& array_name,
                         std::unique_ptr<Expression> index)
    : array_name(array_name), index(std::move(index)) {}

void ArrayAccess::print(std::ostream& out, int indent) const {
    out << "ArrayAccess(" << std::endl
        << std::string(indent + INDENT_WIDTH, ' ') << "array_name=\"" << array_name << "\"," << std::endl
        << std::string(indent + INDENT_WIDTH, ' ') << "index=";
    index->print(out, indent + INDENT_WIDTH);
    out << std::endl
        << std::string(indent, ' ') << ")";
}

ArrayAccess::~ArrayAccess() = default;
