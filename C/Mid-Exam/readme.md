# Mid-Exam — Problem Set

This folder contains my solutions for the **mid-term contest**: 5 problems mixing everything from
Modules 1–11 (loops, conditions, arrays, strings, `strlen()`).

I did not write a theory note for the exam. All problem statements and my solutions are kept as
comments inside `contest.c`. This readme is the revision index for that folder.

Files:

| File | Purpose |
| ---- | ------- |
| `contest.c` | Problem statements + my solutions (kept as comments) |
| `input.txt` | Last input I tested with (Problem 1) |
| `output.txt` | Output produced for that input |

---

# Problems Solved

| No. | Problem | Main Concept |
| --- | ------- | ------------ |
| 1 | Divisible by 2 and by 3 | `if / else if` order, `%` |
| 2 | Count the Consonants | one pass over a string, `continue` |
| 3 | Farmers and Days of Work | work = farmers × days, integer division |
| 4 | Capital / Small / Digits | ASCII ranges in a loop |
| 5 | Frequency of Each Letter | nested loop over `'a'..'z'` |

---

# 1. Divisible by 2 and by 3

**Problem:** Count elements divisible by 2 and divisible by 3. A number divisible by both counts
**only for 2**.

**Idea:** the `if / else if` order *is* the rule:

```c
if (number % 2 == 0) {
    devidedBy2++;
} else if (number % 3 == 0) {
    devidedBy3++;
}
```

**Sample:**

```text
Input:  5 / 1 4 2 5 3    →  2 1
Input:  4 / 6 9 12 15    →  2 2
```

`6` and `12` are divisible by both, but they are caught by the first branch — they never reach
`devidedBy3`.

**Important Correction:** my first version had a third branch

```c
else if (number % 2 == 0 && i % 3 == 0)
```

It was **dead code** (`number % 2 == 0` was already handled above) and it checked the loop **index**
`i` instead of the **value** `number`.

---

# 2. Count the Consonants

**Problem:** Count consonants in a lowercase string (vowels: `a e i o u`).

**Idea:** every character that is *not* a vowel is a consonant — skip vowels with `continue`,
count everything else.

```c
if (a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || a[i] == 'o' || a[i] == 'u') {
    continue;
}
consonent++;
```

**Sample:**

```text
Input:  thefoxisgone   →  7
Input:  sjxapw         →  5
```

**Note:** `|S|` can be `1e5`, so exactly **one pass** over the string is allowed — no nested loop.

---

# 3. Farmers and Days of Work

**Problem:** `M1` farmers finish a work in `D` days. `M2` more farmers appear. Print how many
**fewer** days it takes now (integer part only).

**Idea:** the amount of work is measured in **farmer-days** and never changes:

```text
work     = M1 * D
now      = M1 + M2 farmers
new days = work / (M1 + M2)
answer   = D - new days
```

```c
int total_farmers = m1 + m2;
int new_days = (m1 * days) / total_farmers;
printf("%d\n", days - new_days);
```

**Sample:**

```text
Input:
4
10 5 15
4 0 5
4 1 5
7 1000 1

Output:
5
0
1
1
```

Trace of the last case: `7 × 1 = 7` farmer-days, `1007` farmers → `7 / 1007 = 0` new days
(integer division) → `1 - 0 = 1`.

**Important Correction:** my first attempt divided by the wrong value:

```c
int dayNeedFor_All_People = (days * m1) / days;   // = m1 — the farmers disappear!
```

Dividing by `days` cancels the work; the correct divisor is the **new** number of farmers.

---

# 4. Count Capital Letters, Small Letters and Digits

**Problem:** For each test case, print how many capital letters, small letters and digits a string
contains.

**Idea:** ASCII ranges from [Module 5](../Module-5/readme.md):

```text
'0'..'9'  → digits        'A'..'Z' → capital       'a'..'z' → small
```

**Sample:**

```text
Input:
2
theFox25IsBrave
ILoveYou100TimesAndSay2Also

Output:
3 10 2
7 16 4
```

**Note:** `strlen(a)` is stored in `len` **before** the loop. Putting `strlen(a)` in the loop
condition would recount the whole string on every iteration — wasteful, and `O(n²)` in the worst
case.

---

# 5. Frequency of Each Letter

**Problem:** Print how many times each letter `a`..`z` appears — only the letters that appear at
least once, in alphabetical order.

**Idea:** the outer loop walks `'a'` to `'z'`, the inner loop scans the string for the current
letter:

```c
for (char ch = 'a'; ch <= 'z'; ch++) {
    int count = 0;
    for (int i = 0; i < length; i++) {
        if (a[i] == ch) count++;
    }
    if (count > 0) {
        printf("%c - %d\n", ch, count);
    }
}
```

**Sample:**

```text
Input:  thefoxisbrave
Output: a - 1, b - 1, e - 2, f - 1, h - 1, i - 1, o - 1,
        r - 1, s - 1, t - 1, v - 1, x - 1
```

**Note:** `26 × |S|` comparisons — fine for `|S| = 1e4`. The outer loop also gives the alphabetical
order for free, and `if (count > 0)` skips the missing letters.

---

# Quick Revision

```text
"count only for 2"     → if / else if order does the job
work problem           → work = M1 * D, newDays = work / (M1 + M2)
                         integer division = "take the integer part"
count consonants       → skip vowels with continue
capital/small/digit    → ASCII ranges 'A'-'Z', 'a'-'z', '0'-'9'
frequency              → outer loop over 26 letters, inner loop over the string

strlen() once, BEFORE the loop — never inside the loop condition
check the VALUE (number), not the INDEX (i), when the problem talks about values
```

---

# Common Mistakes to Remember

1. **Dead `else if` branch** — a condition already covered by the `if` above never runs; and `i` is
   the index, not the value (Problem 1).
2. **Cancelling the work** — dividing by the wrong quantity makes the farmers disappear
   (Problem 3).
3. **`strlen()` inside the loop condition** — recounting the string every iteration (Problem 4).
4. **Forgetting `\n` between test cases** — several outputs end with `printf("%d\n", ...)`.
5. **Counting vowels instead of consonants** — the question asks for the *rest*, not the listed
   letters (Problem 2).

---

# What to Learn Next

Directly connected to this exam:

- **Re-solving under time pressure** — write the sample trace before coding
- **Frequency array** — `int freq[26]` counts all letters in one pass instead of `26` passes
- **Edge cases** — `N = 1`, all vowels, all digits, `M2 = 0`
- **Functions** — moving each solution into `solve()` to reuse code between test cases
- **String library functions** — `strcpy`, `strcat`, `strcmp` (see [Module 11](../Module-11/readme.md))
