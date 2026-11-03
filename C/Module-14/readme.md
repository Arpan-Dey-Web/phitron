# Module 14 — Functions: Syntax, 4 Combinations, Scope and Math Functions

Today I learned how to **write my own functions** in C: the syntax, the four combinations of
return/parameter, where variables live (scope), how function memory (the stack) works, and the
built-in math functions.

Main topics:

* Function syntax — definition and call
* The 4 combinations: return / no return × parameter / no parameter
* Variable scope — global vs local (block)
* How each function call gets its own stack memory
* Built-in math functions — `ceil`, `floor`, `round`, `sqrt`, `pow`, `abs`
* Practice: E. Swap and M. Distinct Numbers with functions

This continues from **nested loops** in [Module 13](../Module-13/readme.md).

Files:

| File | Purpose |
| ---- | ------- |
| `main.c` | The 4 function combinations (kept as comments) |
| `extrapractice.c` | Problem statements + function solutions (kept as comments) |
| `quiz.md` | Function quiz with explanations |
| `input.txt` | Last input I tested with |
| `output.txt` | Output produced for that input |

---

# 1. Function Syntax

### Definition

A **function** is a named block of code that performs one task. It can receive values
(**parameters**) and can give a value back (**return**).

### How It Works

Two parts:

```text
1. DEFINITION (the work)      2. CALL (use it from main)
```

```c
return_type function_name(parameter list)
{
    // the work happens here
    return value;              // only if return_type is not void
}
```

| Part | Meaning |
| ---- | ------- |
| `return_type` | what kind of value comes back (`int`, `char`, `void`, ...) |
| `function_name` | any valid name — follows variable naming rules |
| `parameters` | inputs the function needs (`int a, int b`) — optional |
| `return` | sends a value back to the caller — optional if type is `void` |

### Code — definition + call together

```c
#include <stdio.h>

int add(int a, int b)        // DEFINITION: takes 2 ints, returns an int
{
    int total = a + b;
    return total;
}

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);

    int total = add(a, b);   // CALL: values of a and b are passed in
    printf("%d", total);

    return 0;
}
```

```text
Input:  5 7
Output: 12
```

### Important Note

`add(a, b)` in `main` and `int a, int b` in the function are **different variables** that happen to
hold the same values. Changing the parameter inside the function does **not** change `main`'s
variables (this is called *pass by value* — the Swap practice below shows it).

---

# 2. The 4 Combinations

Every function is one of these four shapes:

| # | Return | Parameter | Signature |
| - | ------ | --------- | --------- |
| 1 | yes | yes | `int add(int a, int b)` |
| 2 | yes | no | `int add()` |
| 3 | no | yes | `void add(int a, int b)` |
| 4 | no | no | `void add()` |

## Combination 1 — return + parameter

```c
#include <stdio.h>

int add(int a, int b)
{
    int total = a + b;
    return total;
}

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    int total = add(a, b);
    printf("%d", total);
    return 0;
}
```

The caller **receives** a value and can store or print it.

## Combination 2 — return + no parameter

```c
#include <stdio.h>

int add()
{
    int a, b;
    scanf("%d %d", &a, &b);
    int total = a + b;
    return total;
}

int main()
{
    int total = add();
    printf("%d", total);
    return 0;
}
```

The function reads its **own** input inside itself, then sends the result back.

## Combination 3 — no return + parameter

```c
#include <stdio.h>

void add(int a, int b)      // void = returns nothing
{
    int total = a + b;
    printf("%d", total);
}

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    add(a, b);              // no variable can capture a result
    return 0;
}
```

The function **prints** the answer itself, so `main` gets nothing back.

## Combination 4 — no return + no parameter

```c
#include <stdio.h>

void add()
{
    int a, b;
    scanf("%d %d", &a, &b);
    int total = a + b;
    printf("%d", total);
}

int main()
{
    add();
    return 0;
}
```

The function does everything: reads, works, and prints.

### Important Correction — my original "no return" examples used `int` and then captured the result

My raw notes showed combination 3 as `int add(int a, int b)` (no `return`) with
`int total = add(a, b);` in `main`, and combination 4 as `void add()` with `int total = add();`.
Both are wrong:

```c
int add(int a, int b) { int t = a + b; printf("%d", t); }   // WRONG: declared int, never returns
int total = add(a, b);   // total receives an INDETERMINATE value — unpredictable

void add() { ... }
int total = add();       // WRONG: void function gives NO value → compile error
```

Rules:

1. If the function returns a value → declare its type (`int`, `char`, ...) **and** use `return`.
2. If it returns nothing → declare it `void`, and **never** store its call in a variable.
3. A `void` function call is a statement by itself: `add(a, b);`

---

# 3. Variable Scope

### Definition

**Scope** = the region of code where a variable can be seen and used.

### The two scopes I learned

```text
GLOBAL SCOPE      declared outside every function  → visible in ALL functions
BLOCK SCOPE       declared inside { } of a function → visible ONLY inside it
```

```c
#include <stdio.h>

int count = 10;          // GLOBAL — every function can see count

void show()
{
    printf("%d", count); // OK — reads the global
}

int main()
{
    int local = 5;       // BLOCK (local) to main
    show();

    // printf("%d", local);   // would work here
    return 0;
}
```

### Important Note

**We cannot access a variable outside its scope.** If `show()` declared its own `local`, `main`
could not read it, and vice versa.

---

# 4. How Function Memory Works (Stack)

### How It Works

```text
main() is called
  └─ computer creates a STACK (a workspace) for main
       stores main's variables, function references, return address

main calls add()
  └─ a SEPARATE stack frame is created for add
       add's parameters and locals live HERE

add() finishes
  └─ its stack frame is DESTROYED — that memory is freed
  └─ control returns to main, main's stack frame is untouched
```

Each function call gets its **own** workspace, and it is destroyed when the function returns. That
is why `add()` cannot keep anything after it finishes, and why `main`'s variables are unaffected by
`add()`'s locals.

> This will become much clearer when **pointers** and the difference between stack and heap are
> introduced later.

---

# 5. Built-in (Library) Math Functions

These live in `<math.h>` (except `abs`, which is in `<stdlib.h>` for `int`):

| Function | What it does | Example |
| -------- | ------------ | ------- |
| `ceil(num)` | smallest integer **≥** num (round up) | `ceil(4.5)` → `5` |
| `floor(num)` | largest integer **≤** num (round down) | `floor(4.5)` → `4` |
| `round(num)` | nearest integer | `round(4.5)` → `5` |
| `sqrt(num)` | square root | `sqrt(9)` → `3` |
| `pow(base, exp)` | base raised to exp | `pow(2, 3)` → `8` |
| `abs(num)` | absolute value (removes `-`) | `abs(-7)` → `7` |

### Important Corrections

1. **The square root function is `sqrt()`, not `squr()`** — and it needs `#include <math.h>`.
2. `ceil(4.5)` = **5** (up), `floor(4.5)` = **4** (down) — easy to mix up.
3. These are **built-in** functions, unlike `add()` which is **user-defined** — same calling
   syntax, but I did not write their code.
4. On some systems math functions also need linking with `-lm`
   (`gcc file.c -lm`), otherwise `undefined reference to 'pow'` appears.

```c
#include <stdio.h>
#include <math.h>

int main()
{
    double num = 4.5;
    printf("%.1f\n", ceil(num));    // 5.0
    printf("%.1f\n", floor(num));   // 4.0
    printf("%d\n", (int) pow(2, 3)); // 8
    return 0;
}
```

```text
Output:
5.0
4.0
8
```

---

# 6. Practice Problem E. Swap (using a function)

**Problem:** Given two numbers `X` and `Y`, print them swapped.

**Idea:** print `Y` first, then `X` — inside a function.

```c
#include <stdio.h>

int swap(int a, int b)
{
    int temp = 0, firstNumber, secondNumber;
    temp = a;
    firstNumber = b;
    secondNumber = temp;
    printf("%d %d", firstNumber, secondNumber);
    return 0;
}

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    int result = swap(a, b);
    return 0;
}
```

```text
Input:  5 2
Output: 2 5
```

### Important Note — pass by value

The function only **prints** the swapped values — `main`'s `a` and `b` stay `5 2`. Parameters are
copied (*pass by value*), so `swap()` cannot change `main`'s variables. To really swap the
caller's variables, **pointers** are needed — a later topic.

---

# 7. Practice Problem M. Distinct Numbers (using a function)

**Problem:** Given `N` numbers, print how many **distinct** (unique) values the array contains.

**Example:**

```text
Input:
5
1 8 9 2 9

Output:
4
```

```text
1, 8, 9, 2, 9
       ↑    ↑
     9 counted once → 1, 2, 8, 9 = 4 distinct
```

**Idea:** a frequency array (from [Module 11.5](../Module-11.5(Extra-Practice)/readme.md)) counts
how many times each value appears; every value with count `≥ 1` is one distinct number. The counting
logic goes inside a function because the problem says *solve using function*.

---

# Quick Revision

```text
definition    return_type name(params) { work; return value; }
call          name(arguments);

4 shapes      int  + params   → returns a value
              int  + no params → returns a value
              void + params   → prints/does, returns nothing
              void + no params → prints/does, returns nothing

void function call stands alone:   add(a, b);
non-void result is stored:         int t = add(a, b);

scope         global = outside all functions (visible everywhere)
              block  = inside { } (visible only there)
              cannot use a variable outside its scope

stack         each call → own stack frame → destroyed when function returns
              parameters are COPIES (pass by value)

math.h        ceil(4.5)=5   floor(4.5)=4   round(4.5)=5
              sqrt(9)=3     pow(2,3)=8     abs(-7)=7
```

---

# Important Corrections

1. **A function declared `void` must not have its result stored** — `int t = add();` is a compile
   error when `add` is `void`.
2. **A function declared `int` must return a value** — otherwise the caller gets an unpredictable
   number. If nothing is returned, declare it `void` instead.
3. **`sqrt()`, not `squr()`** — square root lives in `<math.h>`.
4. **`ceil` vs `floor`** — `ceil(4.5) = 5` (up), `floor(4.5) = 4` (down).
5. **Pass by value** — a function cannot change `main`'s variables through normal parameters; it
   only receives copies.

---

# What to Learn Next

Directly connected to this module:

- **Function prototypes** — declaring a function before `main` so order stops mattering
- **Returning from every path** — making sure every branch of an `int` function hits `return`
- **Recursion** — a function that calls itself
- **Pointers as parameters** — how to let a function really modify the caller's variables (this is
  how a true `swap()` works)
- **Void functions vs value-returning functions** — choosing the right shape for a problem
