# Week 2 — Problem Solving Practice

This folder contains my **week 2 problem-solving practice** from the course problem set (characters, expressions, divisors, digit splitting).

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
| 1 | C. Next Alphabet | `char` arithmetic, wrap-around case |
| 2 | D. Ali Baba and Puzzles | Trying all operator combinations, `long long` |
| 3 | K. Divisors | Loop `1..N` with `%` |
| 4 | I. Lucky Numbers | Splitting digits, `\|\|` short-circuit |

---

# 1. C. Next Alphabet

**Problem:** Given a lowercase letter, print the next letter in the alphabet. The next letter after `z` is `a`.

```c
char presentChar;
scanf("%c", &presentChar);

if (presentChar == 'z') {
    printf("a");
} else {
    printf("%c", presentChar + 1);
}
```

**How it works:**

```text
'b' = 'a' + 1        → characters are consecutive ASCII values
a → b, b → c, ..., y → z
z → a                → special wrap-around case, needs an if
```

**Sample:**

```text
Input:  a
Output: b
```

**Note:** Without the `if`, `'z' + 1` would print `{` (ASCII 123), not `a`. Wrap-around must always be handled explicitly.

---

# 2. D. Ali Baba and Puzzles

**Problem:** Given `a, b, c, d`, check whether `d` can be obtained by placing each of `+`, `-`, `*` exactly once between the three numbers:

```text
a □ b □ c = d
```

**Idea:** There is no clever formula — just **try every valid arrangement** and check if any equals `d`.

```c
long long a, b, c, d;
scanf("%lld %lld %lld %lld", &a, &b, &c, &d);

if (
    a + b * c == d ||
    a - b * c == d ||
    a * b + c == d ||
    a * b - c == d ||
    a + b - c == d ||
    a - b + c == d ||
    (a + b) * c == d ||
    (a - b) * c == d ||
    a * (b + c) == d ||
    a * (b - c) == d
) {
    printf("YES\n");
} else {
    printf("NO\n");
}
```

**Where the 10 cases come from:**

```text
Two slots between a, b, c — two different operators from {+, -, *}:

Natural precedence (no parentheses):   a+b*c, a+b-c, a-b+c, a-b*c, a*b+c, a*b-c   → 6 cases
Parentheses grouping first:            (a+b)*c, (a-b)*c, a*(b+c), a*(b-c)          → 4 cases
                                                                    Total        → 10 cases
```

**Sample:**

```text
Input:  3 4 5 23
Output: YES          (3 + 4 * 5 = 23)

Input:  1 2 3 1
Output: NO
```

**Important Notes:**

- Constraints: `a, b, c` up to `10^9`, so `a * b` can reach `10^18` — that requires **`long long`** (`int` would overflow). Signed integer overflow is undefined behavior in C, so choosing the right type up front matters.
- Operator precedence in C: `*` binds tighter than `+` and `-`, which is why `a + b * c` means `a + (b * c)` and separate `(a + b) * c` cases are needed.

---

# 3. K. Divisors

**Problem:** Print all positive divisors of `N` in ascending order, one per line.

**Idea:** A number `i` is a divisor of `n` when `n % i == 0`. Checking `i = 1..n` naturally produces ascending order.

```c
int n;
scanf("%d", &n);

int i = 1;
while (i <= n) {
    if (n % i == 0) {
        printf("%d\n", i);
    }
    i++;
}
```

**Sample:**

```text
Input:  6
Output:
1
2
3
6
```

**Definition:** A divisor divides the number exactly, with no remainder. `5` is not a divisor of `12` because `12 % 5 = 2`.

**Note:** Divisors come in pairs — if `i` divides `n`, then `n / i` also divides `n`. So checking only up to `√n` and printing both `i` and `n / i` is faster (`O(√N)` instead of `O(N)`), but needs care to print in order and avoid printing a square root twice. With `N <= 10^4` the simple loop is already fast enough.

---

# 4. I. Lucky Numbers

**Problem:** A two-digit number is **lucky** if one of its digits is divisible by the other. Print `"YES"` or `"NO"` for a number between 10 and 99.

**Idea:** Split the number into two digits, then check divisibility in both directions.

```c
int n;
int firstNumber = 0;
int secondNumber = 0;

scanf("%d", &n);

secondNumber = n % 10;      // last digit
firstNumber = n /= 10;      // remaining digit (also updates n)

if (secondNumber % firstNumber == 0 || firstNumber % secondNumber == 0) {
    printf("YES");
} else {
    printf("NO");
}
```

**Sample:**

```text
Input:  39
Output: YES          (9 % 3 == 0)

Input:  64
Output: NO           (6 % 4 = 2, 4 % 6 = 4)
```

**How the split works for `n = 39`:**

```text
39 % 10 = 9        → secondNumber = 9
39 / 10 = 3        → firstNumber = 3
```

**Important Notes:**

- `secondNumber = n % 10; firstNumber = n /= 10;` works, but modifying `n` inside an assignment is hard to read. Clearer:

  ```c
  int secondNumber = n % 10;
  int firstNumber = n / 10;
  ```

- **Why no division by zero?** Numbers like `10`, `20`, `90` have a `0` digit. When `secondNumber` is `0`, the first check `0 % firstNumber == 0` is true, and `||` **short-circuits** — the second check (`firstNumber % 0`) is never evaluated. The tens digit of a two-digit number is never `0`, so the first modulus is always safe.
- `0` is divisible by any non-zero number, so `10`, `20`, ..., `90` are all lucky.

---

# Quick Revision

```text
'c' + 1              → next character (watch wrap-around at 'z')

n % 10               → last digit
n / 10               → remove last digit

n % i == 0           → i is a divisor of n

a % b == 0 || b % a == 0    either divides the other

* binds tighter than + and - → (a + b) * c needs parentheses

up to 10^9 * 10^9 = 10^18    → use long long, format %lld
|| short-circuits            → second operand not evaluated if first is true
```

**Common mistakes to avoid:**

- Forgetting the wrap-around case (`z → a`)
- Using `int` for products that can reach `10^18`
- Checking divisibility in only one direction
- Forgetting that `0` can be one of the digits

---

# What to Learn Next

Directly connected to this week's practice:

- **Square root optimization** for divisors — finding all divisors in `O(√N)`
- **Brute force with loops** — checking many candidates automatically instead of listing conditions by hand (Ali Baba problem becomes a loop over operators later)
- **Strings** — processing whole words instead of single characters
- **Reading multiple test cases** — the `T` pattern already used in the Digits problem (Module 6)
