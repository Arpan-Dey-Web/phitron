# Test Contest — Problem Set

This folder contains my solutions for a **practice contest**: 5 problems — a warmup sum,
then a comparison problem, an average-target calculation, a maximum-difference scan and an
ordered walk through a list.

I did not write a theory note for the contest. All problem statements and my solutions are kept as
comments inside `contest.c`. This readme is the revision index for that folder.

Files:

| File | Purpose |
| ---- | ------- |
| `contest.c` | Problem statements + my solutions (kept as comments) |
| `input.txt` | Last input I tested with (Problem 1 — Four Friends) |
| `output.txt` | Output produced for that input |

---

# Problems Solved

| No. | Problem | Main Concept |
| --- | ------- | ------------ |
| 0 | Sum of 2 Numbers | warmup: two `scanf`, one addition |
| 1 | The Four Friends | "strictly greater than everyone" = unique max, else Tie |
| 2 | Phitron Marks Challenge | average → total: `need = N*K - sum`, clamp with `M` |
| 3 | Maximum Difference | check every pair `j > i`; the answer can be negative |
| 4 | Jhankar's Programming Journey | walk while **strictly** increasing, else `break` |

---

# Key Ideas to Revise

1. **Tie by negation** — no need to count how many share the top score. Test each name with
   `a > b && a > c && a > d` (strictly above ALL others); the final `else` catches every
   non-unique maximum, which is exactly a tie.
2. **Average → total** — "average at least K over N subjects" means `total >= N * K`. Compare
   `need` against `M` (the most the last exam can give) for `-1`, and clamp `need <= 0` to `0`.
   Two boundary cases: `need == M` prints `M`, `K == 0` always prints `0`.
3. **Maximum difference with order** — `j > i` forces the second element to come later, so the
   best pair is not simply "largest − smallest". Brute force over all pairs is fine here
   (`N ≤ 1000` → ~500,000 comparisons). A strictly decreasing array gives a **negative**
   answer (`-2` for `9 7 5 3 1`).
4. **Walk and stop** — `last = a[0]`, then `a[i] > last` continues, anything else stops.
   Equal difficulty counts as stopping (only *strictly* greater moves on). `N = 1` never enters
   the loop.

---

# What to Learn Next

Directly connected to this set:

- **One-pass maximum difference** — track the minimum seen so far and compute the best answer
  in `O(N)` instead of `O(N²)`
- **Multiple test cases** — the `T` loop pattern (`for (t = 0; t < T; t++)`) used by most
  contests
- **Prefix sums** — the natural tool behind "target average / target total" problems with many
  queries
