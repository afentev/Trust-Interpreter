#ifndef PARSEREXAMPLE_INTERRUPTIONS_H
#define PARSEREXAMPLE_INTERRUPTIONS_H

#include <exception>

class Interruption : public std::exception {
 public:
  const char* what () const noexcept override;
  ~Interruption() override;
};

class BreakInterruption : public Interruption {
 public:
  const char* what () const noexcept override;
  ~BreakInterruption() override;
};

class ContinueInterruption : public Interruption {
 public:
  const char* what () const noexcept override;
  ~ContinueInterruption() override;
};

class ReturnInterruption : public Interruption {
 public:
  const char* what () const noexcept override;
  ~ReturnInterruption() override;
};


#endif //PARSEREXAMPLE_INTERRUPTIONS_H
