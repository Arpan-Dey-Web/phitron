# Module 17 — Recursion

Today I learned what **recursion** is: a function that calls **itself**. Before that I understood
the **call stack** — how C keeps track of which function is running and cleans up after it. I also
learned how to *control* a recursive function with a **base case**, and what happens when there is
no base case (**stack overflow**).

Main topics:

* The call stack — how function calls are stored and removed
* Recursion — a function calling itself
* Stack overflow — what happens without a stop condition
* Base case — the condition that stops the recursion
* Printing 1..N and N..1 with recursion
* Printing *after* the recursive call (the tricky order)
* Recursing over an array with an index parameter

This continues from **functions** in [Module 14](../Module-14/readme.md) and **arrays** in
[Module 7](../Module-7/readme.md).

Files:

| File | Purpose |
| ---- | ------- |
| `main.c` | Concepts + my code (kept as block comments) |
| `extrapractice.c` | Extra-practice problems (A, B, C, F) + solutions |
| `quiz.md` | Practice quiz with answers and explanations |
| `input.txt` | Last input I tested with (extra-practice problem F) |
| `output.txt` | Output produced for that input |

---

# 1. The Call Stack

### Definition

The **call stack** is the memory area C uses to keep track of function calls. Every time a function
is called, a new **frame** is pushed onto the stack; when the function finishes, its frame is
**removed** automatically.

### How It Works

```text
main() calls hello()
  hello() calls good_Morning()
  good_Morning() finishes  →  its frame is popped off
  hello() calls good_Night()
  good_Night() finishes    →  its frame is popped off
hello() finishes           →  its frame is popped off
main() finishes            →  stack is empty again
```

Stack is **LIFO** — Last In, First Out. The function called *last* is the one that finishes
*first*.

### Code

```c
#include <stdio.h>

void good_Morning();      /* declared before hello() uses them */
void good_Night();

void hello()
{
    printf("Hello\t");
    good_Morning();
    good_Night();
}

void good_Morning()
{
    printf("Good Morning!!!\n");
}

void good_Night()
{
    printf("Good Night!!!\n");
}

int main()
{
    printf("Arpan\n");
    hello();
    return 0;
}
```

### Output

```text
Arpan
Hello	Good Morning!!!
Good Night!!!
```

### Important Note

My first version called `good_Morning()` and `good_Night()` **before** the compiler had seen them.
Modern compilers reject or warn about that (implicit declaration), so the prototypes go on top:

```c
void good_Morning();      /* prototype: "this function exists, it returns void" */
void good_Night();
```

A frame is removed **only after the whole function finishes** — not in the middle. Whatever a
function still needs (its variables) stays alive until its `return`.

---

# 2. What Is Recursion?

### Definition

**Recursion** is when a function calls **itself**.

```text
normal function   →  calls another function, comes back
recursive function→  calls ITSELF, again and again
```

### Code — recursion without a stop

```c
#include <stdio.h>

void hello()          /* recursive function */
{
    printf("Hello\t");
    hello();          /* calls itself */
}

int main()
{
    hello();
    return 0;
}
```

### Important Note — do not run the code above

There is **nothing that stops it**. `hello()` pushes a new frame, which calls `hello()` again,
which pushes another frame... forever. This is an **infinite recursion** — it compiles fine, the
problem only appears at **runtime**.

---

# 3. Stack Overflow

### Definition

The stack has a **fixed size** (implementation-dependent — typically a few MB). If a recursive
function keeps calling itself without stopping, frames pile up until the stack is **full**. That
crash is called a **stack overflow**.

### The Growing Stack

```text
┌──────────┐
│ hello()  │  ← newest frame
├──────────┤
│ hello()  │
├──────────┤
│ hello()  │
├──────────┤
│ hello()  │
├──────────┤
│ main()   │  ← oldest frame, at the bottom
└──────────┘
   stack keeps growing until there is no room left
        ↓
   Stack Overflow — program crashes
```

### Important Note

A **compile error** and a **stack overflow** are different things:

```text
syntax mistake      → does not compile      (found before running)
no base case        → compiles, then crashes (found while running)
```

---

# 4. Base Case — Controlling Recursion

### Definition

The **base case** is the condition that tells the recursive function to **stop**. Every recursive
function needs one, otherwise it never returns.

### Example 4a — Print 1 to 5

```c
#include <stdio.h>

void hello(int i)
{
    if (i == 6)          /* base case: stop before 6 */
    {
        return;
    }

    printf("%d\n", i);   /* print FIRST ... */
    hello(i + 1);        /* ... then recurse */
}

int main()
{
    int i = 1;
    hello(i);
    return 0;
}
```

### Output

```text
1
2
3
4
5
```

**Trace:**

```text
hello(1) → print 1 → hello(2) → print 2 → hello(3) → print 3
          → hello(4) → print 4 → hello(5) → print 5 → hello(6)
          → i == 6, return (unwinding back through every call)
```

### Example 4b — Print N to 1

```c
#include <stdio.h>

void hello(int n)
{
    printf("%d\n", n);   /* print FIRST ... */
    if (n == 1)          /* base case */
    {
        return;
    }
    hello(n - 1);        /* ... then recurse */
}

int main()
{
    int n;
    scanf("%d", &n);
    hello(n);
    return 0;
}
```

### Output — input `4`

```text
4
3
2
1
```

### Example 4c — The Tricky One: Print *After* the Call

```c
#include <stdio.h>

void hello(int n)
{
    if (n == 4)          /* base case */
    {
        return;
    }

    hello(n + 1);        /* recurse FIRST ... */
    printf("%d\n", n);   /* ... then print on the way back */
}

int main()
{
    int n = 1;
    hello(n);
    return 0;
}
```

### Output

```text
3
2
1
```

**Why 3 2 1 and not 1 2 3?**

```text
call order   : hello(1) → hello(2) → hello(3) → hello(4) returns
print order  :        (nothing yet)   print 3, then 2, then 1
```

The `printf` sits **after** the recursive call, so it only runs while the calls **unwind** — last
called, first printed (LIFO again). Same idea as the call stack itself.

### Important Note

```text
printf BEFORE the call  →  prints on the way DOWN   (1 2 3 4 5)
printf AFTER  the call  →  prints on the way BACK   (5 4 3 2 1)
```

The base case decides *when to stop*; the position of `printf` decides *the print order*.

---

# 5. Recursing Over an Array

An array is processed by carrying an **index** that grows by one each call, and stopping when it
reaches `n`.

```c
#include <stdio.h>

void print_Array(int a[], int n, int idx)
{
    if (idx == n)          /* base case: past the last element */
    {
        return;
    }
    printf("%d\n", a[idx]);
    print_Array(a, n, idx + 1);   /* next element */
}

int main()
{
    int n;
    scanf("%d", &n);

    int a[n];
    for (int i = 0; i < n; i++)    /* NOTE: i < n, not i <= n */
    {
        scanf("%d", &a[i]);
    }

    print_Array(a, n, 0);          /* start at index 0 */
    return 0;
}
```

### Output — input `3` then `10 20 30`

```text
10
20
30
```

### Important Note — my bug

My first loop was `for (int i = 0; i <= n; i++)`. That reads **n + 1** values into an array of
size **n** — writing one slot past the end of the array (undefined behaviour). The read loop must
be `i < n`.

The parameter `int a[]` is really a **pointer** to the caller's array (Module 15) — no copy of the
array is made.

---

# Quick Revision

```text
call stack   LIFO; a frame is pushed on call, popped when the function finishes

recursion    a function that calls itself

base case    the condition that stops the recursion — every recursive
             function needs one

no base case → infinite recursion → stack overflow (runtime crash,
             not a compile error)

print before the call → on the way down    (1 2 3)
print after  the call → on the way back    (3 2 1)

array recursion: pass idx, stop when idx == n, recurse with idx + 1
loop bound is i < n — i <= n reads one element too many

prototypes go on top so the compiler knows the functions exist
```

---

# Important Corrections

### 1. Stack frames are removed only when the function fully finishes

My original note said a frame stays "until the function completely executes" — correct, and worth
keeping: C never removes half a frame; variables die together with their frame.

### 2. The array loop bound

```text
wrong   for (int i = 0; i <= n; i++)   → n+1 reads, out of bounds
right   for (int i = 0; i < n;  i++)   → exactly n reads
```

### 3. "Infinite recursion" is not a syntax error

The self-calling `hello()` compiles perfectly. The crash happens at **run** time when the stack
fills up.

### 4. The unfinished "print an array" section

My raw note ended with an empty `<!-- print an array -->` placeholder. Section 5 now completes it
with working, tested code.

---

# What to Learn Next

Directly connected to this module:

- **Recursion vs iteration** — solving the same problem with a loop and with recursion
- **Classic examples** — factorial, sum of an array, counting digits
- **String recursion** — print a string from the last character, or reverse it
- **Deeper call stacks** — why a very deep recursion can still overflow (and what tail
  recursion is)
