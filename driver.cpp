#include "driver.hh"
#include "objects/NilObject.h"
#include "Program.h"
#include <exception>
#include <iostream>

Driver::Driver()
    : parse_only(false),
      scanner(*this),
      parser(scanner, *this) {
    variables["IT"] = std::make_shared<const NilObject>();
}

int Driver::parse(const std::string& f) {
    file = f;
    scan_begin();
    int res = parser();
    scan_end();
    return res;
}

int Driver::evaluate() {
    if (!program) return 1;
    try {
        program->exec(*this);
        return 0;
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
}

int Driver::execute(const std::string& f) {
    int res = parse(f);
    if (res != 0) {
        return res;
    }
    if (parse_only) {
        program->print(std::cout, 0);
        std::cout << std::endl;
        return 0;
    }
    return evaluate();
}

void Driver::scan_begin() {
    if (!(file.empty() || file == "-")) {
        stream.open(file);

        // Restart scanner resetting buffer!
        scanner.yyrestart(&stream);
    }
}

void Driver::scan_end() {
    stream.close();
}
