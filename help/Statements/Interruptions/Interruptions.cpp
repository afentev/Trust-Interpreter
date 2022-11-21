#include "help/Statements/Interruptions/Interruptions.h"

const char* Interruption::what () const noexcept {
  return "INTERNAL ERROR: INTERRUPTION WAS NOT CAUGHT";
}

const char* BreakInterruption::what () const noexcept {
  return "break was used outside of the loop";
}

const char* ContinueInterruption::what () const noexcept {
  return "continue was used outside of the loop";
}

const char* ReturnInterruption::what () const noexcept {
  return "INTERNAL ERROR: RETURN RAISE WAS NOT CAUGHT";
}