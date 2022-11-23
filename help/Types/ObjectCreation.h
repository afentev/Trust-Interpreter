#ifndef PARSEREXAMPLE_OBJECTCREATION_H
#define PARSEREXAMPLE_OBJECTCREATION_H

#include "help/Types/Boolean.h"
#include "help/Types/String.h"
#include "help/Types/Integer.h"
#include "help/Types/Float.h"
#include "help/Types/Usize.h"
#include "help/Types/Char.h"

static std::shared_ptr<Object> create_object (const std::string& type) {
  if (type == "bool") {
    return std::make_shared<Boolean>(false);
  } else if (type == "i32") {
    return std::make_shared<Integer>(0);
  } else if (type == "f64") {
    return std::make_shared<Float>(0.0);
  } else if (type == "String") {
    return std::make_shared<String>(std::string(), false);
  } else if (type == "usize") {
    return std::make_shared<Usize>(0);
  } else if (type == "char") {
    return std::make_shared<Char>('\0');
  } else {
    throw std::runtime_error("INTERNAL ERROR: UNEXPECTED TYPE NAME");
  }
}

#endif //PARSEREXAMPLE_OBJECTCREATION_H
