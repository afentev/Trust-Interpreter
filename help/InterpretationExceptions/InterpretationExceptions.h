#ifndef PARSEREXAMPLE_INTERPRETATIONEXCEPTIONS_H
#define PARSEREXAMPLE_INTERPRETATIONEXCEPTIONS_H

#include <string>
#include <exception>

class InterpretationException: public std::exception {
 public:
  explicit InterpretationException(const std::string& message);

  const char* what () const noexcept override;

  ~InterpretationException() override;

 private:
  std::string message;
};


#endif //PARSEREXAMPLE_INTERPRETATIONEXCEPTIONS_H
