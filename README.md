# push_swap

A sorting algorithm project written in C that sorts a stack of integers using a limited set of operations, with the goal of using the fewest moves possible.

---

## What it does

`push_swap` takes a list of integers as arguments and outputs the sequence of operations needed to sort them in ascending order using two stacks: **stack A** and **stack B**.

---

## Usage

```bash
make
./push_swap 3 1 4 1 5 9 2 6
```

You can also pass numbers as a single quoted string:
```bash
./push_swap "3 1 4 1 5 9 2 6"
```

To verify the output is correct using the provided checker:
```bash
./push_swap 3 1 4 1 5 9 2 6 | ./checker_linux 3 1 4 1 5 9 2 6
```

---

## Allowed Operations

| Operation | Description |
|-----------|-------------|
| `sa` | Swap the first 2 elements of stack A |
| `sb` | Swap the first 2 elements of stack B |
| `ss` | `sa` and `sb` simultaneously |
| `pa` | Push top of stack B onto stack A |
| `pb` | Push top of stack A onto stack B |
| `ra` | Rotate stack A up (first becomes last) |
| `rb` | Rotate stack B up (first becomes last) |
| `rr` | `ra` and `rb` simultaneously |
| `rra` | Reverse rotate stack A (last becomes first) |
| `rrb` | Reverse rotate stack B (last becomes first) |
| `rrr` | `rra` and `rrb` simultaneously |

---

## Algorithm

- **2 numbers** — single swap if needed
- **3 numbers** — hardcoded optimal solution (max 2 ops)
- **4 numbers** — move minimum to B, sort 3, push back
- **5 numbers** — move 2 minimums to B, sort 3, push back
- **6+ numbers** — **Radix sort** using binary rank assignment

---

## Error Handling

The program writes `Error` to stderr and exits with code 1 for:
- Non-integer arguments (e.g. `"abc"`)
- Integer overflow (outside `INT_MIN` / `INT_MAX`)
- Duplicate values
- Empty string arguments

---

## Project Structure

```
push_swap/
├── main.c              # Entry point
├── push_swap.h         # Header / structs / prototypes
├── stack.c             # Stack creation and memory management
├── sort.c              # Sorting algorithms (2/3/4/5/radix)
├── ops.c               # sa, sb, ss, pa, pb
├── ops2.c              # ra, rb, rr
├── reverse_rotate.c    # rra, rrb, rrr
├── parsing.c           # Tokenization and input splitting
├── parsing2.c          # Number validation and conversion
├── parsing3.c          # Top-level parse entry point
├── Makefile
└── libft/              # Custom C library
```

---

## Makefile

```bash
make        # Build push_swap
make clean  # Remove object files
make fclean # Remove object files and binary
make re     # Full rebuild
```

---

## Requirements

- GCC compiler
- GNU Make
- Linux / macOS