#pragma once

#include <fstream>
#include <string>
#include <map>
#include <memory>
#include "objects/Object.h"
#include "Program.h"
#include "scanner.h"
#include "parser.hh"

class Driver {
private:
    std::ifstream stream;

public:
    std::map<std::string, std::shared_ptr<const Object>> variables;
    std::map<std::string, std::map<int, std::shared_ptr<const Object>>> arrays;
    std::string file;

    bool parse_only;
    yy::location location;

    Scanner scanner;
    yy::parser parser;
    std::unique_ptr<Program> program;

    friend class Scanner;

    Driver();
    int parse(const std::string& f);
    int evaluate();
    int execute(const std::string& f);
    void scan_begin();
    void scan_end();
};
