#ifndef LOLBISON_EXPRESSIONS_EXPRESSION_H_
#define LOLBISON_EXPRESSIONS_EXPRESSION_H_

#include "AstNode.h"
#include <memory>

class Object;
class Driver;

class Expression : public AstNode {
public:
    virtual std::shared_ptr<const Object> eval(Driver& driver) = 0;
    virtual ~Expression() {}
};

#endif  // LOLBISON_EXPRESSIONS_EXPRESSION_H_
