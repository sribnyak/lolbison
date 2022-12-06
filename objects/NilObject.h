#ifndef LOLBISON_OBJECTS_NIL_OBJECT_H_
#define LOLBISON_OBJECTS_NIL_OBJECT_H_

#include "objects/Object.h"

class NilObject : public Object {
public:
    ~NilObject() override;
};

#endif  // LOLBISON_OBJECTS_NIL_OBJECT_H_
