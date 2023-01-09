#ifndef PARSEREXAMPLE_INTERRUPTIONS_H
#define PARSEREXAMPLE_INTERRUPTIONS_H

#include <memory>
#include <exception>

class Object;

class Interruption : public std::exception {
 public:
  const char* what () const noexcept override;
  ~Interruption () override;
};

class BreakInterruption : public Interruption {
 public:
  const char* what () const noexcept override;
  ~BreakInterruption () override;
};

class ContinueInterruption : public Interruption {
 public:
  const char* what () const noexcept override;
  ~ContinueInterruption () override;
};

class ReturnInterruption : public Interruption {
 public:
  ReturnInterruption (std::shared_ptr<Object> value);

  std::shared_ptr<Object> get_value ();

  const char* what () const noexcept override;
  ~ReturnInterruption () override;

 private:
  std::shared_ptr<Object> value;
};


#endif //PARSEREXAMPLE_INTERRUPTIONS_H
