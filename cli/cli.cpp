#include "config.hpp"
#include "cram.hpp"
#include "result.hpp"
#include <cxxopts.hpp>
#include <filesystem>
#include <iostream>
#include <string>

namespace fs = std::filesystem;
using namespace cram;

int main(int argc, char *argv[]) {
  cxxopts::Options opts{"cram", "Stow-style configuration manager for Windows"};
  // clang-format off
  opts.add_options()
    ("packages", "List of packages", cxxopts::value<std::vector<std::string>>())
    ("d,dir", "Base directory", cxxopts::value<std::string>()->default_value("."))
    ("t,target", "Target directory: symlinks created here", cxxopts::value<std::string>()->default_value(".."))
    ("no-folding", "Prevent tree folding (disable folder symlinks)", cxxopts::value<bool>()->default_value("false"))
    ("n,dry-run", "Perform a dry run", cxxopts::value<bool>()->default_value("false"))
    ("v,verbose", "Increase verbosity", cxxopts::value<bool>()->default_value("false"))
    ("h,help", "Show usage");
  // clang-format on
  opts.parse_positional({"packages"});
  auto parsed = opts.parse(argc, argv);

  if (parsed.count("help")) {
    std::cout << opts.help() << '\n';

    return Result::Ok;
  }
  if (parsed.count("packages") == 0) {
    std::cerr << "No packages provided\n";
    std::cerr << opts.help() << '\n';

    return Result::Error;
  }

  auto package_args = parsed["packages"].as<std::vector<std::string>>();
  std::vector<fs::path> packages{package_args.begin(), package_args.end()};
  cram::Config cfg{
      packages,                           // <package 1>, <package 2>, ...
      parsed["dir"].as<std::string>(),    // --dir
      parsed["target"].as<std::string>(), // --target
      parsed["no-folding"].as<bool>(),    // --no-folding
      parsed["dry-run"].as<bool>(),       // --dry-run
      parsed["verbose"].as<bool>(),       // --verbose
  };
  cram::Cram cram{cfg};
  return static_cast<int>(cram.run());
}
