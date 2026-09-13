#include "parser.hpp"

#include <string>
#include <vector>

#include <gtest/gtest.h>

TEST(Parser, TestSplit) {
  auto out = parser::Split("This sentence has space.");
  std::vector<std::string> exp = {"This", "sentence", "has", "space."};
  EXPECT_EQ(out, exp);
  EXPECT_EQ(out, exp);
}

TEST(Parser, TestSplitWithCustomDelimiter) {
  auto out = parser::Split("This,sentence,has,space.", ",");
  std::vector<std::string> exp = {"This", "sentence", "has", "space."};
  EXPECT_EQ(out, exp);
  EXPECT_EQ(out, exp);
}

TEST(Parser, TestSplitWithMultipleDelimiter) {
  auto out = parser::Split("This,    sentence,    has,,, ,  space,and what?", " ,");
  std::vector<std::string> exp = {"This", "sentence", "has", "space", "and", "what?"};
  EXPECT_EQ(out, exp);
  EXPECT_EQ(out, exp);
}

TEST(Parser, TestParseExecutable) {
  auto out = parser::ParseExecutable("hello world");
  std::string expCmd = out->GetCmd();
  std::vector<std::string> expArgv = out->GetArgv();

  EXPECT_EQ(expCmd, "hello");
  EXPECT_EQ(expArgv, std::vector<std::string>{"world"});
}

TEST(Parser, TestParse) {
  auto out = parser::Split("This,    sentence,    has,,, ,  space,and what?", " ,");
  std::vector<std::string> exp = {"This", "sentence", "has", "space", "and", "what?"};
  EXPECT_EQ(exp, out);
}
