#include "Program.h"

Program::Program (std::shared_ptr<Statements> statements) : statements(std::move(statements)) {

}

std::shared_ptr<Statements> Program::get_statements () {
  return statements;
}
