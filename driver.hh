#pragma once

#include <fstream>
#include <string>
#include "Program.h"
#include "scanner.h"
#include "parser.hh"

class Driver {
private:
    std::ifstream stream;

public:
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
