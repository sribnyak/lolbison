#ifndef LOLBISON_PROGRAM_H_
#define LOLBISON_PROGRAM_H_

#include "AstNode.h"
#include <iosfwd>
#include <memory>
#include <string>
#include <vector>

class Statement;
class Driver;

class Program : public AstNode {
    std::string version;
    std::vector<std::unique_ptr<Statement>> statements;

public:
    Program(const std::string& version,
            std::vector<std::unique_ptr<Statement>> statements);
    void print(std::ostream& out, int indent) const override;
    void exec(Driver& driver);
};

#endif  // LOLBISON_PROGRAM_H_
