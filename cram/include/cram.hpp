#pragma once

#include "config.hpp"
#include "result.hpp"
#include <filesystem>

namespace cram {

namespace fs = std::filesystem;

class Cram {
private:
  Config cfg_;

public:
  Cram(const Config &cfg);
  ~Cram() = default;

  Result run();

private:
  Result walk_directory(const fs::path &dir);
};

} // namespace cram
