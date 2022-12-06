#include "statements/Break.h"

void Break::print(std::ostream& out, int indent) const {
    out << "Break()";
}

void Break::exec(Driver& driver) {
    // TODO: implement
}

Break::~Break() = default;
