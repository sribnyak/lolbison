#ifndef LOLBISON_STATEMENTS_ARRAY_NEW_INDEX_H_
#define LOLBISON_STATEMENTS_ARRAY_NEW_INDEX_H_

#include "statements/Statement.h"
#include "expressions/Expression.h"
#include <memory>
#include <ostream>
#include <string>

class Driver;

class ArrayNewIndex : public Statement {
    std::string array_name;
    std::unique_ptr<Expression> index;
    std::unique_ptr<Expression> value;

public:
    ArrayNewIndex(const std::string& array_name, std::unique_ptr<Expression> index,
                  std::unique_ptr<Expression> value);
    void print(std::ostream& out, int indent) const override;
    void exec(Driver& driver) override;
    ~ArrayNewIndex() override;
};

#endif  // LOLBISON_STATEMENTS_ARRAY_NEW_INDEX_H_
