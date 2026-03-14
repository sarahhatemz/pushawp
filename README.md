*This project has been created as part of the 42 curriculum by salzghou.*

# push_swap

## Description

**push_swap** is a sorting algorithm project from the 42 curriculum. The goal is to sort a stack of integers using two stacks (`a` and `b`) and a limited set of operations, producing the **shortest possible sequence of instructions**.

The program receives a list of integers as arguments, with the first argument at the top of stack `a`, and outputs the sequence of operations needed to sort stack `a` in ascending order (smallest at the top).

### Available operations

| Operation | Description |
|-----------|-------------|
| `sa` | Swap the top 2 elements of stack a |
| `sb` | Swap the top 2 elements of stack b |
| `ss` | `sa` and `sb` simultaneously |
| `pa` | Push top of stack b onto stack a |
| `pb` | Push top of stack a onto stack b |
| `ra` | Rotate stack a upward (first becomes last) |
| `rb` | Rotate stack b upward (first becomes last) |
| `rr` | `ra` and `rb` simultaneously |
| `rra` | Reverse rotate stack a (last becomes first) |
| `rrb` | Reverse rotate stack b (last becomes first) |
| `rrr` | `rra` and `rrb` simultaneously |

### Algorithm

- **2–3 elements**: hardcoded optimal sequences
- **4–5 elements**: push minimum(s) to b, sort remaining, push back
- **6+ elements**: **Radix sort** on normalized ranks — each number is assigned a rank (0 to n-1), then sorted bit by bit using `pb`/`ra`/`pa`

### Performance

| Input size | Operations |
|------------|------------|
| 100 numbers | < 700 |
| 500 numbers | < 5500 |

---

## Instructions

### Compilation

```bash
make        # builds push_swap
make bonus  # builds checker (bonus)
make clean  # removes object files
make fclean # removes object files and binaries
make re     # fclean + make
```

### Usage

```bash
./push_swap 3 1 2
./push_swap "3 1 2"
./push_swap 42 -7 15 0 3
```

### Checking correctness

Use the provided `checker_linux` binary (or your own `checker` from the bonus):

```bash
ARG="4 67 3 87 23"
./push_swap $ARG | ./checker_linux $ARG
# Output: OK
```

### Error handling

The program prints `Error` to stderr and exits on:
- Non-integer arguments
- Values exceeding `INT_MAX` / `INT_MIN`
- Duplicate values

```bash
./push_swap 1 2 one   # Error
./push_swap 1 1 2     # Error
```

---

## Resources

### References

- [Sorting algorithms — Wikipedia](https://en.wikipedia.org/wiki/Sorting_algorithm)
- [Radix sort — Wikipedia](https://en.wikipedia.org/wiki/Radix_sort)
- [Push_swap — the least number of moves (medium article)](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a)
- [Visualizer for push_swap](https://github.com/o-reo/push_swap_visualizer)

### AI usage

Improving README documentation

Understanding algorithm optimization approaches

Reviewing explanations of sorting strategies

All implementation decisions, algorithms, and code development were written and understood by the project author.



All AI-generated suggestions were reviewed, tested, and understood before being integrated into the project.