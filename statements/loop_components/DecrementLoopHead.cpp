#include "statements/loop_components/DecrementLoopHead.h"
#include "objects/NumberObject.h"
#include "driver.hh"
#include <limits>
#include <memory>
#include <ostream>
#include <string>

void DecrementLoopHead::print(std::ostream& out, int indent) const {
    out << "DecrementLoopHead(" << std::endl
        << std::string(indent + INDENT_WIDTH, ' ') << "counter=\"" << counter << "\"," << std::endl
        << std::string(indent + INDENT_WIDTH, ' ') << "condition=";
    if (condition) {
        condition->print(out, indent + INDENT_WIDTH);
    } else {
        out << "null";
    }
    out << std::endl
        << std::string(indent, ' ') << ")";
}

void DecrementLoopHead::step(Driver& driver) {
    auto counter_object = driver.variables[counter];
    auto casted_object =
        std::dynamic_pointer_cast<const NumberObject>(counter_object);
    int value = casted_object->value;
    if (value == std::numeric_limits<int>::min()) {
        throw std::runtime_error("Loop counter overflow");
    }
    driver.variables[counter] = std::make_shared<const NumberObject>(value - 1);
}

DecrementLoopHead::~DecrementLoopHead() = default;
