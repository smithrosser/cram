#pragma once

#include <filesystem>
#include <vector>

namespace cram {

namespace fs = std::filesystem;

struct Config {
  std::vector<fs::path> packages = {}; ///< Packages (symlinks point here)
  fs::path base_directory = ".";       ///< Base directory to look for packages
  fs::path target_directory = "..";    ///< Symlinks created in this directory
  bool tree_folding_disabled = false;  ///< Enable/disable tree folding
  bool dry_run = false;                ///< Prevent real changes to filesystem
  bool verbose = false;                ///< Log file changes to stdout
};

} // namespace cram
