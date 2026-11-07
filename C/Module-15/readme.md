# Module 15 — Pointers

Today I learned what a **pointer** is, how to create and use one, and the two ways of handing data
to a function: **pass by value** and **pass by reference**. I also saw that an array name behaves
like a pointer — which explains why `scanf()` always needs `&`.

Main topics:

* What a pointer is, declaration and initialization
* Dereferencing
* Pass by value vs pass by reference
* Why `scanf()` needs an address
* Pointers and arrays
* Why functions receive arrays by reference
* Passing a string to a function

This continues from **arrays** in [Module 7](../Module-7/readme.md) and **strings** in
[Module 10](../Module-10/readme.md).

Files:

| File | Purpose |
| ---- | ------- |
| `main.c` | Problem statements + my solutions (kept as comments) |
| `quiz.md` | (empty — practice notes only) |
| `input.txt` | Last input I tested with |
| `output.txt` | Output produced for that input |

---

# 1. What Is a Pointer?

### Definition

A **pointer** is a variable that stores **the memory address of another variable**.

```text
normal variable  →  holds a VALUE      (x holds 10)
pointer variable →  holds an ADDRESS   (ptr holds the address of x)
```

### Declaration and Initialization

```text
syntax:   data_type  *pointerVariableName ;

int *ptr;              // declared, points nowhere yet
```

Give it an address with the **address-of operator `&`**:

```c
int x = 10;
int *ptr = &x;         // ptr now holds the address of x
```

```text
x   →  10            (at address 0x7ffd...)
          ↑
ptr →  0x7ffd...     (the address OF x)
```

### Printing an Address

Addresses are printed with **`%p`** (the pointer specifier):

```c
#include <stdio.h>

int main()
{
    int x = 10;
    int *ptr = &x;

    printf("%p\n", ptr);      // address of x
    printf("%p\n", &x);       // the same address, written directly
    return 0;
}
```

```text
0x7ffe703547e0
0x7ffe703547e0
```

(Exact numbers differ every run — they depend on the system.)

---

# 2. Dereferencing

**Dereferencing** means: go to the address a pointer holds and use the **value stored there**.

```text
*ptr   →  "the value that lives at the address stored in ptr"
```

```c
#include <stdio.h>

int main()
{
    int x = 10;
    int *ptr = &x;

    printf("%p\n", ptr);      // address      → 0x7ffe...
    printf("%d\n", *ptr);     // value at it  → 10

    *ptr = 30;                // write through the pointer
    printf("%d\n", x);        // 30 — x itself changed
    return 0;
}
```

### Important Note

```text
ptr    → the ADDRESS of x
*ptr   → the VALUE stored at that address (10, or 30 after writing)
```

`*ptr = 30;` modifies `x` — the pointer reaches the variable without being handed the variable
itself.

---

# 3. Pass by Value

### Definition

When a function is called normally, the argument is passed **by value**: the function receives a
**copy**. Changes inside the function stay inside.

### Code

```c
#include <stdio.h>

void func(int x)
{
    printf("function x value %d\n", x);
    int *ptr = &x;
    printf("function x address %p\n", ptr);
}

int main()
{
    int x = 10;
    func(10);

    printf("main function x value %d\n", x);
    int *ptr = &x;
    printf("main function x address %p\n", ptr);
    return 0;
}
```

```text
function x value 10
function x address 0x7ffce...      ← a DIFFERENT x
main function x value 10
main function x address 0x7ffd9... ← the original x
```

### Important Note

There are **two separate variables** called `x`:

```text
main's x   →  its own memory slot
func's x   →  a copy, a different slot (different address)
```

Whatever happens to `func`'s copy can never reach `main`'s variable.

---

# 4. Pass by Reference

### Definition

**Pass by reference** means: the function receives the **address** of the variable, so it can read
and change the original.

### Code

```c
#include <stdio.h>

void func(int *ptr)
{
    *ptr = 30;              // write to the ORIGINAL variable
}

int main()
{
    int x = 10;
    func(&x);               // hand over the address
    printf("%d\n", x);      // 30 — x itself changed
    return 0;
}
```

```text
before :  x = 10
func() :  *ptr = 30  →  writes into main's x
after  :  x = 30
```

### The Two Lines to Remember

```c
int *ptr;       // ptr holds a pointer address
*ptr = 30;      // dereferencing: write the value at that address
```

### Question — why does `scanf()` need `&`?

Because `scanf()` **writes into** my variable. It cannot work on a copy — the value has to end up in
the real variable. So I must hand it the **address**:

```c
int x;
scanf("%d", &x);      // &x = "write here, not in a copy"
```

```text
printf("%d", x)   → only needs the VALUE        → no &
scanf("%d", &x)   → needs somewhere to STORE    → & required
```

That is exactly pass by reference: `scanf()` is a function that receives a pointer and fills in the
value at that address.

---

# 5. Pointers and Arrays

An array name **is** (behaves as) a pointer to its first element.

```c
#include <stdio.h>

int main()
{
    int a[5] = {10, 20, 30, 40, 50};

    printf("%p\n", a);       // same as &a[0]
    printf("%p\n", &a[0]);   // the address of the first element
    printf("%p\n", &a[1]);
    printf("%p\n", &a[2]);

    printf("%d\n", *a);      // 10 — dereference the first element
    return 0;
}
```

```text
a      →  0x7ffe703547e0
&a[0]  →  0x7ffe703547e0     ← identical
&a[1]  →  0x7ffe703547e4     ← +4 bytes (one int, typically)
&a[2]  →  0x7ffe703547e8     ← +4 bytes again
```

### How the Address of an Element Is Calculated

```text
address of a[i]  =  base address of a  +  i * sizeof(int)
```

```text
base   = 0x7ffe703547e0
a[2]   = 0x7ffe703547e0 + 2 * 4 = 0x7ffe703547e8
```

**Important Correction:** my original note said *"array total address = first element address + total
elements − 1"*. That is not how it works. Each element is `sizeof(type)` bytes apart, so the index
is **multiplied by the size of one element** — there is no "total address" formula. The typical
`4 bytes` for `int` can be checked with `sizeof(int)`; the exact size is implementation-dependent.

### Array Name = Pointer in Expressions

```text
a        →  address of a[0]
a[i]     →  same as *(a + i)
*(a + 1) →  the value of a[1]
```

```c
*(a + 1) = 200;      // changes a[1] to 200
```

```text
a + 1      →  "one element after a[0]"  (the compiler adds 4 bytes)
*(a + 1)   →  read/write the value THERE
```

### Important Note

An array name is **not an ordinary pointer variable**:

```c
int a[5];
int *p = a;      // OK — a decays to a pointer here
a = p;           // WRONG — you cannot assign to an array name
```

It always refers to the same memory, so it cannot be pointed somewhere else.

---

# 6. Why Functions Receive Arrays by Reference

```c
void func(int arr[], int n);
```

**Problem:** an array can be huge — `int arr[1000000]` is 4 MB of data. If a function received a
**copy** of the array, the program would need another 4 MB every call — twice the memory for
nothing.

**Solution:** C does **not** copy the array. The parameter `arr[]` is really a **pointer** to the
caller's array, so both sides work with the same memory — pass by reference.

```c
#include <stdio.h>

void func(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", arr[i]);
    }
}

int main()
{
    int arr[5] = {10, 20, 30, 40, 50};
    func(arr, 5);          // no & needed — the array name IS the address
    return 0;
}
```

```text
Output:
10
20
30
40
50
```

**Note:** the function can also **modify** the caller's elements (`arr[i] = ...` changes the
original array) — the same reason `scanf("%d", &x)` works.

### Important Note — an array itself cannot be returned

```c
int *bad() {
    int a[5] = {1, 2, 3, 4, 5};
    return a;              // WRONG — a dies when the function ends
}
```

The array lives on the function's stack frame; when the function returns, that memory is released.
Returning a pointer to it gives a **dangling pointer** — reading it is undefined behavior. Return a
`static`/global array, a heap allocation, or fill a buffer the caller provides instead.

---

# 7. Passing a String to a Function

A string is a `char` array, so it follows exactly the same rule as arrays — the function receives a
pointer, not a copy.

```c
#include <stdio.h>

void func(char s[], int n)
{
    printf("%s", s);        // reads the caller's string
}

int main()
{
    char s[10];
    scanf("%s", s);
    func(s, 10);            // array name = address, no & needed
    return 0;
}
```

```text
Input:  hello
Output: hello
```

```text
main's s  ──pointer──►  func's s       (both point at the SAME characters)
```

Because it is the same memory, a function can also **change** the caller's string — for example turn
its first letter into uppercase:

```c
void make_upper(char s[])
{
    if (s[0] >= 'a' && s[0] <= 'z')
    {
        s[0] = s[0] - 32;     // modifies main's string
    }
}
```

This is exactly what `strcpy()`, `strcat()` and `strcmp()` (Module 11) work with: they receive
pointers to the strings, not copies of them.

---

# Quick Revision

```text
pointer     variable that stores an ADDRESS        int *ptr = &x;
%p          print an address
*ptr        the VALUE at that address (dereference)
*ptr = 30   write into the variable ptr points to

pass by value      function gets a COPY   → changes stay local
pass by reference  function gets an ADDRESS → changes reach the caller

scanf("%d", &x)    needs & because it WRITES into x
printf("%d", x)    needs only the value → no &

a      ==  &a[0]
a[i]   ==  *(a + i)
address of a[i] = base + i * sizeof(int)     (NOT base + n - 1)
array name is a pointer in expressions, but cannot be assigned to

array/string argument  → automatically passed by pointer (no copy)
cannot return a local array (its memory is gone)
```

---

# Important Corrections

### 1. Element addresses step by `sizeof`, not by "count"

```text
&a[i] = base + i * sizeof(int)      typical: +4 bytes per element
```

The old formula `first address + total elements - 1` is wrong.

### 2. `&` is required only when the callee must WRITE

```c
scanf("%d", &x);     // write → address needed
printf("%d", x);     // read only → value is enough
```

### 3. Two different `x` variables in pass by value

The printed addresses differ — `func`'s `x` is a separate copy, not main's variable.

### 4. Array name is not a variable you can assign

`a = p;` does not compile; `a` always refers to its own memory.

### 5. Returning a local array is undefined behavior

The memory is released when the function returns; the pointer left behind points at nothing valid.

---

# What to Learn Next

Directly connected to this module:

- **Pointer arithmetic** — `ptr + 1`, `ptr++`, why it moves by `sizeof(type)`
- **Pointers to pointers** — `int **` and `char *argv[]`
- **Dynamic memory** — `malloc()` / `free()` (the way to actually return data from a function)
- **Array of pointers** — `char *words[]` for storing many strings
- **Functions returning pointers** — when it is safe and when it is a dangling pointer
