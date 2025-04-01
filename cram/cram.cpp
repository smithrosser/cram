#include "cram.hpp"
#include "config.hpp"
#include <iostream>

namespace cram {

Cram::Cram(const Config &cfg) : cfg_{cfg} {}

Result Cram::run() {
  std::cout << "Parsed options:\n"
            << "Packages: ";
  for (const auto &p : cfg_.packages) {
    std::cout << p << " ";
  }
  std::cout << '\n'
            << "Base dir: " << cfg_.base_directory << '\n'
            << "Target dir: " << cfg_.target_directory << '\n'
            << "Tree folding off: " << cfg_.tree_folding_disabled << '\n'
            << "Dry run: " << cfg_.dry_run << '\n'
            << "Verbose: " << cfg_.verbose << '\n';

  return Result::Ok;
}

} // namespace cram
