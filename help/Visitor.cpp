#include "Visitor.h"
#include <iostream>

#include "help/Statements/Statements.h"
#include "help/Program.h"
#include "help/Types/ObjectCreation.h"

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

void Visitor::visit(std::shared_ptr<Program> program) {
    program->get_statements()->accept(this);
    std::cout << "Visit program!" << std::endl;
}

void Visitor::visit(std::shared_ptr<Expression> expression) {
    expression->accept(this);
    std::cout << "Visit Expression!" << std::endl;
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
    expression->get_expression()->accept(this);
    object = !*object;
    std::cout << "Visit NotExpression!" << std::endl;
}

void Visitor::visit(std::shared_ptr<AndExpression> expression) {
    expression->get_left_exp()->accept(this);
    std::shared_ptr<Object> left = object;

    expression->get_right_exp()->accept(this);
    std::shared_ptr<Object> right = object;

    object = *left && *right;
    std::cout << "Visit AndExpression!" << std::endl;
}

void Visitor::visit(std::shared_ptr<OrExpression> expression) {
    expression->get_left_exp()->accept(this);
    std::shared_ptr<Object> left = object;

    expression->get_right_exp()->accept(this);
    std::shared_ptr<Object> right = object;

    object = *left || *right;
    std::cout << "Visit OrExpression!" << std::endl;
}

void Visitor::visit(std::shared_ptr<DivExpression> expression) {
    expression->get_left_exp()->accept(this);
    std::shared_ptr<Object> left = object;

    expression->get_right_exp()->accept(this);
    std::shared_ptr<Object> right = object;

    object = *left / *right;
    std::cout << "Visit DivExpression!" << std::endl;
}

void Visitor::visit(std::shared_ptr<MulExpression> expression) {
    expression->get_left_exp()->accept(this);
    std::shared_ptr<Object> left = object;

    expression->get_right_exp()->accept(this);
    std::shared_ptr<Object> right = object;

    object = *left * *right;
    std::cout << "Visit MulExpression!" << std::endl;
}

void Visitor::visit(std::shared_ptr<ModExpression> expression) {
    expression->get_left_exp()->accept(this);
    std::shared_ptr<Object> left = object;

    expression->get_right_exp()->accept(this);
    std::shared_ptr<Object> right = object;

    object = *left % *right;
    std::cout << "Visit ModExpression!" << std::endl;
}

void Visitor::visit(std::shared_ptr<PlusExpression> expression) {
    expression->get_left_exp()->accept(this);
    std::shared_ptr<Object> left = object;

    expression->get_right_exp()->accept(this);
    std::shared_ptr<Object> right = object;

    object = *left + *right;
    std::cout << "Visit PlusExpression!" << std::endl;
}

void Visitor::visit(std::shared_ptr<MinusExpression> expression) {
    expression->get_left_exp()->accept(this);
    std::shared_ptr<Object> left = object;

    expression->get_right_exp()->accept(this);
    std::shared_ptr<Object> right = object;

    object = *left - *right;
    std::cout << "Visit MinusExpression!" << std::endl;
}

void Visitor::visit(std::shared_ptr<UnaryMinusExpression> expression) {
    expression->get_expression()->accept(this);
    object = -*object;
    std::cout << "Visit UnaryMinusExpression!" << std::endl;
}

///

void Visitor::visit(std::shared_ptr<GreaterExpression> expression) {
    expression->get_left_exp()->accept(this);
    std::shared_ptr<Object> left = object;

    expression->get_right_exp()->accept(this);
    std::shared_ptr<Object> right = object;

    object = *left > *right;
    std::cout << "Visit GreaterExpression!" << std::endl;
}

void Visitor::visit(std::shared_ptr<GreaterEqExpression> expression) {
    expression->get_left_exp()->accept(this);
    std::shared_ptr<Object> left = object;

    expression->get_right_exp()->accept(this);
    std::shared_ptr<Object> right = object;

    object = *left >= *right;
    std::cout << "Visit GreaterEqExpression!" << std::endl;
}

void Visitor::visit(std::shared_ptr<EqualExpression> expression) {
    expression->get_left_exp()->accept(this);
    std::shared_ptr<Object> left = object;

    expression->get_right_exp()->accept(this);
    std::shared_ptr<Object> right = object;

    object = *left == *right;
    std::cout << "Visit EqualExpression!" << std::endl;
}

void Visitor::visit(std::shared_ptr<NotEqualExpression> expression) {
    expression->get_left_exp()->accept(this);
    std::shared_ptr<Object> left = object;

    expression->get_right_exp()->accept(this);
    std::shared_ptr<Object> right = object;

    object = *left != *right;
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
    expression->get_left_exp()->accept(this);
    std::shared_ptr<Object> left = object;

    expression->get_right_exp()->accept(this);
    std::shared_ptr<Object> right = object;

    object = *left < *right;
    std::cout << "Visit LessExpression!" << std::endl;
}

void Visitor::visit(std::shared_ptr<IDExpression> expression) {
    object = variables.get_identifier(expression->get_id());
    //std::cout << "Visit IDExpression!" << std::endl;
}

////////////////////////////////////////////////////////////////////////////////////////////////

void Visitor::visit(std::shared_ptr<Statements> expression) {
    variables.add_scope();

    auto statements = expression->get_statements();
    for (const auto& statement: statements) {
        statement->accept(this);
    }

    variables.left_scope();
    std::cout << "Visit Statements!" << std::endl;
}

void Visitor::visit(std::shared_ptr<VariableDeclaration> expression) {
    variables.add_identifier(expression->get_name(), create_object(expression->get_type()), false, false);
    std::cout << "Visit VariableDeclaration!" << std::endl;
}

void Visitor::visit(std::shared_ptr<VariableDeclInit> expression) {
    expression->get_value()->accept(this);
    variables.add_identifier(expression->get_name(), object, expression->is_const(), true);
    std::cout << "Visit VariableDeclInit!" << std::endl;
}

void Visitor::visit(std::shared_ptr<TypelessVariableDecl> expression) {
    expression->get_value()->accept(this);
    variables.add_identifier(expression->get_name(), object, expression->is_const(), true);
    std::cout << "Visit TypelessVariableDecl!" << std::endl;
}

void Visitor::visit(std::shared_ptr<WhileStatement> expression) {
    expression->get_condition()->accept(this);
    while (object->as_predicate()) {
        variables.add_scope();

        try {
            expression->get_statement()->accept(this);
        } catch (BreakInterruption&) {
            variables.left_scope();
            break;
        } catch (ContinueInterruption&) {}

        variables.left_scope();
        expression->get_condition()->accept(this);
    }
    std::cout << "Visit WhileStatement!" << std::endl;
}

void Visitor::visit(std::shared_ptr<IfStatement> expression) {
    variables.add_scope();

    expression->get_condition()->accept(this);
    if (object->as_predicate()) {
        expression->get_statement()->accept(this);
    }

    variables.left_scope();
    std::cout << "Visit IfStatement!" << std::endl;
}

void Visitor::visit(std::shared_ptr<IfElseStatement> expression) {
    variables.add_scope();

    expression->get_condition()->accept(this);
    if (object->as_predicate()) {
        expression->get_true_statement()->accept(this);
    } else {
        expression->get_false_statement()->accept(this);
    }

    variables.left_scope();
    std::cout << "Visit IfElseStatement!" << std::endl;
}

void Visitor::visit(std::shared_ptr<ForStatement> expression) {
    expression->get_start()->accept(this);
    int32_t begin = std::dynamic_pointer_cast<Integer>(object)->to_int();

    expression->get_end()->accept(this);
    int32_t end = std::dynamic_pointer_cast<Integer>(object)->to_int();

    // TODO: negative numbers?
    for (int32_t current = begin; expression->get_inclusivity()? current <= end: current < end; ++current) {
        variables.add_scope();
        variables.add_identifier(expression->get_variable(), std::make_shared<Integer>(current), expression->is_var_const(), true);
        try {
            expression->get_statement()->accept(this);
        } catch (BreakInterruption&) {
            variables.left_scope();
            break;
        } catch (ContinueInterruption&) {}
        variables.left_scope();
    }
    std::cout << "Visit ForStatement!" << std::endl;
}

void Visitor::visit(std::shared_ptr<AssignmentStatement> expression) {
    expression->get_expression()->accept(this);
    variables.mut_identifier(expression->get_identifier(), object);
    std::cout << "Visit AssignmentStatement!" << std::endl;
}

void Visitor::visit(std::shared_ptr<ExpressionList> expression) {
    std::cout << "Visit ExpressionList!" << std::endl;
}

void Visitor::visit(std::shared_ptr<PrintStatement> expression) {
    size_t prev = 1;
    size_t index;
    std::string string = String::remove_escape_chars(expression->get_string());
    size_t sub_number = 0;
    while ((index = string.find("{}", prev)) != std::string::npos) {
        std::cout << string.substr(prev, index - prev);

        std::shared_ptr<Expression> value = expression->get_substitution(sub_number);
        value->accept(this);
        ++sub_number;
        std::cout << object->as_string();

        prev = index + 2;
    }
    std::cout << string.substr(prev, string.size() - prev - 1);
    if (expression->newline()) {
        std::cout << "\n";
    }
    std::cout.flush();

    if (sub_number != expression->subs_number()) {
        throw "More values than slots were provided";
    }

    std::cout << "Visit PrintStatement!" << std::endl;
}

void Visitor::visit(std::shared_ptr<BreakStatement> expression) {
    throw BreakInterruption();
}

void Visitor::visit(std::shared_ptr<ContinueStatement> expression) {
    throw ContinueInterruption();
}

std::shared_ptr<Object> Visitor::get_object() {
    return object;
}

Visitor::~Visitor() = default;