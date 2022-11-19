#ifndef PARSEREXAMPLE_INTERRUPTIONS_H
#define PARSEREXAMPLE_INTERRUPTIONS_H

#include <exception>

class Interruption: public std::exception {
public:
    const char* what() const noexcept override;
};

class BreakInterruption: public Interruption {
public:
    const char* what() const noexcept override;
};

class ContinueInterruption: public Interruption {
public:
    const char* what() const noexcept override;
};

#endif //PARSEREXAMPLE_INTERRUPTIONS_H
