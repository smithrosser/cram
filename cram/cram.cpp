#include "cram.hpp"
#include "options.hpp"
#include <iostream>

namespace cram {

Cram::Cram(const Options &options) : options_{options} {}

Result Cram::run() {
  std::cout << "baskemtball\n";
  return Result::Ok;
}

} // namespace cram
