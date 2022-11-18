#include "Visitor.h"
#include <iostream>

#include <help/Statements.h>
#include <help/Program.h>
#include "Expression.h"

//void Visitor::Visit(std::shared_ptr<Number> expression) {
//    std::cout << "Visit number!" << std::endl;
//}

void Visitor::Visit(std::shared_ptr<Statements> expression) {
    std::cout << "Visit statements!" << std::endl;
}

void Visitor::Visit(std::shared_ptr<Program> program) {
    auto statements = program->get_statements();
    std::cout << "Visit program!" << std::endl;
}

Visitor::~Visitor() = default;