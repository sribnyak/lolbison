#ifndef LOLBISON_PROGRAM_H_
#define LOLBISON_PROGRAM_H_

#include "AstNode.h"
#include "statements/Statement.h"
#include <memory>
#include <ostream>
#include <string>
#include <vector>

class Program : public AstNode {
    std::string version;
    std::vector<std::unique_ptr<Statement>> statements;

public:
    Program(std::string version,
            std::vector<std::unique_ptr<Statement>> statements);
    void print(std::ostream& out, int indent) const override;
};

#endif  // LOLBISON_PROGRAM_H_
