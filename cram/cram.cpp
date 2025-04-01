#include "cram.hpp"
#include "config.hpp"
#include <iostream>

namespace cram {

Cram::Cram(const Config &cfg) : cfg_{cfg} {}

Result Cram::run() {
  std::cout << "baskemtball\n";
  return Result::Ok;
}

} // namespace cram
