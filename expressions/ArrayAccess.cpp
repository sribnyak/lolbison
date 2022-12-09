#include "expressions/ArrayAccess.h"
#include "objects/NumberObject.h"
#include "driver.hh"
#include <stdexcept>

ArrayAccess::ArrayAccess(const std::string& array_name,
                         std::unique_ptr<Expression> index)
    : array_name(array_name), index(std::move(index)) {}

std::shared_ptr<const Object> ArrayAccess::eval(Driver& driver) {
    if (driver.arrays.find(array_name) == driver.arrays.end()) {
        throw std::runtime_error("Array " + array_name + " does not exist");
    }
    const auto& array = driver.arrays[array_name];
    std::shared_ptr<const Object> index_value = index->eval(driver);
    auto index_number =
        std::dynamic_pointer_cast<const NumberObject>(index_value);
    if (!index_number) {
        throw std::runtime_error("Array index must be a number");
    }
    int index_int = index_number->value;
    try {
        return array.at(index_int);
    } catch (const std::out_of_range&) {
        throw std::runtime_error("Array index " +
            std::to_string(index_int) + " does not exist");
    }
}

void ArrayAccess::print(std::ostream& out, int indent) const {
    out << "ArrayAccess(" << std::endl
        << std::string(indent + INDENT_WIDTH, ' ') << "array_name=\"" << array_name << "\"," << std::endl
        << std::string(indent + INDENT_WIDTH, ' ') << "index=";
    index->print(out, indent + INDENT_WIDTH);
    out << std::endl
        << std::string(indent, ' ') << ")";
}

ArrayAccess::~ArrayAccess() = default;
