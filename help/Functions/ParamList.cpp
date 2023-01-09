#include "ParamList.h"

Argument::Argument (std::string name, std::string type, bool constantness) : variable_name(std::move(name)),
                                                                             type(std::move(type)),
                                                                             is_const(constantness) {}

ParamList::ParamList () = default;

void ParamList::add_param (std::shared_ptr<Argument> param) {
  params.push_back(std::move(param));
}

std::shared_ptr<Argument> ParamList::get_param (size_t index) {
  return params[index];
}

size_t ParamList::params_count () {
  return params.size();
}

const std::vector<std::shared_ptr<Argument>>& ParamList::get_params () {
  return params;
}

ParamList::~ParamList () = default;
