%skeleton "lalr1.cc"
%require "3.5"

%defines
%define api.token.constructor
%define api.value.type variant
%define parse.assert

%code requires {
    #include <string>
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

%start unit;
unit: tokens {
    std::cout << "\"end of file\"" << std::endl;
    driver.result = 0;
};

tokens:
    %empty {}
    | tokens token {};

token:
    "line break" { std::cout << "\"line break\"" << std::endl; }
    | "HAI" { std::cout << "\"HAI\"" << std::endl; }
    | "KTHXBYE" { std::cout << "\"KTHXBYE\"" << std::endl; }
    | "ENUF" { std::cout << "\"ENUF\"" << std::endl; }
    | "I" { std::cout << "\"I\"" << std::endl; }
    | "HAS" { std::cout << "\"HAS\"" << std::endl; }
    | "A" { std::cout << "\"A\"" << std::endl; }
    | "ITZ" { std::cout << "\"ITZ\"" << std::endl; }
    | "R" { std::cout << "\"R\"" << std::endl; }
    | "BUKKIT" { std::cout << "\"BUKKIT\"" << std::endl; }
    | "SRS" { std::cout << "\"SRS\"" << std::endl; }
    | "'Z" { std::cout << "\"'Z\"" << std::endl; }
    | "!" { std::cout << "\"!\"" << std::endl; }
    | "SMOOSH" { std::cout << "\"SMOOSH\"" << std::endl; }
    | "MKAY" { std::cout << "\"MKAY\"" << std::endl; }
    | "VISIBLE" {std::cout << "\"VISIBLE\"" << std::endl; }
    | "AN" { std::cout << "\"AN\"" << std::endl; }
    | "O" { std::cout << "\"O\"" << std::endl; }
    | "RLY?" { std::cout << "\"RLY?\"" << std::endl; }
    | "YA" { std::cout << "\"YA\"" << std::endl; }
    | "RLY" { std::cout << "\"RLY\"" << std::endl; }
    | "OIC" { std::cout << "\"OIC\"" << std::endl; }
    | "NO" { std::cout << "\"NO\"" << std::endl; }
    | "WAI" { std::cout << "\"WAI\"" << std::endl; }
    | "IM" { std::cout << "\"IM\"" << std::endl; }
    | "IN" { std::cout << "\"IN\"" << std::endl; }
    | "YR" { std::cout << "\"YR\"" << std::endl; }
    | "UPPIN" { std::cout << "\"UPPIN\"" << std::endl; }
    | "NERFIN" { std::cout << "\"NERFIN\"" << std::endl; }
    | "TIL" { std::cout << "\"TIL\"" << std::endl; }
    | "WILE" { std::cout << "\"WILE\"" << std::endl; }
    | "OUTTA" { std::cout << "\"OUTTA\"" << std::endl; }
    | "WIN" { std::cout << "\"WIN\"" << std::endl; }
    | "FAIL" { std::cout << "\"FAIL\"" << std::endl; }
    | "NOT" { std::cout << "\"NOT\"" << std::endl; }
    | "OF" { std::cout << "\"OF\"" << std::endl; }
    | "BOTH" { std::cout << "\"BOTH\"" << std::endl; }
    | "EITHER" { std::cout << "\"EITHER\"" << std::endl; }
    | "WON" { std::cout << "\"WON\"" << std::endl; }
    | "SAEM" { std::cout << "\"SAEM\"" << std::endl; }
    | "DIFFRINT" { std::cout << "\"DIFFRINT\"" << std::endl; }
    | "SUM" { std::cout << "\"SUM\"" << std::endl; }
    | "DIFF" { std::cout << "\"DIFF\"" << std::endl; }
    | "PRODUKT" { std::cout << "\"PRODUKT\"" << std::endl; }
    | "QUOSHUNT" { std::cout << "\"QUOSHUNT\"" << std::endl; }
    | "MOD" { std::cout << "\"MOD\"" << std::endl; }
    | "BIGGR" { std::cout << "\"BIGGR\"" << std::endl; }
    | "SMALLR" { std::cout << "\"SMALLR\"" << std::endl; }
    | "identifier" { std::cout << "\"identifier " << $1 << "\"" << std::endl; }
    | "number" { std::cout << "\"number " << $1 << "\"" << std::endl; }
    | "version" { std::cout << "\"version " << $1 << "\"" << std::endl; }
    | "string" { std::cout << "\"string " << $1 << "\"" << std::endl; }
    ;

%%

void yy::parser::error(const location_type& l, const std::string& m) {
    std::cerr << l << ": " << m << '\n';
}
