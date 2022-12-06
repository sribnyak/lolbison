#ifndef LOLBISON_AST_NODE_H_
#define LOLBISON_AST_NODE_H_

#include <ostream>

const int INDENT_WIDTH = 4;

class AstNode {
public:
    virtual void print(std::ostream& out, int indent) const = 0;
};

#endif  // LOLBISON_AST_NODE_H_
