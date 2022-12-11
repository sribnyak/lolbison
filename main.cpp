#include <string>
#include "driver.hh"

int main(int argc, char** argv) {
    Driver driver;
    std::string file;

    for (int i = 1; i < argc; ++i) {
        if (argv[i] == std::string("-p")) {
            driver.parse_only = true;
        } else {
            file = argv[i];
        }
    }
    return driver.execute(file);
}
