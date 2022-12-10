#include "objects/BooleanObject.h"
#include "objects/NumberObject.h"
#include <stdexcept>

BooleanObject::BooleanObject(bool value) : value(value) {}

std::shared_ptr<const BooleanObject> BooleanObject::to_boolean() const {
    return shared_from_this();
}

std::shared_ptr<const NumberObject> BooleanObject::to_number() const {
    return std::make_shared<const NumberObject>(value ? 1 : 0);
}

std::shared_ptr<const StringObject> BooleanObject::to_string() const {
    throw std::runtime_error("Cannot implicitly cast boolean to string");
}

bool BooleanObject::equals(std::shared_ptr<const Object> other) const {
    auto other_boolean = std::dynamic_pointer_cast<const BooleanObject>(other);
    return other_boolean && other_boolean->value == value;
}

BooleanObject::~BooleanObject() = default;
