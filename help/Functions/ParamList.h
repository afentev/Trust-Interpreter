#ifndef PARSEREXAMPLE_PARAMLIST_H
#define PARSEREXAMPLE_PARAMLIST_H

#include <vector>
#include "help/Statements/Statements.h"

struct Argument {
    Argument(std::string name, std::string type, bool constantness);

    std::string variable_name;
    std::string type;
    bool is_const;
};

class ParamList: public std::enable_shared_from_this<ParamList> {
 public:
  ParamList ();

  void add_param(std::shared_ptr<Argument> param);
  std::shared_ptr<Argument> get_param(size_t index);
  size_t params_count();
  const std::vector<std::shared_ptr<Argument>>& get_params();

  ~ParamList () ;
 private:
  std::vector<std::shared_ptr<Argument>> params;
};


#endif //PARSEREXAMPLE_PARAMLIST_H
