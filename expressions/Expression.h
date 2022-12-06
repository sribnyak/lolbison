#ifndef LOLBISON_EXPRESSIONS_EXPRESSION_H_
#define LOLBISON_EXPRESSIONS_EXPRESSION_H_

#include "AstNode.h"

class Expression : public AstNode {
public:
    virtual ~Expression() {}
};

#endif  // LOLBISON_EXPRESSIONS_EXPRESSION_H_
