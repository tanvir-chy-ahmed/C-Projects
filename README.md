# 💻 C-Projects

Welcome to the **C-Projects** repository! This repository contains a collection of practical system programming, networking, and utility tool projects written in C (with a touch of Assembly). 

These tools are designed to explore low-level operating system concepts, memory manipulation, and network communication.

## 🗂️ Project Directory

Click on any of the project links below to navigate to its source code and explore how it works under the hood.

| Project Name | Description | Link |
| :--- | :--- | :--- |
| **Raw Keylogger** | Captures, records, and logs keystrokes directly from the system's input devices. | [📁 View Project](./Raw%20Keylogger) |
| **hex-dump** | A utility program that reads binary/text file data and outputs it in a formatted hexadecimal and ASCII view. | [📁 View Project](./hex-dump) |
| **ls-l** | A custom implementation of the standard Linux `ls -l` command to display detailed file, directory, and permission information. | [📁 View Project](./ls-l) |
| **printf in asm** | A low-level implementation of the standard C `printf` formatting function written purely in Assembly language. | [📁 View Project](./printf%20in%20asm) |
| **server** | A foundational IPv4 TCP socket server that establishes a connection, listens for clients, and handles basic network responses. | [📁 View Project](./server) |

---

## 🚀 Getting Started

### Prerequisites
To compile and run these programs, you will generally need a Unix-like environment (Linux or macOS) and the following tools:
*   **GCC** (GNU Compiler Collection) for compiling C code.
*   **NASM** (or a similar assembler) for compiling the Assembly code.
*   **Make** (optional, if makefiles are provided in the subdirectories).

### Basic Compilation
You can compile most of the C projects using `gcc`. Navigate into the project folder of your choice and compile the source file. 

For example, to run the server project:

```bash
# Navigate to the folder
cd server

# Compile the C file
gcc server.c -o server

# Run the executable
./server
