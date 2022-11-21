#ifndef PARSEREXAMPLE_IDENTIFIER_H
#define PARSEREXAMPLE_IDENTIFIER_H

#include <string>
#include <utility>

class Object;  // from "help/Types/Object.h"

class Identifier {
 public:
  Identifier () = delete;
  Identifier (std::shared_ptr<Object> obj, uint8_t layer, bool is_const, bool is_init);

  std::shared_ptr<Object> get_object ();
  void set_object (std::shared_ptr<Object> value);
  uint8_t get_scope ();
  bool get_constantness ();
  bool is_initialised ();
  void set_initialised (bool new_value);

  ~Identifier ();

 private:
  std::shared_ptr<Object> object;
  const uint8_t scope_layer;
  const bool is_constant;
  bool _is_initialised;
};


#endif //PARSEREXAMPLE_IDENTIFIER_H
