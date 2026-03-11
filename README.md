*This project has been created as part of the 42 curriculum by salzghou.

# push_swap

## Description

**push_swap** is a sorting algorithm project from the 42 curriculum.
The goal is to sort a list of integers using **two stacks** and a **limited set of operations**, while producing the **smallest possible number of instructions**.

The program receives integers as arguments and prints a sequence of stack operations that sorts the numbers in **ascending order**.

This project focuses on:

* algorithm design
* optimization
* data structures
* complexity analysis
* memory management in C

The challenge is not only to sort the numbers, but to do so using the **fewest operations possible**.

---

# How It Works

Two stacks are used:

* **Stack A** – initially contains all numbers.
* **Stack B** – starts empty.

The program manipulates these stacks using a limited set of operations until **Stack A is sorted**.

---

# Allowed Operations

| Instruction | Description                                 |
| ----------- | ------------------------------------------- |
| `sa`        | Swap the first two elements of stack A      |
| `sb`        | Swap the first two elements of stack B      |
| `ss`        | Execute `sa` and `sb` simultaneously        |
| `pa`        | Push the top element of B to A              |
| `pb`        | Push the top element of A to B              |
| `ra`        | Rotate stack A (first element becomes last) |
| `rb`        | Rotate stack B                              |
| `rr`        | Execute `ra` and `rb` simultaneously        |
| `rra`       | Reverse rotate stack A                      |
| `rrb`       | Reverse rotate stack B                      |
| `rrr`       | Execute `rra` and `rrb` simultaneously      |

---

# Algorithm Strategy

The project uses different strategies depending on the input size.

### Small Inputs (2–5 numbers)

Hard-coded sorting strategies are used:

* 2 numbers → simple swap
* 3 numbers → minimal case analysis
* 4–5 numbers → push smallest numbers to stack B, sort remaining values, then push them back.

### Large Inputs

For larger datasets the program:

1. **Normalizes values using ranking**
2. **Applies a radix sorting strategy**

Radix sorting works by sorting numbers bit-by-bit using stack operations, ensuring consistent and predictable performance.

---

# Compilation

Compile the project using:

```bash
make
```

This will create the executable:

```bash
./push_swap
```

Clean object files:

```bash
make clean
```

Clean everything:

```bash
make fclean
```

Recompile:

```bash
make re
```

---

# Usage

Example:

```bash
./push_swap 2 1 3 6 5 8
```

Output:

```text
sa
pb
pb
pb
sa
pa
pa
pa
```

Each line represents an operation applied to the stacks.

---

# Error Handling

The program prints:

```
Error
```

when encountering invalid input, such as:

* non-numeric values
* duplicate numbers
* numbers outside the integer range
* invalid argument formatting

---

# Performance Goals

The project is evaluated based on the number of operations required to sort the stacks.

Target benchmarks:

| Input Size  | Maximum Operations |
| ----------- | ------------------ |
| 100 numbers | < 700 operations   |
| 500 numbers | < 5500 operations  |

Efficient algorithm design is essential to meet these limits.

---

# Project Structure

Example structure of the project:

```
push_swap/
│
├── Makefile
├── push_swap.c
├── parsing/
├── operations/
├── sorting/
├── stack/
└── includes/
```

---

# Resources

Useful materials for this project:

* Stack data structures
* Sorting algorithms
* Radix sort algorithm
* Algorithmic complexity (Big-O notation)

Recommended reading:

* https://en.wikipedia.org/wiki/Radix_sort
* https://visualgo.net/en/sorting

---

# AI Usage

AI tools were used for:

* understanding algorithm strategies
* reviewing code structure
* improving documentation clarity

All code and logic were reviewed and understood before being integrated into the project.
