#ifndef LOLBISON_PROGRAM_H_
#define LOLBISON_PROGRAM_H_

#include "AstNode.h"
#include "statements/Statement.h"
#include <memory>
#include <string>
#include <vector>

class Program : public AstNode {
    std::string version;
    std::vector<std::unique_ptr<Statement> > statements;
};

#endif // LOLBISON_PROGRAM_H_
