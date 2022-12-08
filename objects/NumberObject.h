#ifndef LOLBISON_OBJECTS_NUMBER_OBJECT_H_
#define LOLBISON_OBJECTS_NUMBER_OBJECT_H_

#include "objects/Object.h"

class BooleanObject;
class StringObject;

class NumberObject : public Object, public std::enable_shared_from_this<NumberObject> {
public:
    int value;

    std::shared_ptr<const BooleanObject> to_boolean() const override;
    std::shared_ptr<const NumberObject> to_number() const override;
    std::shared_ptr<const StringObject> to_string() const override;
    explicit NumberObject(int value);
    ~NumberObject() override;
};

#endif  // LOLBISON_OBJECTS_NUMBER_OBJECT_H_
