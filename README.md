# push_swap

Sorts a stack of integers using two stacks and a limited instruction set, with as few moves as possible.

---

## Build & run

```bash
cc -Wall -Wextra -Werror src/*.c -Iincludes -o push_swap

./push_swap 3 2 1 0
./push_swap "2 1 3"
```

**Instruction set:** `sa` `sb` `ss` `pa` `pb` `ra` `rb` `rr` `rra` `rrb` `rrr`

---

## The problem

You have two stacks, A and B. Stack A starts with an unsorted list of integers. Stack B is empty. The goal is to sort A in ascending order using only the operations above — and as few of them as possible.

| Op | Effect |
|----|--------|
| `sa` / `sb` | Swap the top two elements of A / B |
| `ss` | `sa` and `sb` simultaneously |
| `pa` / `pb` | Push the top of B to A / top of A to B |
| `ra` / `rb` | Rotate A / B upward (top becomes bottom) |
| `rr` | `ra` and `rb` simultaneously |
| `rra` / `rrb` | Reverse rotate A / B (bottom becomes top) |
| `rrr` | `rra` and `rrb` simultaneously |

**Why it's hard:** you can only see the top of each stack, you can't random-access elements, and every operation counts. The constraint isn't correctness — any sort that terminates is correct — it's minimizing the instruction count. The 42 grading thresholds are roughly: 700 moves for full marks on 100 elements, 5500 for 500 elements. This forces you to think algorithmically rather than just implement a known sort.

There is no single optimal algorithm — the best approach depends on input size. Small inputs (≤ 5) are best handled with hardcoded decision trees. Larger inputs need a strategy that exploits the two-stack structure, which is where chunk-based sorting and cost optimization come in.

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

## Notes

- Input is validated for syntax errors, integer overflow, and duplicates.
- Handles both space-separated string and multi-argument input formats.
