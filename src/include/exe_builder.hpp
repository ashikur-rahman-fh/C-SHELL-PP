#include <memory>
#include <vector>

#include <builtins/exit.hpp>

#include "executable.hpp"

namespace shell {

class ExeBuilder {
 public:
  std::shared_ptr<IExecutable> build(std::vector<std::string>& inputTokens);
  std::shared_ptr<IExecutable> build(const ExecutableContext& context);
};

}  // namespace shell
