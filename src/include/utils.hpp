#pragma once
#include <exception>
#include <string>

namespace utils {
enum LoopDecision {
  Continue,
  Break,
};

class ShellError : public std::exception {
public:
  explicit ShellError(const std::string& message, LoopDecision loopDecision) :
    message_m(message), loopDecision_m(loopDecision) {}

  const char* what() const noexcept override {
    return message_m.c_str();
  }

  LoopDecision getLoopDecision() const {
    return loopDecision_m;
  }

private:
  std::string message_m;
  LoopDecision loopDecision_m;
};

}
