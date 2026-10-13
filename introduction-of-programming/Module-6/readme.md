# Module 6 — Loops Problem Set

This folder contains my practice problems for **loops in C** (`for`, `while`, `do-while`) plus increment operators.

I already studied loop theory in [Module 3](../Module-3/readme.md). This folder is practice only: all problem statements and my solutions are kept as comments inside `main.c`.

Files:

| File | Purpose |
| ---- | ------- |
| `main.c` | Problem statements + my solutions (kept as comments) |
| `quiz.md` | Loop quiz with explanations (`break`, `continue`, nested loops) |
| `input.txt` | Last input I tested with |
| `output.txt` | Output produced for that input |

---

# Problems Solved

| No. | Problem | Main Concept |
| --- | ------- | ------------ |
| 1 | Pre and post increment | `x++` vs `++x` |
| 2 | Print even numbers from 1 to N | `for` loop + `%` |
| 3 | C. Even, Odd, Positive and Negative | Counters inside a loop |
| 4 | D. Fixed Password | `while` + `scanf() != EOF` + `break` |
| 5 | E. Max | Running maximum |
| 6 | Multiplication table | Fixed-iteration `for` loop |
| 7 | Q. Digits | Digit extraction with `while` / `do-while` |

---

# 1. Pre and Post Increment

```c
int x = 10;
int y = x++;      // y = 10, then x becomes 11
printf("%d %d\n", x, y);   // 11 10

int z = ++y;      // y becomes 11 first, then z = 11
printf("%d %d %d", x, y, z); // 11 11 11
```

**Difference:**

```text
x++  → use current value first, increment afterward (post-increment)
++x  → increment first, use new value (pre-increment)
```

When the statement is only `x++;` by itself, both behave the same. The difference matters only when the value is used **inside the same expression**.

---

# 2. Print Even Numbers from 1 to N

**Problem:** Print all even numbers between 1 and `N` inclusive, one per line. If there are none, print `-1`.

**Idea:** Loop from 1 to `N`, print `i` when `i % 2 == 0`.

```c
int n;
scanf("%d", &n);

if (n == 1) {
    printf("-1");
} else {
    for (int i = 1; i <= n; i++) {
        if (i % 2 == 0) {
            printf("%d\n", i);
        }
    }
}
```

**Sample:**

```text
Input:  10
Output:
2
4
6
8
10
```

**Note:** The `n == 1` special case exists because `1` is the only value in the range with no even numbers. An alternative without the special case: start the loop from `2` and step by `2` (`i += 2`), then print `-1` if the loop body never ran.

---

# 3. C. Even, Odd, Positive and Negative

**Problem:** Given `N` numbers, count how many are even, odd, positive, and negative.

**Idea:** Four **counter variables**, each starting at `0`, increased inside a loop.

```c
int takeInput;
int input;
int even = 0, odd = 0, positive = 0, negative = 0;

scanf("%d", &takeInput);

for (int i = 1; i <= takeInput; i++) {
    scanf("%d", &input);

    if (input > 0) {
        positive += 1;
    } else if (input < 0) {
        negative += 1;
    }

    if (input % 2 == 0) {
        even += 1;
    } else {
        odd += 1;
    }
}

printf("Even: %d\n", even);
printf("Odd: %d\n", odd);
printf("Positive: %d\n", positive);
printf("Negative: %d\n", negative);
```

**Sample:**

```text
Input:
5
-5 0 -3 -4 12

Output:
Even: 3
Odd: 2
Positive: 1
Negative: 3
```

**Important notes:**

- `0` counts as **even**, but it is neither positive nor negative — that is why the even/odd check is a separate `if`, not part of the positive/negative chain.
- `positive += 1` is the same as `positive = positive + 1` and `positive++`.
- This counter pattern is reused in many problems: start at `0`, add `1` each time something matches.

---

# 4. D. Fixed Password

**Problem:** Keep reading passwords (one per line). Print `"Wrong"` for each wrong one; when the password `1999` appears, print `"Correct"` and stop.

**Idea:** Read until **end of file (EOF)** using `scanf()`'s return value.

```c
int x;

while (scanf("%d", &x) != EOF) {
    if (x == 1999) {
        printf("Correct\n");
        break;
    } else {
        printf("Wrong\n");
    }
}
```

**How it works:**

```text
scanf() returns how many values were read successfully
        ↓
EOF (end of file) means there is no more input
        ↓
loop continues while input is not finished
        ↓
break stops immediately once the correct password is found
```

**Sample:**

```text
Input:
2200
1020
1999
1000
9999

Output:
Wrong
Wrong
Correct
```

Note that `1000` and `9999` are never processed — `break` exits before reading them.

**Important Correction:** One earlier version of my solution used `break:` (with a colon). That is invalid C — the statement must be `break;`. Also, `printf` after the final line should include `\n` if the problem expects separate lines.

**Alternate form** using `for` with an empty update section (same behavior):

```c
for (; scanf("%d", &x) != EOF; ) {
    ...
}
```

---

# 5. E. Max

**Problem:** Given `N` and then `N` numbers, print the maximum.

**Idea:** Keep a running `max`, update it whenever a larger value arrives.

```c
int max = 0;
int n;
scanf("%d", &n);

for (int i = 1; i <= n; i++) {
    int val;
    scanf("%d", &val);
    if (val > max) {
        max = val;
    }
}
printf("%d", max);
```

**Sample:**

```text
Input:
5
1 8 5 7 5

Output:
8
```

**Important Note:** Starting with `max = 0` is only safe because the problem guarantees `0 <= Xi <= 10^9`. If negative numbers were allowed, `0` could be larger than every input and the answer would be wrong. The general safe way is to initialize with the smallest possible `int`:

```c
#include <limits.h>

int max = INT_MIN;
```

or read the first value before the loop and set `max` to it.

---

# 6. Multiplication Table

**Problem:** Print the multiplication table of `N` from 1 to 12.

**Idea:** A `for` loop with a fixed range — 12 iterations.

```c
int n;
scanf("%d", &n);

for (int i = 1; i <= 12; i++) {
    printf("%d * %d = %d\n", n, i, n * i);
}
```

**Sample:**

```text
Input:  5
Output:
5 * 1 = 5
5 * 2 = 10
...
5 * 12 = 60
```

---

# 7. Q. Digits

**Problem:** `T` test cases. For each number `N`, print its digits from **right to left**, separated by space.

**Idea:** Repeatedly take the last digit with `% 10`, then remove it with `/= 10`.

```c
int t;
scanf("%d", &t);

for (int i = 1; i <= t; i++) {
    int n;
    scanf("%d", &n);

    do {
        printf("%d ", n % 10);   // last digit
        n /= 10;                 // remove last digit
    } while (n != 0);

    printf("\n");
}
```

**Step-by-step for `n = 1200`:**

```text
1200 % 10 = 0  → print 0, n = 120
 120 % 10 = 0  → print 0, n = 12
  12 % 10 = 2  → print 2, n = 1
   1 % 10 = 1  → print 1, n = 0
n == 0 → stop

Output: 0 0 2 1
```

**Why `do-while` instead of `while`:**

| Version | Behavior for `n = 0` |
| ------- | -------------------- |
| `while (n != 0)` | body never runs → prints nothing |
| `do { } while (n != 0);` | body runs once → prints `0` |

The constraints allow `N = 0`, so `do-while` handles it naturally. My earlier `while` version needed an extra `if (n == 0)` workaround for the same case.

**Notes:**

- The space in `printf("%d ", ...)` is required — without it the digits of `121` would print as `121` instead of `1 2 1`.
- The order of printed digits is naturally right-to-left because `% 10` always grabs the **last** digit first.

---

# Quick Revision

```text
for (init; condition; update)   → known number of iterations
while (condition)               → condition checked first, body may run 0 times
do { ... } while (condition);   → body runs at least once

x++  → use then increment
++x  → increment then use

counter pattern:   int count = 0; ... count += 1;

max pattern:       start low (0 or INT_MIN), update when val > max

scanf(...) != EOF  → keep reading until input ends
break              → exit nearest loop immediately

n % 10             → last digit
n /= 10            → remove last digit
```

Loop tracing mental model (from Module 3):

```text
START → CONDITION → WORK → UPDATE → CONDITION → ...
```

---

# What to Learn Next

Directly connected to this module:

- **Nested loops** — loops inside loops (already practiced in `quiz.md`)
- **Loop patterns** — sum, product, reverse a number, count digits
- **Arrays** — storing `N` numbers instead of processing them one at a time
- **Time complexity basics** — why a loop over `N` values is `O(N)`
