#include "objects/StringObject.h"
#include "objects/BooleanObject.h"
#include "objects/NumberObject.h"
#include <cstddef>
#include <stdexcept>

StringObject::StringObject(const std::string& value) : value(value) {}

bool StringObject::is_number() const {
    std::size_t begin = 0;
    std::size_t end = value.size();
    while (begin < end && (value[begin] == ' ' || value[begin] == '\t' ||
                           value[begin] == '\r')) {
        ++begin;
    }
    while (begin < end && (value[end - 1] == ' ' || value[end - 1] == '\t' ||
                           value[end - 1] == '\r')) {
        --end;
    }
    if (begin < end && value[begin] == '-') ++begin;
    if (begin == end) return false;
    for (std::size_t i = begin; i < end; ++i) {
        if (!std::isdigit(value[i])) return false;
    }
    return true;
}

std::shared_ptr<const BooleanObject> StringObject::to_boolean() const {
    return std::make_shared<const BooleanObject>(!value.empty());
}

std::shared_ptr<const NumberObject> StringObject::to_number() const {
    if (!is_number())
        throw std::runtime_error("Cannot cast string \"" + value +
                                 "\" to number");
    try {
        int result = std::stoi(value);
        return std::make_shared<const NumberObject>(result);
    } catch (const std::out_of_range&) {
        throw std::runtime_error("Cannot cast string \"" + value +
                                 "\" to number: integer is out of range");
    }
}

std::shared_ptr<const StringObject> StringObject::to_string() const {
    return shared_from_this();
}

bool StringObject::equals(std::shared_ptr<const Object> other) const {
    auto other_string = std::dynamic_pointer_cast<const StringObject>(other);
    return other_string && other_string->value == value;
}

StringObject::~StringObject() = default;
