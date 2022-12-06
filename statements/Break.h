#ifndef LOLBISON_STATEMENTS_BREAK_H_
#define LOLBISON_STATEMENTS_BREAK_H_
 
#include "statements/Statement.h"
#include <ostream>

class Break : public Statement {
public:
    void print(std::ostream& out, int indent) const override;
    ~Break() override;
};

#endif  // LOLBISON_STATEMENTS_BREAK_H_
