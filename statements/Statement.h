#ifndef LOLBISON_STATEMENTS_STATEMENT_H_
#define LOLBISON_STATEMENTS_STATEMENT_H_

#include "AstNode.h"

class Driver;

class Statement : public AstNode {
public:
    virtual void exec(Driver& driver) = 0;
    virtual ~Statement() {}
};

#endif  // LOLBISON_STATEMENTS_STATEMENT_H_
