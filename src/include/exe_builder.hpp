#include "executable.hpp"
#include <memory>
#include <vector>
#include <builtins/exit.hpp>

namespace shell {

class ExeBuilder {
public:
  std::shared_ptr<IExecutable> build(std::vector<std::string> &inputTokens);
};

}
