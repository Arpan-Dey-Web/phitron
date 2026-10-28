# Module 9 — Array Insert, Delete, Swap and Reverse

Today I learned how to **change the content of an array after it is created**: inserting a value at a
given index, deleting the value at a given index, swapping two variables, and reversing an array.

Main topics:

* Inserting an element at a specific index
* Deleting an element from a specific index
* Swapping two values with a temporary variable
* Reversing an array with the two-pointer technique

This continues directly from **arrays** in [Module 7](../Module-7/readme.md).

Files:

| File | Purpose |
| ---- | ------- |
| `main.c` | Problem statements + my solutions (kept as comments) |
| `quiz.md` | Array insert/delete/swap quiz with explanations |
| `input.txt` | Last input I tested with |
| `output.txt` | Output produced for that input |

---

# 1. Insert an Element at a Given Index

### Definition

**Insert** means: put a new value at a specific index, and push every value after it one step to the
right. The array size grows by 1.

### How It Works

```text
before :  10  100  20  30  40        (insert 100 at index 1)
index  :    0    1   2   3   4
```

Steps:

1. Read `n` values into an array of size `n + 1` (one extra free slot).
2. Move the elements right, **from the end backward**, down to `idx + 1`:
   `a[i] = a[i - 1]`
3. Store the new value: `a[idx] = value`
4. Print `n + 1` elements.

### Code

```c
#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int a[n + 1];                 // one extra slot for the new value
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    int idx, value;
    scanf("%d %d", &idx, &value);

    for (int i = n; i >= idx + 1; i--)   // shift right, backward
    {
        a[i] = a[i - 1];
    }

    a[idx] = value;

    for (int i = 0; i <= n; i++)         // n + 1 elements now
    {
        printf("%d ", a[i]);
    }

    return 0;
}
```

### Output

```text
Input:
4
10 20 30 40
1 100

Output:
10 100 20 30 40
```

### Important Note

The shifting loop **must run backward** (`i = n` down to `idx + 1`).

```text
backward : a[4] = a[3], a[3] = a[2], a[2] = a[1]   → safe, nothing overwritten
forward  : a[1] = a[0], a[2] = a[1]   → WRONG, a[1] was already overwritten
```

If I start from the front, I destroy the value I still need for the next copy.

---

# 2. Delete an Element at a Given Index

### Definition

**Delete** means: remove the value at a specific index, and pull every value after it one step to the
left. The array size shrinks by 1.

### How It Works

```text
before :  10  20  30  40  50        (delete index 2 → value 30)
after  :  10  20  40  50
```

Steps:

1. Read `n` values into an array of size `n`.
2. Move the elements left, **from the front forward**:
   `a[i] = a[i + 1]` for `i = idx` up to `n - 2`
3. Decrease `n` by 1 (`n--`), so the last slot is not printed.
4. Print the first `n` elements.

### Code

```c
#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int a[n];                     // size n — it must hold all n input values
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    int idx;
    scanf("%d", &idx);

    for (int i = idx; i < n - 1; i++)   // shift left, forward
    {
        a[i] = a[i + 1];
    }

    n--;                              // one element less now

    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}
```

### Output

```text
Input:
5
10 20 30 40 50
2

Output:
10 20 40 50
```

### Important Correction — array size while deleting

My original code declared:

```c
int a[n - 1];        // WRONG when we still READ n values
for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);    // writes past the end of the array
}
```

That writes `n` values into a space of `n - 1` — **out-of-bounds memory write**, which is undefined
behavior. The size is reduced **after** the shift (`n--`), not at declaration:

```text
declaration : int a[n]        → room for all input values
after shift : n--             → only affects how many elements we PRINT
```

### Important Note

Deleting at the **last valid index** (`idx == n - 1`) needs no shifting at all — the loop simply does
not run.

---

# 3. Swap Two Variables

### Definition

**Swap** means exchanging the values of two variables. A third variable (`temp`) temporarily holds
one value so it is not lost.

### How It Works

```text
before :  a = 10,  b = 20
step 1 :  temp = a       → temp = 10
step 2 :  a = b          → a = 20
step 3 :  b = temp       → b = 10
after  :  a = 20,  b = 10
```

### Code

```c
#include <stdio.h>

int main()
{
    int a = 10;
    int b = 20;

    int temp = a;
    a = b;
    b = temp;

    printf("%d %d", a, b);
    return 0;
}
```

### Output

```text
20 10
```

### Important Note

Without `temp`, writing `a = b; b = a;` sets **both** variables to `b`'s value — the original `a` is
lost forever. This swapping pattern is used inside the reverse loop below.

---

# 4. Reverse an Array

### Definition

**Reverse** means printing/storing the elements in the opposite order — the first element becomes the
last.

### How It Works — Two Pointer Technique

```text
array :  1  2  3  4  5
         i →       ← j        swap a[i] and a[j], then i++ and j--
```

1. `i` starts at `0` (beginning), `j` starts at `n - 1` (end).
2. While `i < j`, swap `a[i]` and `a[j]` using `temp`.
3. Move `i` forward and `j` backward.
4. Stop when the pointers meet in the middle.

```text
1 2 3 4 5  →  5 2 3 4 1  →  5 4 3 2 1   (i and j meet, done)
```

### Code

```c
#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    for (int i = 0, j = n - 1; i < j; i++, j--)   // two pointers
    {
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}
```

### Output

```text
Input:
5
1 2 3 4 5

Output:
5 4 3 2 1
```

### Important Note

Another way is to **print from the end**:

```c
for (int i = n - 1; i >= 0; i--) {
    printf("%d ", a[i]);
}
```

That only changes the *output order*. The two-pointer method changes the *array itself* — and it uses
the swap pattern from section 3. Both are accepted; the two-pointer approach is the one used in class
today.

---

# Quick Revision

```text
insert at idx  shift RIGHT from end to idx+1 (backward loop), size n -> n+1
delete at idx  shift LEFT  from idx to n-2 (forward loop),  size n -> n-1

shift right    a[i] = a[i-1]   loop i = n .. idx+1
shift left     a[i] = a[i+1]   loop i = idx .. n-2

swap           temp = a; a = b; b = temp;

reverse        two pointers: i = 0, j = n-1, swap while i < j
               (or simply print from i = n-1 down to 0)

array must be big enough for the values actually READ:
               declare int a[n], not int a[n-1], while reading n values
```

---

# Important Corrections

### 1. Insert shifts backward, delete shifts forward

```text
insert  → start at the end, otherwise values get overwritten
delete  → start at the index, later values fall into the hole
```

### 2. Never declare the array smaller than the number of values read

```c
int a[n - 1];                  // WRONG — we read n values
int a[n];                      // correct while reading n values
```

Writing past the end of an array is undefined behavior, not a harmless extra value.

### 3. `n--` after delete only limits printing

Changing `n` does not change the memory of the array — it just tells the print loop how many real
elements are left.

### 4. Swapping needs a third variable

`a = b; b = a;` does not swap. Always keep one value aside in `temp`.

---

# What to Learn Next

Directly connected to this module:

- **Array problems** — maximum, minimum, sum, frequency counting
- **Insertion in a sorted array** — finding the correct index before shifting
- **Two-pointer problems** — checking palindrome array, pair sum with two indexes
- **Functions + arrays** — passing an array and its size to a function
- **Time complexity** — why insert/delete in the middle costs `O(n)` (every later element moves)
