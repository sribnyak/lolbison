#ifndef LOLBISON_OBJECTS_NIL_OBJECT_H_
#define LOLBISON_OBJECTS_NIL_OBJECT_H_

#include "objects/Object.h"
#include <memory>

class BooleanObject;
class NumberObject;
class StringObject;

class NilObject : public Object {
public:
    std::shared_ptr<const BooleanObject> to_boolean() const override;
    std::shared_ptr<const NumberObject> to_number() const override;
    std::shared_ptr<const StringObject> to_string() const override;
    bool equals(std::shared_ptr<const Object> other) const override;
    ~NilObject() override;
};

#endif  // LOLBISON_OBJECTS_NIL_OBJECT_H_
