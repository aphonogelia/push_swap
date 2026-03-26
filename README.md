# push_swap

A 42-school **push_swap** project using linked-list stacks and operation-based sorting.

The program takes a list of integers and prints the sequence of stack operations needed to sort them in ascending order with as few moves as possible.

## Features

- Input validation (syntax + int range checks)
- Duplicate detection
- Linked-list based stacks (`t_stack`, `t_node`)
- Full push_swap instruction set (`sa`, `pb`, `ra`, `rrr`, ...)
- Multiple sorting strategies for small and larger inputs
- LIS-oriented helpers for larger cases

## Build

This repository currently has no root `Makefile` committed.

If your local version includes one, use:

```bash
make
```

Otherwise, a direct build (from project root) can be done with:

```bash
cc -Wall -Wextra -Werror src/*.c -Iincludes -o push_swap
```

## Usage

```bash
./push_swap "2 1 3"
./push_swap 3 2 1 0
```

To validate output with a checker:

```bash
ARG="3 2 1 0"
./push_swap $ARG | ./other/pro_checker $ARG
```

## Testing

A tester is included in:

- `other/Push-Swap-Tester/push_swap_test.sh`
- `other/Push-Swap-Tester/push_swap_test_linux.sh`

Typical Linux usage (from directory containing `push_swap` and tester files):

```bash
bash push_swap_test_linux.sh
bash push_swap_test_linux.sh 250 250
bash push_swap_test_linux.sh -b 100 100
```

## Visualizer

A separate visualizer project is available in:

- `visualizer/`

See `visualizer/README.md` for build and runtime requirements.

## Project Layout

- `includes/`: shared declarations and types
- `src/`: core implementation
- `other/`: third-party checker/tester utilities
- `visualizer/`: C++ visualizer project

## Potential Improvements

### 1) Add a canonical root Makefile

- Include standard rules: `all`, `clean`, `fclean`, `re`
- Avoid relinking when objects are up-to-date
- Keep build flags centralized

### 2) Improve error-path consistency

- Use one small helper for writing `Error\n` and cleanup
- Return `0` for normal no-op exits (for example, no-argument run)

### 3) Harden shell scripts

- In tester scripts, guard argument checks like `[ "$1" = "-v" ]` to avoid empty-arg shell warnings
- Add `set -eu` (or a documented reason not to) for safer script execution

### 4) Add benchmark visibility

- Add a reproducible benchmark section (100 and 500 elements)
- Track min/avg/max operations over fixed seeds

### 5) Strengthen docs

- Add one quick-start command block from clone to first successful run
- Document expected behavior for edge cases (empty string, duplicates, out-of-range)

### 6) Add lightweight CI

- Compile on Linux with `-Wall -Wextra -Werror`
- Run a short deterministic test suite on pull requests

---

If you want, I can also generate a strict 42-style `Makefile` and a tiny CI workflow next.