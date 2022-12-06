#include "driver.hh"
#include <iostream>

Driver::Driver()
    : trace_parsing(false),
      trace_scanning(false),
      location_debug(false),
      scanner(*this),
      parser(scanner, *this) {}

int Driver::parse(const std::string& f) {
    file = f;
    // initialize location positions
    location.initialize(&file);
    scan_begin();
    parser.set_debug_level(trace_parsing);
    int res = parser();

    if (program) {
        program->print(std::cout, 0);
        std::cout << std::endl;
        result = 0;
    } else {
        result = 1;
    }

    scan_end();
    return res;
}

void Driver::scan_begin() {
    scanner.set_debug(trace_scanning);
    if (!(file.empty() || file == "-")) {
        stream.open(file);
        std::cerr << "File name is " << file << std::endl;

        // Restart scanner resetting buffer!
        scanner.yyrestart(&stream);
    }
}

void Driver::scan_end() {
    stream.close();
}
