#include <memory>
#include <string>
#include <vector>

namespace ast {

class Program;
class Version;
class Statement;
class VarDecl;
class VarAssign;
class ArrayDecl;
class ArrayNewIndex;
class ArrayAssign;
class Print;
class IfThen;
class Loop;
class LoopHead;
class IncrementLoopHead;
class DecrementLoopHead;
class LoopCondition;
class LoopWhile;
class LoopUntil;
class Break;
class ExprStatement;
class Expression;

class Program {
    Version version;
    std::vector<std::unique_ptr<Statement> > statements;
};

class Version {
    int major;
    int minor;
};

class Statement {
public:
    virtual ~Statement() {}
};

class VarDecl : public Statement {
    std::string name;
    std::unique_ptr<Expression> value;
};

class VarAssign : public Statement {
    std::string name;
    std::unique_ptr<Expression> value;
};

class ArrayDecl : public Statement {
    std::string name;
};

class ArrayNewIndex : public Statement {
    std::string array_name;
    std::unique_ptr<Expression> index;
    std::unique_ptr<Expression> value;
};

class ArrayAssign : public Statement {
    std::string array_name;
    std::unique_ptr<Expression> index;
    std::unique_ptr<Expression> value;
};

class Print : public Statement {
    std::vector<std::unique_ptr<Expression> > arguments;
};

class IfThen : public Statement {
    std::vector<std::unique_ptr<Statement> > true_statements;
    std::vector<std::unique_ptr<Statement> > false_statements;
};

class Loop : public Statement {
    std::string name;
    std::unique_ptr<LoopHead> head;
    std::vector<std::unique_ptr<Statement> > statements;
};

class LoopHead {
public:
    virtual ~LoopHead() {}
};

class IncrementLoopHead : public LoopHead {
    std::string counter;
    std::unique_ptr<LoopCondition> condition;
};

class DecrementLoopHead : public LoopHead {
    std::string counter;
    std::unique_ptr<LoopCondition> condition;
};

class LoopCondition {
public:
    virtual ~LoopCondition() {}
};

class LoopWhile : public LoopCondition {
    std::unique_ptr<Expression> condition;
};

class LoopUntil : public LoopCondition {
    std::unique_ptr<Expression> condition;
};

class Break : public Statement {};

class ExprStatement : public Statement {
    std::unique_ptr<Expression> expression;
};

class Expression {
public:
    virtual ~Expression() {}
};

// TODO expressions

}
