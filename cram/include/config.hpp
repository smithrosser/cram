#pragma once

#include <filesystem>
#include <vector>

namespace cram {

namespace fs = std::filesystem;

struct Config {
  std::vector<fs::path> packages;  ///< Packages (symlinks point here)
  fs::path base_dir;               ///< Base directory to look for packages
  fs::path target_dir;             ///< Symlinks created in this directory
  bool dry_run;                    ///< Prevent real changes to filesystem
  bool verbose;                    ///< Log file changes to stdout
};

}  // namespace cram
