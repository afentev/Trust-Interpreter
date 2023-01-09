#include "InterpretationExceptions.h"

InterpretationException::InterpretationException (const std::string& message) : message(message) {}

const char* InterpretationException::what () const noexcept {
  return message.data();
}

InterpretationException::~InterpretationException () = default;
