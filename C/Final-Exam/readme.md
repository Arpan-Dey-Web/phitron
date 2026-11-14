# Final Exam — Problem Set

This folder contains my solutions for the **final contest**: 5 problems covering the whole course —
`long long` arithmetic and divisibility, a 2D matrix diagonal check, last row/column traversal, a
nested-loop pattern (Christmas tree), and arrays with sorting.

I did not write a theory note for the exam. All problem statements and my solutions are kept as
comments inside `contest.c`. This readme is the revision index for that folder.

Files:

| File | Purpose |
| ---- | ------- |
| `contest.c` | Problem statements + my solutions (kept as comments) |
| `input.txt` | Last input I tested with (Problem 5) |
| `output.txt` | Output produced for that input |

---

# Problems Solved

| No. | Problem | Main Concept |
| --- | ------- | ------------ |
| 1 | Missing Number | `%` divisibility test, `long long` (product up to 1e18) |
| 2 | Jadu Matrix | square check + `i == j \|\| i + j == n - 1` (both diagonals) |
| 3 | Last Row and Last Column | two fixed walks: `arr[n-1][j]` and `arr[i][m-1]` |
| 4 | Christmas Tree | pyramid (`spaces--`, `stars += 2`) + 5-row trunk |
| 5 | Copy, Sort, Difference | copy while reading, selection sort, absolute difference |

---

# Key Ideas to Revise

1. **Missing Number** — `M / (A*B*C)` only when `M % (A*B*C) == 0`, else `-1`. `0 % x == 0`, so a
   zero product still gives `0`. `1e6 * 1e6 * 1e6 = 1e18` fits in `long long`.
2. **Jadu Matrix** — must be square first; on the diagonals the value must be `1`, everywhere else
   `0`. Both diagonal positions in one condition: `i == j || i + j == n - 1`.
3. **Last row / last column** — the corner element belongs to both lines and appears in both.
4. **Christmas tree** = the centred pyramid from Pattern-Printing (start indent `(n + 9) / 2`,
   rows `(n + 11) / 2`) plus 5 trunk rows of `5 spaces + n stars`.
5. **Copy, Sort, Difference** — `b[i] = a[i]` while reading, so sorting `B` cannot disturb `A`.
   Absolute value by hand: `if (diff < 0) diff = -diff;`.

---

# What to Learn Next

Directly connected to this exam:

- **Sorting without writing it yourself** — `qsort()` from the C library
- **2D array transposes and diagonal sums** — the same index tricks as Jadu Matrix
- **Bigger inputs** — why selection sort `O(n²)` is too slow for `n = 1e5` (that is what
  Algorithm modules are for)
