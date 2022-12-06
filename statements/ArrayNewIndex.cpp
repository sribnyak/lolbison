#include "statements/ArrayNewIndex.h"
#include "driver.hh"
#include <exception>

ArrayNewIndex::ArrayNewIndex(const std::string& array_name,
                             std::unique_ptr<Expression> index,
                             std::unique_ptr<Expression> value)
    : array_name(array_name),
      index(std::move(index)),
      value(std::move(value)) {}

void ArrayNewIndex::print(std::ostream& out, int indent) const {
    out << "ArrayNewIndex(" << std::endl
        << std::string(indent + INDENT_WIDTH, ' ') << "array_name=\"" << array_name << "\"," << std::endl
        << std::string(indent + INDENT_WIDTH, ' ') << "index=";
    index->print(out, indent + INDENT_WIDTH);
    out << "," << std::endl
        << std::string(indent + INDENT_WIDTH, ' ') << "value=";
    value->print(out, indent + INDENT_WIDTH);
    out << std::endl
        << std::string(indent, ' ') << ")";
}

void ArrayNewIndex::exec(Driver& driver) {
    if (driver.arrays.find(array_name) == driver.arrays.end()) {
        throw std::runtime_error("Array " + array_name + " does not exist");
    }
    auto array = driver.arrays[array_name];
    // TODO check if index is int
}

ArrayNewIndex::~ArrayNewIndex() = default;
