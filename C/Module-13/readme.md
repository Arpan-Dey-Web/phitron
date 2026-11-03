# Module 13 — Nested Loop Recap: Star Patterns and Pair Sum

Today I revisited **nested loops** and used them to print shape patterns, then solved the classic
**pair sum** problem (does any two elements add up to `x`?).

Main topics:

* Printing an upward star triangle — two ways
* Printing a downward star triangle
* Printing a pyramid (spaces + stars)
* Extra practice — number triangle, inverted pyramid, alphabet triangle
* Pair sum problem — nested loop over an array
* Sorting basics (from the quiz — ascending and descending order)

This continues from **loops** in [Module 6](../Module-6/readme.md) and **arrays** in
[Module 7](../Module-7/readme.md).

Files:

| File | Purpose |
| ---- | ------- |
| `main.c` | Pattern + pair sum problems (kept as comments) |
| `extrapractice.c` | Extra pattern problems (kept as comments) |
| `quiz.md` | Nested loop / pair sum quiz with explanations |
| `input.txt` | Last input I tested with |
| `output.txt` | Output produced for that input |

---

# 1. Upward Star Pattern (Two Ways)

### Definition

Print a triangle where row `i` contains `i` stars:

```text
*
**
***
****
*****
```

### How It Works

The **outer loop** chooses the row. The **inner loop** prints that row's stars.

**Way 1 — inner loop depends on the row number:**

```c
#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)   // j runs up to the current row number
        {
            printf("*");
        }
        printf("\n");                   // move to the next line AFTER the inner loop
    }

    return 0;
}
```

**Way 2 — keep a separate `star` counter:**

```c
int star = 1;
for (int i = 1; i <= n; i++)
{
    for (int j = 1; j <= star; j++)
    {
        printf("*");
    }
    printf("\n");
    star++;                             // one more star than last row
}
```

```text
Input:  4
Output:
*
**
***
****
```

### Important Note

Both ways produce the same output. Way 1 uses `i` directly; Way 2 uses a counter that I increase by
myself. The counter style is useful later because I can change it by **2** (for pyramids) instead of
always by 1.

---

# 2. Downward Star Pattern

### How It Works

Same as above, but the counter **starts at `n` and decreases**:

```c
#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int star = n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= star; j++)
        {
            printf("*");
        }
        printf("\n");
        star--;
    }

    return 0;
}
```

```text
Input:  4
Output:
****
***
**
*
```

### Important Note

The only differences from the upward pattern are `int star = n` and `star--`.

---

# 3. Pyramid (Spaces + Stars)

### Definition

A pyramid is centered: every row has **leading spaces** and an **odd number of stars**.

```text
   *
  ***
 *****
*******
```

### How It Works

```text
row 0 :  3 spaces + 1 star     space = n-1, star = 1
row 1 :  2 spaces + 3 stars    space--, star += 2
row 2 :  1 space  + 5 stars
row 3 :  0 spaces + 7 stars
```

Each row prints **spaces first**, then stars, then a newline:

```c
#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int star = 1;
    int space = n - 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= space; j++)
        {
            printf(" ");
        }
        for (int j = 1; j <= star; j++)
        {
            printf("*");
        }
        printf("\n");

        star += 2;          // 1, 3, 5, 7 ... (odd numbers)
        space--;            // 3, 2, 1, 0 ...
    }

    return 0;
}
```

```text
Input:  4
Output:
   *
  ***
 *****
*******
```

### Important Correction — `star += 2`, not `star++`

I also tried `star++`, which prints **1, 2, 3, 4** stars after the spaces — that is not a pyramid,
it is a diagonal shape. A pyramid must grow **2 stars per row** (one on each side), because each row
keeps the center aligned.

---

# 4. Pair Sum Problem

**Problem:** Read `n` numbers and a value `x`. Print `YES` if **any two elements** of the array sum
to `x`, otherwise print `NO`.

**Idea:** For every element `a[i]`, check every other element `a[j]`. If `a[i] + a[j] == x`, the
answer is `YES`.

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

    int x;
    scanf("%d", &x);

    int flag = 0;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)     // j starts AFTER i → no self-pair
        {
            if (a[i] + a[j] == x)
            {
                flag = 1;
                break;                      // one proof is enough
            }
        }
        if (flag == 1)
        {
            break;
        }
    }

    if (flag == 1)
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }

    return 0;
}
```

```text
Input:
4
2 7 11 15
9

Output: YES

Input:
3
1 2 3
100

Output: NO
```

### Important Corrections — three bugs in my first version

My original code was:

```c
for (int i = 0; i < n - 1; i++)
{
    for (int j = 0; j < n; j++)          // BUG 1: j starts at 0
    {
        if (a[i] + a[j] == x)
        {
            flag++;
            printf("YES");               // BUG 2: prints every time
        }
    }
}
```

1. **`j = 0` pairs an element with itself** — `i == j` is allowed, so `4 + 4 == 8` would say `YES`
   even though the problem needs **two different** elements. Fix: `j = i + 1`.
2. **`printf("YES")` inside the loop** — a match found twice prints `YESYES`. Fix: set a flag and
   print **once after** the loops.
3. **No `break`** — after finding one pair the loops keep searching for no reason. Fix: `break` out
   of both loops.

### Edge Case

```text
n = 1          → inner loop never runs → NO (need two elements)
x = 2*a[i]     → with j = i + 1 this is NOT counted as a pair (correct)
duplicate values  → [4, 4], x = 8 → YES (two different indexes, same value)
```

---

# 5. Extra Practice Patterns

From `extrapractice.c` — same idea, different shapes:

```text
n = 4

inverted pyramid        number triangle        alphabet triangle
    *******                1                      A
     *****               1 2                    A B
      ***              1 2 3                  A B C
       *             1 2 3 4                A B C D
```

| Pattern | Spaces | Stars / content |
| ------- | ------ | --------------- |
| Inverted pyramid | `i - 1` | `2 * (n - i) + 1` |
| Number triangle | `n - i` | print `1 … i` with `printf("%d ", k)` |
| Alphabet triangle | `n - i` | print `'A' + k` with `printf("%c ", 'A' + k)` |

### Important Note — `'A' + k` gives the next letter

```text
'A' + 0 → 'A'    'A' + 1 → 'B'    'A' + 2 → 'C'
```

Adding an integer to a `char` moves forward in the ASCII table — that is how one loop can print a
whole alphabet.

---

# 6. Sorting Basics (from the quiz)

```text
ascending order    small → large     [5, 2, 9, 1] → [1, 2, 5, 9]
descending order   large → small     [5, 2, 9, 1] → [9, 5, 2, 1]
```

The comparison logic (`<` for ascending, `>` for descending) becomes important when we write sorting
loops in a later module.

---

# Quick Revision

```text
nested loop      outer = row, inner = print that row
upward triangle  star starts 1, star++
downward         star starts n, star--
pyramid          print spaces FIRST, then stars; star += 2, space--
'A' + k          next letter of the alphabet

pair sum         for i: 0..n-2, for j: i+1..n-1
                 a[i] + a[j] == x → YES
                 use a flag, print ONCE after the loop, break when found

ascending        [1, 2, 5, 9]
descending       [9, 5, 2, 1]
```

---

# Important Corrections

1. **`j` must start at `i + 1` in pair sum** — `j = 0` lets an element pair with itself.
2. **Print the result once, after the loop** — printing inside gives `YESYESYES`.
3. **`star += 2` for pyramids** — `star++` after spaces makes a diagonal, not a pyramid.
4. **Spaces are printed before stars** — each row is: spaces → stars → `\n`.
5. **`printf("\n")` after the inner loop only** — inside the inner loop every star goes on its own
   line.

---

# What to Learn Next

Directly connected to this module:

- **Bubble sort** — how to actually sort an array step by step
- **Counting patterns** — how many of each character/value in one pass
- **Function-based problems** — solving pattern/sum problems inside a function (see
  [Module 14](../Module-14/readme.md))
- **More pair problems** — pair with a given index, closest pair to `x`
