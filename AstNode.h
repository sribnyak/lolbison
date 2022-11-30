#ifndef LOLBISON_ASTNODE_H_
#define LOLBISON_ASTNODE_H_

#include <ostream>

class AstNode {
public:
    virtual ~AstNode() {}
    virtual void print(std::ostream& out, int indent) const = 0;
};

#endif // LOLBISON_ASTNODE_H_
