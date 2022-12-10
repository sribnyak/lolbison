#ifndef LOLBISON_OBJECTS_STRING_OBJECT_H_
#define LOLBISON_OBJECTS_STRING_OBJECT_H_

#include "objects/Object.h"
#include <memory>
#include <string>

class BooleanObject;
class NumberObject;

class StringObject : public Object, public std::enable_shared_from_this<StringObject> {
private:
    bool is_number() const;

public:
    std::string value;

    std::shared_ptr<const BooleanObject> to_boolean() const override;
    std::shared_ptr<const NumberObject> to_number() const override;
    std::shared_ptr<const StringObject> to_string() const override;
    bool equals(std::shared_ptr<const Object> other) const override;
    explicit StringObject(const std::string& value);
    ~StringObject() override;
};

#endif  // LOLBISON_OBJECTS_STRING_OBJECT_H_
