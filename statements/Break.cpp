#include "statements/Break.h"

void Break::print(std::ostream& out, int indent) const {
    out << "Break()";
}

Break::~Break() = default;
