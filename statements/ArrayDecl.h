#ifndef LOLBISON_STATEMENTS_ARRAY_DECL_H_
#define LOLBISON_STATEMENTS_ARRAY_DECL_H_

#include "statements/Statement.h"
#include <ostream>
#include <string>

class Driver;

class ArrayDecl : public Statement {
    std::string name;

public:
    ArrayDecl(const std::string& name);
    void print(std::ostream& out, int indent) const override;
    void exec(Driver& driver) override;
    ~ArrayDecl() override;
};

#endif  // LOLBISON_STATEMENTS_ARRAY_DECL_H_
