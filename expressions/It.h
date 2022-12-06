#ifndef LOLBISON_EXPRESSIONS_IT_H_
#define LOLBISON_EXPRESSIONS_IT_H_

#include "expressions/Expression.h"
#include <ostream>
#include <string>

class It : public Expression {
public:
    void print(std::ostream& out, int indent) const override;
    ~It() override;
};

#endif  // LOLBISON_EXPRESSIONS_IT_H_
