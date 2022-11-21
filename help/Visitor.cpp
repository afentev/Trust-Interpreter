#include "Visitor.h"
#include "help/VisitorDependencies.h"

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

void Visitor::visit (std::shared_ptr<Statements> statement) {
  variables.add_scope();

  auto statements = statement->get_statements();
  for (const auto& statement: statements) {
    statement->accept(this);
  }

  variables.left_scope();
}

void Visitor::visit (std::shared_ptr<VariableDeclaration> statement) {
  variables.add_identifier(statement->get_name(), create_object(statement->get_type()), false, false);
}

void Visitor::visit (std::shared_ptr<VariableDeclInit> statement) {
  statement->get_value()->accept(this);
  variables.add_identifier(statement->get_name(), object, statement->is_const(), true);
}

void Visitor::visit (std::shared_ptr<TypelessVariableDecl> statement) {
  statement->get_value()->accept(this);
  variables.add_identifier(statement->get_name(), object, statement->is_const(), true);
}

void Visitor::visit (std::shared_ptr<WhileStatement> statement) {
  statement->get_condition()->accept(this);
  while (object->as_predicate()) {
    uint16_t restore_scope = variables.get_scope();
    variables.add_scope();

    try {
      statement->get_statement()->accept(this);
    } catch (BreakInterruption&) {
      variables.reduce_scope(restore_scope);
      break;
    } catch (ContinueInterruption&) {}

    variables.left_scope();
    statement->get_condition()->accept(this);
  }
}

void Visitor::visit (std::shared_ptr<IfStatement> statement) {
  variables.add_scope();

  statement->get_condition()->accept(this);
  if (object->as_predicate()) {
    statement->get_statement()->accept(this);
  }

  variables.left_scope();
}

void Visitor::visit (std::shared_ptr<IfElseStatement> statement) {
  variables.add_scope();

  statement->get_condition()->accept(this);
  if (object->as_predicate()) {
    statement->get_true_statement()->accept(this);
  } else {
    statement->get_false_statement()->accept(this);
  }

  variables.left_scope();
}

void Visitor::visit (std::shared_ptr<ForStatement> statement) {
  statement->get_start()->accept(this);
  if (object->get_type() != "i32") {
    throw InterpretationException("Can not use type \"" + object->get_type() + "\" as range bound");
  }
  int32_t begin = std::dynamic_pointer_cast<Integer>(object)->to_int();

  statement->get_end()->accept(this);
  if (object->get_type() != "i32") {
    throw InterpretationException("Can not use type \"" + object->get_type() + "\" as range bound");
  }
  int32_t end = std::dynamic_pointer_cast<Integer>(object)->to_int();

  for (int32_t current = begin; statement->get_inclusivity() ? current <= end : current < end; ++current) {
    uint16_t restore_scope = variables.get_scope();

    variables.add_scope();
    variables.add_identifier(statement->get_variable(), std::make_shared<Integer>(current), statement->is_var_const(),
                             true);
    try {
      statement->get_statement()->accept(this);
    } catch (BreakInterruption&) {
      variables.reduce_scope(restore_scope);
      break;
    } catch (ContinueInterruption&) {}
    variables.left_scope();
  }
}

void Visitor::visit (std::shared_ptr<AssignmentStatement> statement) {
  statement->get_expression()->accept(this);
  variables.mut_identifier(statement->get_identifier(), object);
}

void Visitor::visit (std::shared_ptr<ExpressionList> statement) {}

void Visitor::visit (std::shared_ptr<PrintStatement> statement) {
  size_t prev = 1;
  size_t index;
  std::string string = String::remove_escape_chars(statement->get_string());
  size_t sub_number = 0;
  while ((index = string.find("{}", prev)) != std::string::npos) {
    std::cout << string.substr(prev, index - prev);

    std::shared_ptr<Expression> value = statement->get_substitution(sub_number);
    value->accept(this);
    ++sub_number;
    std::cout << object->as_string();

    prev = index + 2;
  }
  std::cout << string.substr(prev, string.size() - prev - 1);
  if (statement->newline()) {
    std::cout << "\n";
  }
  std::cout.flush();

  if (sub_number != statement->subs_number()) {
    throw InterpretationException("More values than slots were provided");
  }
}

void Visitor::visit (std::shared_ptr<BreakStatement> statement) {
  throw BreakInterruption();
}

void Visitor::visit (std::shared_ptr<ContinueStatement> statement) {
  throw ContinueInterruption();
}

void Visitor::visit (std::shared_ptr<ReturnStatement> statement) {
  throw ReturnInterruption();
}

Visitor::~Visitor () = default;
