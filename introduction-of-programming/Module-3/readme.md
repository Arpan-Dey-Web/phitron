# Day 3 — Loops in C

Today I learned about **loops in C programming**.

A loop allows us to execute the same block of code repeatedly while a particular condition is satisfied.

The three basic types of loops in C are:

1. `for` loop
2. `while` loop
3. `do-while` loop

I also learned:

* Loop initialization
* Loop condition
* Loop update
* Loop control variable
* `break`
* `continue`
* Summation using a loop

---

# 1. What is a Loop?

Suppose we want to print:

```text
I am Sorry
I am Sorry
I am Sorry
I am Sorry
I am Sorry
```

Writing `printf()` five times would work:

```c
printf("I am Sorry\n");
printf("I am Sorry\n");
printf("I am Sorry\n");
printf("I am Sorry\n");
printf("I am Sorry\n");
```

But what if we want to print it 1,000 times?

Writing the same line 1,000 times would be inefficient.

A loop allows us to tell the computer:

> Repeat this block of code until a particular condition becomes false.

So instead of writing the same code again and again, we can write:

```c
for (int i = 0; i < 5; i++) {
    printf("I am Sorry\n");
}
```

This is one of the main purposes of loops.

---

# 2. Types of Loops in C

C provides three basic loops:

```text
for loop
while loop
do-while loop
```

Their basic idea is:

```text
for
   ↓
Initialization → Condition → Body → Update

while
   ↓
Initialization → Condition → Body → Update

do-while
   ↓
Initialization → Body → Update → Condition
```

The main difference is **when the condition is checked** and how the loop is structured.

---

# 3. `for` Loop

The `for` loop is commonly used when we know how many times we want to repeat something, or when the loop follows a clear counter-based pattern.

Basic syntax:

```c
for (initialization; condition; update) {
    // code to repeat
}
```

Example:

```c
#include <stdio.h>

int main() {

    for (int i = 0; i <= 10; i++) {
        printf("I am Sorry\n");
    }

    return 0;
}
```

---

# 4. Understanding the Three Parts of a `for` Loop

Consider:

```c
for (int i = 0; i <= 10; i++) {
    printf("I am Sorry\n");
}
```

There are three important parts:

```text
int i = 0
    ↓
Initialization

i <= 10
    ↓
Condition

i++
    ↓
Update
```

Let's understand them individually.

---

## 4.1 Initialization

```c
int i = 0;
```

This is the **initialization** part.

Here we create a variable named `i` and give it the initial value `0`.

`i` is commonly used as a **loop control variable** or **counter variable**.

It helps us keep track of how many iterations have happened.

The initialization happens **once**, before the loop starts.

---

## 4.2 Condition

```c
i <= 10
```

This is the **condition**.

Before each iteration, C checks this condition.

As long as the condition is true, the loop body executes.

For example:

```text
i = 0  →  0 <= 10  → true
i = 1  →  1 <= 10  → true
i = 2  →  2 <= 10  → true
...
i = 10 → 10 <= 10 → true
i = 11 → 11 <= 10 → false
```

When the condition becomes false, the loop stops.

---

## 4.3 Update

```c
i++
```

This is the **update** part.

After each iteration, `i` is increased by 1.

For example:

```text
i = 0
i = 1
i = 2
i = 3
...
```

This allows the loop to eventually reach a condition where it becomes false.

---

# 5. Complete Execution Flow of a `for` Loop

For:

```c
for (int i = 0; i <= 10; i++) {
    printf("%d\n", i);
}
```

the execution is approximately:

```text
1. int i = 0
       ↓
2. Check i <= 10
       ↓
3. If true → execute loop body
       ↓
4. Execute i++
       ↓
5. Check i <= 10 again
       ↓
6. Repeat
       ↓
7. When condition becomes false → exit loop
```

Example:

```text
Initialization
     ↓
    i = 0
     ↓
Condition → 0 <= 10 → true
     ↓
Body
     ↓
Update → i = 1
     ↓
Condition → 1 <= 10 → true
     ↓
Body
     ↓
Update → i = 2
     ↓
...
     ↓
i = 11
     ↓
11 <= 10 → false
     ↓
Loop ends
```

---

# 6. `i++`, `i += 1`, and `i = i + 1`

These expressions all increase `i` by 1:

```c
i++;
```

```c
i += 1;
```

```c
i = i + 1;
```

For a loop update, these have the same effect:

```c
for (int i = 0; i <= 10; i++) {
}
```

and:

```c
for (int i = 0; i <= 10; i += 1) {
}
```

and:

```c
for (int i = 0; i <= 10; i = i + 1) {
}
```

All increase `i` by 1 after every iteration.

---

# 7. `i += number`

We can increase the variable by a value other than 1.

For example:

```c
i += 2;
```

means:

```c
i = i + 2;
```

And:

```c
i += 5;
```

means:

```c
i = i + 5;
```

Example:

```c
for (int i = 0; i <= 10; i += 2) {
    printf("%d\n", i);
}
```

Output:

```text
0
2
4
6
8
10
```

The value changes like this:

```text
0 → 2 → 4 → 6 → 8 → 10 → 12
```

When `i` becomes `12`:

```text
12 <= 10
```

is false, so the loop stops.

---

# 8. `i = i + number`

This is also possible.

Example:

```c
for (int i = 0; i <= 10; i = i + 2) {
    printf("%d\n", i);
}
```

This does the same thing as:

```c
for (int i = 0; i <= 10; i += 2) {
    printf("%d\n", i);
}
```

So:

```text
i += 2
```

is simply a shorter way of writing:

```text
i = i + 2
```

---

# 9. `i++` vs `i += number`

The important difference is:

```c
i++;
```

always increases `i` by exactly `1`.

While:

```c
i += number;
```

can increase `i` by any value.

Examples:

```c
i++;
```

means:

```text
i = i + 1
```

```c
i += 3;
```

means:

```text
i = i + 3
```

```c
i += 10;
```

means:

```text
i = i + 10
```

---

# 10. `i++` and `i = i + 1`

These have the same effect when used only for updating the variable:

```c
i++;
```

and:

```c
i = i + 1;
```

Both increase `i` by 1.

There is a more advanced difference when `i++` is used inside a larger expression because `i++` is a **post-increment operator**, but for today's loop topic, the important point is:

> In the update part of a loop, `i++` increases `i` by 1.

---

# 11. Loop Body

The code inside the `{ }` is called the **loop body**.

Example:

```c
for (int i = 0; i <= 10; i++) {
    printf("I am Sorry\n");
}
```

The loop body is:

```c
{
    printf("I am Sorry\n");
}
```

This code runs once for every successful iteration.

So if the loop runs 11 times, the `printf()` statement runs 11 times.

---

# 12. Example — Print Numbers from 0 to 10

```c
#include <stdio.h>

int main() {

    for (int i = 0; i <= 10; i++) {
        printf("%d\n", i);
    }

    return 0;
}
```

Output:

```text
0
1
2
3
4
5
6
7
8
9
10
```

The loop runs **11 times**, not 10 times.

Why?

Because both `0` and `10` are included:

```text
0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
```

---

# 13. Sum of 1 to N

A very important beginner problem is:

> Find the sum of all numbers from `1` to `N`.

For example, if:

```text
N = 5
```

then:

```text
1 + 2 + 3 + 4 + 5 = 15
```

We can solve this using a loop.

```c
#include <stdio.h>

int main() {

    int num;

    scanf("%d", &num);

    int totalSum = 0;

    for (int i = 1; i <= num; i++) {
        totalSum += i;
    }

    printf("%d\n", totalSum);

    return 0;
}
```

---

# 14. How the Sum Program Works

Suppose the user enters:

```text
5
```

Initially:

```text
totalSum = 0
```

Then the loop starts.

### First iteration

```text
i = 1

totalSum = 0 + 1
          = 1
```

### Second iteration

```text
i = 2

totalSum = 1 + 2
          = 3
```

### Third iteration

```text
i = 3

totalSum = 3 + 3
          = 6
```

### Fourth iteration

```text
i = 4

totalSum = 6 + 4
          = 10
```

### Fifth iteration

```text
i = 5

totalSum = 10 + 5
          = 15
```

Final result:

```text
15
```

This is an example of an **accumulator variable**.

Here:

```c
int totalSum = 0;
```

acts as the accumulator because it continuously stores the running total.

---

# 15. What is an Accumulator?

An accumulator is a variable that keeps collecting a result during repeated operations.

Example:

```c
int totalSum = 0;
```

Then:

```c
totalSum += i;
```

keeps adding the current value of `i`.

Another common example is:

```c
int product = 1;
```

and:

```c
product *= i;
```

which can be used to calculate products.

This concept will become very important in problem solving.

---

# 16. `break`

The `break` statement is used to **immediately terminate the nearest loop or switch statement**.

Example:

```c
#include <stdio.h>

int main() {

    for (int i = 0; i <= 10; i++) {

        if (i == 5) {
            break;
        }

        printf("%d\n", i);
    }

    return 0;
}
```

Output:

```text
0
1
2
3
4
```

---

# 17. How `break` Works

Let's follow the loop:

```text
i = 0 → i == 5? No → print 0
i = 1 → i == 5? No → print 1
i = 2 → i == 5? No → print 2
i = 3 → i == 5? No → print 3
i = 4 → i == 5? No → print 4
i = 5 → i == 5? Yes → break
```

When `break` executes:

```text
Current loop ends immediately
        ↓
Execution continues after the loop
```

The loop does **not** continue to:

```text
6
7
8
9
10
```

---

# 18. Important: `break` Is About the Nearest Loop

`break` must appear inside a loop or a `switch` statement.

When used inside nested loops, it terminates only the **nearest enclosing loop**.

For example:

```c
while (...) {

    for (...) {
        break;
    }

}
```

The `break` exits the `for` loop, not the outer `while` loop.

This becomes important later when working with nested loops.

---

# 19. `continue`

The `continue` statement is used to **skip the remaining part of the current iteration** and move to the next iteration.

Example:

```c
#include <stdio.h>

int main() {

    for (int i = 0; i <= 10; i++) {

        if (i == 5) {
            continue;
        }

        printf("%d\n", i);
    }

    return 0;
}
```

Output:

```text
0
1
2
3
4
6
7
8
9
10
```

Notice:

```text
5
```

is missing.

---

# 20. How `continue` Works

When:

```text
i = 5
```

this condition becomes true:

```c
if (i == 5)
```

Then:

```c
continue;
```

runs.

That means the remaining code in the current iteration is skipped.

So:

```c
printf("%d\n", i);
```

does not execute for `i = 5`.

Then the loop moves to the next iteration.

Conceptually:

```text
i = 5
   ↓
continue
   ↓
skip remaining code
   ↓
next iteration
   ↓
i = 6
```

---

# 21. `break` vs `continue`

This difference is very important.

## `break`

Stops the entire loop.

```text
Loop
 ↓
break
 ↓
EXIT LOOP
```

## `continue`

Skips only the current iteration.

```text
Loop
 ↓
continue
 ↓
SKIP CURRENT ITERATION
 ↓
NEXT ITERATION
```

### Example

```c
if (i == 5) {
    break;
}
```

Output stops at:

```text
0 1 2 3 4
```

But:

```c
if (i == 5) {
    continue;
}
```

skips only `5`:

```text
0 1 2 3 4 6 7 8 9 10
```

---

# 22. `continue` in a `for` Loop

There is an important detail about `continue` in a `for` loop.

Consider:

```c
for (int i = 0; i <= 10; i++) {

    if (i == 5) {
        continue;
    }

    printf("%d\n", i);
}
```

When `i == 5`:

```c
continue;
```

skips the `printf()` statement.

But the `i++` update still happens.

So:

```text
i = 5
 ↓
continue
 ↓
i++
 ↓
i = 6
 ↓
condition checked again
```

This is important because otherwise we might accidentally create an infinite loop in a different loop structure.

---

# 23. `while` Loop

The `while` loop repeats a block of code **as long as its condition is true**.

Syntax:

```c
while (condition) {
    // code
}
```

Example:

```c
#include <stdio.h>

int main() {

    int i = 0;

    while (i <= 10) {
        printf("%d\n", i);
        i++;
    }

    return 0;
}
```

Output:

```text
0
1
2
3
4
5
6
7
8
9
10
```

---

# 24. How `while` Loop Works

A `while` loop usually has three parts, but unlike a `for` loop they are written separately.

```c
int i = 0;

while (i <= 10) {

    printf("%d\n", i);

    i++;
}
```

Here:

```text
int i = 0;
     ↓
Initialization

while (i <= 10)
     ↓
Condition

i++;
     ↓
Update
```

Execution:

```text
Initialization
     ↓
Check condition
     ↓
If true → execute body
     ↓
Update
     ↓
Check condition again
     ↓
Repeat
```

---

# 25. `for` vs `while`

These loops can often perform the same task.

For example, this `for` loop:

```c
for (int i = 0; i <= 10; i++) {
    printf("%d\n", i);
}
```

can be written as:

```c
int i = 0;

while (i <= 10) {
    printf("%d\n", i);
    i++;
}
```

The main difference is **how the loop structure is organized**.

### `for`

Initialization, condition and update are written together:

```c
for (initialization; condition; update)
```

### `while`

They are usually written separately:

```c
initialization;

while (condition) {
    // body
    update;
}
```

---

# 26. When is `while` Useful?

A `while` loop is useful when the number of iterations is not necessarily known in advance.

For example:

```text
Keep asking for a password
until the correct password is entered.
```

The number of attempts could be:

```text
1
2
5
10
...
```

We don't necessarily know beforehand.

A `while` loop can naturally represent this:

```c
while (passwordIsWrong) {
    // ask again
}
```

---

# 27. `do-while` Loop

The third type of loop is:

```text
do-while
```

Syntax:

```c
do {
    // code
} while (condition);
```

Example:

```c
#include <stdio.h>

int main() {

    int i = 0;

    do {
        printf("%d\n", i);
        i++;

    } while (i <= 10);

    return 0;
}
```

Output:

```text
0
1
2
3
4
5
6
7
8
9
10
```

---

# 28. Main Difference of `do-while`

The biggest difference between `while` and `do-while` is:

> `do-while` executes the loop body **at least once** before checking the condition.

Example:

```c
int i = 20;

do {
    printf("%d\n", i);
    i++;
} while (i <= 10);
```

What happens?

First, the body runs:

```text
20
```

Then:

```text
i <= 10
```

is checked:

```text
20 <= 10
```

which is false.

So the loop ends.

Output:

```text
20
```

Even though the condition was false from the beginning.

---

# 29. `while` vs `do-while`

Consider:

```c
int i = 20;

while (i <= 10) {
    printf("%d\n", i);
    i++;
}
```

The condition is checked first:

```text
20 <= 10
```

False.

Therefore the body runs **zero times**.

But:

```c
int i = 20;

do {
    printf("%d\n", i);
    i++;
} while (i <= 10);
```

The body runs first.

Therefore it runs **one time**.

This is the key difference:

```text
while
→ condition first
→ body may run 0 times

do-while
→ body first
→ condition afterward
→ body runs at least 1 time
```

---

# 30. Loop Comparison

| Loop       | Condition Checked     | Minimum Executions |
| ---------- | --------------------- | -----------------: |
| `for`      | Before each iteration |                  0 |
| `while`    | Before each iteration |                  0 |
| `do-while` | After each iteration  |                  1 |

---

# 31. Loop Control Flow

## `for`

```text
Initialization
      ↓
Condition
      ↓
   true?
   ↙   ↘
 yes    no
  ↓      ↓
Body     Exit
  ↓
Update
  ↓
Condition again
```

## `while`

```text
Initialization
      ↓
Condition
      ↓
   true?
   ↙   ↘
 yes    no
  ↓      ↓
Body     Exit
  ↓
Update
  ↓
Condition again
```

## `do-while`

```text
Initialization
      ↓
Body
      ↓
Update
      ↓
Condition
      ↓
   true?
   ↙   ↘
 yes    no
  ↓      ↓
Body    Exit
```

---

# 32. Common Loop Mistakes

## Forgetting the update

Example:

```c
int i = 0;

while (i <= 10) {
    printf("%d\n", i);
}
```

Here `i` never changes.

So:

```text
i = 0
i = 0
i = 0
i = 0
...
```

The condition remains true forever.

This creates an **infinite loop**.

The correct version is:

```c
int i = 0;

while (i <= 10) {
    printf("%d\n", i);
    i++;
}
```

---

## Wrong condition

Example:

```c
for (int i = 0; i >= 10; i++) {
    printf("%d\n", i);
}
```

The condition:

```text
0 >= 10
```

is already false.

So the loop executes zero times.

---

# 33. Infinite Loop

A loop becomes infinite when its stopping condition is never reached.

Example:

```c
while (1) {
    printf("Hello\n");
}
```

Since:

```text
1
```

is non-zero, the condition is always true.

Therefore the loop does not stop by itself.

We can stop it with:

```c
break;
```

Example:

```c
while (1) {

    int x;

    scanf("%d", &x);

    if (x == 0) {
        break;
    }
}
```

This loop continues until the user enters `0`.

---

# 34. Important Mental Model for Loops

Every loop should be understood using three questions:

### 1. Where does it start?

```text
Initialization
```

Example:

```c
int i = 0;
```

### 2. When does it stop?

```text
Condition
```

Example:

```c
i <= 10
```

### 3. How does it move toward the stopping point?

```text
Update
```

Example:

```c
i++
```

So:

```text
START → CONDITION → WORK → UPDATE → CONDITION → ...
```

This mental model will be extremely useful when solving programming problems.

---

# 35. Quick Revision

## `for`

```c
for (int i = 0; i <= 10; i++) {
    printf("%d\n", i);
}
```

Structure:

```text
for (initialization; condition; update)
```

---

## `while`

```c
int i = 0;

while (i <= 10) {
    printf("%d\n", i);
    i++;
}
```

---

## `do-while`

```c
int i = 0;

do {
    printf("%d\n", i);
    i++;
} while (i <= 10);
```

The semicolon after:

```c
while (i <= 10);
```

is required.

---

## `break`

```c
if (condition) {
    break;
}
```

Meaning:

> Stop the nearest loop immediately.

---

## `continue`

```c
if (condition) {
    continue;
}
```

Meaning:

> Skip the rest of the current iteration and continue with the next iteration.

---

## Accumulator

```c
int sum = 0;

for (int i = 1; i <= n; i++) {
    sum += i;
}
```

Used to keep a running result.

---

# Important Corrections from My Original Notes

### 1. Output of the `break` example

Your original loop starts with:

```c
int i = 0;
```

so the output is:

```text
0 1 2 3 4
```

not:

```text
1 2 3 4
```

because `0` is printed before `i` reaches `5`.

---

### 2. Output of the `continue` example

Similarly, the original loop starts from `0`.

So the output is:

```text
0 1 2 3 4 6 7 8 9 10
```

not:

```text
1 2 3 4 6 7 8 9 10
```

Only `5` is skipped.

---

### 3. `i++` does not mean "increase by any number"

It specifically means:

```c
i = i + 1;
```

For other increments, use:

```c
i += 2;
i += 5;
i += 10;
```

or:

```c
i = i + 2;
i = i + 5;
i = i + 10;
```

---

### 4. `continue` does not end the loop

`continue` only skips the current iteration.

The loop itself continues.

`break` ends the nearest loop completely.

---

### 5. `do-while` runs at least once

Even if the condition is false initially:

```c
do {
    // runs first
} while (condition);
```

the body executes once before the condition is checked.

---

# What to Learn Next

The most useful next concepts connected directly to today's lesson are:

* **Nested loops** — putting one loop inside another.
* **Loop patterns** — counting, accumulating, finding maximum/minimum, counting digits.
* **Increment/decrement** — `++`, `--`, prefix vs postfix.
* **Operator precedence** — understanding expressions such as `i + 1 < n`.
* **Time complexity basics** — understanding why one loop may be `O(n)` and nested loops may be `O(n²)`.

For today's lesson, the most important thing is to become completely comfortable tracing a loop manually:

```text
initial value
     ↓
condition
     ↓
body
     ↓
update
     ↓
condition again
```

If you can trace those five steps correctly, you have understood the core idea of loops.
