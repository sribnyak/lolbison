#ifndef LOLBISON_STATEMENTS_ARRAYDECL_H_
#define LOLBISON_STATEMENTS_ARRAYDECL_H_

#include "statements/Statement.h"
#include <ostream>
#include <string>

class ArrayDecl : public Statement {
    std::string name;

public:
    ArrayDecl(std::string name);
    void print(std::ostream& out, int indent) const override;
    ~ArrayDecl() override;
};

#endif  // LOLBISON_STATEMENTS_ARRAYDECL_H_
