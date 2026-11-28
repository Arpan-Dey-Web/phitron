# C++ Mid Exam — Problem Set

This folder contains my solutions for the **C++ mid-term contest** (official Module 04 of the
C++ for DSA track): 5 problems covering `sort()`, functions that return heap arrays, frequency
counting with EOF input, a `class` with constructors and tie-breaking, and a triple loop.

I did not write a theory note for the exam. All problem statements and my solutions are kept as
comments inside `contest.cpp`. This readme is the revision index for that folder.

Files:

| File | Purpose |
| ---- | ------- |
| `contest.cpp` | Problem statements + my solutions (kept as comments) |
| `input.txt` | Last input I tested with (Problem 1) |
| `output.txt` | Output produced for that input |

---

# Problems Solved

| No. | Problem | Main Concept |
| --- | ------- | ------------ |
| 1 | Sort It Twice | `sort(arr, arr+n)` then `sort(..., greater<int>())` |
| 2 | sort_it() | read + sort inside a function, return a `new[]` array |
| 3 | Amena's Alphabets | `cin.get(ch)` per character, `count[26]` flush per line |
| 4 | Best Student | `class Student` + two constructors, tie → smaller ID |
| 5 | Three Sum | three nested loops `i < j < k`, break out on first hit |

---

# Key Ideas to Revise

1. **Sort twice, same array** — ascending first, then re-sort with `greater<int>()` for
   descending. `N` up to `10^5` means `O(N log N)` is required; a `O(N²)` sort would time out.
2. **Returning an array from a function** — a local array dies with the frame, so `sort_it()`
   builds it with `new int[n]` and returns the pointer; `main()` must `delete[]` it. (Module 2's
   heap rule, now used in a contest.)
3. **Amena's line sort** — no `sort()` at all: count `count[26]`, flush a..z on every `'\n'`,
   reset the counters, flush once more at EOF for a last line without a newline. `cin.get(ch)`
   is what sees the newline (`cin >>` would skip it).
4. **Tie-break in one condition** — `current.marks > best.marks || (equal && current.id < best.id)`.
   The class needs a default `Student() {}` because `main()` has no arguments yet at that point,
   plus the full constructor that copies each field with `this->` / `strcpy`.
5. **Three distinct indexes** — `i < j < k` in three loops makes "distinct" automatic (values
   may repeat — `2 2 2` is a valid YES). `found` + `break` at every level stops the search at
   the first hit.

---

# What to Learn Next

Directly connected to this exam:

- **String Class in C++** — `std::string` with `sort(s.begin(), s.end())` would collapse Amena's
  problem into a few lines (Module 05)
- **Two-pointer three-sum** — `O(N²)` or `O(N log N)` instead of the `O(N³)` brute force
- **Private members + getters** — what a "real" `Student` class looks like after encapsulation
