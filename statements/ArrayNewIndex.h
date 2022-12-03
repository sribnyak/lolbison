#ifndef LOLBISON_STATEMENTS_ARRAYNEWINDEX_H_
#define LOLBISON_STATEMENTS_ARRAYNEWINDEX_H_

#include "statements/Statement.h"
#include "expressions/Expression.h"
#include <memory>
#include <ostream>
#include <string>

class ArrayNewIndex : public Statement {
    std::string array_name;
    std::unique_ptr<Expression> index;
    std::unique_ptr<Expression> value;

public:
    ArrayNewIndex(std::string array_name, std::unique_ptr<Expression> index,
                  std::unique_ptr<Expression> value);
    void print(std::ostream& out, int indent) const override;
    ~ArrayNewIndex() override;
};

#endif  // LOLBISON_STATEMENTS_ARRAYNEWINDEX_H_
