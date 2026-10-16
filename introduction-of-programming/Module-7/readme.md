# Module 7 — Arrays

Today I learned about **arrays in C**.

Main topics:

* Why arrays are needed
* Array declaration and syntax
* Indexes
* Accessing and assigning elements
* How an array is stored in memory
* Taking input into an array
* Printing an array
* Reverse printing
* Array initialization rules

---

# 1. Why Do We Need Arrays?

Suppose I need to store 100 values. Writing 100 separate variables is impractical:

```c
int a1, a2, a3, ... a100;   // painful
```

An **array** lets me store many values of the **same data type** under one name, and reach each value through its **index**.

```text
normal variable  →  one name, one value
array            →  one name, many values (same type)
```

---

# 2. Declaration Syntax

```text
data_type  name  [ quantity ];

int        arr   [ 10 ];
```

```c
int arr[10];
```

This creates room for **10 integers**.

**Important:** An array holds only **one data type**. I cannot mix `int` and `char` in the same array.

---

# 3. Indexes

Every element of an array has an **index** — its position number.

```text
Index counting:

Position:   1st   2nd   3rd   ...   10th
Index:       0     1     2   ...     9
```

Rules:

```text
index starts at  0
index ends at    size - 1
```

So:

```c
int arr[10];
```

```text
valid indexes : 0, 1, 2, ..., 9
invalid       : 10, 11, -1  (undefined behavior — never access these)
```

Access one element:

```text
array_name [ index_number ]
```

Example:

```c
arr[3]    // the element at index 3 (the 4th element)
```

---

# 4. Assigning and Reading a Value

Assign:

```c
array_name [ index ] = value;
```

```c
int arr[10];
arr[2] = 20;
```

Read:

```c
printf("%d", arr[2]);   // prints 20
```

```c
#include <stdio.h>

int main() {
    int arr[10];

    arr[2] = 20;
    printf("%d", arr[2]);   // 20

    return 0;
}
```

Each index behaves like its own normal variable:

```c
arr[0] = 5;
arr[1] = 10;
arr[2] = arr[0] + arr[1];   // 15
```

---

# 5. How an Array Is Stored in Memory

An array stores its elements **one after another in consecutive memory locations**.

For a typical `int` (4 bytes):

```text
Index:     arr[0]   arr[1]   arr[2]   arr[3]
Address:   x50240   x50244   x50248   x50252
           +4       +4       +4
```

Because each `int` takes 4 bytes, the next element sits exactly 4 bytes after the previous one.

**How the computer finds index 3 instantly:**

```text
address of arr[3] = first element address + (3 * 4 bytes)
```

It does **not** search from the beginning. This is why array access is very fast.

```text
first address  x50240
index 3        x50240 + 3*4 = x5024C   (the 4th element)
```

### Important Note

Exact addresses and the 4-byte size depend on the system and compiler — `sizeof(int)` can be checked with `sizeof()`. The important idea is:

```text
elements are stored sequentially
        ↓
index arithmetic finds any element immediately
```

---

# 6. Input into an Array

```c
#include <stdio.h>

int main() {
    int ar[5];

    for (int i = 0; i <= 4; i++) {
        scanf("%d", &ar[i]);
    }

    return 0;
}
```

The loop fills indexes `0` to `4` one by one.

**Note:** `scanf()` needs `&ar[i]` — the memory address of that slot — to know where to store the input.

---

# 7. Output of an Array

```c
#include <stdio.h>

int main() {
    int ar[5];

    for (int i = 0; i <= 4; i++) {
        printf("%d\n", ar[i]);   // VALUE of ar[i]
    }

    return 0;
}
```

### Important Correction — `&ar[i]` vs `ar[i]`

My first version printed:

```c
printf("%d", &ar[i]);   // WRONG for printing a value
```

`&ar[i]` is the **memory address** of the element, not its value, and `%d` is not the correct specifier for addresses anyway.

```text
ar[i]     → the value stored at index i
&ar[i]    → the memory address of index i
```

To **print the value**, use `ar[i]` (no `&`).
To **give scanf a place to write**, use `&ar[i]` (with `&`).

---

# 8. Reverse Printing

```c
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    for (int i = n - 1; i >= 0; i--) {
        printf("%d\n", a[i]);
    }

    return 0;
}
```

**Sample:**

```text
Input:
3
10 20 30

Output:
30
20
10
```

The loop starts at the last index `n - 1` and moves down to `0`.

**Note:** `int a[n]` is a **variable-length array (VLA)** — the size is decided while the program runs. This is allowed in C99 and later.

---

# 9. Array Initialization at Declaration

I can give values at the same time I declare the array:

```c
int arr[] = {10, 20, 30, 40, 50, 60};
```

Here `arr[]` has no written size — the compiler automatically sizes it to **6**.

Or give both size and values:

```c
int arr[5] = {10, 20};
```

If I give fewer values than the size, the rest are **filled with 0**:

```text
arr → 10, 20, 0, 0, 0
```

Print all elements:

```c
for (int i = 0; i < 5; i++) {
    printf("%d\n", arr[i]);
}
```

---

# 10. Uninitialized Arrays Contain Garbage

```c
int arr[5];
```

If I print the elements without storing anything first, I get **garbage values** — whatever happened to be in that memory:

```text
arr → 8472631, -928371, ...   (undefined, different every run)
```

To make an array of all zeros:

```c
int arr[5] = {0};
```

This gives:

```text
arr → 0, 0, 0, 0, 0
```

Rule of thumb:

```text
int arr[5] = {0};     → all 0, safe to start accumulating
int arr[5];           → garbage until assigned
```

---

# Quick Revision

```text
declare     data_type name[size];        int arr[10];
first index 0
last index  size - 1
assign      arr[i] = value;
read        arr[i]
address     &ar[i]   (for scanf only)

elements stored consecutively in memory
find index k:  first_address + k * sizeof(type)

int arr[] = {1,2,3};        → size becomes 3
int arr[5] = {10, 20};      → 10, 20, 0, 0, 0
int arr[5] = {0};           → 0, 0, 0, 0, 0
int arr[5];                 → garbage values
int a[n];                   → variable-length array (C99+)
```

---

# Important Corrections

### 1. `&ar[i]` does not print the element's value

```text
printf("%d", ar[i]);    → prints the value
printf("%d", &ar[i]);   → prints an address (and %d is wrong for that)
```

### 2. Last index is `size - 1`, not `size`

```c
int arr[10];   // indexes 0 .. 9, never 10
```

### 3. Memory addresses grow by the size of the type

For `int` (typically 4 bytes): `arr[0]`, `arr[1]`, `arr[2]` are each 4 bytes apart. Exact sizes can be checked with `sizeof()` and are not guaranteed by the C standard.

### 4. Uninitialized does not mean zero

`int arr[5];` holds garbage. Only `int arr[5] = {0};` (or assigning each element) makes the values known.

---

# What to Learn Next

Directly connected to this module:

- **Array problems** — sum, maximum, minimum, counting evens/odds (see `extraPractice.c`)
- **Copying and reversing arrays** — two-pointer swap technique
- **Common array bugs** — out-of-bounds access, off-by-one in loop conditions
- **Functions + arrays** — passing an array to a function
- **Time complexity** — why one loop over an array is `O(N)`
