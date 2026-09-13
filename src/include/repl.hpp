#pragma once

#include <string>
namespace repl {

class Repl {
 public:
  Repl();

  void Run() const;

  std::string getPromptSymbol() const;

  void setPromptSymbol(const std::string& promptSymbol);

 private:
  std::string promptSymbol_m;
};

}  // namespace repl
