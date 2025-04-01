#pragma once

#include "options.hpp"
#include "result.hpp"
#include <filesystem>

namespace cram {

namespace fs = std::filesystem;

class Cram {
private:
  Options options_;

public:
  Cram(const Options &options);
  ~Cram() = default;

  Result run();

private:
  Result walk_directory(const fs::path &dir);
};

} // namespace cram
