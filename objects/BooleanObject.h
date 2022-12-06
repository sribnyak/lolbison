#ifndef LOLBISON_OBJECTS_BOOLEAN_OBJECT_H_
#define LOLBISON_OBJECTS_BOOLEAN_OBJECT_H_

#include "objects/Object.h"

class BooleanObject : public Object {
public:
    bool value;

    explicit BooleanObject(bool value);
    ~BooleanObject() override;
};

#endif  // LOLBISON_OBJECTS_BOOLEAN_OBJECT_H_
