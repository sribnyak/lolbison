#include "statements/Break.h"
#include "BreakIndicator.h"
#include <ostream>

void Break::print(std::ostream& out, int indent) const {
    out << "Break()";
}

void Break::exec(Driver& driver) {
    throw BreakIndicator();
}

Break::~Break() = default;
