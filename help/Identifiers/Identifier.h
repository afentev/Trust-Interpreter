#ifndef PARSEREXAMPLE_IDENTIFIER_H
#define PARSEREXAMPLE_IDENTIFIER_H

#include <string>

class Object;  // from "help/Types/Object.h"

class Identifier {
 public:
  Identifier () = delete;

  Identifier (std::shared_ptr<Object> obj, uint8_t layer, bool is_const, bool is_init);

  std::shared_ptr<Object> get_object ();

  void set_object (std::shared_ptr<Object>);

  std::string get_identifier ();

  uint8_t get_scope ();

  bool get_constantness ();

  bool is_initialised ();

  void set_initialised (bool);

  ~Identifier ();

 private:
  std::shared_ptr<Object> object;
  const uint8_t scope_layer;
  const bool is_constant;
  bool _is_initialised;
};


#endif //PARSEREXAMPLE_IDENTIFIER_H
