# Pattern-Printing — Nested Loop Patterns

This folder collects **11 patterns printed with nested loops** — the classic way to master `for`
loops after [Module 6](../Module-6/readme.md).

Every pattern is built from the same two-line idea:

```text
outer loop  →  chooses the ROW
inner loop  →  prints one row (spaces, stars or numbers)
```

I did not write a theory note here. All patterns and my solutions are kept as comments inside
`main.c`. This readme is the revision index for that folder.

Files:

| File | Purpose |
| ---- | ------- |
| `main.c` | All 11 patterns + my solutions (kept as comments) |
| `input.txt` | Last input I tested with (Pattern 10) |
| `output.txt` | Output produced for that input |

---

# Patterns Solved

| No. | Pattern | What Changes Each Row |
| --- | ------- | --------------------- |
| 1 | Solid square | nothing — every row is identical |
| 2 | Rectangle | nothing, but width and height are separate inputs |
| 3 | Rectangle of numbers | nothing, inner counter is printed |
| 4 | Right triangle (growing) | row limit = row number `i` |
| 5 | Inverted triangle (shrinking) | outer loop counts `n .. 1` |
| 6 | Number triangle | inner limit shrinks (`a--`) |
| 7 | Right triangle, solid | star counter grows (`star++`) |
| 8 | Odd number pyramid | printed value grows by 2 (`a += 2`) |
| 9 | Inverted triangle, solid | star counter shrinks (`star--`) |
| 10 | Centred pyramid | spaces `--`, stars `+= 2` |
| 11 | Diamond | pattern 10 + its mirror |

---

# The Four Counters to Remember

Almost every pattern is a variation of these four counters:

```text
row      i = 1 .. n            which line am I on
space    starts at n-1, space--      fewer spaces per row
star     starts at 1,   star += 2    1, 3, 5, 7 ... (pyramid)
             or starts at n, star--  n, n-1, ... (inverted)
limit    the inner loop's upper bound (i for a triangle, n for a rectangle)
```

Opposite movements make the shape:

```text
spaces shrinking + stars growing   →  pyramid (10) and diamond (11)
inner limit = row number           →  triangle (4)
inner limit = n, outer = m         →  rectangle (1, 2, 3)
```

---

# 1–3: Square, Rectangle, Number Rectangle

```text
square (n=3)      rectangle (4 3)    number rect (4 3)
***               ****               1234
***               ****               1234
***               ****               1234
```

* **Square** — both loops run `n` times.
* **Rectangle** — inner loop runs `n` times (width), outer loop `m` times (height). Two different
  limits are what turn the square into a rectangle.
* **Number rectangle** — same loops, but the inner counter `j` is printed instead of `*`.

---

# 4–5: Triangle and Inverted Triangle (with spaces)

```text
input 4, pattern 4        input 4, pattern 5
*                         * * * *
* *                       * * *
* * *                     * *
* * * *                   *
```

* **Pattern 4** — the inner limit is the row number `i`, so each row gains one star.
* **Pattern 5** — the outer loop counts **down** (`i = n .. 1`), so the first row has the most
  stars. The same shape can also be written with `i = 1 .. n` and the limit `n + 1 - i`.

---

# 6: Number Triangle

```text
input 4
1 2 3 4
1 2 3
1 2
1
```

The inner counter always restarts at 1 — only the **limit** shrinks (`a` starts at `n`, `a--` after
every row). It is the mirror of pattern 3, which keeps the limit fixed and repeats the same row.

---

# 7–9: Solid Triangles and the Odd Pyramid

```text
pattern 7 (4)      pattern 8 (4)        pattern 9 (4)
*                  1                    ****
**                 1 3                  ***
***                1 3 5                **
****               1 3 5 7              *
```

* **Pattern 7** — `star++` grows the row: the same shape as pattern 4 without the trailing space.
  A single space in `printf("* ")` vs `printf("*")` is the only difference.
* **Pattern 8** — the printed value is a **separate** counter (`a = 1`, then `a += 2`), not the loop
  index — that is why it shows odd numbers.
* **Pattern 9** — `star--` shrinks the row: the mirror of pattern 7.

---

# 10: Centred Pyramid

```text
input 5
    *
   ***
  *****
 *******
*********
```

Row `i` gets `(n - i)` spaces and `(2i - 1)` stars:

```text
space  = n - 1, then space--      (fewer spaces)
star   = 1,     then star += 2    (1, 3, 5, 7, ...)
```

Spaces are printed **only before** the stars — never after them, so the output has no trailing
whitespace. This pattern is what `input.txt` / `output.txt` in this folder record.

---

# 11: Diamond

```text
input 4
   *
  ***
 *****
*******
 *****
  ***
   *
```

The pyramid of pattern 10 followed by its mirror:

```text
first half   : space--, star += 2      (exactly pattern 10)
second half  : space grows from 1, star = 2n-3 then star -= 2
total lines  : 2n - 1   (the middle row is printed only once)
```

---

# Quick Revision

```text
outer loop  → row          inner loop → prints one row

rectangle   inner = n, outer = m
triangle    inner limit = row number i
inverted    outer counts n .. 1   (or star--)

pyramid     space--  and  star += 2
diamond     pyramid + its mirror, total 2n-1 lines
odd numbers a = 1, a += 2 (independent of the index)

printf("* ") vs printf("*")   → trailing space or not
```

---

# Common Mistakes to Remember

1. **Same limit for both loops** — gives a square, not a rectangle (Pattern 2).
2. **Forgetting `printf("\n")`** — everything ends up on one line.
3. **Printing a space after the last star** — violates the "no extra spaces" rule of pattern
   problems (Pattern 10).
4. **Using the loop index where a value is needed** — the odd pyramid needs its own `a += 2`
   counter (Pattern 8).
5. **Diamond row count** — `2n - 1` lines, not `2n`; the middle row must not be printed twice.

---

# What to Learn Next

Directly connected to this set:

- **Number/diamond variants** — the same counters with digits instead of `*`
- **Hollow patterns** — printing only the borders (`*   *`)
- **Character patterns** — letters and symbols with the same loops
- **Pattern 4 vs 7 in one program** — comparing how a format string changes the output
- **Time complexity** — why printing a triangle is `O(n²)` (each star is one `printf`)
