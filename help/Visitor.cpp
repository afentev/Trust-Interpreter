#include "Visitor.h"
#include <iostream>

#include <help/Statements.h>
#include <help/Program.h>
#include "Expression.h"

void Visitor::visit(std::shared_ptr<Program> program) {
    auto statements = program->get_statements();
    for (const auto& statement: statements->statements) {
        statement->accept(this);
    }
    std::cout << "Visit program!" << std::endl;
}

void Visitor::visit(std::shared_ptr<Statement> expression) {
    std::cout << "Visit statement!" << std::endl;
}

void Visitor::visit(std::shared_ptr<Statements> expression) {
    std::cout << "Visit statements!" << std::endl;
}

void Visitor::visit(std::shared_ptr<Expression> program) {
    std::cout << "Visit expression!" << std::endl;
}

void Visitor::visit(std::shared_ptr<VariableDeclaration> expression) {
    std::cout << "Visit VariableDeclaration!" << std::endl;
}

void Visitor::visit(std::shared_ptr<Object> expression) {
    std::cout << "Visit Object!" << std::endl;
}

void Visitor::visit(std::shared_ptr<Boolean> expression) {
    std::cout << "Visit Boolean!" << std::endl;
}

void Visitor::visit(std::shared_ptr<Integer> expression) {
    std::cout << "Visit Integer!" << std::endl;
}

void Visitor::visit(std::shared_ptr<String> expression) {
    std::cout << "Visit String!" << std::endl;
}

///////

void Visitor::visit(std::shared_ptr<AndExpression> program) {
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
    std::cout << "Visit LessEqExpression!" << std::endl;
}

void Visitor::visit(std::shared_ptr<LessExpression> expression) {
    std::cout << "Visit LessExpression!" << std::endl;
}

void Visitor::visit(std::shared_ptr<IDExpression> expression) {
    std::cout << "Visit IDExpression!" << std::endl;
}

Visitor::~Visitor() = default;