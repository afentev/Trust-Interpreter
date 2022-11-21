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
#include "help/Expressions/AsExpression.h"

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

#include "help/InterpretationExceptions/InterpretationExceptions.h"

void Visitor::visit (std::shared_ptr<Program> program) {
  int16_t exit_code = 0;

  try {
    program->get_statements()->accept(this);
  } catch (ReturnInterruption&) {
    ;
  } catch (InterpretationException& error) {
    exit_code = 1;
    std::cerr << "InterpretationError: " << error.what() << std::endl;
  }
  std::cerr << "\n" << "Program finished with exit code " << exit_code << std::endl;
}

void Visitor::visit (std::shared_ptr<Expression> expression) {
  expression->accept(this);
}

void Visitor::visit (std::shared_ptr<Boolean> expression) {
  object = expression;
}

void Visitor::visit (std::shared_ptr<Integer> expression) {
  object = expression;
}

void Visitor::visit (std::shared_ptr<Float> expression) {
  object = expression;
}

void Visitor::visit (std::shared_ptr<String> expression) {
  object = expression;
}

void Visitor::visit (std::shared_ptr<NotExpression> expression) {
  expression->get_expression()->accept(this);
  object = !*object;
}

void Visitor::visit (std::shared_ptr<AndExpression> expression) {
  expression->get_left_exp()->accept(this);
  std::shared_ptr<Object> left = object;

  expression->get_right_exp()->accept(this);
  std::shared_ptr<Object> right = object;

  object = *left && *right;
}

void Visitor::visit (std::shared_ptr<OrExpression> expression) {
  expression->get_left_exp()->accept(this);
  std::shared_ptr<Object> left = object;

  expression->get_right_exp()->accept(this);
  std::shared_ptr<Object> right = object;

  object = *left || *right;
}

void Visitor::visit (std::shared_ptr<DivExpression> expression) {
  expression->get_left_exp()->accept(this);
  std::shared_ptr<Object> left = object;

  expression->get_right_exp()->accept(this);
  std::shared_ptr<Object> right = object;

  object = *left / *right;
}

void Visitor::visit (std::shared_ptr<MulExpression> expression) {
  expression->get_left_exp()->accept(this);
  std::shared_ptr<Object> left = object;

  expression->get_right_exp()->accept(this);
  std::shared_ptr<Object> right = object;

  object = *left * *right;
}

void Visitor::visit (std::shared_ptr<ModExpression> expression) {
  expression->get_left_exp()->accept(this);
  std::shared_ptr<Object> left = object;

  expression->get_right_exp()->accept(this);
  std::shared_ptr<Object> right = object;

  object = *left % *right;
}

void Visitor::visit (std::shared_ptr<PlusExpression> expression) {
  expression->get_left_exp()->accept(this);
  std::shared_ptr<Object> left = object;

  expression->get_right_exp()->accept(this);
  std::shared_ptr<Object> right = object;

  object = *left + *right;
}

void Visitor::visit (std::shared_ptr<MinusExpression> expression) {
  expression->get_left_exp()->accept(this);
  std::shared_ptr<Object> left = object;

  expression->get_right_exp()->accept(this);
  std::shared_ptr<Object> right = object;

  object = *left - *right;
}

void Visitor::visit (std::shared_ptr<UnaryMinusExpression> expression) {
  expression->get_expression()->accept(this);
  object = -*object;
}

void Visitor::visit (std::shared_ptr<GreaterExpression> expression) {
  expression->get_left_exp()->accept(this);
  std::shared_ptr<Object> left = object;

  expression->get_right_exp()->accept(this);
  std::shared_ptr<Object> right = object;

  object = *left > *right;
}

void Visitor::visit (std::shared_ptr<GreaterEqExpression> expression) {
  expression->get_left_exp()->accept(this);
  std::shared_ptr<Object> left = object;

  expression->get_right_exp()->accept(this);
  std::shared_ptr<Object> right = object;

  object = *left >= *right;
}

void Visitor::visit (std::shared_ptr<EqualExpression> expression) {
  expression->get_left_exp()->accept(this);
  std::shared_ptr<Object> left = object;

  expression->get_right_exp()->accept(this);
  std::shared_ptr<Object> right = object;

  object = *left == *right;
}

void Visitor::visit (std::shared_ptr<NotEqualExpression> expression) {
  expression->get_left_exp()->accept(this);
  std::shared_ptr<Object> left = object;

  expression->get_right_exp()->accept(this);
  std::shared_ptr<Object> right = object;

  object = *left != *right;
}

void Visitor::visit (std::shared_ptr<LessEqExpression> expression) {
  expression->get_left_exp()->accept(this);
  std::shared_ptr<Object> left = object;

  expression->get_right_exp()->accept(this);
  std::shared_ptr<Object> right = object;

  object = *left <= *right;
}

void Visitor::visit (std::shared_ptr<LessExpression> expression) {
  expression->get_left_exp()->accept(this);
  std::shared_ptr<Object> left = object;

  expression->get_right_exp()->accept(this);
  std::shared_ptr<Object> right = object;

  object = *left < *right;
}

void Visitor::visit (std::shared_ptr<IDExpression> expression) {
  object = variables.get_identifier(expression->get_id());
}

void Visitor::visit (std::shared_ptr<AsExpression> expression) {
  expression->get_expression()->accept(this);
  std::string type = expression->get_type();
  if (type == "bool") {
    object = object->as_bool();
  } else if (type == "i32") {
    object = object->as_i32();
  } else if (type == "f64") {
    object = object->as_f64();
  } else if (type == "String") {
    object = object->as_String();
  } else {
    throw std::runtime_error("INTERNAL ERROR: UNEXPECTED TYPE NAME");
  }
}

void Visitor::visit (std::shared_ptr<Statements> expression) {
  variables.add_scope();

  auto statements = expression->get_statements();
  for (const auto& statement: statements) {
    statement->accept(this);
  }

  variables.left_scope();
}

void Visitor::visit (std::shared_ptr<VariableDeclaration> expression) {
  variables.add_identifier(expression->get_name(), create_object(expression->get_type()), false, false);
}

void Visitor::visit (std::shared_ptr<VariableDeclInit> expression) {
  expression->get_value()->accept(this);
  variables.add_identifier(expression->get_name(), object, expression->is_const(), true);
}

void Visitor::visit (std::shared_ptr<TypelessVariableDecl> expression) {
  expression->get_value()->accept(this);
  variables.add_identifier(expression->get_name(), object, expression->is_const(), true);
}

void Visitor::visit (std::shared_ptr<WhileStatement> expression) {
  expression->get_condition()->accept(this);
  while (object->as_predicate()) {
    uint16_t restore_scope = variables.get_scope();
    variables.add_scope();

    try {
      expression->get_statement()->accept(this);
    } catch (BreakInterruption&) {
      variables.reduce_scope(restore_scope);
      break;
    } catch (ContinueInterruption&) {}

    variables.left_scope();
    expression->get_condition()->accept(this);
  }
}

void Visitor::visit (std::shared_ptr<IfStatement> expression) {
  variables.add_scope();

  expression->get_condition()->accept(this);
  if (object->as_predicate()) {
    expression->get_statement()->accept(this);
  }

  variables.left_scope();
}

void Visitor::visit (std::shared_ptr<IfElseStatement> expression) {
  variables.add_scope();

  expression->get_condition()->accept(this);
  if (object->as_predicate()) {
    expression->get_true_statement()->accept(this);
  } else {
    expression->get_false_statement()->accept(this);
  }

  variables.left_scope();
}

void Visitor::visit (std::shared_ptr<ForStatement> expression) {
  expression->get_start()->accept(this);
  if (object->get_type() != "i32") {
    throw InterpretationException("Can not use type \"" + object->get_type() + "\" as range bound");
  }
  int32_t begin = std::dynamic_pointer_cast<Integer>(object)->to_int();

  expression->get_end()->accept(this);
  if (object->get_type() != "i32") {
    throw InterpretationException("Can not use type \"" + object->get_type() + "\" as range bound");
  }
  int32_t end = std::dynamic_pointer_cast<Integer>(object)->to_int();

  for (int32_t current = begin; expression->get_inclusivity() ? current <= end : current < end; ++current) {
    uint16_t restore_scope = variables.get_scope();

    variables.add_scope();
    variables.add_identifier(expression->get_variable(), std::make_shared<Integer>(current), expression->is_var_const(),
                             true);
    try {
      expression->get_statement()->accept(this);
    } catch (BreakInterruption&) {
      variables.reduce_scope(restore_scope);
      break;
    } catch (ContinueInterruption&) {}
    variables.left_scope();
  }
}

void Visitor::visit (std::shared_ptr<AssignmentStatement> expression) {
  expression->get_expression()->accept(this);
  variables.mut_identifier(expression->get_identifier(), object);
}

void Visitor::visit (std::shared_ptr<ExpressionList> expression) {}

void Visitor::visit (std::shared_ptr<PrintStatement> expression) {
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
    throw InterpretationException("More values than slots were provided");
  }
}

void Visitor::visit (std::shared_ptr<BreakStatement> expression) {
  throw BreakInterruption();
}

void Visitor::visit (std::shared_ptr<ContinueStatement> expression) {
  throw ContinueInterruption();
}

void Visitor::visit (std::shared_ptr<ReturnStatement> expression) {
  throw ReturnInterruption();
}

std::shared_ptr<Object> Visitor::get_object () {
  return object;
}

Visitor::~Visitor () = default;