# Module 19 — Practice: 2D Arrays and Recursion

This folder is a **practice set after Module 18 (2D arrays) and Module 17 (recursion)** — 4
problems: mirroring a 2D array, then three recursive problems (digits, vowels, factorial).

I did not write a theory note for this session. All problem statements and my solutions are
kept as comments inside `main.c`. This readme is the revision index for that folder.

Revision first: [Module 17 — Recursion](../Module-17/readme.md) and
[Module 18 — 2D Arrays](../Module-18/readme.md).

Files:

| File | Purpose |
| ---- | ------- |
| `main.c` | Problem statements + my solutions (kept as block comments) |
| `quiz.md` | (empty — practice notes only) |
| `input.txt` | Last input I tested with (Problem J) |
| `output.txt` | Output produced for that input |

---

# Problems Solved

| No. | Problem | Main Concept |
| --- | ------- | ------------ |
| W | Mirror Array | inner loop counts **down**: `j = c-1 .. 0` |
| D | Print Digits using Recursion | `n / 10` to go left, print on the way back |
| I | Count Vowels | whole line via `fgets()` (spaces!), count on unwind |
| J | Factorial | `n * factorial(n-1)`, base `n == 1`, `long long` |

---

# The Ideas Behind These 4

**W — Mirror Array.** The rows do not move, only the columns inside each row flip. Input loop
walks `j = 0 .. c-1`, output loop walks `j = c-1 .. 0`. Same shape, opposite direction.

**D — Print digits.** Recursing with `n / 10` first walks to the leftmost digit; the `printf`
with `n % 10` runs while the calls unwind, so digits print left to right:

```text
print_digits(121)
  -> print_digits(12)
       -> print_digits(1)
            -> print_digits(0)   returns (base case)
            -> print 1
       -> print 2
  -> print 1
= "1 2 1 "
```

Edge case: `N = 0` would print nothing (the base case hits at once), so `main()` prints `0`
itself.

**I — Count Vowels.** Two traps:

1. `scanf("%s")` stops at the first space — this string has spaces, so read the whole line with
   `fgets()`.
2. The check runs **after** `rec(s, i + 1)` returns, i.e. counting happens on the way back.
   `'\0'` is the base case.

**J — Factorial.** `n * factorial(n - 1)` with base `n == 1`. `N` starts at 1, so `0!` never
comes up. `20!` does not fit in `int` — the function returns `long long` and prints with `%lld`.
This is the solution in `input.txt` / `output.txt` (`5` → `120`).

---

# Quick Revision

```text
mirror row       inner loop backwards: j = c-1 .. 0
digits           recurse n/10 first, print n%10 on the way back, 0 handled in main
vowels           fgets() for whole line, '\0' = base case, count after the call
factorial        n * f(n-1), base n == 1, long long for N up to 20

recursion shape  go deeper first, act on the way back (D, I)
                 act first, go deeper after (the reverse order)
```

---

# What to Learn Next

Directly connected to this set:

- **String recursion** — reverse a string, check a palindrome recursively
- **Recursion on a 2D array** — print a matrix cell by cell with an index pair
- **`qsort()`** — sorting without writing your own loops (Final Exam problem 5 reminds you why
  that matters)
