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
    const std::string& s
  );
%}

%x str

id    [a-zA-Z][a-zA-Z_0-9]*
int   [0-9]+
blank [ \t\r]


%%

  std::string parsed_string;


<INITIAL>{blank}+ {}
<INITIAL>\n+     {
    return yy::parser::make_EOL();
}
<INITIAL>HAI      return yy::parser::make_HAI();
<INITIAL>KTHXBYE  return yy::parser::make_KTHXBYE();
<INITIAL>ENUF     return yy::parser::make_ENUF();
<INITIAL>I        return yy::parser::make_I();
<INITIAL>HAS      return yy::parser::make_HAS();
<INITIAL>A        return yy::parser::make_A();
<INITIAL>ITZ      return yy::parser::make_ITZ();
<INITIAL>R        return yy::parser::make_R();
<INITIAL>BUKKIT   return yy::parser::make_BUKKIT();
<INITIAL>SRS      return yy::parser::make_SRS();
<INITIAL>'Z       return yy::parser::make_APOSTROPHE_Z();
<INITIAL>!        return yy::parser::make_EXCLAMATION();
<INITIAL>SMOOSH   return yy::parser::make_SMOOSH();
<INITIAL>MKAY     return yy::parser::make_MKAY();
<INITIAL>VISIBLE  return yy::parser::make_VISIBLE();
<INITIAL>AN       return yy::parser::make_AN();
<INITIAL>O        return yy::parser::make_O();
<INITIAL>"RLY?"   return yy::parser::make_RLY_QUESTION();
<INITIAL>YA       return yy::parser::make_YA();
<INITIAL>RLY      return yy::parser::make_RLY();
<INITIAL>OIC      return yy::parser::make_OIC();
<INITIAL>NO       return yy::parser::make_NO();
<INITIAL>WAI      return yy::parser::make_WAI();
<INITIAL>IM       return yy::parser::make_IM();
<INITIAL>IN       return yy::parser::make_IN();
<INITIAL>YR       return yy::parser::make_YR();
<INITIAL>UPPIN    return yy::parser::make_UPPIN();
<INITIAL>NERFIN   return yy::parser::make_NERFIN();
<INITIAL>TIL      return yy::parser::make_TIL();
<INITIAL>WILE     return yy::parser::make_WILE();
<INITIAL>OUTTA    return yy::parser::make_OUTTA();
<INITIAL>WIN      return yy::parser::make_WIN();
<INITIAL>FAIL     return yy::parser::make_FAIL();
<INITIAL>NOT      return yy::parser::make_NOT();
<INITIAL>OF       return yy::parser::make_OF();
<INITIAL>BOTH     return yy::parser::make_BOTH();
<INITIAL>EITHER   return yy::parser::make_EITHER();
<INITIAL>WON      return yy::parser::make_WON();
<INITIAL>SAEM     return yy::parser::make_SAEM();
<INITIAL>DIFFRINT return yy::parser::make_DIFFRINT();
<INITIAL>SUM      return yy::parser::make_SUM();
<INITIAL>DIFF     return yy::parser::make_DIFF();
<INITIAL>PRODUKT  return yy::parser::make_PRODUKT();
<INITIAL>QUOSHUNT return yy::parser::make_QUOSHUNT();
<INITIAL>MOD      return yy::parser::make_MOD();
<INITIAL>BIGGR    return yy::parser::make_BIGGR();
<INITIAL>SMALLR   return yy::parser::make_SMALLR();
<INITIAL>\"       parsed_string.clear(); BEGIN(str);
<INITIAL>{id}     return yy::parser::make_IDENTIFIER(yytext);
<INITIAL>-?{int}  return make_NUMBER(yytext);
<INITIAL>{int}\.{int} return yy::parser::make_VERSION(yytext);
<INITIAL>.        throw yy::parser::syntax_error(std::string("invalid character: ") + yytext);
<INITIAL><<EOF>>  return yy::parser::make_END();

<str>:\)  parsed_string += '\n';
<str>:>   parsed_string += '\t';
<str>:o   parsed_string += '\a';  // beep
<str>:\"  parsed_string += '"';
<str>::   parsed_string += ':';
<str>:.   throw yy::parser::syntax_error(std::string("unknown escape sequence: ") + yytext);
<str>:    throw yy::parser::syntax_error("unterminated string constant");
<str>\n   throw yy::parser::syntax_error("unterminated string constant");
<str>\"   BEGIN(INITIAL); return yy::parser::make_STRING(parsed_string);
<str>[^:\n\"]+  parsed_string += yytext;
<str><<EOF>>    throw yy::parser::syntax_error("unterminated string constant");

%%

yy::parser::symbol_type make_NUMBER(
  const std::string& s
) {
  errno = 0;
  long n = strtol(s.c_str(), NULL, 10);
  if (! (INT_MIN <= n && n <= INT_MAX && errno != ERANGE))
    throw yy::parser::syntax_error("integer is out of range: " + s);
  return yy::parser::make_NUMBER((int) n);
}
