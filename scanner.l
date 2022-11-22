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

  yy::parser::symbol_type make_REAL(
      const std::string &s,
      const yy::parser::location_type& loc
    );

  yy::parser::symbol_type make_SIZE_T(
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
float [0-9]+\.[0-9]+
size_t [0-9]+usize
blank [ \t\r]
string_literal \"([^\\\"]|\\.)*\"
comment_line "//".*"\n"
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

{blank}+   {
    if (driver.location_debug) {
        std::cerr << "Blank matched" << std::endl;
    }
    // loc.step();
}
\n+ {
    if (driver.location_debug) {
        std::cerr << "EOL called" << std::endl;
    }
    loc.lines(yyleng);
    loc.step();
}

"let"      return yy::parser::make_LET(loc);
"mut"      return yy::parser::make_MUT(loc);
"return"   return yy::parser::make_RETURN(loc);
"break"    return yy::parser::make_BREAK(loc);
"continue" return yy::parser::make_CONTINUE(loc);
"as"       return yy::parser::make_AS(loc);
"fn"       return yy::parser::make_FN(loc);
"->"       return yy::parser::make_ARROW(loc);
":"        return yy::parser::make_COLON(loc);
"i32"      return yy::parser::make_INT32(loc);
"usize"    return yy::parser::make_USIZE(loc);
"f64"      return yy::parser::make_FLOAT64(loc);
"String"   return yy::parser::make_STRING(loc);
"bool"     return yy::parser::make_BOOL(loc);
"true"     return yy::parser::make_TRUE(loc);
"false"     return yy::parser::make_FALSE(loc);
"-"        {
              return yy::parser::make_MINUS  (loc);
           }
"+"        return yy::parser::make_PLUS   (loc);
"+="       return yy::parser::make_PLUSASSIGN(loc);
"-="       return yy::parser::make_MINUSASSIGN(loc);
"*="       return yy::parser::make_STARASSIGN(loc);
"%="       return yy::parser::make_PERCENTASSIGN(loc);
"/="       return yy::parser::make_SLASHASSIGN(loc);
"*"        return yy::parser::make_STAR   (loc);
"/"        return yy::parser::make_SLASH  (loc);
"%"        return yy::parser::make_PERCENT  (loc);
"{"        return yy::parser::make_LBRACE  (loc);
"}"        return yy::parser::make_RBRACE  (loc);
"("        return yy::parser::make_LPAREN (loc);
")"        return yy::parser::make_RPAREN (loc);
"["        return yy::parser::make_LSUBSCR (loc);
"]"        return yy::parser::make_RSUBSCR (loc);
"!"        return yy::parser::make_NOT   (loc);
"="        return yy::parser::make_ASSIGN (loc);
";"        return yy::parser::make_SEMICOLON(loc);
","        return yy::parser::make_COMMA(loc);
"if"       return yy::parser::make_IF(loc);
"else"     return yy::parser::make_ELSE(loc);
"while"    return yy::parser::make_WHILE(loc);
"for"      return yy::parser::make_FOR(loc);
"in"       return yy::parser::make_IN(loc);
".."       return yy::parser::make_RANGE(loc);
"..="      return yy::parser::make_RANGEEQ(loc);
">"        return yy::parser::make_GREATER(loc);
">="       return yy::parser::make_GREQ(loc);
"=="       return yy::parser::make_EQUAL(loc);
"!="       return yy::parser::make_NEQUAL(loc);
"<="       return yy::parser::make_LEEQ(loc);
"<"        return yy::parser::make_LESS(loc);
"&&"       return yy::parser::make_AND(loc);
"||"       return yy::parser::make_OR(loc);
"print!"   return yy::parser::make_PRINT(loc);
"println!" return yy::parser::make_PRINTLN(loc);

{comment_line} return yy::parser::make_COMMENTLINE(yytext, loc);
{string_literal} return yy::parser::make_STRLITERAL(yytext, loc);
{float}    return make_REAL(yytext, loc);
{size_t}   return make_SIZE_T(yytext, loc);
{int}      return make_NUMBER(yytext, loc);
{id}       {
                if (driver.location_debug) {
                    std::cerr << "ID found " << yytext << std::endl;
                }
                return yy::parser::make_IDENTIFIER(yytext, loc);
           }
.          {
                throw yy::parser::syntax_error(loc, "invalid character: " + std::string(yytext));
           }
<<EOF>>    return yy::parser::make_END (loc);
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

yy::parser::symbol_type make_REAL(
  const std::string &s,
  const yy::parser::location_type& loc
) {
  errno = 0;
  double n = strtod(s.c_str(), NULL);
  return yy::parser::make_REAL(n, loc);
}

yy::parser::symbol_type make_SIZE_T(
  const std::string &s,
  const yy::parser::location_type& loc
) {
  errno = 0;
  size_t n;
  std::string stripped = s.substr(0, s.find("usize"));
  sscanf(stripped.c_str(), "%zu", &n);
  return yy::parser::make_SIZE_T(n, loc);
}