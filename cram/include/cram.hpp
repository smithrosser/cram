#pragma once

#include <filesystem>
#include <utility>
#include <vector>
#include "config.hpp"

namespace cram {

namespace fs = std::filesystem;

using SymlinkBasePath = fs::path;
using SymlinkTargetPath = fs::path;
using SymlinkList = std::vector<std::pair<SymlinkBasePath, SymlinkTargetPath>>;

class Cram {
private:
  Config cfg_;
  SymlinkList links_;

public:
  Cram(const Config& cfg);
  ~Cram() = default;

  int run();

private:
  void poll_for_symlinks(const fs::path& dir);
  void make_symlinks();
};

}  // namespace cram
