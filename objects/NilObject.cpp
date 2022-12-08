#include "objects/NilObject.h"
#include "objects/BooleanObject.h"
#include <stdexcept>

std::shared_ptr<const BooleanObject> NilObject::to_boolean() const {
    return std::make_shared<const BooleanObject>(false);
}

std::shared_ptr<const NumberObject> NilObject::to_number() const {
    throw std::runtime_error("Cannot implicitly cast nil to number");
}

std::shared_ptr<const StringObject> NilObject::to_string() const {
    throw std::runtime_error("Cannot implicitly cast nil to string");
}

NilObject::~NilObject() = default;
