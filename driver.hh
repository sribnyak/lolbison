#pragma once

#include <fstream>
#include <string>
#include <map>
#include <memory>
#include "objects/NilObject.h"
#include "objects/Object.h"
#include "Program.h"
#include "scanner.h"
#include "parser.hh"

class Driver {
private:
    std::ifstream stream;

public:
    std::map<std::string, std::shared_ptr<Object>> variables;
    std::map<std::string, std::map<int, std::shared_ptr<Object>>> arrays;
    int result;
    std::string file;

    bool trace_parsing;
    bool trace_scanning;
    bool location_debug;
    yy::location location;

    Scanner scanner;
    yy::parser parser;
    std::unique_ptr<Program> program;

    friend class Scanner;

    Driver();
    int parse(const std::string& f);
    void scan_begin();
    void scan_end();
};
