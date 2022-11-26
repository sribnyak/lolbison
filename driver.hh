#pragma once

#include <map>
#include <string>
#include <fstream>
#include "scanner.h"
#include "parser.hh"

class Driver {
public:
    Driver();
    int result;
    int parse(const std::string& f);
    std::string file;

    void scan_begin();
    void scan_end();

    bool trace_parsing;
    bool trace_scanning;
    bool location_debug;
    yy::location location;

    friend class Scanner;
    Scanner scanner;
    yy::parser parser;

private:
    std::ifstream stream;
};
