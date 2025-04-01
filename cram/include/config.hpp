#pragma once

#include <filesystem>
#include <vector>

namespace cram {

namespace fs = std::filesystem;

struct Config {
  std::vector<fs::path> base_directories = {}; ///< Symlinks point to files here
  fs::path target_directory = "..";    ///< Symlinks created in this directory
  bool is_tree_folding_enabled = true; ///< Enable/disable tree folding
  bool is_dry_run = false;             ///< Prevent real changes to filesystem
  bool is_verbose = false;             ///< Log file changes to stdout
};

} // namespace cram
