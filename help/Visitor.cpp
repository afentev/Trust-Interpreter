#include "Visitor.h"
#include "help/VisitorDependencies.h"

void Visitor::visit (std::shared_ptr<Program> program) {
  int16_t exit_code = 0;

  try {
    program->get_functions()->accept(this);
  } catch (ReturnInterruption& return_value) {
    ;
  } catch (InterpretationException& error) {
    exit_code = 1;
    std::cerr << "InterpretationError: " << error.what() << std::endl;
  }
  std::cerr << "\n" << "Program finished with exit code " << exit_code << std::endl;
}

void Visitor::visit(std::shared_ptr<FunctionDeclarationList> function_declaration_list) {
  std::shared_ptr<FunctionDeclaration> main_function = nullptr;
  for (const std::shared_ptr<FunctionDeclaration>& function: function_declaration_list->get_declarations()) {
    if (function->get_name() == "main") {
      if (main_function != nullptr) {
        throw InterpretationException("Program can not contain more than 1 main function");
      }
      if (!function->get_params()->get_params().empty()) {
        throw InterpretationException("Main function can not have any arguments");
      }
      if (function->get_return_type() != "void") {
        throw InterpretationException("Main function can not have a return type");
      }
      if (function->get_return_expression() != nullptr) {
        throw InterpretationException("Main function can not have non-trivial return [at the end]");
      }
      main_function = function;
    } else {
      functions.add_function(function);
    }
  }
  main_function->accept(this);
}

void Visitor::visit(std::shared_ptr<FunctionDeclaration> function) {
  function->get_statements()->accept(this);
  std::shared_ptr<ReturnStatement> return_expression = function->get_return_expression();
  if (return_expression != nullptr) {
    return_expression->accept(this);
  }
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

void Visitor::visit (std::shared_ptr<Usize> expression) {
  object = expression;
}

void Visitor::visit (std::shared_ptr<NotExpression> expression) {
  object = !*evaluate(expression->get_expression());
}

void Visitor::visit (std::shared_ptr<AndExpression> expression) {
  object = *evaluate(expression->get_left_exp()) && *evaluate(expression->get_right_exp());
}

void Visitor::visit (std::shared_ptr<OrExpression> expression) {
  object = *evaluate(expression->get_left_exp()) || *evaluate(expression->get_right_exp());
}

void Visitor::visit (std::shared_ptr<DivExpression> expression) {
  object = *evaluate(expression->get_left_exp()) / *evaluate(expression->get_right_exp());
}

void Visitor::visit (std::shared_ptr<MulExpression> expression) {
  object = *evaluate(expression->get_left_exp()) * *evaluate(expression->get_right_exp());
}

void Visitor::visit (std::shared_ptr<ModExpression> expression) {
  object = *evaluate(expression->get_left_exp()) % *evaluate(expression->get_right_exp());
}

void Visitor::visit (std::shared_ptr<PlusExpression> expression) {
  object = *evaluate(expression->get_left_exp()) + *evaluate(expression->get_right_exp());
}

void Visitor::visit (std::shared_ptr<MinusExpression> expression) {
  object = *evaluate(expression->get_left_exp()) - *evaluate(expression->get_right_exp());
}

void Visitor::visit (std::shared_ptr<UnaryMinusExpression> expression) {
  object = -*evaluate(expression->get_expression());
}

void Visitor::visit (std::shared_ptr<GreaterExpression> expression) {
  object = *evaluate(expression->get_left_exp()) > *evaluate(expression->get_right_exp());
}

void Visitor::visit (std::shared_ptr<GreaterEqExpression> expression) {
  object = *evaluate(expression->get_left_exp()) >= *evaluate(expression->get_right_exp());
}

void Visitor::visit (std::shared_ptr<EqualExpression> expression) {
  object = *evaluate(expression->get_left_exp()) == *evaluate(expression->get_right_exp());
}

void Visitor::visit (std::shared_ptr<FunctionCall> expression) {
  std::string name = expression->get_function_name();
  if (!functions.contains(name)) {
    throw InterpretationException("Invocation an undeclared function \"" + name + "\"");
  }
  std::shared_ptr<FunctionDeclaration> function = functions.get_function(name);

  Visitor new_function_visitor;
  prepare_for_call(new_function_visitor, expression);

  std::string expected_type = function->get_return_type();
  try {
    new_function_visitor.visit(functions.get_function(name));
    if (expected_type != "void") {
      throw InterpretationException("Non-void function \"" + name + "\" did not return anything");
    }
    object = nullptr;
  } catch(BreakInterruption&) {
    throw InterpretationException("break was used outside of the loop");
  } catch (ContinueInterruption&) {
    throw InterpretationException("continue was used outside of the loop");
  } catch (ReturnInterruption& ret) {
    object = ret.get_value();
    if (object == nullptr) {
      if (expected_type == "void") {
        return;
      }
      throw InterpretationException("Non-void function \"" + name + "\" returned nothing");
    }
    if (object->get_type() != expected_type) {
      throw InterpretationException("Return value type mismatch in function \"" + name + "\"");
    }
  }
}

void Visitor::visit (std::shared_ptr<NotEqualExpression> expression) {
  object = *evaluate(expression->get_left_exp()) != *evaluate(expression->get_right_exp());
}

void Visitor::visit (std::shared_ptr<LessEqExpression> expression) {
  object = *evaluate(expression->get_left_exp()) <= *evaluate(expression->get_right_exp());
}

void Visitor::visit (std::shared_ptr<LessExpression> expression) {
  object = *evaluate(expression->get_left_exp()) < *evaluate(expression->get_right_exp());
}

void Visitor::visit (std::shared_ptr<IDExpression> expression) {
  object = variables.get_identifier(expression->get_id());
}

void Visitor::visit (std::shared_ptr<AsExpression> expression) {
  evaluate(expression->get_expression());
  std::string type = expression->get_type();
  if (type == "bool") {
    object = object->as_bool();
  } else if (type == "i32") {
    object = object->as_i32();
  } else if (type == "f64") {
    object = object->as_f64();
  } else if (type == "String") {
    object = object->as_String();
  } else if (type == "usize") {
    object = object->as_usize();
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
  evaluate(statement->get_value());
  variables.add_identifier(statement->get_name(), object, statement->is_const(), true);
}

void Visitor::visit (std::shared_ptr<TypelessVariableDecl> statement) {
  evaluate(statement->get_value());
  variables.add_identifier(statement->get_name(), object, statement->is_const(), true);
}

void Visitor::visit (std::shared_ptr<WhileStatement> statement) {
  while (evaluate(statement->get_condition())->as_predicate()) {
    uint16_t restore_scope = variables.get_scope();
    variables.add_scope();

    try {
      statement->get_statement()->accept(this);
    } catch (BreakInterruption&) {
      variables.reduce_scope(restore_scope);
      break;
    } catch (ContinueInterruption&) {}

    variables.left_scope();
  }
}

void Visitor::visit (std::shared_ptr<IfStatement> statement) {
  variables.add_scope();

  evaluate(statement->get_condition());
  if (object->as_predicate()) {
    statement->get_statement()->accept(this);
  }

  variables.left_scope();
}

void Visitor::visit (std::shared_ptr<IfElseStatement> statement) {
  variables.add_scope();

  evaluate(statement->get_condition());
  if (object->as_predicate()) {
    statement->get_true_statement()->accept(this);
  } else {
    statement->get_false_statement()->accept(this);
  }

  variables.left_scope();
}

void Visitor::visit (std::shared_ptr<ForStatement> statement) {
  evaluate(statement->get_start());
  if (object->get_type() != "i32") {
    throw InterpretationException("Can not use type \"" + object->get_type() + "\" as range bound");
  }
  int32_t begin = std::dynamic_pointer_cast<Integer>(object)->to_int();

  evaluate(statement->get_end());
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
  evaluate(statement->get_expression());
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

    evaluate(statement->get_substitution(sub_number));
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

void Visitor::visit(std::shared_ptr<FunctionCall> expression) {
  throw InterpretationException("Unimplemented subscription in visitor");
}

void Visitor::visit (std::shared_ptr<BreakStatement> statement) {
  throw BreakInterruption();
}

void Visitor::visit (std::shared_ptr<ContinueStatement> statement) {
  throw ContinueInterruption();
}

void Visitor::visit (std::shared_ptr<ReturnStatement> statement) {
  std::shared_ptr<Expression> return_value = statement->get_value();
  if (return_value != nullptr) {
    if (function_name == "main") {
      throw InterpretationException("Main function can not have non-trivial return");
    }
    evaluate(return_value);
  } else {
    object = nullptr;
  }
  throw ReturnInterruption(object);
}

std::shared_ptr<Object> Visitor::evaluate (std::shared_ptr<Expression> expression) {
  expression->accept(this);
  if (object == nullptr) {
    throw InterpretationException("void function was used in expression");
  }
  return object;
}

void Visitor::prepare_for_call (Visitor& consumer, std::shared_ptr<FunctionCall> callee) {
  std::string name = callee->get_function_name();

  consumer.function_name = name;
  consumer.functions = functions;

  std::unordered_set<std::string> arguments;
  std::shared_ptr<ParamList> required = functions.get_function(name)->get_params();
  std::shared_ptr<ExpressionList> substitutions = callee->get_arguments();
  size_t params_count = required->params_count();
  if (substitutions->subs_number() != params_count) {
    throw InterpretationException("Invocation function \"" + name + "\" with incorrect number of arguments");
  }
  for (size_t number = 0; number < params_count; ++number) {
    std::shared_ptr<Argument> current_required = required->get_param(number);
    if (arguments.contains(current_required->variable_name)) {
      throw InterpretationException("Two different arguments can not have the same name: \"" +\
                                    current_required->variable_name + "\"");
    }
    arguments.insert(current_required->variable_name);

    evaluate(substitutions->get_expression(number));
    if (object->get_type() != current_required->type) {
      throw InterpretationException("Invocation function \"" + name + "\" with incorrect type of argument #" +\
                                    std::to_string(number + 1));
    }
    consumer.variables.add_identifier(current_required->variable_name, object,
                                      current_required->is_const, true);
  }
}

Visitor::~Visitor () = default;
