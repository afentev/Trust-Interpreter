%skeleton "lalr1.cc"
%require "3.5"

%defines
%define api.token.constructor
%define api.value.type variant
%define parse.assert

%code requires {
    #include <string>
    #include <memory>
    /* Forward declaration of classes in order to disable cyclic dependencies */
    class Scanner;
    class Driver;

    class Visitor;
    class Expression;
    class Program;
    class Statement;
    class Statements;
    class VariableDeclaration;
    class Boolean;
    class String;
    class Integer;
    class NotExpression;
    class AndExpression;
    class OrExpression;
    class EqualExpression;
    class NotEqualExpression;
    class LessEqExpression;
    class LessExpression;
    class GreaterEqExpression;
    class GreaterExpression;
    class PlusExpression;
    class MinusExpression;
    class UnaryMinusExpression;
    class MulExpression;
    class DivExpression;
    class ModExpression;
    class IDExpression;
}


%define parse.trace
%define parse.error verbose

%code {
    #include "driver.hh"
    #include "location.hh"

    #include "help/Expression.h"
    #include "help/Visitor.h"
    #include "help/Program.h"
    #include "help/Statement.h"
    #include "help/Statements.h"
    #include "help/VariableDeclaration.h"
    #include "help/Types/Boolean.h"
    #include "help/Types/Integer.h"
    #include "help/Types/String.h"
    #include "help/Expressions/NotExpression.h"
    #include "help/Expressions/AndExpression.h"
    #include "help/Expressions/OrExpression.h"
    #include "help/Expressions/EqualExpression.h"
    #include "help/Expressions/NotEqualExpression.h"
    #include "help/Expressions/GreaterExpression.h"
    #include "help/Expressions/GreaterEqExpression.h"
    #include "help/Expressions/LessExpression.h"
    #include "help/Expressions/LessEqExpression.h"
    #include "help/Expressions/PlusExpression.h"
    #include "help/Expressions/MinusExpression.h"
    #include "help/Expressions/UnaryMinusExpression.h"
    #include "help/Expressions/MulExpression.h"
    #include "help/Expressions/ModExpression.h"
    #include "help/Expressions/DivExpression.h"
    #include "help/Expressions/IDExpression.h"

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
%nterm <std::shared_ptr<Expression>> expression
%nterm <std::shared_ptr<Program>> program
%nterm <std::shared_ptr<Statements>> statements;
%nterm <std::shared_ptr<Statement>> statement;
%nterm <std::shared_ptr<VariableDeclaration>> let_statement;
%nterm <std::shared_ptr<VariableDeclaration>> mut_let_statement;
%nterm <std::shared_ptr<VariableDeclaration>> const_let_statement;
%nterm <std::string> type;

// Prints output in parsing option for debugging location terminal
%printer { yyo << $$; } <*>;

%%

%start program;
program:
    "fn" "main" "(" ")" "{" statements "}" {
    $$ = std::make_shared<Program>($6);
    driver.program = $$;
    };

statements:
    %empty {$$ = std::make_shared<Statements>();}
    | statements statement {$1->add_statement($2); $$ = $1;};

statement:
    "{" statements "}" {}
    | ";" {}
    | let_statement {$$ = $1;}
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
    const_let_statement {$$ = $1;}
    | mut_let_statement {$$ = $1;};

mut_let_statement:
    "let" "mut" "identifier" ":" type "=" expression ";" {$$ = std::make_shared<VariableDeclaration>($3, $5);}
    | "let" "mut" "identifier" ":" type ";" {$$ = std::make_shared<VariableDeclaration>($3, $5);};

const_let_statement:
    "let" "identifier" ":" type "=" expression ";" {$$ = std::make_shared<VariableDeclaration>($2, $4);};

iterator:
    expression ".." expression {}
    | expression "..=" expression {}
    | expression {};  // iterate through string

type:
    "i32" {$$ = "i32";}
    | "String" {$$ = "String";}
    | "bool" {$$ = "bool";};

expression:
    "number" {$$ = std::make_shared<Integer> ($1);}
    | "false" {$$ = std::make_shared<Boolean> (false);}
    | "true" {$$ = std::make_shared<Boolean> (true);}
    | "identifier" {$$ = std::make_shared<IDExpression> ($1);}
    | "!" expression {$$ = std::make_shared<NotExpression> ($2);}
    | "(" expression ")" {$$ = $2;}
    | "-" expression {$$ = std::make_shared<UnaryMinusExpression> ($2);}
    | expression "<" expression {$$ = std::make_shared<LessExpression> ($1, $3);}
    | expression "<=" expression {$$ = std::make_shared<LessEqExpression> ($1, $3);}
    | expression "==" expression {$$ = std::make_shared<EqualExpression> ($1, $3);}
    | expression "!=" expression {$$ = std::make_shared<NotEqualExpression> ($1, $3);}
    | expression ">=" expression {$$ = std::make_shared<GreaterEqExpression> ($1, $3);}
    | expression ">" expression {$$ = std::make_shared<GreaterExpression> ($1, $3);}
    | expression "&&" expression {$$ = std::make_shared<AndExpression> ($1, $3);}
    | expression "||" expression {$$ = std::make_shared<OrExpression> ($1, $3);}
    | expression "*" expression {$$ = std::make_shared<MulExpression> ($1, $3);}
    | expression "/" expression {$$ = std::make_shared<DivExpression> ($1, $3);}
    | expression "%" expression {$$ = std::make_shared<ModExpression> ($1, $3);}
    | expression "+" expression {$$ = std::make_shared<PlusExpression> ($1, $3);}
    | expression "-" expression {$$ = std::make_shared<MinusExpression> ($1, $3);};

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
