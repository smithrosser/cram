#include <cstdlib>
#include <cxxopts.hpp>
#include <filesystem>
#include <iostream>
#include <string>
#include "config.hpp"
#include "cram.hpp"

namespace fs = std::filesystem;
using namespace cram;

int main(int argc, char* argv[]) {
  fs::path cwd = fs::current_path();

  // clang-format off
  cxxopts::Options opts{"cram", "Stow-style configuration manager for Windows"};
  opts.add_options()
    ("packages", "List of packages", cxxopts::value<std::vector<std::string>>())
    ("d,dir", "Base directory", cxxopts::value<std::string>()->default_value(cwd))
    ("t,target", "Target directory", cxxopts::value<std::string>()->default_value(cwd.parent_path()))
    ("n,dry-run", "Perform a dry run", cxxopts::value<bool>()->default_value("false"))
    ("v,verbose", "Increase verbosity", cxxopts::value<bool>()->default_value("false"))
    ("h,help", "Show usage");
  opts.parse_positional({"packages"});
  auto parsed = opts.parse(argc, argv);
  // clang-format on

  if (parsed.count("help")) {
    std::cout << opts.help() << '\n';
    return EXIT_SUCCESS;
  }
  if (!parsed.count("packages")) {
    std::cerr << "No packages provided\n" << opts.help() << '\n';
    return EXIT_FAILURE;
  }
  auto package_args = parsed["packages"].as<std::vector<std::string>>();

  cram::Config cfg{
      // <package 1>, <package 2>, ...
      std::vector<fs::path>{package_args.begin(), package_args.end()},
      fs::absolute(parsed["dir"].as<std::string>()),     // --dir
      fs::absolute(parsed["target"].as<std::string>()),  // --target
      parsed["dry-run"].as<bool>(),                      // --dry-run
      parsed["verbose"].as<bool>(),                      // --verbose
  };
  cram::Cram cram{cfg};
  return cram.run();
}
