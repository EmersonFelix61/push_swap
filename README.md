*This project has been created as part of the 42 curriculum by emda-sil, raferrei.*

# Push_swap

## Description

`push_swap` is a C sorting project built around two stacks, `a` and `b`, and a
restricted instruction set. Stack `a` initially contains a sequence of unique
signed integers in argument order, with the first value at the top; stack `b`
starts empty. The program must leave `a` sorted in ascending order and `b`
empty while emitting as few valid Push_swap operations as the selected strategy
can produce.

The project focuses on operation-count complexity rather than only the CPU cost
of a conventional sorting algorithm. It contains four runtime-selectable
strategies, an inversion-based disorder metric, an optional benchmark report,
and a bonus `checker` that executes and validates an operation stream.

The generated operations are written exclusively to standard output. Errors
and optional benchmark data are written to standard error, so the operation
stream remains safe to pipe into a checker.

## Allowed operations

| Instruction | Effect |
| --- | --- |
| `sa` | Swap the top two values of `a`; do nothing when fewer than two exist. |
| `sb` | Swap the top two values of `b`; do nothing when fewer than two exist. |
| `ss` | Execute `sa` and `sb` simultaneously. |
| `pa` | Move the top value of `b` to the top of `a`; do nothing if `b` is empty. |
| `pb` | Move the top value of `a` to the top of `b`; do nothing if `a` is empty. |
| `ra` | Rotate `a` upward: its top value becomes its last value. |
| `rb` | Rotate `b` upward: its top value becomes its last value. |
| `rr` | Execute `ra` and `rb` simultaneously. |
| `rra` | Reverse-rotate `a`: its last value becomes its top value. |
| `rrb` | Reverse-rotate `b`: its last value becomes its top value. |
| `rrr` | Execute `rra` and `rrb` simultaneously. |

## Instructions

### Requirements and compilation

The project requires a C compiler, `make`, and a POSIX-like environment. The
Makefile compiles with `cc -Wall -Wextra -Werror` and builds the bundled Libft
through its own Makefile.

```sh
make          # build push_swap
make bonus    # build the bonus checker
make clean    # remove object and dependency files
make fclean   # remove generated files and both executables
make re       # perform a clean rebuild of push_swap
```

The primary target does not relink when its inputs have not changed.

### Usage

```text
./push_swap [--simple | --medium | --complex | --adaptive] [--bench] <integers...>
```

Without a strategy selector, `--adaptive` is used. Exactly one strategy
selector may be supplied, and `--bench` may appear at most once.

Values can be passed as separate arguments, inside one quoted, space-separated
argument, or as a mixture of both forms:

```sh
./push_swap 4 67 3 87 23
./push_swap "4 67 3 87 23"
./push_swap --medium "4 67" 3 87 23
```

Force a strategy explicitly:

```sh
./push_swap --simple 5 4 3 2 1
./push_swap --medium 5 4 3 2 1
./push_swap --complex 5 4 3 2 1
./push_swap --adaptive 5 4 3 2 1
```

With no arguments, with one integer, or with an already sorted sequence, the
program emits no operations. Invalid input writes exactly `Error\n` to standard
error. Invalid cases include non-numeric tokens, values outside the signed
32-bit `int` range, duplicate values, empty arguments, unknown or repeated
flags, and multiple strategy selectors.

### Benchmark mode

`--bench` prints a report to standard error after sorting. The report contains:

- disorder as a percentage with two decimal places;
- the selected strategy and the complexity of the method actually used;
- the total number of generated operations;
- the individual count of all eleven operation types.

```sh
./push_swap --bench --adaptive 3 1 2 0 > operations.txt 2> benchmark.txt
```

For this input, `benchmark.txt` contains:

```text
[bench] disorder: 83.33%
[bench] strategy: Adaptive / O(n log n)
[bench] total_ops: 4
[bench] ops: sa: 0 sb: 0 ss: 0 pa: 1 pb: 1 ra: 1 rb: 0 rr: 0 rra: 1 rrb: 0 rrr: 0
```

When adaptive mode is selected, the strategy name remains `Adaptive`; its
reported complexity identifies the internal disorder regime that ran.

### Bonus checker

Build the checker with `make bonus`. It parses the same integer input, reads one
instruction per line from standard input, and prints:

- `OK` when `a` is sorted and `b` is empty;
- `KO` when the valid instruction stream does not reach that state;
- `Error` to standard error for invalid arguments or instructions.

The checker accepts integer arguments only, not Push_swap strategy or benchmark
flags.

```sh
ARG="4 67 3 87 23"
./push_swap --complex $ARG | ./checker $ARG
```

Benchmark data can be saved without contaminating the checker input:

```sh
ARG="4 67 3 87 23"
./push_swap --bench --adaptive $ARG 2> benchmark.txt | ./checker $ARG
```

## Algorithms and design choices

### Disorder metric

Disorder is measured before any Push_swap operation. For every pair of
positions `i < j`, the pair is an inversion when `a[i] > a[j]`:

```text
disorder = inversion_count / (n * (n - 1) / 2)
```

The result lies in `[0, 1]`: `0` is sorted order and `1` is reverse order. A
stack with fewer than two values has disorder `0`. The calculation performs no
Push_swap operations, uses `O(1)` auxiliary space, and takes `O(n²)` host-side
comparison time.

The complexity classes below count generated Push_swap instructions, as
required by the subject. Auxiliary space excludes the linked-list nodes that
store the input itself.

| Strategy | Internal method | Operation upper bound | Auxiliary space |
| --- | --- | --- | --- |
| Simple | Cost-guided insertion | `O(n²)` | `O(1)` |
| Medium | Square-root chunk partitioning | `O(n√n)` | `O(n)` |
| Complex | Binary LSD radix sort over ranks | `O(n log n)` | `O(n)` |
| Adaptive | Selects one of the three methods from disorder | Regime-dependent | `O(n)` worst case |

Inputs of two to five values use short small-stack paths. These optimizations
stay within the upper bound of every selected regime.

### Simple — cost-guided insertion, `O(n²)` operations

The simple strategy pushes values from `a` to `b` until three remain, sorts the
three-value core, and then rebuilds `a`. For every value currently in `b`, it
finds the circular insertion position in `a` and estimates the rotations needed
to bring both the value and its destination to the top. The candidate with the
lowest combined rotation cost is inserted first. Finally, the minimum value is
rotated to the top.

There are at most `O(n)` insertions, and each insertion emits at most `O(n)`
rotations plus one push. The resulting operation bound is therefore `O(n²)`.
No auxiliary array is required. This method is the baseline and is appropriate
for the low-disorder adaptive regime because it can choose direct insertion
positions without running fixed passes over every rank bit.

### Medium — square-root chunks, `O(n√n)` operations

The medium strategy copies the values into an `O(n)` array and heap-sorts that
array to define ordered value ranges. The chunk width is `ceil(√n)` and is
doubled for inputs larger than 100; the asymptotic width remains `Θ(√n)`.

During distribution, values at or below the current chunk limit are pushed to
`b`, while other values rotate through `a`. Once a chunk is complete, the limit
advances. This costs at most `O(n)` operations per chunk across `O(√n)` chunks.
Because later chunks are pushed above earlier chunks in `b`, the current maximum
is confined to the active top band of `Θ(√n)` values during reconstruction.
Moving each maximum to the top and applying `pa` therefore costs `O(√n)` per
value. Both phases are bounded by `O(n√n)` generated operations.

Chunking is used for medium disorder because it avoids the quadratic insertion
regime while retaining value-range locality that is absent from a full radix
pass.

### Complex — binary radix by rank, `O(n log n)` operations

The complex strategy first heap-sorts an auxiliary copy of the values. Each
original value is mapped by binary search to a rank from `0` to `n - 1`, making
the method independent of signs and the magnitude of the original integers.

For each rank bit, from least significant to most significant:

1. emit `pb` when the current bit is `0`;
2. emit `ra` when the current bit is `1`;
3. emit `pa` until all values from `b` return to `a`.

There are `ceil(log2(n))` relevant bits. Each pass emits at most `n`
distribution operations and `n` return pushes, so the operation count is
bounded by `O(n log n)`. The sorted rank array requires `O(n)` auxiliary space.
Its predictable pass cost makes radix sorting suitable for highly disordered
inputs.

### Adaptive — disorder-driven selection

Adaptive mode is the default and uses the thresholds mandated by the subject:

| Measured disorder | Internal strategy | Required operation class |
| --- | --- | --- |
| `disorder < 0.2` | Simple insertion | `O(n²)` |
| `0.2 <= disorder < 0.5` | Medium chunking | `O(n√n)` |
| `disorder >= 0.5` | Complex radix | `O(n log n)` |

The thresholds separate inputs with few inversions, partially mixed inputs,
and inputs with at least half of all pairs inverted. The chosen internal method
then supplies the required upper bound for that regime. The adaptive dispatcher
itself performs no stack operations beyond those emitted by the selected
method. Its worst-case auxiliary space is `O(n)`.

## Performance targets

The subject evaluates random inputs using these operation-count thresholds:

| Input size | Minimum pass | Good | Excellent |
| ---: | ---: | ---: | ---: |
| 100 values | `< 2000` | `< 1500` | `< 700` |
| 500 values | `< 12000` | `< 8000` | `< 5500` |

A GNU/Linux test example is:

```sh
ARG="$(shuf -i 0-9999 -n 100 | tr '\n' ' ')"
./push_swap --adaptive $ARG | wc -l
./push_swap --adaptive $ARG | ./checker $ARG
```

The checker establishes correctness; `wc -l` measures the Push_swap operation
count because every operation occupies exactly one output line.

## Project structure

```text
.
├── algorithm/       simple, medium, complex, adaptive, and tiny-stack logic
├── bench/           operation counters and benchmark formatting
├── checker_files/   bonus checker entry point and instruction dispatcher
├── get_next_line/   line reader used by the checker
├── includes/        project and bonus headers
├── libft/           local C utility library and its Makefile
├── operations/      swap, push, rotate, and reverse-rotate primitives
├── parsers/         argument tokenization, flags, range, and duplicate checks
├── src/             push_swap entry point and strategy dispatch
├── utils/           linked-stack and algorithm helpers
└── Makefile
```

Stacks are singly linked lists. Sorting helpers use the operation wrappers so
that every emitted instruction updates both the stack state and its benchmark
counter consistently.

## Contributions

| Contributor | Main contributions |
| --- | --- |
| `emda-sil` | Input parsing and flags; disorder/adaptive dispatch; medium and complex strategies; benchmark reporting and project integration. |
| `raferrei` | Stack operations and helpers; simple and tiny-stack sorting; bonus checker and Get Next Line integration. |
| Both | Architecture, error handling, integration, testing, review, and resolution of shared implementation issues. |

Both contributors are expected to understand and defend every part of the
project, independently of the ownership summary above.

## Resources

- *Push_swap* subject, version 1.1 — normative project requirements, operation
  model, strategy classes, thresholds, and evaluation targets.
- Thomas H. Cormen, Charles E. Leiserson, Ronald L. Rivest, and Clifford Stein,
  *Introduction to Algorithms*, 4th edition — asymptotic analysis, heaps, radix
  sorting, and correctness arguments.
- Donald E. Knuth, *The Art of Computer Programming, Volume 3: Sorting and
  Searching* — classical analysis of sorting and searching techniques.
- [GNU C Library manual: Memory Allocation](https://www.gnu.org/software/libc/manual/html_node/Memory-Allocation.html)
  — allocation and release semantics used by the stacks and auxiliary arrays.
- [Linux `write(2)` manual](https://man7.org/linux/man-pages/man2/write.2.html)
  and [Linux `read(2)` manual](https://man7.org/linux/man-pages/man2/read.2.html)
  — low-level output and checker input behavior.
- [42School Norminette](https://github.com/42School/norminette) — source-format
  requirements and checker.

### AI usage

AI was used as a support tool during the development of this project, mainly for architecture review, edge case analysis, discussion of algorithmic strategies, bug debugging, benchmark organization, and conceptual validation of the choices made in the code. The final implementation decisions, integration, testing, and adaptation to the subject requirements were made by the project authors.
