#include <memory>
#include <string>
#include <vector>
#include <ostream>

class AstNode;
class Program;
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
class NumberLiteral;
class StringLiteral;
class BooleanLiteral;
class It;
class Identifier;
class LogicalNot;
class BinaryOp;
class ArrayAccess;
class Join;
class BinarySum;
class BinarySub;
class BinaryMul;
class BinaryDiv;
class BinaryMod;
class BinaryMax;
class BinaryMin;
class BinaryEq;
class BinaryNeq;
class BinaryAnd;
class BinaryOr;
class BinaryXor;

class AstNode {
public:
    virtual ~AstNode() {}
    virtual void print(std::ostream& out, int indent) const = 0;
};

class Program : public AstNode {
    std::string version;
    std::vector<std::unique_ptr<Statement> > statements;
};

class Statement : public AstNode {
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
    bool suppress_newline;
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

class LoopHead : public AstNode {
    std::string counter;
    std::unique_ptr<LoopCondition> condition;

public:
    virtual ~LoopHead() {}
};

class IncrementLoopHead : public LoopHead {};

class DecrementLoopHead : public LoopHead {};

class LoopCondition : public AstNode {
    std::unique_ptr<Expression> condition;

public:
    virtual ~LoopCondition() {}
};

class LoopWhile : public LoopCondition {};

class LoopUntil : public LoopCondition {};

class Break : public Statement {};

class ExprStatement : public Statement {
    std::unique_ptr<Expression> expression;
};

class Expression : public AstNode {
public:
    virtual ~Expression() {}
};

class NumberLiteral : public Expression {
    int value;
};

class StringLiteral : public Expression {
    std::string value;
};

class BooleanLiteral : public Expression {
    bool value;
};

class It : public Expression {};

class Identifier : public Expression {
    std::string name;
};

class LogicalNot : public Expression {
    std::unique_ptr<Expression> operand;
};

class BinaryOp : public Expression {
    std::unique_ptr<Expression> lhs;
    std::unique_ptr<Expression> rhs;

public:
    virtual ~BinaryOp() {}
};

class ArrayAccess : public Expression {
    std::string array_name;
    std::unique_ptr<Expression> index;
};

class Join : public Expression {
    std::vector<std::unique_ptr<Expression> > arguments;
};

class BinarySum : public BinaryOp {};
class BinarySub : public BinaryOp {};
class BinaryMul : public BinaryOp {};
class BinaryDiv : public BinaryOp {};
class BinaryMod : public BinaryOp {};
class BinaryMax : public BinaryOp {};
class BinaryMin : public BinaryOp {};
class BinaryEq : public BinaryOp {};
class BinaryNeq : public BinaryOp {};
class BinaryAnd : public BinaryOp {};
class BinaryOr : public BinaryOp {};
class BinaryXor : public BinaryOp {};
