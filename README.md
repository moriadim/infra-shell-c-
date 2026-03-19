# Infra-Shell-C

A lightweight, customized UNIX shell written entirely in C from scratch.

## Why this project?
I built this to understand what happens under the hood when I type a command in my Linux terminal. As a DevOps enthusiast and a CS student at ESTIN, I wanted to see how processes are managed at the OS level (particularly focusing on `fork`, `execvp`, and process execution flow).

## Features
- **Core Execution Rules**: Implements basic system execution using POSIX OS APIs (`fork`, `execvp`, `waitpid`).
- **Built-in Commands**: Includes native support for `cd`, `exit`, and a custom `about` command.
- **Robust Parsing**: Tokenizes inputs safely and implements dynamic memory allocation that prevents segmentation faults.
- **Error Handling**: Graceful error handling customized with the `infra-sh:` prefix.
- **Modular Codebase**: Well-organized code partitioned into logical C headers and source wrappers.

## How to Compile

A `Makefile` is provided to simplify compilation:

```bash
# To compile with optimization for production:
make

# To compile with debugging flags (for valgrind/gdb):
make debug
```

## Usage

Simply run the generated executable:
```bash
./shell
```

Then you can use it just like a normal shell:
```bash
infra-sh> ls -l
infra-sh> cd /tmp
infra-sh> about
Infra-Shell-C by Abdellah - ESTIN 2026
infra-sh> exit
```

## Future Improvements
- [ ] Add support for input/output redirection (`>`, `<`).
- [ ] Pipe handling (`|`) for chaining commands.
- [ ] Keep track of command history.
