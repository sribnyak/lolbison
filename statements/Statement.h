#ifndef LOLBISON_STATEMENTS_STATEMENT_H_
#define LOLBISON_STATEMENTS_STATEMENT_H_

#include "AstNode.h"

class Statement : public AstNode {
public:
    virtual ~Statement() {}
};

#endif  // LOLBISON_STATEMENTS_STATEMENT_H_
