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
    #include "ast_forward_declarations.h"
}


%define parse.trace
%define parse.error verbose

%code {
    #include "driver.hh"
    #include "location.hh"

    #include "ast.h"

    /* Redefine parser to use our function from scanner */
    static yy::parser::symbol_type yylex(Scanner &scanner) {
        return scanner.ScanToken();
    }

    void do_something(int) {} // temporary stub before AST is implemented
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

// Prints output in parsing option for debugging location terminal
%printer { yyo << $$; } <*>;

%%

%start program;

program: empty_lines "HAI" VERSION EOL statements "KTHXBYE" empty_lines {
    Program($3, std::vector<std::unique_ptr<Statement> >()).print(std::cout, 3);
    //Program($3, $5).print(std::cout, 0);
    std::cout << std::endl;
    driver.result = 0;
};

empty_lines:
    %empty
    | empty_lines EOL;

statements:
    %empty { do_something(0); }
    | statements statement { do_something(1); }
    ;

statement:
    var_decl
    | var_assign
    | array_decl
    | array_new_index
    | array_assign
    | print
    | if_then
    | loop
    | "ENUF" EOL  { do_something(2); }
    | expr EOL  { do_something(3); }
    | EOL;

var_decl:
    "I" "HAS" "A" IDENTIFIER EOL { do_something(4); }
    | "I" "HAS" "A" IDENTIFIER "ITZ" expr EOL { do_something(5); }
    ;

var_assign: IDENTIFIER "R" expr EOL { do_something(6); };

array_decl: "I" "HAS" "A" IDENTIFIER "ITZ" "A" "BUKKIT" EOL { do_something(7); };

array_new_index: IDENTIFIER "HAS" "A" "SRS" expr "ITZ" expr EOL { do_something(8); };

array_assign: IDENTIFIER "'Z" "SRS" expr "R" expr EOL { do_something(9); };

array_access: IDENTIFIER "'Z" "SRS" expr { do_something(10); };

print:
    "VISIBLE" many_args EOL  { do_something(11); }
    | "VISIBLE" many_args "!" EOL { do_something(12); }
    ;

join: "SMOOSH" many_args "MKAY" { do_something(13); };

many_args:
    expr { do_something(14); }
    | many_args expr { do_something(15); }
    | many_args "AN" expr { do_something(25); }
    ;

if_then: "O" "RLY?" EOL "YA" "RLY" EOL statements "OIC" EOL { do_something(16); }
    | "O" "RLY?" EOL "YA" "RLY" EOL statements "NO" "WAI" EOL statements "OIC" EOL { do_something(17); }
    ;

loop: "IM" "IN" "YR" IDENTIFIER loop_head EOL statements "IM" "OUTTA" "YR" IDENTIFIER EOL { do_something(40); };

loop_head:
    %empty { do_something(41); }
    | "UPPIN" "YR" IDENTIFIER loop_condition { do_something(42); }
    | "NERFIN" "YR" IDENTIFIER loop_condition { do_something(43); }
    ;

loop_condition:
    %empty { do_something(44); }
    | "TIL" expr { do_something(45); }
    | "WILE" expr { do_something(46); }
    ;

expr:
    NUMBER { do_something(18); }
    | STRING { do_something(19); }
    | boolean
    | "IT" { do_something(18); }
    | IDENTIFIER { do_something(20); }
    | logical_not
    | binary_op
    | array_access
    | join
    ;

boolean: "WIN" { do_something(21); }
    | "FAIL" { do_something(22); }
    ;

logical_not: "NOT" expr { do_something(23); };

binary_op:
    binary_op_name expr "AN" expr { do_something(24); }
    | binary_op_name expr expr { do_something(26); }
    ;

binary_op_name:
    math_func "OF" { do_something(27); }
    | "BOTH" "OF" { do_something(28); }
    | "EITHER" "OF" { do_something(29); }
    | "WON" "OF" { do_something(30); }
    | "BOTH" "SAEM" { do_something(31); }
    | "DIFFRINT" { do_something(32); }
    ;

math_func:
    "SUM" { do_something(33); }
    | "DIFF" { do_something(34); }
    | "PRODUKT" { do_something(35); }
    | "QUOSHUNT" { do_something(36); }
    | "MOD" { do_something(37); }
    | "BIGGR" { do_something(38); }
    | "SMALLR" { do_something(39); }
    ;

%%

void yy::parser::error(const location_type& l, const std::string& m) {
    std::cerr << l << ": " << m << '\n';
}
