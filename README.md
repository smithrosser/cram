# Cram

Cram is a 'stow'-style configuration manager for Windows. Currently a work in progress.

## Usage

```
cram [OPTIONS...] <package_1>, <package_2>

  -d, --dir arg     Base directory (default: .)
  -t, --target arg  Target directory (default: ..)
  -n, --dry-run     Perform a dry run
  -v, --verbose     Increase verbosity
  -h, --help        Show usage
```

## Building

Dependencies:
- `cmake`
- `cxxopts` (included as submodule)

To build:
```
git clone --recurse-submodules https://github.com/smithrosser/cram
cd cram
mkdir build && cd build
cmake ..
cmake --build .
```

## Roadmap

- [x] Command-line parsing
- [x] Basic symlink creation from list of 'packages' (files only)
- [ ] Symlink deletion
- [ ] Symlinking folders (emulate stow 'tree folding' feature)
- [ ] Unit tests
- [ ] Release workflow

Command line options: 

- [x] `-d [dir], --dir=[dir]`: Set the input directory
- [x] `-t [dir], --target=[dir]`: Set the output (target) directory
- [x] `--dry-run`: Dry run -- will not change filesystem
- [x] `-v, --verbose`: Print changes to be made to stdout
- [ ] `--no-folding`: Prevent 'tree folding', (creating directory symlinks instead of individual ones)
