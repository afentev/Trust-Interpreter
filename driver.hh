#pragma once

#include <map>
#include <string>
#include <fstream>
#include "scanner.h"
#include "parser.hh"
#include "help/Program.h"


class Driver {
 public:
  Driver ();

  std::map<std::string, int> variables;
  int result;

  int parse (const std::string& f);

  std::string file;


  void scan_begin ();

  void scan_end ();

  void execute ();

  bool trace_parsing;
  bool trace_scanning;
  yy::location location;

  friend class Scanner;

  Scanner scanner;
  yy::parser parser;
  bool location_debug;

  std::shared_ptr<Program> program;
 private:
  std::ifstream stream;

};
