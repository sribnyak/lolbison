#ifndef LOLBISON_OBJECTS_BOOLEAN_OBJECT_H_
#define LOLBISON_OBJECTS_BOOLEAN_OBJECT_H_

#include "objects/Object.h"

class NumberObject;
class StringObject;

class BooleanObject : public Object, public std::enable_shared_from_this<BooleanObject> {
public:
    bool value;

    std::shared_ptr<const BooleanObject> to_boolean() const override;
    std::shared_ptr<const NumberObject> to_number() const override;
    std::shared_ptr<const StringObject> to_string() const override;
    bool equals(std::shared_ptr<const Object> other) const override;
    explicit BooleanObject(bool value);
    ~BooleanObject() override;
};

#endif  // LOLBISON_OBJECTS_BOOLEAN_OBJECT_H_
