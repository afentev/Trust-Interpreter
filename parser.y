%skeleton "lalr1.cc"
%require "3.5"

%defines
%define api.token.constructor
%define api.value.type variant
%define parse.assert

%code requires {
    #include <string>
    /* Forward declaration of classes in order to disable cyclic dependencies */
    class Scanner;
    class Driver;
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
    FN "fn"
    WHILE "while"
    FOR "for"
    IN "in"
    RANGE ".."
    RANGEEQ "..="
    QUOTE "\""
    MAIN "main"
    LET "let"
    MUT "mut"
    RETURN "return"
    COLON ":"
    ASSIGN "="
    MINUS "-"
    PLUS "+"
    STAR "*"
    SLASH "/"
    PERCENT "%"
    LBRACE "{"
    RBRACE "}"
    LPAREN "("
    RPAREN ")"
    NOT "!"
    AND "&&"
    OR "||"
    EQUAL "=="
    NEQUAL "!="
    GREATER ">"
    GREQ ">="
    LESS "<"
    LEEQ "<="
    SEMICOLON ";"
    IF "if"
    ELSE "else"
    TRUE "true"
    FALSE "false"
    INT32 "i32"
    STRING "String"
    BOOL "bool"
;

%token <std::string> IDENTIFIER "identifier"
%token <int> NUMBER "number"
%nterm <int> expression

// Prints output in parsing option for debugging location terminal
%printer { yyo << $$; } <*>;

%%

%start unit;
unit:
    "fn" "main" "(" ")" "{" statements "}" {};

statements:
    %empty {}
    | statements statement {};

statement:
    "{" statements "}" {}
    | ";" {}
    | let_statement {}
    | "identifier" "=" expression {}
    | expression ";" {}
    | if_statement {}
    | "while" expression "{" statements "}" {}
    | "for" "identifier" "in" iterator "{" statements "}" {}
    | "return" ";" {};

if_statement:
    "if" expression "{" statements "}" {}
    | "if" expression "{" statements "}" "else" if_statement {}
    | "if" expression "{" statements "}" "else" "{" statements "}" {};

let_statement:
    const_statement {}
    | mut_statement {};

mut_statement:
    "let" "mut" "identifier" ":" type "=" expression ";" {}
    | "let" "mut" "identifier" ":" type ";" {};

const_statement:
    "let" "identifier" ":" type "=" expression ";" {};

iterator:
    expression ".." expression {}
    | expression "..=" expression {}
    | expression {};  // iterate through string

type:
    "i32" {}
    | "String" {}
    | "bool" {};

expression:
    "number" {}
    | "false" {}
    | "true" {}
    | "identifier" {}
    | "!" expression {}
    | "(" expression ")" {}
    | "-" expression {}
    | expression "<" expression {}
    | expression "<=" expression {}
    | expression "==" expression {}
    | expression "!=" expression {}
    | expression ">=" expression {}
    | expression ">" expression {}
    | expression "&&" expression {}
    | expression "||" expression {}
    | expression "*" expression {}
    | expression "/" expression {}
    | expression "%" expression {}
    | expression "+" expression {}
    | expression "-" expression {};

%left "=";
%left "||";
%left "&&";
%left "==" "!=";
%left ">" "<" "<=" ">=";
%left "+" "-";
%left "*" "/" "%";
%left "!";

%%

void
yy::parser::error(const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << '\n';
}
