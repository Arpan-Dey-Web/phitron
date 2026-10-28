# Week 1 — Problem Solving Practice

This folder contains my **week 1 problem-solving practice** from the course problem set (basic input/output, conditions, first loop).

I solved the problems without taking separate notes. All problem statements and my solutions are kept as comments inside `main.c`. This readme is the revision index for that folder.

Files:

| File | Purpose |
| ---- | ------- |
| `main.c` | Problem statements + my solutions (kept as comments) |
| `input.txt` | Last input I tested with |
| `output.txt` | Output produced for that input |

---

# Problems Solved

| No. | Problem | Main Concept |
| --- | ------- | ------------ |
| 1 | Zero or Non Zero | `if-else`, comparison with `0` |
| 2 | 5 Marks for good hand writing | Arithmetic with input |
| 3 | Multiple or not | Modulo `%`, checking both directions |
| 4 | Floating Point Number | `scanf("%f")`, precision with `%.3f` |
| 5 | Read and print 4 variable types | `int`, `long long`, `float`, `char` + format specifiers |
| 6 | Print 1 to N with Yes/No | `for` loop + divisibility by 5 |

---

# 1. Zero or Non Zero

**Problem:** Print `"Zero"` if `N == 0`, otherwise `"Non Zero"`.

```c
int num;
scanf("%d", &num);

if (num == 0) {
    printf("Zero");
} else {
    printf("Non Zero");
}
```

**Sample:**

```text
Input:  5
Output: Non Zero
```

**Note:** Use `==` for comparison. A single `=` is assignment and would always be true here.

---

# 2. 5 Marks for good hand writing

**Problem statement (original):** "You will be given an integer number N. You will have to **add 5** with N and print it." Constraints: `1 <= N <= 100`.

**My original solution:**

```c
int a;
scanf("%d", &a);

if (a > 0) {
    a += 5;
    printf("%d", a);
} else if (a < 0) {
    a -= 5;        // subtracting 5 — not what the statement asks
    printf("%d", a);
}
```

**Important Correction:** The statement says **always add 5**. Subtracting for negative numbers is a wrong interpretation. Also, the constraints guarantee `N >= 1`, so the whole `if-else` is unnecessary:

```c
int a;
scanf("%d", &a);
a += 5;
printf("%d", a);
```

**Sample:**

```text
Input:  100
Output: 105
```

**Lesson:** Read constraints first. If `N` is always positive, extra branches only add opportunities for bugs. Also, when `a = 0` neither branch runs and the program prints nothing — another reason the simple version is better.

---

# 3. Multiple or not

**Problem:** Given `a` and `b`, print `"Yes"` if one is a multiple of the other (either `a % b == 0` **or** `b % a == 0`), otherwise `"No"`.

**My original solution:**

```c
int a, b;
scanf("%d %d", &a, &b);

if (a % b == 0) {
    printf("Yes");
} else {
    printf("No");
}
```

**Important Correction:** This only checks one direction. It fails when `b` is the multiple of `a`:

```text
Input:  9 5
Expected: Yes      (9 is a multiple of 5)
My output: No      (9 % 5 = 4)
```

Correct version:

```c
if (a % b == 0 || b % a == 0) {
    printf("Yes");
} else {
    printf("No");
}
```

**Sample:**

```text
Input:  5 9
Output: No
```

**Lesson:** When a problem says "or vice versa", both directions must be checked. The sample cases may not expose a one-sided check — test with reversed inputs too.

---

# 4. Floating Point Number

**Problem:** Print a floating point number `x` up to 3 decimal places.

```c
float num;
scanf("%f", &num);
printf("%.3f", num);
```

**Sample:**

```text
Input:  22.12344
Output: 22.123
```

**Notes:**

- `%.3f` means: print with exactly 3 digits after the decimal point.
- C's `printf` rounds to the requested precision (here `22.12344` → `22.123`).
- Reading a `float` uses `%f` in both `scanf` and `printf`.

---

# 5. Read and Print 4 Variable Types

**Problem:** Take four inputs on separate lines and print them serially:

```text
A → int          (-10^9 <= A <= 10^9)
B → long long    (-10^18 <= B <= 10^18)
C → float        (print 2 decimal places)
D → char
```

**Correct solution:**

```c
#include <stdio.h>

int main() {
    int A;
    long long B;
    float C;
    char D;

    scanf("%d %lld %f %c", &A, &B, &C, &D);
    printf("%d\n%lld\n%.2f\n%c\n", A, B, C, D);

    return 0;
}
```

**Sample:**

```text
Input:
100
1234567891234567
23.5675
A

Output:
100
1234567891234567
23.57
A
```

**Important Corrections to my original code:**

1. I used `%lf` for `long long B`. Wrong — `%lf` is for `double` in `scanf` and `printf`. `long long` requires **`%lld`**. Passing the wrong format specifier is undefined behavior.
2. My `printf` used `%lf` for `B` again, plain `%f` for `C` (prints `23.567500`, not `23.57`), and missed the required newlines between values.
3. Format specifiers must match the data types:

| Type | `scanf` | `printf` |
| ---- | ------- | -------- |
| `int` | `%d` | `%d` |
| `long long` | `%lld` | `%lld` |
| `float` | `%f` | `%.2f` (2 decimals) |
| `char` | `%c` | `%c` |

**Note on input on separate lines:** whitespace inside a `scanf` format string (including the spaces I wrote) matches any amount of whitespace — spaces, tabs, newlines. So one `scanf` still correctly reads four lines.

---

# 6. Print 1 to N with Yes/No

**Problem:** For each value from 1 to `N`, print the value followed by `Yes` if it is divisible by 5, otherwise `No`.

```c
int n;
scanf("%d", &n);

for (int i = 1; i <= n; i++) {
    if (i % 5 == 0) {
        printf("%d Yes\n", i);
    } else {
        printf("%d No\n", i);
    }
}
```

**Sample:**

```text
Input:  5

Output:
1 No
2 No
3 No
4 No
5 Yes
```

**Note:** This was my first `for` loop in problem solving — loop variable `i` from `1` to `n` inclusive (`i <= n`), and `% 5 == 0` checks divisibility by 5.

---

# Quick Revision

```text
==              comparison (equality)
=               assignment

a % b == 0      a is divisible by b

a % b == 0 || b % a == 0     one is a multiple of the other (check BOTH ways)

%.3f / %.2f     print float with 3 / 2 decimal places

int       → %d
long long → %lld
float     → %f  (scanf)  /  %.Nf (printf)
char      → %c

for (int i = 1; i <= n; i++)   loop from 1 to n inclusive
```

**Common mistakes I made:**

- Checking only one direction of the multiple relation
- Adding unnecessary branches because I did not read the constraints
- Wrong format specifier (`%lf`) for `long long`

---

# What to Learn Next

Directly connected to this week's practice:

- **More loop patterns** — sum, product, counting within a range (Module 6, week 2)
- **Reading until EOF** — unknown amount of input
- **Integer division vs remainder** — `n / 10` and `n % 10` working together
- **Testing edge cases** — reversed inputs, `0`, negative values, minimum/maximum constraints
