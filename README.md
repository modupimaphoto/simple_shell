# 0x16. C - Simple Shell

This is a basic UNIX command line interpreter (shell) written in C. 
The shell provides a minimal command-line interface with basic features and built-in commands.

## Features

- Display a prompt and wait for the user to type a command.
- Execute simple commands with arguments.
- Handle built-in commands like `exit` and `cd`.
- Use the `getline()` function to read user input.
- Handle the "end of file" condition (Ctrl+D) for graceful termination.
- Fork a new process for external commands.
- Display a prompt again after each command execution.
- Error handling for command execution and system calls.
