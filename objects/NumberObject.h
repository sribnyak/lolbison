#ifndef LOLBISON_OBJECTS_NUMBER_OBJECT_H_
#define LOLBISON_OBJECTS_NUMBER_OBJECT_H_

#include "objects/Object.h"

class NumberObject : public Object {
public:
    int value;

    explicit NumberObject(int value);
    ~NumberObject() override;
};

#endif  // LOLBISON_OBJECTS_NUMBER_OBJECT_H_
