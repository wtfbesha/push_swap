*This project has been created as part of the 42 curriculum by neric and mtorfs.*

## description
The push_swap project is made to not only sort numbers but also display how the algorithms sorted them step by step. It can be ran with the flags to choose what algorithm does the sorting (look at instructions) or use the adaptive flag what calculates the best choice out of the 3 options.

## How it works

- **Stack A** starts with the input numbers.
- **Stack B** starts empty.
- The program outputs instructions to sort the numbers into ascending order in Stack A.
- Each instruction is printed on its own line.

The input should contain valid, distinct integers.
## Sorting strategies

| Flag | Strategy | Complexity |
| --- | --- | --- |
| `--simple` | Bubble sort adaptation | `O(n²)` |
| `--medium` | Block-based partitioning | `O(n√n)` |
| `--complex` | Merge sort using two stacks | `O(n log n)` |
| `--adaptive` | Selects the estimated best strategy for the input | Depends on the selected strategy |

The complexity figures describe how each algorithm scales as the input grows. The number of stack operations can vary depending on the input and strategy.

## instructions and requirements

- git 
- make
- c compiler
```bash
git clone git@github.com:wtfbesha/push_swap.git
cd push_swap
make
```
template

```bash
./push_swap <flag> <number> [<number> ...]
```
choose a strategy
```bash
./push_swap --simple 42 7 19 3 28
./push_swap --medium 42 7 19 3 28
./push_swap --complex 42 7 19 3 28
```
or let adaptive choose
```bash
./push_swap --adaptive 42 7 19 3 28
```
Clean and Rebuild

```bash
make fclean
make re
```

## Resourcess
https://en.wikipedia.org/wiki/Merge_sort
https://en.wikipedia.org/wiki/Sorting_algorithm
https://www.geeksforgeeks.org/c/c-bubble-sort/
https://en.wikipedia.org/wiki/Algorithmic_efficiency

