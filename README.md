# push_swap

Sorts a stack of integers using two stacks and a limited instruction set, with as few moves as possible.

---

## Build & run

```bash
cc -Wall -Wextra -Werror src/*.c -Iincludes -o push_swap

./push_swap 3 2 1 0
./push_swap "2 1 3"
```

To validate with a checker:
```bash
ARG="3 2 1 0"
./push_swap $ARG | ./other/pro_checker $ARG
```

**Instruction set:** `sa` `sb` `ss` `pa` `pb` `ra` `rb` `rr` `rra` `rrb` `rrr`

---

## Sorting strategies

### Small inputs (≤ 5 elements)
Hardcoded optimal sequences. For 3 elements, at most 2 moves. For 5, a fixed decision tree keeps it under 12.

### Larger inputs — chunk-based with cost optimization

Numbers are pushed from stack A to stack B in sorted chunks (ranges). Rather than arbitrary chunking, each chunk targets a range of values so that B ends up roughly sorted in reverse — ready to be pushed back to A.

Before each push, the algorithm calculates the **cost** of moving every candidate node to the top of its stack, factoring in both A and B rotations (using `ra`/`rra` and `rb`/`rrb` to find the cheaper direction). It then executes the move with the lowest total cost. Where possible, simultaneous rotations (`rr`, `rrr`) are used to reduce the instruction count further.

This greedy cost model consistently sorts 100 numbers in under 700 moves and 500 numbers in under 5500.

### LIS (Longest Increasing Subsequence)
For pre-sorted or nearly-sorted inputs, a LIS pass identifies the largest already-ordered subset and keeps it in place, only moving elements that are out of order. This avoids unnecessary operations when the input has significant structure.

---

## Testing

```bash
# Run the included tester
bash other/Push-Swap-Tester/push_swap_test_linux.sh

# With custom size and iterations
bash other/Push-Swap-Tester/push_swap_test_linux.sh 250 250

# Benchmark mode
bash other/Push-Swap-Tester/push_swap_test_linux.sh -b 100 100
```

A visualizer is available in `visualizer/` — see `visualizer/README.md` for build instructions.

---

## Notes

- Input is validated for syntax errors, integer overflow, and duplicates.
- Handles both space-separated string and multi-argument input formats.
