#include "cram.hpp"
#include "options.hpp"

using namespace cram;

int main(int argc, char *argv[]) {
  Options options{};
  Cram cram{options};

  return static_cast<int>(cram.run());
}
