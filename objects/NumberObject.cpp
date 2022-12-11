#include "objects/NumberObject.h"
#include "objects/BooleanObject.h"
#include "objects/StringObject.h"
#include <string>

NumberObject::NumberObject(int value) : value(value) {}

std::shared_ptr<const BooleanObject> NumberObject::to_boolean() const {
    return std::make_shared<const BooleanObject>(value != 0);
}

std::shared_ptr<const NumberObject> NumberObject::to_number() const {
    return shared_from_this();
}

std::shared_ptr<const StringObject> NumberObject::to_string() const {
    return std::make_shared<const StringObject>(std::to_string(value));
}

bool NumberObject::equals(std::shared_ptr<const Object> other) const {
    auto other_number = std::dynamic_pointer_cast<const NumberObject>(other);
    return other_number && other_number->value == value;
}

NumberObject::~NumberObject() = default;
