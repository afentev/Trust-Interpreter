#ifndef PARSEREXAMPLE_OBJECTCREATION_H
#define PARSEREXAMPLE_OBJECTCREATION_H

#include "help/Types/Boolean.h"
#include "help/Types/String.h"
#include "help/Types/Integer.h"

static std::shared_ptr<Object> create_object(std::string type) {
    if (type == "bool") {
        return std::make_shared<Boolean>(false);
    } else if (type == "i32") {
        return std::make_shared<Integer>(0);
    } else if (type == "String") {
        return std::make_shared<String>("");
    } else {
        throw "Unexpected type name";
    }
}

#endif //PARSEREXAMPLE_OBJECTCREATION_H
