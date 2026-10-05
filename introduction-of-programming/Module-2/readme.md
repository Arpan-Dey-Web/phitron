# Day 2 — Operators and Conditional Statements in C

Today I learned about:

* Arithmetic Operators
* Relational Operators
* Logical Operators
* Conditional Statements
* `if`
* `if-else`
* `if-else-if` ladder
* Nested `if`
* Multiple independent `if` statements
* The difference between `=` and `==`

---

# 1. Operators

An **operator** is a symbol that tells the compiler to perform a particular operation on one or more values.

For example:

```c
a + b
```

Here:

```text
a → operand
+ → operator
b → operand
```

So we can think of it as:

```text
operand + operator + operand
```

An operator works on its **operands** and produces a result.

There are different types of operators in C.

Today I learned three important categories:

```text
Arithmetic Operators
Relational Operators
Logical Operators
```

---

# 2. Arithmetic Operators

Arithmetic operators are used to perform mathematical calculations.

C has 5 basic arithmetic operators:

| Operator | Name           | Example |
| -------- | -------------- | ------- |
| `+`      | Addition       | `a + b` |
| `-`      | Subtraction    | `a - b` |
| `*`      | Multiplication | `a * b` |
| `/`      | Division       | `a / b` |
| `%`      | Modulus        | `a % b` |

---

## 2.1 Addition `+`

Used to add two values.

```c
int a = 10;
int b = 5;

printf("%d\n", a + b);
```

Output:

```text
15
```

---

## 2.2 Subtraction `-`

Used to subtract one value from another.

```c
int a = 10;
int b = 5;

printf("%d\n", a - b);
```

Output:

```text
5
```

---

## 2.3 Multiplication `*`

Used to multiply two values.

```c
int a = 10;
int b = 5;

printf("%d\n", a * b);
```

Output:

```text
50
```

---

## 2.4 Division `/`

Used to divide one value by another.

```c
int a = 10;
int b = 5;

printf("%d\n", a / b);
```

Output:

```text
2
```

### Important: Integer Division

When both operands are integers, C performs **integer division**.

Example:

```c
int a = 10;
int b = 3;

printf("%d\n", a / b);
```

Output:

```text
3
```

It does not print:

```text
3.333333
```

because both `a` and `b` are `int`.

If we use a floating-point value:

```c
float a = 10.0f;
float b = 3.0f;

printf("%f\n", a / b);
```

we can get a decimal result.

So:

```text
10 / 3 using int   → 3
10.0 / 3.0         → approximately 3.333333
```

---

## 2.5 Modulus `%`

The modulus operator gives the **remainder** after division.

Example:

```c
int a = 10;
int b = 3;

printf("%d\n", a % b);
```

Output:

```text
1
```

Because:

```text
10 ÷ 3 = 3 remainder 1
```

Therefore:

```text
10 % 3 = 1
```

Another example:

```c
17 % 5 = 2
```

because:

```text
17 ÷ 5 = 3 remainder 2
```

### Important

The `%` operator is used with **integer operands**.

It is very important in problem solving because it is commonly used for:

* checking even/odd numbers
* finding remainders
* extracting digits
* cyclic calculations
* divisibility checks

Example:

```c
int number = 10;

if (number % 2 == 0) {
    printf("Even");
}
```

---

# 3. Complete Arithmetic Example

```c
#include <stdio.h>

int main() {
    int a = 10;
    int b = 5;

    printf("Addition = %d\n", a + b);
    printf("Subtraction = %d\n", a - b);
    printf("Multiplication = %d\n", a * b);
    printf("Division = %d\n", a / b);
    printf("Modulus = %d\n", a % b);

    return 0;
}
```

Output:

```text
Addition = 15
Subtraction = 5
Multiplication = 50
Division = 2
Modulus = 0
```

Because:

```text
10 + 5 = 15
10 - 5 = 5
10 × 5 = 50
10 ÷ 5 = 2
10 % 5 = 0
```

---

## Important Note

It is not always correct to say:

> Arithmetic operators always return a numerical value.

A better statement is:

> Arithmetic operators perform mathematical operations and produce a result whose type depends on the operands.

For example:

```c
int a = 10;
int b = 3;

a / b
```

produces an integer result.

While:

```c
double a = 10.0;
double b = 3.0;

a / b
```

produces a floating-point result.

---

# 4. Relational Operators

Relational operators are used to **compare two values**.

C has 6 relational operators:

| Operator | Meaning                  | Example  |
| -------- | ------------------------ | -------- |
| `<`      | Less than                | `a < b`  |
| `<=`     | Less than or equal to    | `a <= b` |
| `>`      | Greater than             | `a > b`  |
| `>=`     | Greater than or equal to | `a >= b` |
| `==`     | Equal to                 | `a == b` |
| `!=`     | Not equal to             | `a != b` |

---

# 5. Understanding Relational Operators

Suppose:

```c
int a = 10;
int b = 5;
```

Then:

```text
a < b
```

means:

```text
10 < 5
```

which is false.

Similarly:

```text
a > b
```

means:

```text
10 > 5
```

which is true.

---

## Result of a Relational Expression in C

Relational expressions produce:

```text
0 → false
1 → true
```

Strictly speaking, in C the result type of a relational operator is `int`.

Example:

```c
int a = 10;
int b = 5;

printf("%d\n", a > b);
printf("%d\n", a < b);
```

Output:

```text
1
0
```

So it is better to remember:

```text
true  → 1
false → 0
```

rather than saying that relational operators return the C `bool` type.

---

# 6. `==` vs `=`

This is one of the most important things to understand.

## `=` means assignment

```c
int money = 100;
```

Here:

```text
= → assignment operator
```

It assigns `100` to `money`.

---

## `==` means comparison

```c
money == 100
```

This asks:

> Is the value of `money` equal to `100`?

The result is:

```text
1 → yes / true
0 → no / false
```

### Remember

```text
=  → put/store a value
== → compare two values
```

Example:

```c
int money = 100;

if (money == 100) {
    printf("Money is 100");
}
```

---

# 7. Logical Operators

Logical operators are used to combine or modify conditions.

There are 3 main logical operators:

| Operator | Name        |   |            |
| -------- | ----------- | - | ---------- |
| `&&`     | Logical AND |   |            |
| `        |             | ` | Logical OR |
| `!`      | Logical NOT |   |            |

---

# 8. Logical AND `&&`

`&&` means **AND**.

Both conditions must be true for the complete expression to be true.

Example:

```c
int age = 25;
int money = 100;

if (age >= 18 && money >= 50) {
    printf("Condition is true");
}
```

We have two conditions:

```text
age >= 18
money >= 50
```

Both are true, so:

```text
true && true = true
```

Result:

```text
1
```

### Truth Table

| A     | B     | A `&&` B |
| ----- | ----- | -------- |
| false | false | false    |
| false | true  | false    |
| true  | false | false    |
| true  | true  | true     |

So the simple rule is:

> **AND requires both sides to be true.**

---

# 9. Logical OR `||`

`||` means **OR**.

At least one condition must be true.

Example:

```c
int age = 15;

if (age < 18 || age > 60) {
    printf("Special condition");
}
```

The two conditions are:

```text
age < 18
age > 60
```

For `age = 15`:

```text
true || false = true
```

So the condition is true.

### Truth Table

| A | B | A `||` B |
|---|---|---|
| false | false | false |
| false | true | true |
| true | false | true |
| true | true | true |

Simple rule:

> **OR requires at least one side to be true.**

---

# 10. Logical NOT `!`

`!` means **NOT**.

It reverses the logical value.

```text
true  → false
false → true
```

Example:

```c
int isRaining = 0;

if (!isRaining) {
    printf("I will go outside");
}
```

Since:

```text
isRaining = false
```

then:

```text
!isRaining = true
```

So the message will be printed.

### Important

Unlike `&&` and `||`, the `!` operator works with **one operand**.

So:

```c
!condition
```

is correct.

---

# 11. Short-Circuit Evaluation

An important behavior of logical operators is **short-circuit evaluation**.

For `&&`:

> If the left side is false, C does not need to evaluate the right side.

For `||`:

> If the left side is true, C does not need to evaluate the right side.

Example:

```c
if (0 && something) {
    printf("Hello");
}
```

Because the first condition is already false, the complete `&&` expression must be false.

Similarly:

```c
if (1 || something) {
    printf("Hello");
}
```

Because the first condition is already true, the complete `||` expression must be true.

This becomes very useful later when working with conditions, pointers, and problem-solving.

---

# 12. Conditional Statements

A conditional statement allows a program to **make decisions**.

Real-life example:

```text
If I have enough money:
    I will eat biriyani.

Otherwise:
    I will drink tea.
```

In C, we can write this using `if` and `else`.

---

# 13. `if` Statement

The basic syntax is:

```c
if (condition) {
    // code
}
```

Example:

```c
#include <stdio.h>

int main() {
    int money = 50;

    if (money <= 100) {
        printf("I will eat biriyani");
    }

    return 0;
}
```

Here the condition is:

```c
money <= 100
```

Since:

```text
50 <= 100
```

is true, the code inside the `if` block runs.

Output:

```text
I will eat biriyani
```

---

# 14. How `if` Works

The general flow is:

```text
Condition
   ↓
 Is it true?
   ↓
 ┌─────────────┐
 │             │
Yes           No
 │             │
 ↓             ↓
Run if       Skip if
block        block
```

Example:

```c
if (money <= 100) {
    printf("Eat biriyani");
}
```

If:

```text
money = 50
```

then:

```text
50 <= 100 → true
```

so the block executes.

---

# 15. `if-else` Statement

Sometimes we want to execute one block when the condition is true and another block when it is false.

Syntax:

```c
if (condition) {
    // true
}
else {
    // false
}
```

Example:

```c
#include <stdio.h>

int main() {
    int money = 50;

    if (money <= 100) {
        printf("I will eat biriyani");
    }
    else {
        printf("I will drink a cup of tea");
    }

    return 0;
}
```

For:

```text
money = 50
```

the condition:

```text
50 <= 100
```

is true.

So the output is:

```text
I will eat biriyani
```

---

# 16. Important Understanding of `else`

`else` belongs to the **nearest preceding `if` that has not already been matched by another `else`**.

For beginner-level code, the easiest way to think about it is:

```text
if condition is true
    → run if block

otherwise
    → run else block
```

An `if` does **not require** an `else`.

This is completely valid:

```c
if (money <= 100) {
    printf("Eat biriyani");
}
```

If the condition is false, the program simply skips the block and continues with the next statement.

---

# 17. `if-else-if` Ladder

When we need to check multiple conditions, we can use an `if-else-if` ladder.

Structure:

```c
if (condition1) {
    // code
}
else if (condition2) {
    // code
}
else if (condition3) {
    // code
}
else {
    // code
}
```

Example:

```c
#include <stdio.h>

int main() {
    int money = 50;

    if (money <= 30) {
        printf("I will drink tea");
    }
    else if (money <= 70) {
        printf("I will eat fuchka");
    }
    else if (money <= 100) {
        printf("I will eat biriyani");
    }
    else {
        printf("I will go for a tour");
    }

    return 0;
}
```

For:

```text
money = 50
```

the program checks:

```text
money <= 30 → false
money <= 70 → true
```

So it prints:

```text
I will eat fuchka
```

After finding the first true condition, the remaining conditions in that ladder are skipped.

---

# 18. Order Matters in an `if-else-if` Ladder

Consider:

```c
int money = 50;

if (money <= 100) {
    printf("Biriyani");
}
else if (money > 30) {
    printf("Fuchka");
}
else {
    printf("Tea");
}
```

For `money = 50`:

```text
money <= 100
     ↓
    true
```

So `Biriyani` is printed.

The:

```c
else if (money > 30)
```

is **not checked**, because the first `if` was already true.

Therefore:

> In an `if-else-if` ladder, the program executes only the **first true condition**.

This is why the order of conditions is important.

---

# 19. Nested `if`

A **nested `if`** means placing one `if` statement inside another `if` statement.

Example:

```c
#include <stdio.h>

int main() {
    int money = 50;

    if (money <= 100) {
        printf("I will eat biriyani\n");

        if (money <= 50) {
            printf("I will drink coffee\n");
        }
        else {
            printf("I will go back\n");
        }
    }
    else {
        printf("I will drink tea\n");
    }

    return 0;
}
```

Here we have:

```text
Outer if
   ↓
money <= 100
   ↓
true
   ↓
Inner if
   ↓
money <= 50
```

For:

```text
money = 50
```

both conditions are true.

Output:

```text
I will eat biriyani
I will drink coffee
```

---

# 20. Why Use Nested `if`?

Nested conditions are useful when one decision depends on another decision.

For example:

```text
If the user is logged in:
    check whether the user is an admin
```

Conceptually:

```text
Is user logged in?
       ↓
      Yes
       ↓
Is user admin?
       ↓
      Yes
       ↓
Give admin access
```

So the second condition is meaningful only after the first condition is satisfied.

---

# 21. Multiple Independent `if` Statements

This is a very important difference.

We can write:

```c
if (condition1) {
    // code
}

if (condition2) {
    // code
}

if (condition3) {
    // code
}
```

These are **three independent `if` statements**.

They are not an `if-else-if` ladder.

Each condition is checked separately.

---

## Example

```c
#include <stdio.h>

int main() {
    int money = 1000;

    if (money <= 100) {
        printf("I will eat biriyani\n");
    }

    if (money == 1000) {
        printf("I will go for a tour\n");
    }

    if (money < 500) {
        printf("I will go for a walk\n");
    }

    return 0;
}
```

Let's check them one by one.

### First condition

```text
1000 <= 100
```

False.

So nothing is printed.

### Second condition

```text
1000 == 1000
```

True.

So:

```text
I will go for a tour
```

is printed.

### Third condition

```text
1000 < 500
```

False.

So nothing is printed.

Final output:

```text
I will go for a tour
```

---

# 22. `if` Does Not Always Need `else`

One important correction from the original note:

It is **not necessary** for every `if` block to end with `else`.

This is perfectly valid:

```c
if (money <= 100) {
    printf("Eat biriyani");
}

if (money == 1000) {
    printf("Go for a tour");
}
```

These are two separate conditions.

The program checks both.

So:

```text
if
if
if
```

means:

> Check all three separately.

While:

```text
if
else if
else
```

means:

> Check the conditions as one chain and execute only the first matching branch.

---

# 23. Very Important Mistake — `=` Instead of `==`

Consider this:

```c
if (money = 1000) {
    printf("I will go for a tour");
}
```

This is **not a comparison**.

Here:

```c
money = 1000
```

is an assignment.

It changes `money` to `1000`.

The assignment expression itself has the value:

```text
1000
```

Since `1000` is non-zero, C treats it as **true** in a condition.

So this `if` will execute.

Example:

```c
int money = 50;

if (money = 1000) {
    printf("Tour");
}
```

After the assignment:

```text
money = 1000
```

and the condition evaluates as true.

Output:

```text
Tour
```

### This is a common beginner mistake

Wrong:

```c
if (money = 1000)
```

Correct:

```c
if (money == 1000)
```

Remember:

```text
=  → assignment
== → comparison
```

---

# 24. Conditions in C

A condition does not necessarily need to be literally `true` or `false`.

In C:

```text
0      → false
non-zero → true
```

For example:

```c
int x = 10;

if (x) {
    printf("True");
}
```

Since `x` is `10`, which is non-zero, the condition is true.

But:

```c
int x = 0;

if (x) {
    printf("True");
}
```

will not print anything because `0` means false.

This becomes very important later when learning pointers and other C concepts.

---

# 25. Corrected Version of the Final Example

The original example contained:

```c
if (money = 1000)
```

and:

```c
if (money < 500>)
```

Both require attention.

The correct version is:

```c
#include <stdio.h>

int main() {
    int money = 1000;

    if (money <= 100) {
        printf("I will eat biriyani\n");
    }

    if (money == 1000) {
        printf("I will go for a tour\n");
    }

    if (money < 500) {
        printf("I will go for a walk\n");
    }

    return 0;
}
```

Output:

```text
I will go for a tour
```

The three `if` statements are independent, so all three conditions are checked.

---

# 26. Difference Between `if-else-if` and Multiple `if`

This difference should be very clear.

## `if-else-if`

```c
if (condition1) {
    ...
}
else if (condition2) {
    ...
}
else {
    ...
}
```

Flow:

```text
condition 1
    ↓
 true → execute and stop checking this ladder
    ↓
 false
    ↓
condition 2
    ↓
 true → execute and stop
    ↓
 false
    ↓
else
```

Only **one branch** is executed.

---

## Multiple `if`

```c
if (condition1) {
    ...
}

if (condition2) {
    ...
}

if (condition3) {
    ...
}
```

Flow:

```text
condition 1 → check
condition 2 → check
condition 3 → check
```

Every condition is checked independently.

Therefore, **multiple blocks can execute**.

---

# 27. Quick Comparison

| Structure     | How it works                                           |
| ------------- | ------------------------------------------------------ |
| `if`          | Runs code only when condition is true                  |
| `if-else`     | Chooses between two branches                           |
| `if-else-if`  | Checks multiple conditions; first true branch executes |
| Nested `if`   | An `if` inside another `if`                            |
| Multiple `if` | Every `if` is checked independently                    |

---

# 28. Quick Revision

## Arithmetic Operators

```text
+ → Addition
- → Subtraction
* → Multiplication
/ → Division
% → Remainder
```

Example:

```c
10 % 3
```

Result:

```text
1
```

---

## Relational Operators

```text
<   → Less than
<=  → Less than or equal
>   → Greater than
>=  → Greater than or equal
==  → Equal
!=  → Not equal
```

They produce:

```text
0 → false
1 → true
```

---

## Logical Operators

```text
&& → AND
|| → OR
!  → NOT
```

Remember:

```text
A && B → both must be true
A || B → at least one must be true
!A     → reverses A
```

---

## Conditional Statements

```c
if (condition) {
    // code
}
```

```c
if (condition) {
    // code
}
else {
    // code
}
```

```c
if (condition1) {
    // code
}
else if (condition2) {
    // code
}
else {
    // code
}
```

Nested:

```c
if (condition1) {

    if (condition2) {
        // code
    }
}
```

Independent:

```c
if (condition1) {
    // code
}

if (condition2) {
    // code
}
```

---

# Important Corrections from My Original Notes

### 1. Relational operators do not literally return C `bool`

In C, relational and equality expressions produce an `int` result:

```text
true  → 1
false → 0
```

We often describe this as a Boolean result because the expression represents true/false logically.

---

### 2. `!` is different from `&&` and `||`

`&&` and `||` work with two operands:

```c
a && b
a || b
```

But `!` works with one operand:

```c
!a
```

---

### 3. `if` does not require `else`

This is valid:

```c
if (condition) {
    // code
}
```

When the condition is false, C simply skips that block and continues.

---

### 4. `if-else-if` does not execute every true-looking condition

Once one condition in an `if-else-if` ladder is true, its branch executes and the remaining branches in that ladder are skipped.

---

### 5. Separate `if` statements are independent

```c
if (a) {}
if (b) {}
if (c) {}
```

All three conditions can execute.

They are different from:

```c
if (a) {}
else if (b) {}
else if (c) {}
```

where only the first matching branch executes.

---

### 6. `=` and `==` are completely different

```c
=
```

means assignment.

```c
==
```

means comparison.

This is one of the most important mistakes to avoid when writing conditions.

---

# What to Learn Next

Based directly on today's topics, the next useful concepts are:

* **Operator precedence and associativity** — understand which operation happens first.
* **Assignment operators** — `=`, `+=`, `-=`, `*=`, `/=`, `%=` .
* **Increment and decrement** — `++` and `--`.
* **Type conversion / type casting** — especially important for division and comparisons.
* **`switch` statement and ternary operator (`?:`)** — other ways to write conditional logic.

For future high-level interview problem solving, today's most important foundation is being completely comfortable with **conditions, comparison, logical expressions, integer division, modulus, and `=` vs `==`**.
