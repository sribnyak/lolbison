#ifndef LOLBISON_ASTNODE_H_
#define LOLBISON_ASTNODE_H_

#include <ostream>

const int INDENT_WIDTH = 4;

class AstNode {
public:
    virtual void print(std::ostream& out, int indent) const = 0;
};

#endif // LOLBISON_ASTNODE_H_
