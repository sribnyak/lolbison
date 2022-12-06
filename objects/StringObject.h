#ifndef LOLBISON_OBJECTS_STRING_OBJECT_H_
#define LOLBISON_OBJECTS_STRING_OBJECT_H_

#include "objects/Object.h"
#include <string>

class StringObject : public Object {
public:
    std::string value;

    explicit StringObject(const std::string& value);
    ~StringObject() override;
};

#endif  // LOLBISON_OBJECTS_STRING_OBJECT_H_
