# Cram

Cram is a 'stow'-style configuration manager for Windows. Currently a work in progress.

## Roadmap

- [ ] Basic symlink creation from internal package structure (both folders & single files)

Command line options: 

- [ ] `-d [dir], --dir=[dir]`: Set the input directory
- [ ] `-t [dir], --target=[dir]`: Set the output (target) directory
- [ ] `--no-folding`: Prevent 'tree folding', (creating directory symlinks instead of individual ones)
- [ ] `-n, --no, --simulate`: Dry run -- will not change filesystem
- [ ] `-v, --verbose`: Print changes to be made to stdout
