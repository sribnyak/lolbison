#include "driver.hh"
#include <exception>
#include <iostream>

Driver::Driver()
    : trace_parsing(false),
      trace_scanning(false),
      location_debug(false),
      scanner(*this),
      parser(scanner, *this) {
    variables["IT"] = std::make_shared<NilObject>();
}

int Driver::parse(const std::string& f) {
    file = f;
    // initialize location positions
    location.initialize(&file);
    scan_begin();
    parser.set_debug_level(trace_parsing);
    int res = parser();

    result = 1;
    if (program) {
        try {
            program->exec(*this);
            result = 0;
        } catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
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
