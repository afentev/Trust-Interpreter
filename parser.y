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

    class Program;
    class Visitor;
    class Statement;
    class Expression;

    class Object;
    class Boolean;
    class String;
    class Integer;
    class Float;
    class Usize;
    class Char;
    class Vector;

    class BreakStatement;
    class ContinueStatement;
    class ReturnStatement;
    class InterpretationException;
    class AssignmentStatement;
    class ExpressionList;
    class ForStatement;
    class IfElseStatement;
    class IfStatement;
    class PrintStatement;
    class Statements;
    class TypelessVariableDecl;
    class VariableDeclaration;
    class VariableDeclInit;
    class WhileStatement;
    class PushStatement;
    class PopStatement;

    class AndExpression;
    class AsExpression;
    class DivExpression;
    class EqualExpression;
    class FunctionCall;
    class GreaterEqExpression;
    class GreaterExpression;
    class IDExpression;
    class LessEqExpression;
    class LessExpression;
    class MinusExpression;
    class ModExpression;
    class MulExpression;
    class NotEqualExpression;
    class NotExpression;
    class OrExpression;
    class PlusExpression;
    class UnaryMinusExpression;
    class SubscriptionExpression;
    class SubscriptionAssignment;
    class VectorEnumerationExpression;
    class VectorValueExpression;
    class SizeExpression;

    class FunctionDeclarationList;
    class FunctionDeclaration;
    class ParamList;
    class Argument;
}


%define parse.trace
%define parse.error verbose

%code {
    #include "driver.hh"
    #include "location.hh"

    #include "help/Visitor.h"
    #include "help/Program.h"
    #include "help/Types/Boolean.h"
    #include "help/Types/Integer.h"
    #include "help/Types/Float.h"
    #include "help/Types/String.h"
    #include "help/Types/Usize.h"
    #include "help/Types/Char.h"
    #include "help/Types/Vector.h"

    #include "help/Expressions/NotExpression.h"
    #include "help/Expressions/AndExpression.h"
    #include "help/Expressions/OrExpression.h"
    #include "help/Expressions/EqualExpression.h"
    #include "help/Expressions/FunctionCall.h"
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
    #include "help/Expressions/AsExpression.h"
    #include "help/Expressions/SubscriptionExpression.h"
    #include "help/Expressions/VectorEnumerationExpression.h"
    #include "help/Expressions/VectorValueExpression.h"
    #include "help/Expressions/SizeExpression.h"

    #include "help/Statements/WhileStatement.h"
    #include "help/Statements/IfStatement.h"
    #include "help/Statements/IfElseStatement.h"
    #include "help/Statements/ForStatement.h"
    #include "help/Statements/VariableDeclaration.h"
    #include "help/Statements/VariableDeclInit.h"
    #include "help/Statements/TypelessVariableDecl.h"
    #include "help/Statements/AssignmentStatement.h"
    #include "help/Statements/ExpressionList.h"
    #include "help/Statements/PrintStatement.h"
    #include "help/Statements/Interruptions/BreakStatement.h"
    #include "help/Statements/Interruptions/ContinueStatement.h"
    #include "help/Statements/Interruptions/ReturnStatement.h"
    #include "help/Statements/SubscriptionAssignment.h"
    #include "help/Statements/PushStatement.h"
    #include "help/Statements/PopStatement.h"

    #include "help/Functions/FunctionDeclarationList.h"
    #include "help/Functions/FunctionDeclaration.h"
    #include "help/Functions/ParamList.h"

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
    ARROW "->"
    WHILE "while"
    FOR "for"
    IN "in"
    DOT "."
    RANGE ".."
    RANGEEQ "..="
    QUOTE "\""
    LET "let"
    MUT "mut"
    RETURN "return"
    BREAK "break"
    CONTINUE "continue"
    PUSH "push"
    POP "pop"
    LEN "len"
    AS "as"
    COLON ":"
    ASSIGN "="
    MINUS "-"
    PLUS "+"
    PLUSASSIGN "+="
    MINUSASSIGN "-="
    STARASSIGN "*="
    PERCENTASSIGN "%="
    SLASHASSIGN "/="
    STAR "*"
    SLASH "/"
    PERCENT "%"
    LBRACE "{"
    RBRACE "}"
    LPAREN "("
    RPAREN ")"
    LSUBSCR "["
    RSUBSCR "]"
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
    COMMA ","
    IF "if"
    ELSE "else"
    TRUE "true"
    FALSE "false"
    INT32 "i32"
    FLOAT64 "f64"
    STRING "String"
    USIZE "usize"
    BOOL "bool"
    CHAR "char"
    VEC "Vec"
    VECMACROS "vec!"
    PRINT "print!"
    PRINTLN "println!"
;

%token <std::string> IDENTIFIER "identifier"
%token <int> NUMBER "integer_number"
%token <double> REAL "real_number"
%token <size_t> SIZE_T "size_t"
%token <char> CHARLITERAL "char_literal"

%token <std::string> STRLITERAL "string_literal"
%token <std::string> COMMENTLINE "comment_line"
%nterm <std::shared_ptr<Expression>> expression
%nterm <std::shared_ptr<Program>> program
%nterm <std::shared_ptr<Statements>> statements;
%nterm <std::shared_ptr<Statement>> statement;
%nterm <std::shared_ptr<Statement>> let_statement;
%nterm <std::shared_ptr<Statement>> mut_let_statement;
%nterm <std::shared_ptr<Statement>> const_let_statement;
%nterm <std::shared_ptr<Statement>> if_statement;
%nterm <std::shared_ptr<ForStatement>> for_loop;
%nterm <std::shared_ptr<ExpressionList>> expression_list;
%nterm <std::shared_ptr<PrintStatement>> print_statement;
%nterm <std::string> type;
%nterm <std::string> primitive_type;

%nterm <std::shared_ptr<FunctionDeclarationList>> function_declaration_list;
%nterm <std::shared_ptr<FunctionDeclaration>> function_declaration;
%nterm <std::shared_ptr<ParamList>> param_list;
%nterm <std::shared_ptr<Argument>> argument;

// Prints output in parsing option for debugging location terminal
%printer { yyo << $$; } <*>;

%%

%start program;
program:
    function_declaration_list {$$ = std::make_shared<Program>($1);
                               driver.program = $$;};

function_declaration_list:
    %empty {$$ = std::make_shared<FunctionDeclarationList>();}
    | "comment_line" {$$ = std::make_shared<FunctionDeclarationList>();}
    | function_declaration_list function_declaration {$1->add_declaration($2); $$ = $1;};

function_declaration:
    "fn" "identifier" "(" param_list ")" "{" statements "}" {$$ = std::make_shared<FunctionDeclaration>($2, "void", $4, $7, nullptr);}
    | "fn" "identifier" "(" param_list ")" "->" type "{" statements "}" {$$ = std::make_shared<FunctionDeclaration>($2, $7, $4, $9, nullptr);}
    | "fn" "identifier" "(" param_list ")" "->" type "{" statements expression "}" {$$ = std::make_shared<FunctionDeclaration>($2, $7, $4, $9, std::make_shared<ReturnStatement>($10));};

param_list:
    %empty {$$ = std::make_shared<ParamList>();}
    | argument {$$ = std::make_shared<ParamList>(); $$->add_param($1);}
    | param_list "," argument {$1->add_param($3); $$ = $1;};

argument:
    "identifier" ":" type {$$ = std::make_shared<Argument>($1, $3, true);}
    | "mut" "identifier" ":" type {$$ = std::make_shared<Argument>($2, $4, false);};

statements:
    %empty {$$ = std::make_shared<Statements>();}
    | statements statement {$1->add_statement($2); $$ = $1;};

statement:
    "{" statements "}" {$$ = $2;}
    | ";" {$$ = std::make_shared<ExpressionList>();}
    | "comment_line" {$$ = std::make_shared<ExpressionList>();}
    | "break" {$$ = std::make_shared<BreakStatement>();}
    | "continue" {$$ = std::make_shared<ContinueStatement>();}
    | print_statement {$$ = $1;}
    | let_statement {$$ = $1;}
    | "identifier" "[" expression "]" "=" expression ";" {$$ = std::make_shared<SubscriptionAssignment>($1, $3, $6);}
    | "identifier" "[" expression "]" "+=" expression ";" {$$ = std::make_shared<SubscriptionAssignment>($1, $3, std::make_shared<PlusExpression>(std::make_shared<SubscriptionExpression>(std::make_shared<IDExpression>($1), $3), $6));}
    | "identifier" "[" expression "]" "-=" expression ";" {$$ = std::make_shared<SubscriptionAssignment>($1, $3, std::make_shared<MinusExpression>(std::make_shared<SubscriptionExpression>(std::make_shared<IDExpression>($1), $3), $6));}
    | "identifier" "[" expression "]" "*=" expression ";" {$$ = std::make_shared<SubscriptionAssignment>($1, $3, std::make_shared<MulExpression>(std::make_shared<SubscriptionExpression>(std::make_shared<IDExpression>($1), $3), $6));}
    | "identifier" "[" expression "]" "%=" expression ";" {$$ = std::make_shared<SubscriptionAssignment>($1, $3, std::make_shared<ModExpression>(std::make_shared<SubscriptionExpression>(std::make_shared<IDExpression>($1), $3), $6));}
    | "identifier" "[" expression "]" "/=" expression ";" {$$ = std::make_shared<SubscriptionAssignment>($1, $3, std::make_shared<DivExpression>(std::make_shared<SubscriptionExpression>(std::make_shared<IDExpression>($1), $3), $6));}
    | "identifier" "." "push" "(" expression ")" ";" {$$ = std::make_shared<PushStatement>($1, $5);}
    | "identifier" "." "pop" "(" ")" ";" {$$ = std::make_shared<PopStatement>($1);}
    | "identifier" "=" expression ";" {$$ = std::make_shared<AssignmentStatement>($1, $3);}
    | "identifier" "+=" expression ";" {$$ = std::make_shared<AssignmentStatement>($1, std::make_shared<PlusExpression>(std::make_shared<IDExpression>($1), $3));}
    | "identifier" "-=" expression ";" {$$ = std::make_shared<AssignmentStatement>($1, std::make_shared<MinusExpression>(std::make_shared<IDExpression>($1), $3));}
    | "identifier" "*=" expression ";" {$$ = std::make_shared<AssignmentStatement>($1, std::make_shared<MulExpression>(std::make_shared<IDExpression>($1), $3));}
    | "identifier" "%=" expression ";" {$$ = std::make_shared<AssignmentStatement>($1, std::make_shared<ModExpression>(std::make_shared<IDExpression>($1), $3));}
    | "identifier" "/=" expression ";" {$$ = std::make_shared<AssignmentStatement>($1, std::make_shared<DivExpression>(std::make_shared<IDExpression>($1), $3));}
    | expression ";" {$$ = $1;}
    | if_statement {$$ = $1;}
    | "while" expression "{" statements "}" {$$ = std::make_shared<WhileStatement>($2, $4);}
    | for_loop {$$ = $1;}
    | "return" ";" {$$ = std::make_shared<ReturnStatement>(nullptr);}
    | "return" expression ";" {$$ = std::make_shared<ReturnStatement>($2);};

print_statement:
    "print!" "(" ")" ";" {$$ = std::make_shared<PrintStatement>("\"\"", std::make_shared<ExpressionList>(), false);}
    | "print!" "(" "string_literal" ")" ";" {$$ = std::make_shared<PrintStatement>($3, std::make_shared<ExpressionList>(), false);}
    | "print!" "(" "string_literal" "," expression_list ")" ";" {$$ = std::make_shared<PrintStatement>($3, $5, false);}
    | "println!" "(" ")" ";" {$$ = std::make_shared<PrintStatement>("\"\"", std::make_shared<ExpressionList>(), true);}
    | "println!" "(" "string_literal" ")" ";" {$$ = std::make_shared<PrintStatement>($3, std::make_shared<ExpressionList>(), true);}
    | "println!" "(" "string_literal" "," expression_list ")" ";" {$$ = std::make_shared<PrintStatement>($3, $5, true);};

if_statement:
    "if" expression "{" statements "}" {$$ = std::make_shared<IfStatement>($2, $4);}
    | "if" expression "{" statements "}" "else" if_statement {$$ = std::make_shared<IfElseStatement>($2, $4, $7);}
    | "if" expression "{" statements "}" "else" "{" statements "}" {$$ = std::make_shared<IfElseStatement>($2, $4, $8);};

let_statement:
    const_let_statement {$$ = $1;}
    | mut_let_statement {$$ = $1;};

mut_let_statement:
    "let" "mut" "identifier" ":" type "=" expression ";" {$$ = std::make_shared<VariableDeclInit>($3, $5, false, $7);}
    | "let" "mut" "identifier" ":" type ";" {$$ = std::make_shared<VariableDeclaration>($3, $5);}
    | "let" "mut" "identifier" "=" expression ";" {$$ = std::make_shared<TypelessVariableDecl>($3, false, $5);};

const_let_statement:
    "let" "identifier" ":" type "=" expression ";" {$$ = std::make_shared<VariableDeclInit>($2, $4, true, $6);}
    | "let" "identifier" "=" expression ";" {$$ = std::make_shared<TypelessVariableDecl>($2, true, $4);};

for_loop:
    "for" "identifier" "in" expression ".." expression "{" statements "}" {$$ = std::make_shared<ForStatement>($2, $4, $6, $8, false, true);}
    | "for" "mut" "identifier" "in" expression ".." expression "{" statements "}" {$$ = std::make_shared<ForStatement>($3, $5, $7, $9, false, false);}
    | "for" "identifier" "in" expression "..=" expression "{" statements "}" {$$ = std::make_shared<ForStatement>($2, $4, $6, $8, true, true);}
    | "for" "mut" "identifier" "in" expression "..=" expression "{" statements "}" {$$ = std::make_shared<ForStatement>($3, $5, $7, $9, true, false);};

type:
    "i32" {$$ = "i32";}
    | "usize" {$$ = "usize";}
    | "f64" {$$ = "f64";}
    | "String" {$$ = "String";}
    | "bool" {$$ = "bool";}
    | "char" {$$ = "char";}
    | "Vec" "<" type ">" {$$ = "Vec<" + $3 + ">";};

primitive_type:
    "i32" {$$ = "i32";}
    | "usize" {$$ = "usize";}
    | "f64" {$$ = "f64";}
    | "bool" {$$ = "bool";}
    | "char" {$$ = "char";};

expression:
    "integer_number" {$$ = std::make_shared<Integer> ($1);}
    | "size_t" {$$ = std::make_shared<Usize> ($1);}
    | "real_number" {$$ = std::make_shared<Float> ($1);}
    | "false" {$$ = std::make_shared<Boolean> (false);}
    | "true" {$$ = std::make_shared<Boolean> (true);}
    | "string_literal" {$$ = std::make_shared<String> ($1);}
    | "char_literal" {$$ = std::make_shared<Char> ($1);}
    | "vec!" "[" expression_list "]" {$$ = std::make_shared<VectorEnumerationExpression>($3);}
    | "vec!" "[" expression ";" expression "]" {$$ = std::make_shared<VectorValueExpression>($3, $5);}
    | "identifier" {$$ = std::make_shared<IDExpression> ($1);}
    | "identifier" "(" expression_list ")" {$$ = std::make_shared<FunctionCall>($1, $3);}
    | "!" expression {$$ = std::make_shared<NotExpression> ($2);}
    | "(" expression ")" {$$ = $2;}
    | "-" expression {$$ = std::make_shared<UnaryMinusExpression> ($2);}
    | "identifier" "[" expression "]" {$$ = std::make_shared<SubscriptionExpression>(std::make_shared<IDExpression>($1), $3);}
    | "identifier" "." "len" "(" ")" {$$ = std::make_shared<SizeExpression>($1);}
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
    | expression "-" expression {$$ = std::make_shared<MinusExpression> ($1, $3);}
    | expression "as" primitive_type {$$ = std::make_shared<AsExpression>($1, $3);};

expression_list:
    %empty {$$ = std::make_shared<ExpressionList>();}
    | expression {$$ = std::make_shared<ExpressionList>(); $$->add_expression($1);}
    | expression_list "," expression {$1->add_expression($3); $$ = $1;};

%left "=" "+=" "-=" "*=" "/=" "%=";
%left ".." "..=";
%left "||";
%left "&&";
%left "==" "!=" ">" "<" "<=" ">=";
%left "+" "-";
%left "*" "/" "%";
%left "as";
%left "!";

%%

void
yy::parser::error(const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << '\n';
}
