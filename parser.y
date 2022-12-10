%skeleton "lalr1.cc"
%require "3.5"

%defines
%define api.token.constructor
%define api.value.type variant
%define parse.assert

%code requires {
    #include <memory>
    #include <string>
    #include <vector>
    class Scanner;
    class Driver;
    #include "expressions/binary_ops/BinaryAnd.h"
    #include "expressions/binary_ops/BinaryDiv.h"
    #include "expressions/binary_ops/BinaryEq.h"
    #include "expressions/binary_ops/BinaryMax.h"
    #include "expressions/binary_ops/BinaryMin.h"
    #include "expressions/binary_ops/BinaryMod.h"
    #include "expressions/binary_ops/BinaryMul.h"
    #include "expressions/binary_ops/BinaryNeq.h"
    #include "expressions/binary_ops/BinaryOp.h"
    #include "expressions/binary_ops/BinaryOr.h"
    #include "expressions/binary_ops/BinarySub.h"
    #include "expressions/binary_ops/BinarySum.h"
    #include "expressions/binary_ops/BinaryXor.h"
    #include "expressions/ArrayAccess.h"
    #include "expressions/BooleanLiteral.h"
    #include "expressions/Expression.h"
    #include "expressions/Identifier.h"
    #include "expressions/It.h"
    #include "expressions/Join.h"
    #include "expressions/LogicalNot.h"
    #include "expressions/NumberLiteral.h"
    #include "expressions/StringLiteral.h"
    #include "statements/loop_components/DecrementLoopHead.h"
    #include "statements/loop_components/IncrementLoopHead.h"
    #include "statements/loop_components/LoopCondition.h"
    #include "statements/loop_components/LoopHead.h"
    #include "statements/loop_components/LoopUntil.h"
    #include "statements/loop_components/LoopWhile.h"
    #include "statements/ArrayAssign.h"
    #include "statements/ArrayDecl.h"
    #include "statements/ArrayNewIndex.h"
    #include "statements/Break.h"
    #include "statements/ExprStatement.h"
    #include "statements/IfThen.h"
    #include "statements/Loop.h"
    #include "statements/Print.h"
    #include "statements/Statement.h"
    #include "statements/VarAssign.h"
    #include "statements/VarDecl.h"
    #include "Program.h"
}


%define parse.trace
%define parse.error verbose

%code {
    #include "driver.hh"
    #include "location.hh"

    /* Redefine parser to use our function from scanner */
    static yy::parser::symbol_type yylex(Scanner &scanner) {
        return scanner.ScanToken();
    }
}

%lex-param { Scanner &scanner }

%parse-param { Scanner &scanner }
%parse-param { Driver &driver }

%locations

%define api.token.prefix {TOK_}
// token name in variable
%token
    END 0 "end of file"
    EOL     "line break"
    HAI     "HAI"
    KTHXBYE "KTHXBYE"
    ENUF    "ENUF"
    I       "I"
    HAS     "HAS"
    A       "A"
    ITZ     "ITZ"
    R       "R"
    BUKKIT  "BUKKIT"
    SRS     "SRS"
    APOSTROPHE_Z "'Z"
    EXCLAMATION  "!"
    SMOOSH  "SMOOSH"
    MKAY    "MKAY"
    VISIBLE "VISIBLE"
    AN      "AN"
    O       "O"
    RLY_QUESTION "RLY?"
    YA      "YA"
    RLY     "RLY"
    OIC     "OIC"
    NO      "NO"
    WAI     "WAI"
    IM      "IM"
    IN      "IN"
    YR      "YR"
    UPPIN   "UPPIN"
    NERFIN  "NERFIN"
    TIL     "TIL"
    WILE    "WILE"
    OUTTA   "OUTTA"
    WIN     "WIN"
    FAIL    "FAIL"
    NOT     "NOT"
    OF      "OF"
    BOTH    "BOTH"
    EITHER  "EITHER"
    WON     "WON"
    SAEM    "SAEM"
    DIFFRINT "DIFFRINT"
    SUM     "SUM"
    DIFF    "DIFF"
    PRODUKT "PRODUKT"
    QUOSHUNT "QUOSHUNT"
    MOD     "MOD"
    BIGGR   "BIGGR"
    SMALLR  "SMALLR"
;

%token <std::string> IDENTIFIER "identifier"
%token <int> NUMBER "number"
%token <std::string> VERSION "version"
%token <std::string> STRING "string"
%nterm <std::vector<std::unique_ptr<Statement>>> statements
%nterm <std::unique_ptr<Statement>> statement
%nterm <std::unique_ptr<VarDecl>> var_decl
%nterm <std::unique_ptr<VarAssign>> var_assign
%nterm <std::unique_ptr<ArrayDecl>> array_decl
%nterm <std::unique_ptr<ArrayNewIndex>> array_new_index
%nterm <std::unique_ptr<ArrayAssign>> array_assign
%nterm <std::unique_ptr<ArrayAccess>> array_access
%nterm <std::unique_ptr<Print>> print
%nterm <std::unique_ptr<Join>> join
%nterm <std::vector<std::unique_ptr<Expression>>> many_args
%nterm <std::unique_ptr<IfThen>> if_then
%nterm <std::unique_ptr<Loop>> loop
%nterm <std::unique_ptr<LoopHead>> loop_head
%nterm <std::unique_ptr<LoopCondition>> loop_condition
%nterm <std::unique_ptr<Expression>> expr
%nterm <std::unique_ptr<BooleanLiteral>> boolean
%nterm <std::unique_ptr<LogicalNot>> logical_not
%nterm <std::unique_ptr<BinaryOp>> binary_op
%nterm <std::unique_ptr<BinaryOp>> binary_op_name
%nterm <std::unique_ptr<BinaryOp>> math_func

%%

%start program;

program: empty_lines "HAI" VERSION EOL statements "KTHXBYE" empty_lines {
    driver.program = std::make_unique<Program>($3, std::move($5));
};

empty_lines:
    %empty
    | empty_lines EOL;

statements:
    %empty {}
    | statements statement {
        $$ = std::move($1);
        if ($2) { $$.push_back(std::move($2)); }
    };

statement:
    var_decl { $$ = std::move($1); }
    | var_assign { $$ = std::move($1); }
    | array_decl { $$ = std::move($1); }
    | array_new_index { $$ = std::move($1); }
    | array_assign { $$ = std::move($1); }
    | print { $$ = std::move($1); }
    | if_then { $$ = std::move($1); }
    | loop { $$ = std::move($1); }
    | "ENUF" EOL { $$ = std::make_unique<Break>(); }
    | expr EOL { $$ = std::make_unique<ExprStatement>(std::move($1)); }
    | EOL {}
    ;

var_decl:
    "I" "HAS" "A" IDENTIFIER EOL { $$ = std::make_unique<VarDecl>($4); }
    | "I" "HAS" "A" IDENTIFIER "ITZ" expr EOL { $$ = std::make_unique<VarDecl>($4, std::move($6)); }
    ;

var_assign: IDENTIFIER "R" expr EOL { $$ = std::make_unique<VarAssign>($1, std::move($3)); };

array_decl: "I" "HAS" "A" IDENTIFIER "ITZ" "A" "BUKKIT" EOL { $$ = std::make_unique<ArrayDecl>($4); };

array_new_index: IDENTIFIER "HAS" "A" "SRS" expr "ITZ" expr EOL { $$ = std::make_unique<ArrayNewIndex>($1, std::move($5), std::move($7)); };

array_assign: IDENTIFIER "'Z" "SRS" expr "R" expr EOL { $$ = std::make_unique<ArrayAssign>($1, std::move($4), std::move($6)); };

array_access: IDENTIFIER "'Z" "SRS" expr { $$ = std::make_unique<ArrayAccess>($1, std::move($4)); };

print:
    "VISIBLE" many_args EOL { $$ = std::make_unique<Print>(std::move($2), false); }
    | "VISIBLE" many_args "!" EOL { $$ = std::make_unique<Print>(std::move($2), true); }
    ;

join: "SMOOSH" many_args "MKAY" { $$ = std::make_unique<Join>(std::move($2)); }

many_args:
    expr { $$ = std::vector<std::unique_ptr<Expression>>(); $$.push_back(std::move($1)); }
    | many_args expr { $$ = std::move($1); $$.push_back(std::move($2)); }
    | many_args "AN" expr { $$ = std::move($1); $$.push_back(std::move($3)); }
    ;

if_then: "O" "RLY?" EOL "YA" "RLY" EOL statements "OIC" EOL {
        $$ = std::make_unique<IfThen>(std::move($7));
    }
    | "O" "RLY?" EOL "YA" "RLY" EOL statements "NO" "WAI" EOL statements "OIC" EOL {
        $$ = std::make_unique<IfThen>(std::move($7), std::move($11));
    }
    ;

loop: "IM" "IN" "YR" IDENTIFIER loop_head EOL statements "IM" "OUTTA" "YR" IDENTIFIER EOL {
        if ($4 != $11) {
            yy::parser::error(driver.location, "loop name mismatch: " + $4 + " != " + $11);
            YYABORT;
        }
        $$ = std::make_unique<Loop>($4, std::move($5), std::move($7));
    };

loop_head:
    %empty {}
    | "UPPIN" "YR" IDENTIFIER loop_condition { $$ = std::make_unique<IncrementLoopHead>($3, std::move($4)); }
    | "NERFIN" "YR" IDENTIFIER loop_condition { $$ = std::make_unique<DecrementLoopHead>($3, std::move($4)); }
    ;

loop_condition:
    %empty {}
    | "TIL" expr { $$ = std::make_unique<LoopUntil>(std::move($2)); }
    | "WILE" expr { $$ = std::make_unique<LoopWhile>(std::move($2)); }
    ;

expr:
    NUMBER { $$ = std::make_unique<NumberLiteral>($1); }
    | STRING { $$ = std::make_unique<StringLiteral>($1); }
    | boolean { $$ = std::move($1); }
    | "IT" { $$ = std::make_unique<It>(); }
    | IDENTIFIER { $$ = std::make_unique<Identifier>($1); }
    | logical_not { $$ = std::move($1); }
    | binary_op { $$ = std::move($1); }
    | array_access { $$ = std::move($1); }
    | join { $$ = std::move($1); }
    ;

boolean: "WIN" { $$ = std::make_unique<BooleanLiteral>(true); }
    | "FAIL" { $$ = std::make_unique<BooleanLiteral>(false); }
    ;

logical_not: "NOT" expr { $$ = std::make_unique<LogicalNot>(std::move($2)); };

binary_op:
    binary_op_name expr "AN" expr { $$ = std::move($1); $$->init_args(std::move($2), std::move($4)); }
    | binary_op_name expr expr { $$ = std::move($1); $$->init_args(std::move($2), std::move($3)); }
    ;

binary_op_name:
    math_func "OF" { $$ = std::move($1); }
    | "BOTH" "OF" { $$ = std::make_unique<BinaryAnd>(); }
    | "EITHER" "OF" { $$ = std::make_unique<BinaryOr>(); }
    | "WON" "OF" { $$ = std::make_unique<BinaryXor>(); }
    | "BOTH" "SAEM" { $$ = std::make_unique<BinaryEq>(); }
    | "DIFFRINT" { $$ = std::make_unique<BinaryNeq>(); }
    ;

math_func:
    "SUM" { $$ = std::make_unique<BinarySum>(); }
    | "DIFF" { $$ = std::make_unique<BinarySub>(); }
    | "PRODUKT" { $$ = std::make_unique<BinaryMul>(); }
    | "QUOSHUNT" { $$ = std::make_unique<BinaryDiv>(); }
    | "MOD" { $$ = std::make_unique<BinaryMod>(); }
    | "BIGGR" { $$ = std::make_unique<BinaryMax>(); }
    | "SMALLR" { $$ = std::make_unique<BinaryMin>(); }
    ;

%%

void yy::parser::error(const location_type& l, const std::string& m) {
    std::cerr << l << ": " << m << '\n';
}
