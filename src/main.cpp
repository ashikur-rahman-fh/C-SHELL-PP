#include <exception>
#include <iostream>

#include "repl.hpp"

int main() {
  // Flush after every std::cout / std:cerr
  std::cout << std::unitbuf;
  std::cerr << std::unitbuf;

  try {
    repl::Repl().Run();
  } catch (std::exception ex) {
    std::cerr << "REPL stopped unexpectedly. " << ex.what() << std::endl;
  }
}
