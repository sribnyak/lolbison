%{
    #include <cerrno>
    #include <climits>
    #include <cstdlib>
    #include <cstring> // strerror
    #include <string>
    #include <iostream>
    #include "driver.hh"
    #include "parser.hh"
%}

%option noyywrap nounput noinput batch debug

%option c++
%option yyclass="Scanner"

%{
  // Code definitions at the end of scanner.cpp

  // A number symbol corresponding to the value in S.
  yy::parser::symbol_type make_NUMBER(
    const std::string &s,
    const yy::parser::location_type& loc
  );

  void Scanner::UpdateLocation() {
    if (driver.location_debug) {
        std::cerr << "Action called " << driver.location << std::endl;
    }
    driver.location.columns(yyleng);
  }
%}

id    [a-zA-Z][a-zA-Z_0-9]*
int   [0-9]+
blank [ \t\r]

%{
  // Code run each time a pattern is matched.
  #define YY_USER_ACTION UpdateLocation();
%}

%%


%{
  // A handy shortcut to the location held by the driver.
  yy::location& loc = driver.location;
  if (driver.location_debug) {
  // Code run each time yylex is called.
    std::cerr << "BEFORE " << loc << std::endl;
  }
  // loc.step();
  if (driver.location_debug) {
    std::cerr << "AFTER " <<  loc << std::endl;
  }
%}

{blank}+ {
    if (driver.location_debug) {
        std::cerr << "Blank matched" << std::endl;
    }
    // loc.step();
}
\n+     {
    if (driver.location_debug) {
        std::cerr << "EOL called" << std::endl;
    }
    loc.lines(yyleng);
    loc.step();
    return yy::parser::make_EOL(loc);
}
HAI     return yy::parser::make_HAI(loc);
KTHXBYE return yy::parser::make_KTHXBYE(loc);
ENUF    return yy::parser::make_ENUF(loc);
I       return yy::parser::make_I(loc);
HAS     return yy::parser::make_HAS(loc);
A       return yy::parser::make_A(loc);
ITZ     return yy::parser::make_ITZ(loc);
R       return yy::parser::make_R(loc);
BUKKIT  return yy::parser::make_BUKKIT(loc);
SRS     return yy::parser::make_SRS(loc);
'Z      return yy::parser::make_APOSTROPHE_Z(loc);
!       return yy::parser::make_EXCLAMATION(loc);
SMOOSH  return yy::parser::make_SMOOSH(loc);
MKAY    return yy::parser::make_MKAY(loc);
VISIBLE return yy::parser::make_VISIBLE(loc);
AN      return yy::parser::make_AN(loc);
O       return yy::parser::make_O(loc);
"RLY?"  return yy::parser::make_RLY_QUESTION(loc);
YA      return yy::parser::make_YA(loc);
RLY     return yy::parser::make_RLY(loc);
OIC     return yy::parser::make_OIC(loc);
NO      return yy::parser::make_NO(loc);
WAI     return yy::parser::make_WAI(loc);
IM      return yy::parser::make_IM(loc);
IN      return yy::parser::make_IN(loc);
YR      return yy::parser::make_YR(loc);
UPPIN   return yy::parser::make_UPPIN(loc);
NERFIN  return yy::parser::make_NERFIN(loc);
TIL     return yy::parser::make_TIL(loc);
WILE    return yy::parser::make_WILE(loc);
OUTTA   return yy::parser::make_OUTTA(loc);
WIN     return yy::parser::make_WIN(loc);
FAIL    return yy::parser::make_FAIL(loc);
NOT     return yy::parser::make_NOT(loc);
OF      return yy::parser::make_OF(loc);
BOTH    return yy::parser::make_BOTH(loc);
EITHER  return yy::parser::make_EITHER(loc);
WON     return yy::parser::make_WON(loc);
SAEM    return yy::parser::make_SAEM(loc);
DIFFRINT  return yy::parser::make_DIFFRINT(loc);
SUM     return yy::parser::make_SUM(loc);
DIFF    return yy::parser::make_DIFF(loc);
PRODUKT return yy::parser::make_PRODUKT(loc);
QUOSHUNT  return yy::parser::make_QUOSHUNT(loc);
MOD     return yy::parser::make_MOD(loc);
BIGGR   return yy::parser::make_BIGGR(loc);
SMALLR  return yy::parser::make_SMALLR(loc);
\"\"    return yy::parser::make_STR("", loc); // TODO: support strings
{id}    return yy::parser::make_IDENTIFIER(yytext, loc);
{int}   return make_NUMBER(yytext, loc);
.       throw yy::parser::syntax_error(loc, std::string("invalid character: ") + yytext);
<<EOF>> return yy::parser::make_END(loc);

%%

yy::parser::symbol_type make_NUMBER(
  const std::string &s,
  const yy::parser::location_type& loc
) {
  errno = 0;
  long n = strtol(s.c_str(), NULL, 10);
  if (! (INT_MIN <= n && n <= INT_MAX && errno != ERANGE))
    throw yy::parser::syntax_error(loc, "integer is out of range: " + s);
  return yy::parser::make_NUMBER((int) n, loc);
}
