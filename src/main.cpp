#include <exception>
#include <iostream>
#include <stdexcept>

#include "repl.hpp"

int main() {
  // Flush after every std::cout / std:cerr
  std::cout << std::unitbuf;
  std::cerr << std::unitbuf;

  try {
    repl::Repl().Run();
  } catch (const std::logic_error& logic) {
    std::cerr << "REPL stopped unexpectedly. " << logic.what() << std::endl;
  } catch (std::exception ex) {
    std::cerr << "REPL stopped unexpectedly. " << ex.what() << std::endl;
  }
}
