*This project has been created as part of the 42 curriculum by mohanegg.*

# ft_printf

## Description

`ft_printf` is a 42 School project that consists of recreating the behavior of the standard C `printf()` function.

The goal is to understand variadic functions in C and implement formatted output using `write()`, without relying on the original `printf()` implementation.

The project handles a format string, identifies conversion specifiers, retrieves the corresponding arguments, and prints their values using dedicated helper functions.

## Supported Conversions

| Conversion | Description |
|---|---|
| `%c` | Prints a single character |
| `%s` | Prints a string |
| `%p` | Prints a pointer address |
| `%d` | Prints a signed decimal integer |
| `%i` | Prints an integer in decimal notation |
| `%u` | Prints an unsigned decimal integer |
| `%x` | Prints a hexadecimal number in lowercase |
| `%X` | Prints a hexadecimal number in uppercase |
| `%%` | Prints a percent sign |

## Algorithm and Data Structure

### 1. Format Parsing

The main function, `ft_printf()`, processes the format string sequentially, one character at a time.

It maintains an index that tracks the current position in the format string.

- If the current character is not `%`, it is printed directly.
- If the current character is `%`, the next character is checked to identify the conversion specifier.
- The corresponding argument is retrieved and passed to the appropriate handler.

### 2. Variadic Argument Management

The project uses `va_list` to manage the variable number of arguments.

The following macros are used:

- `va_start`: Initializes access to the variadic arguments.
- `va_arg`: Retrieves the next argument with its expected type.
- `va_end`: Ends the variadic argument processing.

Each conversion retrieves its argument using the correct C type.

### 3. Conversion Handling

The conversion handler is divided into smaller functions according to the argument type:

- Text handler: `%c`, `%s`, and `%%`.
- Number handler: `%d`, `%i`, and `%u`.
- Hexadecimal and pointer handler: `%x`, `%X`, and `%p`.

This separation keeps the code modular and makes each conversion easier to understand and maintain.

### 4. Recursive Number Conversion

Recursive functions are used to print decimal and hexadecimal numbers.

For decimal numbers, the algorithm divides the number by 10 until it reaches a single digit. It then prints the digits while the recursive calls return.

For hexadecimal numbers, the same approach is used with base 16. A character lookup table is used to select the correct hexadecimal digit.

Signed decimal numbers are handled separately to print the negative sign. The minimum integer value is handled as a special case to avoid signed integer overflow when negating it.

### 5. Data Structures and State Management

The implementation does not require custom linked lists, trees, or other complex data structures.

It relies on:

- `va_list`: Compiler-provided type used to access variadic arguments.
- `size_t`: Tracks the current position in the format string.
- Integer counters: Track the number of characters successfully printed.
- Helper functions: Separate parsing, dispatching, and conversion responsibilities.

The format index is passed by address to helper functions so they can update the original position in the format string.

This approach keeps the implementation simple and avoids unnecessary memory allocation.

### 6. Error Handling

The output functions return the number of characters written or `-1` when a write operation fails.

Errors are propagated through the helper functions to `ft_printf()`, which stops processing and returns `-1`.

## Instructions

### Compilation

Clone the repository:

```bash
git clone <your-repository-url>
cd ft_printf
```

Build the static library:

```bash
make
```

This generates:

```text
libftprintf.a
```

Available Makefile rules:

| Command | Description |
|---|---|
| `make` | Compiles the library |
| `make clean` | Removes object files |
| `make fclean` | Removes object files and the library |
| `make re` | Rebuilds the library |

### Usage

Include the project header:

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello, %s!\n", "42");
    ft_printf("Number: %d\n", 42);
    ft_printf("Hexadecimal: %x\n", 255);
    return (0);
}
```

Compile your program with the library:

```bash
cc -Wall -Wextra -Werror main.c libftprintf.a -o program
```

Execute:

```bash
./program
```

## Resources

### Documentation and References

- [C Documentation - cppreference](https://en.cppreference.com/w/c)
- [Variadic Functions in C - cppreference](https://en.cppreference.com/w/c/variadic)
- [42 School](https://42.fr/)

### AI Usage

AI tools, specifically ChatGPT, were used as a learning and development assistant during this project.

They were used for:

- Explaining variadic functions, `va_list`, `va_start`, `va_arg`, and `va_end`.
- Understanding pointers, recursion, and C concepts.
- Discussing the project architecture and breaking the implementation into helper functions.
- Reviewing code, identifying bugs, and understanding compiler and linker errors.
- Preparing edge-case tests and comparing the implementation's output and return values with the standard `printf()`.
- Helping draft and organize this README.

AI-generated suggestions were reviewed, adapted, and tested during development. The purpose was to understand the implementation and be able to explain the code independently.

## Project Structure

```text
ft_printf/
├── ft_printf.h
├── ft_printf.c
├── ft_printf_format.c
├── ft_putchar.c
├── ft_putstr.c
├── ft_putnbr.c
├── ft_put_unsigned.c
├── ft_put_hex.c
├── ft_put_pointer.c
├── Makefile
└── README.md
```

---

**Project:** ft_printf  
**School:** 42 Network / 1337  
**Language:** C