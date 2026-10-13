# Module 6 — Loops Quiz

Practice quiz on **loops in C**: tracing `for` and `while`, `break`, `continue`, nested loops, and infinite loops.

How to use this file:

1. Attempt each question yourself first.
2. Trace the loop by hand (initial value → condition → body → update).
3. Check the answer and explanation below each question.

---

## Question 1

How many times will `"hi"` be printed by the following code?

```c
for (int i = 0; i <= 10; i++) {
    printf("hi ");
    if (i > 2) {
        break;
    }
}
```

A. 2
B. 3
C. 4
D. 10

<details>
<summary>Answer</summary>

**C) 4**

</details>

### Explanation

The loop starts at `i = 0` and prints `"hi"` **before** checking the `break` condition:

```text
i = 0 → print "hi" → 0 > 2? no
i = 1 → print "hi" → 1 > 2? no
i = 2 → print "hi" → 2 > 2? no
i = 3 → print "hi" → 3 > 2? yes → break (loop ends)
```

`"hi"` is printed 4 times (for `i = 0, 1, 2, 3`).

Compare with Question 9, where `break` comes **before** the `printf`.

---

## Question 2

How many times will `*` be printed by the following nested loops?

```c
int i = 3;

while (i <= 5) {
    for (int j = 0; j < i; j++) {
        printf("*");
    }
    i++;
}
```

A. 10
B. 7
C. 12
D. Infinite loop

<details>
<summary>Answer</summary>

**C) 12**

</details>

### Explanation

Outer loop (`while`): runs for `i = 3, 4, 5` (3 iterations).

Inner loop (`for`): prints `*` exactly `i` times each iteration:

```text
i = 3 → j = 0, 1, 2           → 3 stars
i = 4 → j = 0, 1, 2, 3        → 4 stars
i = 5 → j = 0, 1, 2, 3, 4     → 5 stars
```

```text
Total = 3 + 4 + 5 = 12
```

---

## Question 3

How many times will `#` be printed by the following code?

```c
int i = -3;

while (i < 0) {
    for (int j = 0; j < 5; j++) {
        printf("#");
    }
    i--;
}
```

A. 0
B. 22
C. 5
D. Infinite loop

<details>
<summary>Answer</summary>

**D) Infinite loop**

</details>

### Explanation

Outer loop: `i` starts at `-3` and the condition is `i < 0`. Each iteration does `i--`, so `i` becomes `-4, -5, -6, ...` — it moves **further below zero**, never reaching a point where `i < 0` is false.

The condition stays true forever, so the inner loop keeps printing 5 `#` characters in every never-ending iteration.

---

## Question 4

How many times will `"hi"` be printed by the following code?

```c
for (int i = -4; i >= 0; i++) {
    for (int j = 5; j < 2; j++) {
        printf("hi ");
    }
}
```

A. 4
B. 12
C. 0
D. Infinite loop

<details>
<summary>Answer</summary>

**C) 0**

</details>

### Explanation

Outer loop: `i = -4`, condition `i >= 0` → `-4 >= 0` is **false**. The outer loop body never runs.

Because the outer loop never runs, the inner loop never runs either. `"hi"` is printed **0 times**.

---

## Question 5

Which one is an infinite loop?

A. `for (int i = -4; i >= 0; i--)`
B. `for (int i = -4; i <= 0; i++)`
C. `for (int i = -4; i <= 0; i--)`
D. None

<details>
<summary>Answer</summary>

**C) `for (int i = -4; i <= 0; i--)`**

</details>

### Explanation

Check each option:

```text
A) i = -4, condition i >= 0  → -4 >= 0 is false → loop never runs (0 iterations)

B) i = -4, condition i <= 0, update i++
   i moves -4 → -3 → ... → 0 → 1 → condition 1 <= 0 false → loop ends (finite)

C) i = -4, condition i <= 0, update i--
   i moves -4 → -5 → -6 → ... always <= 0 → condition never false → INFINITE
```

The lesson: the update direction must **move toward** the condition becoming false. Here `i--` moves away from `0`, so the loop never stops.

---

## Question 6

Which loop prints all values from 1 to 10 **inclusive**?

A. `for (int i = 0; i < 10; i++) { printf("%d ", i); }`
B. `for (int i = 1; i < 10; i++) { printf("%d ", i); }`
C. `for (int i = 1; i <= 10; i++) { printf("%d ", i); }`
D. `for (int i = 0; i <= 10; i++) { printf("%d ", i); }`

<details>
<summary>Answer</summary>

**C) `for (int i = 1; i <= 10; i++)`**

</details>

### Explanation

```text
A) 0 to 9  → includes 0, misses 10
B) 1 to 9  → misses 10
C) 1 to 10 → correct
D) 0 to 10 → includes extra 0
```

For "1 to N inclusive", use start `1` and condition `i <= N`.

---

## Question 7

Which loop prints all values from 1 to 10 **exclusive** (meaning 1 to 9)?

A. `int i = 0; while (i < 10) { printf("%d ", i); i++; }`
B. `int i = 1; while (i < 10) { printf("%d ", i); i++; }`
C. `int i = 2; while (i < 10) { printf("%d ", i); i++; }`
D. `int i = 2; while (i <= 10) { printf("%d ", i); i++; }`

<details>
<summary>Answer</summary>

**B) `int i = 1; while (i < 10) { ... }`**

</details>

### Explanation

"1 to 10 exclusive" means **1 through 9** (10 itself is excluded).

```text
A) 0 to 9  → starts at extra 0
B) 1 to 9  → correct
C) 2 to 9  → misses 1
D) 2 to 10 → misses 1, includes 10
```

Note the difference from Question 6:

```text
inclusive → i <= 10   (10 included)
exclusive → i <  10   (10 excluded)
```

---

## Question 8

What will be the output of the following code?

```c
for (int i = 0; i < 5; i++) {
    if (i == 3) {
        continue;
    }
    printf("%d ", i);
}
```

A. `0 1 2 3 4 5`
B. `0 1 2 4 5`
C. `0 1 2`
D. `0 1 2 4`

<details>
<summary>Answer</summary>

**D) `0 1 2 4`**

</details>

### Explanation

The loop runs for `i = 0, 1, 2, 3, 4`. When `i == 3`, `continue` skips the `printf` for that iteration only:

```text
i = 0 → print 0
i = 1 → print 1
i = 2 → print 2
i = 3 → continue (skip printf)
i = 4 → print 4
```

Output: `0 1 2 4`

The loop itself is **not** ended — only the current iteration is skipped.

---

## Question 9

How many times will `"hi"` be printed?

```c
for (int i = 0; i <= 10; i++) {
    if (i > 2) {
        break;
    }
    printf("hi ");
}
```

A. 2
B. 3
C. 4
D. 10

<details>
<summary>Answer</summary>

**B) 3**

</details>

### Explanation

Here `break` comes **before** the `printf`:

```text
i = 0 → 0 > 2? no → print "hi"
i = 1 → 1 > 2? no → print "hi"
i = 2 → 2 > 2? no → print "hi"
i = 3 → 3 > 2? yes → break (printf never reached)
```

`"hi"` is printed 3 times.

**Key comparison with Question 1:**

```text
Question 1: print THEN check break → 4 times
Question 9: check break THEN print → 3 times
```

The order of statements inside the loop body changes the result.

---

## Question 10

How many times will `"hi"` be printed?

```c
for (int i = 0; i <= 10; i++) {
    if (i > 2) {
        continue;
    }
    printf("hi ");
}
```

A. 2
B. 3
C. 9
D. 10

<details>
<summary>Answer</summary>

**B) 3**

</details>

### Explanation

For `i = 0, 1, 2`, the condition `i > 2` is false, so `"hi"` is printed (3 times).

For `i = 3` to `i = 10`, `continue` skips the `printf` every time. The loop still **runs** until `i = 11`, but nothing more is printed.

```text
printed: i = 0, 1, 2   → 3 times
skipped: i = 3 .. 10
```

---

# Quick Revision

## Tracing a loop by hand

```text
initial value
     ↓
condition → false? → exit
     ↓ true
body (watch for break / continue)
     ↓
update
     ↓
condition again
```

## `break` vs `continue`

| Statement | Effect |
| --------- | ------ |
| `break` | Ends the **nearest loop** immediately |
| `continue` | Skips the rest of the **current iteration only** |

## Order matters

```c
printf("hi ");        // print then check  → value is printed
if (i > 2) break;
```

```c
if (i > 2) break;     // check then print  → value is skipped
printf("hi ");
```

## Infinite loop checklist

```text
condition stays true forever?
    ↓
update moves AWAY from the stopping point?
    ↓
yes + yes → infinite loop
```

Example: `i = -4; i <= 0; i--` — `i` only gets smaller, so `i <= 0` never becomes false.

## Inclusive vs exclusive range

```text
1 to 10 inclusive → i = 1; i <= 10
1 to 10 exclusive → i = 1; i <  10
```

## Nested loop counting

Total iterations = sum of inner-loop counts for every outer iteration:

```text
outer i = 3 → 3 inner runs
outer i = 4 → 4 inner runs
outer i = 5 → 5 inner runs
Total = 3 + 4 + 5 = 12
```

---

# Common Mistakes to Remember

1. **Ignoring statement order** — `printf` before `break` gives a different count than `break` before `printf` (Questions 1 and 9).
2. **Wrong update direction** — `i--` inside a `while (i < 0)` loop creates an infinite loop (Question 3).
3. **Confusing `<=` with `<`** — inclusive vs exclusive endpoints (Questions 6 and 7).
4. **Thinking `continue` ends the loop** — it only skips one iteration; the loop keeps going (Question 8 and 10).
5. **Forgetting the outer loop may not run** — always check the outer condition first (Question 4).

---

# What to Learn Next

Directly connected to this quiz:

- **Writing loops from patterns** — printing triangles and other star patterns with nested loops
- **Loop invariants in simple problems** — why a correct update always reaches the stopping condition
- **Sum, product, min/max inside loops** — accumulator patterns from Module 6 problems
- **Time complexity basics** — a nested loop over `N` values is `O(N²)`, a single loop is `O(N)`
