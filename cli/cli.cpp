#include "config.hpp"
#include "cram.hpp"
#include <cxxopts.hpp>
#include <iostream>

using namespace cram;

int main(int argc, char *argv[]) {
  cxxopts::Options opts{"cram", "Stow-style configuration manager for Windows"};

  // clang-format off
  opts.add_options()
    ("t,test", "Test argument");
  // clang-format on
  auto res = opts.parse(argc, argv);

  if (res.count("test") > 0) {
    std::cout << "Test option passed\n";
  }

  cram::Config cfg{};
  cram::Cram cram{cfg};
  return static_cast<int>(cram.run());
}
