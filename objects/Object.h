#ifndef LOLBISON_OBJECTS_OBJECT_H_
#define LOLBISON_OBJECTS_OBJECT_H_

#include <memory>

class BooleanObject;
class NumberObject;
class StringObject;

class Object {
public:
    virtual std::shared_ptr<const BooleanObject> to_boolean() const = 0;
    virtual std::shared_ptr<const NumberObject> to_number() const = 0;
    virtual std::shared_ptr<const StringObject> to_string() const = 0;
    virtual bool equals(std::shared_ptr<const Object> other) const = 0;
    virtual ~Object() {}
};

#endif  // LOLBISON_OBJECTS_OBJECT_H_
