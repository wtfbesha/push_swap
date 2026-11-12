*This project has been created as part of the 42 curriculum by neric, mtorfs.*

# push_swap

<p align="center">
  <strong>Because swap_push doesn't feel as natural.</strong><br>
  Two stacks. A limited set of instructions. One sorted sequence.
</p>

## Description

**push_swap** is a sorting project written in C. It takes a list of distinct integers and prints a sequence of stack operations that sorts them in ascending order, with the smallest value at the top of Stack A.

The project explores algorithmic complexity in a restricted environment: instead of sorting an array directly, the program must work with two stacks and a limited instruction set. It includes three selectable strategies and an adaptive strategy that chooses between them based on the disorder of the input.

The goal is to produce an efficient operation sequence. The program aims to reduce the number of operations; it does not claim to find the globally shortest possible sequence for every input.

## Contents

- [How it works](#how-it-works)
- [Sorting strategies](#sorting-strategies)
- [Instructions](#instructions)
- [Operations](#operations)
- [Benchmark mode](#benchmark-mode)
- [Performance targets](#performance-targets)
- [Team and contributions](#team-and-contributions)
- [Resources](#resources)

## How it works

- **Stack A** starts with the input numbers. The first number supplied is at the top.
- **Stack B** starts empty.
- The program analyzes the input and selects the requested sorting strategy.
- It prints the operations needed to sort Stack A in ascending order.
- Each operation is printed on its own line.

The operation sequence is written to **standard output**. When benchmark mode is enabled, benchmark information is written to **standard error**, keeping the operation stream usable with a checker.

### Input validation

Input values must be valid, distinct integers within the range of a C `int`.

The program reports `Error` followed by a newline on standard error for invalid input, including non-integer arguments, values outside the valid integer range, or duplicates. If no arguments are supplied, the program prints nothing.

## Sorting strategies

| Flag | Strategy | Operation-count complexity |
| --- | --- | --- |
| `--simple` | Bubble sort adaptation | `O(n²)` |
| `--medium` | Block-based partitioning | `O(n√n)` |
| `--complex` | Merge sort using two stacks | `O(n log n)` |
| `--adaptive` | Selects a strategy based on input disorder | Depends on the selected strategy |

The complexity classes above refer to the number of **Push_swap instructions generated**, as required by the project subject.

### Disorder metric

Before making any moves, the program measures how far the input is from being sorted.

An inversion is a pair of values where a larger number appears before a smaller one. For an input of `n` distinct values:

```text
inversions = number of pairs (i, j) where i < j and a[i] > a[j]
total_pairs = n × (n - 1) / 2
disorder = inversions / total_pairs
```

For inputs with fewer than two values, disorder is defined as `0`.

The disorder value ranges from `0` to `1`:

- `0` means the input is already sorted.
- `1` means the input is in reverse order.
- Values between `0` and `1` indicate intermediate levels of disorder.

Calculating this metric requires `O(n²)` pair comparisons and `O(1)` extra space. These comparisons do not generate Push_swap instructions, so they are separate from the operation-count complexity classes below.

### Simple: bubble sort adaptation

The simple strategy uses repeated passes to identify and correct local inversions in the stack. It is a straightforward baseline strategy and is most appropriate for smaller or nearly sorted inputs.

In the operation-count model, up to `n` passes may process up to `n` values each, giving a worst-case target of **`O(n²)` operations**.

### Medium: block-based partitioning

The medium strategy divides values into approximately `√n` blocks. It moves values between the stacks by block or range, reducing the amount of searching needed to organize the input.

If processing a value requires up to `O(√n)` block-related work, processing all `n` values gives a target of **`O(n√n)` operations**.

### Complex: merge sort using two stacks

The complex strategy applies a merge-sort approach using Stacks A and B to move and order values. Each merge level processes the values, and the number of levels grows logarithmically with the input size.

With `O(n)` work per level and `O(log n)` levels, the operation-count target is **`O(n log n)`**.

### Adaptive strategy

Adaptive mode measures the disorder before sorting and chooses a strategy using these thresholds:

| Disorder | Selected strategy | Operation-count target |
| --- | --- | --- |
| `disorder < 0.2` | Simple | `O(n²)` |
| `0.2 ≤ disorder < 0.5` | Medium | `O(n√n)` |
| `disorder ≥ 0.5` | Complex | `O(n log n)` |

The thresholds use normalized disorder, so they do not depend on the number of input values. They are practical cutoffs for choosing between a simple method for nearly ordered inputs, a block-based method for moderate disorder, and a more scalable method for highly disordered inputs. They are heuristics, not a guarantee that the selected strategy will produce the fewest possible instructions for every input.

Adaptive mode has the operation-count bound of the strategy selected for the input’s disorder range. The disorder calculation itself uses `O(n²)` CPU comparisons, but emits no stack operations.

The stacks store the input values across the sorting process, requiring `O(n)` storage. The program’s total auxiliary storage is also `O(n)` or less, depending on the data structures used by the implementation.

## Instructions

### Requirements

- Git
- `make`
- A C compiler

### Clone and build

```bash
git clone git@github.com:wtfbesha/push_swap.git
cd push_swap
make
```

The build creates the `push_swap` executable.

### Run the program

```bash
./push_swap [--simple | --medium | --complex | --adaptive] [--bench] <integer> [<integer> ...]
```

If no strategy flag is supplied, the program uses adaptive mode.

Examples:

```bash
# Use adaptive mode explicitly
./push_swap --adaptive 42 7 19 3 28

# Use a specific strategy
./push_swap --simple 42 7 19 3 28
./push_swap --medium 42 7 19 3 28
./push_swap --complex 42 7 19 3 28

# Use adaptive mode by default
./push_swap 42 7 19 3 28
```

### Makefile commands

| Command | Description |
| --- | --- |
| `make` | Build the project. |
| `make clean` | Remove intermediate build files. |
| `make fclean` | Remove build files and the executable. |
| `make re` | Clean and rebuild the project. |

## Operations

The program uses the standard Push_swap instruction set. Each printed instruction counts as one operation.

| Instruction | Effect |
| --- | --- |
| `sa` | Swap the top two values of Stack A. |
| `sb` | Swap the top two values of Stack B. |
| `ss` | Swap the top two values of both stacks. |
| `pa` | Push the top value of Stack B onto Stack A. |
| `pb` | Push the top value of Stack A onto Stack B. |
| `ra` | Rotate Stack A upward: its first value moves to the bottom. |
| `rb` | Rotate Stack B upward: its first value moves to the bottom. |
| `rr` | Rotate both stacks upward. |
| `rra` | Reverse-rotate Stack A: its last value moves to the top. |
| `rrb` | Reverse-rotate Stack B: its last value moves to the top. |
| `rrr` | Reverse-rotate both stacks. |

## Benchmark mode

Add `--bench` to print benchmark information after sorting. The report includes:

- Input disorder as a percentage, formatted to two decimal places.
- The name of the strategy used and its complexity class.
- The total number of operations.
- The count of each operation type: `sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, and `rrr`.

Benchmark information is written to **standard error** and appears only when `--bench` is present. Sorting operations remain on **standard output**.

```bash
./push_swap --adaptive --bench 4 67 3 87 23
```

To save the two output streams separately:

```bash
./push_swap --adaptive --bench 4 67 3 87 23 > operations.txt 2> benchmark.txt
```

To count the operations without benchmark mode:

```bash
./push_swap --adaptive 4 67 3 87 23 | wc -l
```

If an external checker is available, use it to verify the generated sequence:

```bash
ARG="4 67 3 87 23"
./push_swap --complex $ARG | ./checker_linux $ARG
```

## Performance targets

The project subject gives the following operation-count targets for random inputs:

| Input size | Pass target | Good target | Excellent target |
| --- | ---: | ---: | ---: |
| 100 numbers | Fewer than 2,000 operations | Fewer than 1,500 operations | Fewer than 700 operations |
| 500 numbers | Fewer than 12,000 operations | Fewer than 8,000 operations | Fewer than 5,500 operations |

Actual operation counts depend on the input order and the selected strategy.

## Team and contributions

This is a group project completed by two learners.

| Learner | Contributions |
| --- | --- |
| `neric` | `[Add this learner’s specific contributions, such as algorithms, parsing, testing, or documentation.]` |
| `mtorfs` | `[Add this learner’s specific contributions, such as algorithms, parsing, testing, or documentation.]` |

Replace the bracketed text with an accurate description of each learner’s work before submitting.

## Resources

- 42 **push_swap** project subject, version 1.2.
- [Merge sort](https://en.wikipedia.org/wiki/Merge_sort)
- [Sorting algorithms](https://en.wikipedia.org/wiki/Sorting_algorithm)
- [Bubble sort in C](https://www.geeksforgeeks.org/c/c-bubble-sort/)
- [Algorithmic efficiency](https://en.wikipedia.org/wiki/Algorithmic_efficiency)

### AI use

AI assistance was used to draft and organize this README, including its explanations of the disorder metric, strategy choices, complexity model, and command-line usage. AI was not used in this documentation exchange to write the project’s C implementation. The team should verify that every description in this README matches the code. Any other AI use during the project should also be documented here.
