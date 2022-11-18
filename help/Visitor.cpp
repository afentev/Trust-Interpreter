#include "Visitor.h"
#include <iostream>

#include "help/Statements.h"
#include "help/Program.h"
#include "help/Types/Object.h"
#include "help/Types/Integer.h"
#include "help/Types/Boolean.h"
#include "help/Types/String.h"
#include "help/Expressions/LessEqExpression.h"
#include "help/Statements/IfStatement.h"
#include "Expression.h"

void Visitor::visit(std::shared_ptr<Program> program) {
    program->get_statements()->accept(this);
    std::cout << "Visit program!" << std::endl;
}

//std::shared_ptr<Object> Visitor::visit(std::shared_ptr<Object> expression) {
//    std::cout << "Visit Object!" << std::endl;
//    return expression;
//}

void Visitor::visit(std::shared_ptr<Boolean> expression) {
    std::cout << "Visit Boolean!" << std::endl;
    object = expression;
}

void Visitor::visit(std::shared_ptr<Integer> expression) {
    std::cout << "Visit Integer!" << std::endl;
    object = expression;
}

void Visitor::visit(std::shared_ptr<String> expression) {
    std::cout << "Visit String!" << std::endl;
    object = expression;
}

///////

void Visitor::visit(std::shared_ptr<NotExpression> expression) {
    std::cout << "Visit NotExpression!" << std::endl;
}

void Visitor::visit(std::shared_ptr<AndExpression> expression) {
    std::cout << "Visit AndExpression!" << std::endl;
}

void Visitor::visit(std::shared_ptr<OrExpression> expression) {
    std::cout << "Visit OrExpression!" << std::endl;
}

void Visitor::visit(std::shared_ptr<DivExpression> expression) {
    std::cout << "Visit DivExpression!" << std::endl;
}

void Visitor::visit(std::shared_ptr<MulExpression> expression) {
    std::cout << "Visit MulExpression!" << std::endl;
}

void Visitor::visit(std::shared_ptr<ModExpression> expression) {
    std::cout << "Visit ModExpression!" << std::endl;
}

void Visitor::visit(std::shared_ptr<PlusExpression> expression) {
    std::cout << "Visit PlusExpression!" << std::endl;
}

void Visitor::visit(std::shared_ptr<MinusExpression> expression) {
    std::cout << "Visit MinusExpression!" << std::endl;
}

void Visitor::visit(std::shared_ptr<UnaryMinusExpression> expression) {
    std::cout << "Visit UnaryMinusExpression!" << std::endl;
}

///

void Visitor::visit(std::shared_ptr<GreaterExpression> expression) {
    std::cout << "Visit GreaterExpression!" << std::endl;
}

void Visitor::visit(std::shared_ptr<GreaterEqExpression> expression) {
    std::cout << "Visit GreaterEqExpression!" << std::endl;
}

void Visitor::visit(std::shared_ptr<EqualExpression> expression) {
    std::cout << "Visit EqualExpression!" << std::endl;
}

void Visitor::visit(std::shared_ptr<NotEqualExpression> expression) {
    std::cout << "Visit NotEqualExpression!" << std::endl;
}

void Visitor::visit(std::shared_ptr<LessEqExpression> expression) {
    expression->get_left_exp()->accept(this);
    std::shared_ptr<Object> left = object;

    expression->get_right_exp()->accept(this);
    std::shared_ptr<Object> right = object;

    object = *left <= *right;
    std::cout << "Visit LessEqExpression!" << std::endl;
}

void Visitor::visit(std::shared_ptr<LessExpression> expression) {
    std::cout << "Visit LessExpression!" << std::endl;
}

void Visitor::visit(std::shared_ptr<IDExpression> expression) {
    std::cout << "Visit IDExpression!" << std::endl;
}

////////////////////////////////////////////////////////////////////////////////////////////////

void Visitor::visit(std::shared_ptr<Statements> expression) {
    auto statements = expression->get_statements();
    for (const auto& statement: statements) {
        statement->accept(this);
    }
    std::cout << "Visit Statements!" << std::endl;
}

void Visitor::visit(std::shared_ptr<VariableDeclaration> expression) {
    std::cout << "Visit VariableDeclaration!" << std::endl;
}

void Visitor::visit(std::shared_ptr<VariableDeclInit> expression) {
    std::cout << "Visit VariableDeclInit!" << std::endl;
}

void Visitor::visit(std::shared_ptr<WhileStatement> expression) {
    std::cout << "Visit WhileStatement!" << std::endl;
}

void Visitor::visit(std::shared_ptr<IfStatement> expression) {
    expression->get_condition()->accept(this);
    if (object->as_predicate()) {
        expression->get_statement()->accept(this);
    }
    std::cout << "Visit IfStatement!" << std::endl;
}

void Visitor::visit(std::shared_ptr<IfElseStatement> expression) {
    std::cout << "Visit IfElseStatement!" << std::endl;
}

void Visitor::visit(std::shared_ptr<IfElifStatement> expression) {
    std::cout << "Visit IfElifStatement!" << std::endl;
}

void Visitor::visit(std::shared_ptr<ForStatement> expression) {
    std::cout << "Visit ForStatement!" << std::endl;
}

void Visitor::visit(std::shared_ptr<Iterator> expression) {
    std::cout << "Visit Iterator!" << std::endl;
}

Visitor::~Visitor() = default;