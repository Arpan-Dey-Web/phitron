# Module 5 — Conditions Problem Set

This folder contains my practice problems for **conditional statements in C** (`if`, `else if`, `else`).

I did not write a full theory note for this module. All problem statements and my solutions are kept as comments inside `main.c`. This readme is the revision index for that folder.

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
| 1 | I. Welcome for you with Conditions | `if-else`, comparison `>=` |
| 2 | J. Multiples | Modulo `%`, OR condition `\|\|` |
| 3 | P. First digit! | Integer division `/`, first digit extraction |
| 4 | N. Char | `char` arithmetic, ASCII difference of 32 |
| 5 | M. Capital or Small or Digit | Nested `if`, ASCII ranges |
| 6 | Min and Max of 3 Numbers | Multiple comparison conditions |

---

# 1. I. Welcome for you with Conditions

**Problem:** Given `A` and `B`, print `"Yes"` if `A >= B`, otherwise print `"No"`.

**Idea:** One comparison, one `if-else`.

```c
int a, b;
scanf("%d %d", &a, &b);

if (a >= b) {
    printf("Yes");
} else {
    printf("No");
}
```

**Sample:**

```text
Input:  10 9
Output: Yes

Input:  5 7
Output: No
```

**Note:** `5 5` also prints `Yes` because the condition is `>=` (greater **or equal**), not `>`.

---

# 2. J. Multiples

**Problem:** Print `"Multiples"` if `A` is a multiple of `B` **or** `B` is a multiple of `A`, otherwise `"No Multiples"`.

**Idea:** Use the modulo operator. If `a % b == 0`, then `a` is divisible by `b`.

```c
if (a % b == 0 || b % a == 0) {
    printf("Multiples");
} else {
    printf("No Multiples");
}
```

**Sample:**

```text
Input:  9 3
Output: Multiples      (9 % 3 == 0)

Input:  6 24
Output: Multiples      (24 % 6 == 0)

Input:  12 5
Output: No Multiples
```

**Important Note:** The problem statement's own wording ("A is multiple of B if B is divisible by A") is confusing. The correct meaning is:

```text
A is a multiple of B  →  A % B == 0
```

Because the problem asks about **either direction**, checking both with `||` is required.

---

# 3. P. First digit!

**Problem:** Given a 4-digit number `X` (`999 < X <= 9999`), print `"EVEN"` if its first digit is even, otherwise `"ODD"`.

**Idea:** Integer division removes digits from the right.

```c
int a;
scanf("%d", &a);

int firstDigit = a / 1000;   // 4569 / 1000 = 4

if (firstDigit % 2 == 0) {
    printf("EVEN");
} else {
    printf("ODD");
}
```

**How it works:**

```text
4569 / 1000 = 4.569 → stored as int → 4
4 % 2 == 0 → EVEN
```

**Related trick:**

```text
n / 1000  → remove last 3 digits (only correct for 4-digit numbers)
n % 10    → last digit (4569 % 10 = 9)
```

**Important Correction:** My original comment said dividing gives "a float value but int will take the int value only". That is not how C works. In C, `4569 / 1000` is **integer division** because both operands are `int` — the result is truncated to `4` directly. No `float` is involved.

**General method** (works for any number of digits): keep dividing by 10 until the number has one digit left. This becomes easier after loops (Module 6).

---

# 4. N. Char

**Problem:** If the letter is lowercase, convert it to uppercase; if uppercase, convert to lowercase.

**Idea:** In ASCII, the difference between a lowercase letter and its uppercase version is exactly `32`.

```text
'a' = 97    'A' = 65   → 97 - 65 = 32
```

```c
char ch;
scanf("%c", &ch);

if (ch >= 'a' && ch <= 'z') {
    ch = ch - 32;      // lowercase → uppercase
    printf("%c", ch);
} else {
    ch = ch + 32;      // uppercase → lowercase
    printf("%c", ch);
}
```

**Sample:**

```text
Input:  a
Output: A

Input:  A
Output: a
```

**Note:** Ranges like `ch >= 'a' && ch <= 'z'` work because ASCII values increase in order (`'a' < 'b' < ... < 'z'`). This is true for ASCII, but not guaranteed for every character encoding — fine for competitive programming judges.

---

# 5. M. Capital or Small or Digit

**Problem:** Given one character, print whether it is a digit or an alphabet, and if an alphabet, whether it is capital or small.

**Idea:** Three ASCII ranges, checked with nested conditions.

```text
'0'..'9'  → 48..57
'A'..'Z'  → 65..90
'a'..'z'  → 97..122
```

```c
char ch;
scanf("%c", &ch);

if (ch >= '0' && ch <= '9') {
    printf("IS DIGIT\n");
} else if (ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z') {
    printf("ALPHA\n");
    if (ch >= 'a' && ch <= 'z') {
        printf("IS SMALL\n");
    } else {
        printf("IS CAPITAL\n");
    }
}
```

**Sample:**

```text
Input:  A
Output:
ALPHA
IS CAPITAL

Input:  9
Output:
IS DIGIT
```

**Note:** `&&` has higher precedence than `||`, so `ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z'` is read as `(a..z) || (A..Z)` — correct without extra parentheses, but adding them makes intent clearer.

---

# 6. Min and Max of 3 Numbers

**Problem:** Given 3 numbers, print the minimum followed by the maximum.

**Idea:** Two separate chains of conditions — one for max, one for min.

```c
int a, b, c;
scanf("%d %d %d", &a, &b, &c);

int maximumNumber, minimumNumber;

if (a >= b && a >= c) {
    maximumNumber = a;
} else if (b >= a && b >= c) {
    maximumNumber = b;
} else {
    maximumNumber = c;
}

if (a <= b && a <= c) {
    minimumNumber = a;
} else if (b <= a && b <= c) {
    minimumNumber = b;
} else {
    minimumNumber = c;
}

printf("%d %d", minimumNumber, maximumNumber);
```

**Sample:**

```text
Input:  10 20 -5
Output: -5 20
```

**Cleaner alternative** — start with `a` as the candidate instead of comparing three ways every time:

```c
int maximumNumber = a;
int minimumNumber = a;

if (b > maximumNumber) maximumNumber = b;
if (c > maximumNumber) maximumNumber = c;

if (b < minimumNumber) minimumNumber = b;
if (c < minimumNumber) minimumNumber = c;
```

This pattern is used again in Module 6 when finding the maximum of `N` numbers.

---

# Quick Revision

```text
if (condition)          → run block when condition is true
else                    → run block otherwise
else if                 → check another condition

a % b == 0              → a is divisible by b
a / 1000                → first digit of a 4-digit number (integer division)
a % 10                  → last digit of a

'a' = 97, 'A' = 65      → difference is 32
'0' = 48                → digits are 48..57

&&  → both conditions must be true
||  → at least one condition must be true
```

---

# What to Learn Next

Directly connected to this module:

- **Loops** — printing many values, repeating comparisons (Module 6)
- **Digit extraction with loops** — first/last digit of any number, not just 4-digit numbers
- **`switch` statement** — another way to branch on a value
- **Logical operator precedence** — why `&&` binds tighter than `||`
