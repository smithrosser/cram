#include "cram.hpp"
#include <cstdlib>
#include <exception>
#include <filesystem>
#include <iostream>
#include <stdexcept>
#include <utility>
#include "config.hpp"

namespace cram {

Cram::Cram(const Config& cfg) : cfg_{cfg} {}

int Cram::run() {
  try {
    for (const auto& p : cfg_.packages) {
      poll_for_symlinks(cfg_.base_dir / p);
    }
    make_symlinks();
  } catch (const std::exception& e) {
    std::cerr << "Cram error -- " << e.what() << '\n';
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}

void Cram::poll_for_symlinks(const fs::path& dir) {
  for (const auto& entry : fs::recursive_directory_iterator{dir}) {
    if (fs::is_directory(entry)) {
      continue;
    }

    fs::path link_src = entry.path();
    fs::path link_dest = cfg_.target_dir / entry.path().lexically_relative(dir);

    if (fs::exists(link_dest)) {
      throw std::runtime_error("File \"" + link_dest.string() +
                               "\" already exists");
    }
    links_.emplace_back(std::make_pair(link_src, link_dest));
  }
}

void Cram::make_symlinks() {
  for (const auto& ln : links_) {
    if (cfg_.verbose) {
      std::cout << "Creating symlink: " << ln.first << " -> " << ln.second
                << '\n';
    }
    if (cfg_.dry_run) {
      continue;
    }

    if (!fs::exists(ln.second.parent_path())) {
      fs::create_directories(ln.second.parent_path());
    }
    fs::create_symlink(ln.first, ln.second);
  }
}

}  // namespace cram
