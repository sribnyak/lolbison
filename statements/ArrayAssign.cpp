#include "statements/ArrayAssign.h"
#include "objects/NumberObject.h"
#include "driver.hh"
#include <stdexcept>

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
    if (driver.arrays.find(array_name) == driver.arrays.end()) {
        throw std::runtime_error("Array " + array_name + " does not exist");
    }
    auto& array = driver.arrays[array_name];
    std::shared_ptr<const Object> index_value = index->eval(driver);
    auto index_number =
        std::dynamic_pointer_cast<const NumberObject>(index_value);
    if (!index_number) {
        throw std::runtime_error("Array index must be a number");
    }
    int index_int = index_number->value;
    if (array.find(index_int) == array.end()) {
        throw std::runtime_error("Array index " +
            std::to_string(index_int) + " does not exist");
    }
    array[index_int] = value->eval(driver);
}

ArrayAssign::~ArrayAssign() = default;
