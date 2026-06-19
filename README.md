*This project has been created as part of the 42 curriculum by emda-sil, raferrei.*

# **Push_swap**

## Description

`push_swap` is a 42 algorithm project whose goal is to sort a list of integers using only two stacks, named `a` and `b`, and a limited set operations. It is focussed on algorithm optimization and complexity.

The initial stack `a` contains the numbers in the order received, while stack `b` starts empty. At the end, stack `a` must be sorted in ascending order and stack `b` must be empty.

**There are 4 sorting strategies:**
- `Simple`: Insertion-based adaptation - **O(n²)**

- `Medium`: Chunk-Based Sorting - **O(n√n)**

- `Complex`: Radix Sort adaptation - **O(nlogn)**

- `Adaptive Strategy`

**Allowed operations:**

| Operation | Description |
|---|---|
| `sa` | **Swap a -** Swap the first two elements at the top of stack a. Do nothing if there is only one or no elements.|
| `sb` | **Swap b -** Swap the first two elements at the top of stack b. Do nothing if there is only one or no elements.|
| `ss` | **Swap -** Execute `sa` and `sb` at the same time |
| `pa` | **Push a -** Take the first element at the top of b and put it at the top of a. Do nothing if b is empty. |
| `pb` | **Push b -** Take the first element at the top of a and put it at the top of b. Do nothing if a is empty. |
| `ra` | **Rotate a -** Shift up all elements of stack a by one. The first element becomes the last one. |
| `rb` | **Rotate b -** Shift up all elements of stack b by one. The first element becomes the last one. |
| `rr` | **Rotate -** `ra` and `rb` at the same time. |
| `rra` | **Reverse rotate a -** Shift down all elements of stack a by one. The last element becomes the first one. |
| `rrb` | **Reverse rotate b -** Shift down all elements of stack b by one. The last element becomes the first one. |
| `rrr` | **Reverse rotate -** Execute `rra` and `rrb` at the same time |

This implementation also includes several selectable strategies and a benchmark mode that prints extra information about the sorting process.

## Instructions

### Compilation

Compile the main program with:

```bash
make
```

Clean object files:

```bash
make clean
```

Remove object files and binaries:

```bash
make fclean
```

Recompile from scratch:

```bash
make re
```

### Execution

Run `push_swap` with a list of integers:

```bash
./push_swap 3 2 1
```

Example output:

```bash
sa
rra
```

The program accepts integers either as separate arguments or inside quoted strings:

```bash
./push_swap 4 67 3 87 23
./push_swap "4 67 3 87 23"
```

Invalid input prints `Error` and exits. Invalid input includes duplicated numbers, non-numeric values, numbers outside the `int` range, empty arguments, or invalid flags.

### Strategy flags

By default, the program uses the adaptive strategy.

You can force a specific strategy with one of these flags:

```bash
./push_swap --simple 5 4 3 2 1
./push_swap --medium 5 4 3 2 1
./push_swap --complex 5 4 3 2 1
./push_swap --adaptive 5 4 3 2 1
```

Only one strategy flag can be used at a time.

### Benchmark mode

Use `--bench` to display extra information on `stderr` after the operations:

```bash
./push_swap --bench --adaptive 3 2 1
```

Benchmark mode prints:

- disorder percentage;
- selected strategy;
- theoretical complexity;
- total number of operations;
- operation count by instruction.

Example:

```text
[bench] disorder: 100.00%
[bench] strategy: Adaptive / O(n log n)
[bench] total_ops: 2
[bench] ops: sa: 1 sb: 0 ss: 0 pa: 0 pb: 0 ra: 0 rb: 0 rr: 0 rra: 1 rrb: 0 rrr: 0
```

### Checker bonus

The repository contains source files for a bonus checker in `checker_files/`.

The intended compilation command is:

```bash
make bonus
```

The checker reads operations from standard input and prints:

- `OK` if the operations sort stack `a` and leave stack `b` empty;
- `KO` otherwise;
- `Error` for invalid input or invalid instructions.

Example intended usage:

```bash
ARG="3 2 1"
./push_swap $ARG | ./checker $ARG
```

## Project structure

```text
.
├── algorithm/       Sorting strategies
├── bench/           Benchmark and statistics output
├── checker_files/   Bonus checker source files
├── includes/        Header files
├── libft/           Custom 42 C library
├── operations/      Stack operations: swap, push, rotate, reverse rotate
├── parsers/         Input parsing, flag parsing and validation
├── src/             Main program
├── utils/           Stack utilities and algorithm helpers
└── Makefile
```

## Algorithms

### Simple strategy — insertion-based sorting, `O(n²)`

The simple strategy keeps three elements in stack `a` and pushes the rest to stack `b`. After sorting the three remaining elements, it repeatedly chooses the best element from `b` to insert back into `a`.

For each value in `b`, the algorithm calculates:

- the position where it should be inserted in `a`;
- the cost of rotating `a` to that position;
- the cost of rotating `b` to bring that value to the top;
- the combined cost of both movements.

The cheapest candidate is moved first. At the end, the minimum value is rotated to the top of stack `a`.

The initial distribution emits at most `O(n)` pushes. During reconstruction,
at most `n` values are inserted and each insertion emits at most `O(n)`
rotations plus one push. Therefore, the generated operation count is bounded
by `O(n²)`. The algorithm reuses the existing stack nodes and requires
`O(1)` auxiliary space.

### Medium strategy — chunk sorting, approximately `O(n√n)`

The medium strategy converts the stack into a sorted array and uses it to define value ranges, or chunks. The chunk size is based on the square root of the input size, with a larger chunk size for inputs above 100 numbers.

The algorithm works in two main phases:

1. Push values from `a` to `b` when they fall inside the current chunk limit.
2. Rebuild `a` by repeatedly moving the maximum value in `b` to the top and pushing it back to `a`.

With a chunk size proportional to `√n`, there are `O(√n)` chunks. Each
chunk requires at most `O(n)` rotations and pushes, so the generated
operation count is bounded by `O(n√n)`. The sorted auxiliary array requires
`O(n)` space.

### Complex strategy — binary radix sort by rank, `O(n log n)`

The complex strategy uses a binary radix sort adapted to the two-stack rules of `push_swap`.

Because the original numbers can be negative or very large, the algorithm first works with ranks. A sorted array is created, and each value receives a rank according to its position in that sorted array. For example, the smallest value has rank `0`, the next has rank `1`, and so on.

Then the algorithm processes each bit of the rank:

1. If the current bit is `0`, the value is pushed to stack `b` with `pb`.
2. If the current bit is `1`, stack `a` is rotated with `ra`.
3. After each bit pass, all values in `b` are pushed back to `a` with `pa`.

There are `ceil(log2(n))` bit passes. Each pass emits at most `n`
distribution operations and at most `n` pushes back to stack `a`.
Consequently, the operation count is bounded by `O(n log n)`. Ranking makes
the algorithm independent from the original integer range and requires an
`O(n)` auxiliary array.

### Adaptive strategy

The adaptive strategy is the default mode. It measures disorder before
executing any Push_swap operation by dividing the number of inverted pairs by
the total number of pairs.

It selects the mandatory complexity regime using these thresholds:

- `disorder < 0.2`: Simple, bounded by `O(n²)` operations;
- `0.2 <= disorder < 0.5`: Medium, bounded by `O(n√n)` operations;
- `disorder >= 0.5`: Complex, bounded by `O(n log n)` operations.

Low-disorder inputs use the insertion-based method because its direct
rotations and insertions are suitable for inputs with few inversions.
Medium-disorder inputs use chunk partitioning to limit searches to ranges.
High-disorder inputs use radix sorting because every bit pass has a predictable
linear operation bound.

The disorder calculation emits no Push_swap operations and uses `O(1)`
auxiliary space. Adaptive uses `O(n)` auxiliary space in the worst case,
according to the selected internal method.

## Technical choices

- The stacks are implemented as singly linked lists.
- The parser accepts both quoted and unquoted input.
- The parser rejects duplicate values and values outside the `int` range.
- The project uses `libft` for common utility functions.
- Benchmark information is printed to `stderr` so it does not interfere with the operation list printed to `stdout`.

## Contributions

| NAME | CONTRIBUTIONS |
|---|---|
| `Emda-sil` | Parsing, Benchmark system, Algorithm implementation - medium and complex |
| `Raferrei` | Stack operations, Algorithm implementation - Simple, Bonus |
| `Both` | Error handling |

## Resources

https://www.geeksforgeeks.org/
https://42-cursus.gitbook.io/guide/2-rank-02/push_swap
Book: Entendendo algoritmos "Aditya Y.Bhargava" - novatec

### Use of AI

AI was used as a learning and support tool to draft and review documentation,
suggest test cases, and identify possible subject-compliance issues in the
parser, algorithms, benchmark flow, Makefile, and bonus checker.

All findings, tests, debugging decisions, and final implementation choices were
reviewed and validated by the project authors.
