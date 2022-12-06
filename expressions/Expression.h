#ifndef LOLBISON_EXPRESSIONS_EXPRESSION_H_
#define LOLBISON_EXPRESSIONS_EXPRESSION_H_

#include "AstNode.h"
#include "objects/Object.h"
#include "objects/NilObject.h"
#include <memory>

class Driver;

class Expression : public AstNode {
public:
    std::shared_ptr<Object> eval(Driver& driver) { // TODO: make pure virtual
        return std::make_shared<NilObject>();
    }
    virtual ~Expression() {}
};

#endif  // LOLBISON_EXPRESSIONS_EXPRESSION_H_
