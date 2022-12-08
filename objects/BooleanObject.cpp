#include "objects/BooleanObject.h"
#include "objects/NumberObject.h"
#include "objects/StringObject.h"

BooleanObject::BooleanObject(bool value) : value(value) {}

std::shared_ptr<const BooleanObject> BooleanObject::to_boolean() const {
    return shared_from_this();
}

std::shared_ptr<const NumberObject> BooleanObject::to_number() const {
    return std::make_shared<const NumberObject>(value ? 1 : 0);
}

std::shared_ptr<const StringObject> BooleanObject::to_string() const {
    return std::make_shared<const StringObject>(value ? "WIN" : "FAIL");
}

BooleanObject::~BooleanObject() = default;
