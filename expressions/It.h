#ifndef LOLBISON_EXPRESSIONS_IT_H_
#define LOLBISON_EXPRESSIONS_IT_H_

#include "expressions/Expression.h"
#include <ostream>

class Object;
class Driver;

class It : public Expression {
public:
    void print(std::ostream& out, int indent) const override;
    std::shared_ptr<const Object> eval(Driver& driver) override;
    ~It() override;
};

#endif  // LOLBISON_EXPRESSIONS_IT_H_
