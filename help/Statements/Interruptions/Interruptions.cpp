#include "help/Statements/Interruptions/Interruptions.h"
#include "help/Types/Object.h"

const char* Interruption::what () const noexcept {
  return "INTERNAL ERROR: INTERRUPTION WAS NOT CAUGHT";
}

const char* BreakInterruption::what () const noexcept {
  return "break was used outside of the loop";
}

const char* ContinueInterruption::what () const noexcept {
  return "continue was used outside of the loop";
}

ReturnInterruption::ReturnInterruption (std::shared_ptr<Object> value) : value(std::move(value)) {}

std::shared_ptr<Object> ReturnInterruption::get_value () {
  return value;
}

const char* ReturnInterruption::what () const noexcept {
  return "INTERNAL ERROR: RETURN RAISE WAS NOT CAUGHT";
}

Interruption::~Interruption () = default;

BreakInterruption::~BreakInterruption () = default;

ContinueInterruption::~ContinueInterruption () = default;

ReturnInterruption::~ReturnInterruption () = default;
