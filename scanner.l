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

%x str

id    [a-zA-Z][a-zA-Z_0-9]*
int   [0-9]+
blank [ \t\r]

%{
  // Code run each time a pattern is matched.
  #define YY_USER_ACTION UpdateLocation();
%}

%%

  std::string parsed_str;

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

<INITIAL>{blank}+ {
    if (driver.location_debug) {
        std::cerr << "Blank matched" << std::endl;
    }
    // loc.step();
}
<INITIAL>\n+     {
    if (driver.location_debug) {
        std::cerr << "EOL called" << std::endl;
    }
    loc.lines(yyleng);
    loc.step();
    return yy::parser::make_EOL(loc);
}
<INITIAL>HAI      return yy::parser::make_HAI(loc);
<INITIAL>KTHXBYE  return yy::parser::make_KTHXBYE(loc);
<INITIAL>ENUF     return yy::parser::make_ENUF(loc);
<INITIAL>I        return yy::parser::make_I(loc);
<INITIAL>HAS      return yy::parser::make_HAS(loc);
<INITIAL>A        return yy::parser::make_A(loc);
<INITIAL>ITZ      return yy::parser::make_ITZ(loc);
<INITIAL>R        return yy::parser::make_R(loc);
<INITIAL>BUKKIT   return yy::parser::make_BUKKIT(loc);
<INITIAL>SRS      return yy::parser::make_SRS(loc);
<INITIAL>'Z       return yy::parser::make_APOSTROPHE_Z(loc);
<INITIAL>!        return yy::parser::make_EXCLAMATION(loc);
<INITIAL>SMOOSH   return yy::parser::make_SMOOSH(loc);
<INITIAL>MKAY     return yy::parser::make_MKAY(loc);
<INITIAL>VISIBLE  return yy::parser::make_VISIBLE(loc);
<INITIAL>AN       return yy::parser::make_AN(loc);
<INITIAL>O        return yy::parser::make_O(loc);
<INITIAL>"RLY?"   return yy::parser::make_RLY_QUESTION(loc);
<INITIAL>YA       return yy::parser::make_YA(loc);
<INITIAL>RLY      return yy::parser::make_RLY(loc);
<INITIAL>OIC      return yy::parser::make_OIC(loc);
<INITIAL>NO       return yy::parser::make_NO(loc);
<INITIAL>WAI      return yy::parser::make_WAI(loc);
<INITIAL>IM       return yy::parser::make_IM(loc);
<INITIAL>IN       return yy::parser::make_IN(loc);
<INITIAL>YR       return yy::parser::make_YR(loc);
<INITIAL>UPPIN    return yy::parser::make_UPPIN(loc);
<INITIAL>NERFIN   return yy::parser::make_NERFIN(loc);
<INITIAL>TIL      return yy::parser::make_TIL(loc);
<INITIAL>WILE     return yy::parser::make_WILE(loc);
<INITIAL>OUTTA    return yy::parser::make_OUTTA(loc);
<INITIAL>WIN      return yy::parser::make_WIN(loc);
<INITIAL>FAIL     return yy::parser::make_FAIL(loc);
<INITIAL>NOT      return yy::parser::make_NOT(loc);
<INITIAL>OF       return yy::parser::make_OF(loc);
<INITIAL>BOTH     return yy::parser::make_BOTH(loc);
<INITIAL>EITHER   return yy::parser::make_EITHER(loc);
<INITIAL>WON      return yy::parser::make_WON(loc);
<INITIAL>SAEM     return yy::parser::make_SAEM(loc);
<INITIAL>DIFFRINT return yy::parser::make_DIFFRINT(loc);
<INITIAL>SUM      return yy::parser::make_SUM(loc);
<INITIAL>DIFF     return yy::parser::make_DIFF(loc);
<INITIAL>PRODUKT  return yy::parser::make_PRODUKT(loc);
<INITIAL>QUOSHUNT return yy::parser::make_QUOSHUNT(loc);
<INITIAL>MOD      return yy::parser::make_MOD(loc);
<INITIAL>BIGGR    return yy::parser::make_BIGGR(loc);
<INITIAL>SMALLR   return yy::parser::make_SMALLR(loc);
<INITIAL>\"       parsed_str.clear(); BEGIN(str);
<INITIAL>{id}     return yy::parser::make_IDENTIFIER(yytext, loc);
<INITIAL>-?{int}  return make_NUMBER(yytext, loc);
<INITIAL>{int}\.{int} return yy::parser::make_VERSION(yytext, loc);
<INITIAL>.        throw yy::parser::syntax_error(loc, std::string("invalid character: ") + yytext);
<INITIAL><<EOF>>  return yy::parser::make_END(loc);

<str>:\)  parsed_str += '\n';
<str>:>   parsed_str += '\t';
<str>:o   parsed_str += '\a';  // beep
<str>:\"  parsed_str += '"';
<str>::   parsed_str += ':';
<str>:.   throw yy::parser::syntax_error(loc, std::string("unknown escape sequence: ") + yytext);
<str>:    throw yy::parser::syntax_error(loc, "unterminated string constant");
<str>\n   throw yy::parser::syntax_error(loc, "unterminated string constant");
<str>\"   BEGIN(INITIAL); return yy::parser::make_STR(parsed_str, loc);
<str>[^:\n\"]+  parsed_str += yytext;
<str><<EOF>>    throw yy::parser::syntax_error(loc, "unterminated string constant");

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
