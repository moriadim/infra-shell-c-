# Infra-Shell-C

A lightweight, customized UNIX shell written entirely in C from scratch.

## 💡 Why this project?
I built this shell to understand exactly what happens under the hood when I type a command in my Linux terminal. As a DevOps enthusiast and a CS student at ESTIN, I wanted to see how processes are managed at the OS level, particularly focusing on `fork()`, `execvp()`, and dynamic memory management. It's essentially a look inside the gears of operating systems.

## ✨ Features
- **Core Execution Foundation**: Implements basic system execution using POSIX OS APIs (`fork`, `execvp`, `waitpid`).
- **Built-in Commands**: Includes native support for `cd`, `exit`, and a custom `about` command.
- **Robust Parsing**: Tokenizes inputs safely with dynamic memory allocation to prevent segmentation faults.
- **Customized UX**: Features an aesthetically pleasing cyan-colored ANSI prompt and graceful error handling prefixed with `infra-sh:`.
- **Modular Codebase**: The code is well-organized into logical C headers (`shell.h`) and source wrappers (`parser.c`, `exec.c`, `main.c`). Fully documented using Doxygen-style comments.
- **Dockerized Environment**: Ships with a minimal Alpine-based Dockerfile to completely isolate the build and execution process, making it trivial to test on any machine.

## 🏗️ Project Structure
- `shell.h`: Contains all headers, constants, and function definitions.
- `main.c`: The core REPL (Read-Eval-Print Loop) that spins up the shell.
- `parser.c`: Handles string splitting and tokenization via `strtok()`.
- `exec.c`: Manages built-ins dispatching and the `fork()`/`exec()` lifecycle.
- `Makefile`: Automates the compilation process (supports standard building and a debug mode for Valgrind).
- `Dockerfile`: Provides an isolated Alpine Linux environment to build and run the shell.

## 🚀 How to Compile & Run

### Method 1: Bare Metal (Makefile)
You'll need `gcc` and `make`.
```bash
# Compile the optimal production build
make

# Run the shell
./shell
```

*(Note: Use `make debug` if you want to trace memory leaks using tools like Valgrind or gdb).*

### Method 2: Docker Container (Isolated)
You can run the shell in a secure, isolated Linux container using Docker without cluttering your local system:
```bash
# Build the Alpine-based image
docker build -t infra-shell-c .

# Run the container interactively
docker run -it infra-shell-c
```

## 🎮 Usage Example

```bash
infra-sh> ls -l
infra-sh> cd /tmp
infra-sh> about
Infra-Shell-C by Abdellah - ESTIN 2026
infra-sh> exit
```

## 🔭 Future Improvements
- [ ] Add support for file redirection (`>`, `<`).
- [ ] Implement system pipes (`|`) for chaining commands.
- [ ] Keep track of command history.
