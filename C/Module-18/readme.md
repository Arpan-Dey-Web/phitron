# Module 18 — 2D Arrays and Matrices

Today I learned what a **2D array** is — an array inside an array — how to declare one, how the
computer stores it in memory, and how to take input and print it with nested loops. After that came
**matrices**: the different types (row, column, zero, diagonal, scalar, unit) and how to *check*
which type a given matrix is, including the **primary** and **secondary diagonal**.

Main topics:

* Why 2D arrays exist (1D = a line, 2D = height × width)
* Declaration, structure and indexing
* How a 2D array is stored (row by row)
* Input / output with nested loops
* Printing a specific row or column
* 6 matrix types and how they relate to each other
* Checking the matrix type with code
* Primary and secondary diagonal

This continues from **arrays** in [Module 7](../Module-7/readme.md), **nested loops** in
[Module 13](../Module-13/readme.md) and **functions** in [Module 14](../Module-14/readme.md).

Files:

| File | Purpose |
| ---- | ------- |
| `main.c` | Concepts + my code (kept as block comments) |
| `quiz.md` | Practice quiz with answers and explanations |
| `input.txt` | Last input I tested with (secondary-diagonal check) |
| `output.txt` | Output produced for that input |
| `extrapractice.c` | (empty — no extra practice yet) |

---

# 1. Why Do We Need a 2D Array?

```text
1D array  ->  just a LINE       one row of values
2D array  ->  a RECTANGLE       it has HEIGHT and WIDTH
3D array  ->  a CUBE            height, width and depth
```

A mark sheet is the classic example: students × subjects. One number is a single value (1D), but a
whole class's marks in 3 subjects is a table (2D).

### Definition

A **2D array** is an array whose every index holds **another array** (a row). Both sizes must be
fixed when you declare it.

```text
arr[n] = [
  [0, 1, 2, 3],
  [4, 5, 6, 7],
  [8, 9, 10, 11]
]
```

---

# 2. Declaration and Structure

### Syntax

```c
int arrayName[Row Number][Column Number];
```

```c
int arr[4][4];
```

### The Grid

```text
            Column
             0    1    2    3
           ┌────┬────┬────┬────┐
    Row 0   │ 21 │ 22 │ 23 │ 24 │
           ├────┼────┼────┼────┤
    Row 1   │ 25 │ 26 │ 27 │ 28 │
           ├────┼────┼────┼────┤
    Row 2   │ 29 │ 30 │ 31 │ 32 │
           ├────┼────┼────┼────┤
    Row 3   │ 33 │ 34 │ 35 │ 36 │
           └────┴────┴────┴────┘
```

### Accessing an Element

```c
arr[1][2]        // row 1, column 2  ->  27
```

```text
             Column 0       Column 1       Column 2
    Row 0  |  arr[0][0]  |  arr[0][1]  |  arr[0][2]  |
    Row 1  |  arr[1][0]  |  arr[1][1]  |  arr[1][2]  |
    Row 2  |  arr[2][0]  |  arr[2][1]  |  arr[2][2]  |
```

### Important Note

The first index is the **row** (how far *down*), the second is the **column** (how far *right*).
Both start at 0. Remember it as `arr[row][col]` — always in that order.

---

# 3. How the Computer Stores a 2D Array

Memory is a **single line**, so a 2D array is stored **row after row** — one whole row, then the
next, with no gaps:

```text
row 0: 21 22 23 24   then   row 1: 25 26 27 28   then   row 2: 29 30 31 32   then   row 3: ...
└────────────────────┘      └────────────────────┘
        one after another in one continuous block
```

### The Address Formula

```text
address of arr[i][j]  =  base address  +  ( i * columns  +  j ) * sizeof(int)
```

```text
arr[1][2] in a 4-wide array ->  1 * 4 + 2 = 6th element (0-based)
```

**Important:** you multiply by **columns** — the width of one row — because skipping one full row
means skipping `columns` elements. (This is the 1D rule `base + i * sizeof(int)` from
[Module 15](../Module-15/readme.md) with the row folded in.)

---

# 4. Input and Output

Two nested loops: the **outer** loop walks the rows, the **inner** loop walks the columns.

```c
#include <stdio.h>

int main()
{
    int r, c;
    scanf("%d %d", &r, &c);

    int arr[r][c];

    /* input: row by row */
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    /* output: same shape */
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}
```

### Output — input `2 3` then `1 2 3 4 5 6`

```text
1 2 3 
4 5 6 
```

### Important Note

`int arr[r][c]` is a **variable-length array** (C99): `r` and `c` are read at runtime, not written
in the declaration. It works, but the array lives on the stack — keep `r` and `c` small for large
inputs.

---

# 5. Printing a Specific Row or Column

```c
#include <stdio.h>

int main()
{
    int r, c;
    scanf("%d %d", &r, &c);

    int arr[r][c];
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    /* one whole ROW: walk the columns of that row */
    int rowNumber;
    scanf("%d", &rowNumber);
    for (int i = 0; i < c; i++)                 /* row has c elements */
    {
        printf("%d ", arr[rowNumber][i]);
    }
    printf("\n------------------------------\n");

    /* one whole COLUMN: walk the rows of that column */
    int colNumber;
    scanf("%d", &colNumber);
    for (int i = 0; i < r; i++)                 /* column has r elements */
    {
        printf("%d ", arr[i][colNumber]);
    }

    return 0;
}
```

### Important Note — my bug

The column loop in my first version was `for (i = 0; i < c; i++)`. A column has **r** elements,
not **c** — with `c > r` it reads past the last row (out of bounds), with `c < r` it stops too
early. It only *looked* right because every example was square.

```text
row loop    ->  i < c    (one row is c columns wide)
column loop ->  i < r    (one column is r rows tall)
```

---

# 6. Types of Matrices

### 1. Row Matrix — exactly ONE row

```text
┌─────────────┐
│ a   b   c   │
└─────────────┘

1 × 3 Matrix
```

### 2. Column Matrix (Vector Matrix) — exactly ONE column

```text
┌───┐
│ a │
│ b │
│ c │
└───┘

3 × 1 Matrix
```

### 3. Zero Matrix (Null Matrix) — every element is 0

```text
┌───┬───┬───┐
│ 0 │ 0 │ 0 │
├───┼───┼───┤
│ 0 │ 0 │ 0 │
├───┼───┼───┤
│ 0 │ 0 │ 0 │
└───┴───┴───┘

3 × 3 Matrix
```

### 4. Diagonal Matrix — square, everything OFF the diagonal is 0

```text
┌───┬───┬───┐
│ a │ 0 │ 0 │
├───┼───┼───┤
│ 0 │ b │ 0 │
├───┼───┼───┤
│ 0 │ 0 │ c │
└───┴───┴───┘
```

**Important:** a diagonal matrix must be **square** (rows = columns) — a diagonal only exists in a
square matrix.

### 5. Scalar Matrix — diagonal where every diagonal value is EQUAL

```text
┌───┬───┬───┐
│ a │ 0 │ 0 │
├───┼───┼───┤
│ 0 │ a │ 0 │
├───┼───┼───┤
│ 0 │ 0 │ a │
└───┴───┴───┘
```

### 6. Unit Matrix (Identity Matrix) — diagonal of 1s

```text
┌───┬───┬───┐
│ 1 │ 0 │ 0 │
├───┼───┼───┤
│ 0 │ 1 │ 0 │
├───┼───┼───┤
│ 0 │ 0 │ 1 │
└───┴───┴───┘
```

### Quick Comparison

```text
Row Matrix       -> 1 row
Column Matrix    -> 1 column
Zero Matrix      -> every element is 0
Diagonal Matrix  -> elements OFF the main diagonal are 0
Scalar Matrix    -> diagonal elements are all EQUAL
Unit Matrix      -> diagonal elements are all 1
```

### How They Are Related

```text
                        Matrix
                           │
              ┌────────────┴────────────┐
              │                         │
       Diagonal Matrix            Zero Matrix
              │
       Scalar Matrix
              │
         Unit Matrix
```

**A Unit Matrix is a special Scalar Matrix, and a Scalar Matrix is a special Diagonal Matrix.**
Every unit matrix is scalar, every scalar matrix is diagonal — but not the other way around.

---

# 7. Checking Which Type Is It

The checks all follow the same pattern: **read the matrix, then test the definition with loops
and conditions**. Full code for each is in `main.c`.

```text
row matrix      r == 1
column matrix   c == 1
square matrix   r == c
zero matrix     count of 0s  ==  r * c
```

```c
/* row matrix check (from main.c) */
if (r == 1)
{
    printf("This is a row matrix");
}
else
{
    printf("This is not a row matrix");
}
```

### Important Note — my bug

In my first three checks the `printf` lines were **missing the semicolon**:

```c
printf("This is an row metrix")     // does not compile
printf("This is a row matrix");     // correct
```

`printf(...)` is a statement — it needs `;`. (Also: "a row matrix", not "an row matrix", and
*spatrix* is spelled **matrix**.)

---

# 8. Primary and Secondary Diagonal

```text
Primary diagonal    : top-left  -> bottom-right    position: i == j
Secondary diagonal  : bottom-left -> top-right      position: i + j == rows - 1
```

```text
For a 3 × 3 matrix:

  primary (i == j)       secondary (i + j == 2)
  ┌───┬───┬───┐          ┌───┬───┬───┐
  │ a │ . │ . │          │ . │ . │ c │
  ├───┼───┼───┤          ├───┼───┼───┤
  │ . │ b │ . │          │ . │ b │ . │
  ├───┼───┼───┤          ├───┼───┼───┤
  │ . │ . │ c │          │ a │ . │ . │
  └───┴───┴───┘          └───┴───┴───┘
```

### Rules I Learned

1. Both diagonals exist **only in square matrices** (`r == c`). A 4×3 matrix has no diagonal.
2. On the primary diagonal the row index equals the column index: `arr[0][0]`, `arr[1][1]`, ...
3. On the secondary diagonal the indexes **add up** to `rows - 1`: `arr[0][2]`, `arr[1][1]`,
   `arr[2][0]` for 3×3.
4. The two diagonals share a value only where the positions meet — the **centre** of an
   odd-sized matrix (for 3×3: `arr[1][1]`).

### The Check (in `main.c`)

```c
/* secondary diagonal: every element OFF i + j == r - 1 must be 0 */
if (i + j != r - 1 && arr[i][j] != 0)
{
    is_Diagonal = false;
}
```

```text
Input (3 × 3):        Output:
1 0 0                 This is not a Secondary Diagonal Matrix
0 2 0
0 0 3
```

The matrix *is* diagonal, but it is **primary**-diagonal, not secondary — the values 1, 2, 3 sit on
`i == j`, while the secondary positions are 0, 0, 0. That is exactly what `input.txt` /
`output.txt` in this folder record.

### Important Note — my bug (fixed)

My first primary-diagonal check printed the "not a diagonal matrix" message **inside** the loop —
so a matrix with several non-zero off-diagonal elements printed the message many times. The fix:
set a **flag** inside the loop and print **once** after it (the way the secondary check already
did).

---

# Quick Revision

```text
declaration     int arr[r][c]        arr[row][col], both 0-based

storage         row after row in one line
address         base + (i * columns + j) * sizeof(int)

input/output    outer loop = row, inner loop = column

row check       r == 1        column check   c == 1
square check    r == c        zero check     zeros == r * c

diagonals exist only in square matrices
primary    i == j                (top-left  -> bottom-right)
secondary  i + j == rows - 1     (bottom-left -> top-right)

diagonal -> scalar -> unit   (each is a special case of the one above)
```

---

# Important Corrections

### 1. Column loop runs `r` times, not `c` times

```text
wrong   for (i = 0; i < c; i++)  printf("%d ", arr[i][col]);   // out of bounds
right   for (i = 0; i < r; i++)  printf("%d ", arr[i][col]);
```

### 2. Every `printf(...)` needs a semicolon

My row/column/square checks had `printf(...)` with no `;` — they did not compile at all.

### 3. Diagonal check must print ONCE

A flag (`is_Diagonal`) is set inside the loop; the message is printed after the loop. Printing
inside the loop repeats the message for every offending element.

### 4. A diagonal only exists in a square matrix

`rows != columns` → no primary, no secondary diagonal. This is why the check starts with
`if (r == c)`.

---

# What to Learn Next

Directly connected to this module:

- **Transpose of a matrix** — swapping rows and columns (`arr[j][i]`)
- **Sum of the diagonals** — one loop over `i` for primary, `rows-1-i` for secondary
- **Matrix multiplication** — three nested loops
- **Rotating a matrix 90°** — transpose + reverse, built from what you already know
