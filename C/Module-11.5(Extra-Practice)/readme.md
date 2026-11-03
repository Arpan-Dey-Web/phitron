# Module 11.5 — Extra Practice: Frequency Array and String Compare

This folder is a **practice set after Module 11 (string functions)** — 2 problems: counting with a
frequency array, and comparing two strings lexicographically.

I did not write a full theory note for this session. All problem statements and my solutions are
kept inside `main.c`. This readme is the revision index for that folder.

Files:

| File | Purpose |
| ---- | ------- |
| `main.c` | Problem statements + my solutions |
| `input.txt` | Last input I tested with |
| `output.txt` | Output produced for that input |

---

# 1. Frequency Array

### Definition

A **frequency array** is a small array where the **index is the value** and the stored number is
**how many times that value appeared**.

### How It Works

```text
input values : 1 3 1 5 3 1

fre[0] → 0 times      fre[1] → 3 times
fre[2] → 0 times      fre[3] → 2 times
fre[4] → 0 times      fre[5] → 1 time
```

Steps:

1. Create `fre[]` and set **every slot to 0** — `{0}` does this automatically.
2. For each input value `a[i]`, do `fre[a[i]]++` — one more occurrence of that value.
3. Print `index -> count` for every slot.

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

    int fre[6] = {0};

    for (int i = 0; i < n; i++)
    {
        fre[a[i]]++;            // value a[i] appeared one more time
    }

    for (int i = 0; i < 6; i++)
    {
        printf("%d -> %d\n", i, fre[i]);
    }

    return 0;
}
```

```text
Input:
6
1 3 1 5 3 1

Output:
0 -> 0
1 -> 3
2 -> 0
3 -> 2
4 -> 0
5 -> 1
```

### Important Note

`int fre[6]` only works when every input value is between **0 and 5**. If the input can be larger,
the size must cover the largest possible value — `fre[a[i]]` with a value outside the array is an
**out-of-bounds access** (undefined behavior).

---

# 2. C. Compare — Smallest Lexicographical String

**Problem:** Given two strings `X` and `Y`, print the smallest one in lexicographical (dictionary)
order. If they are equal, print either.

**Idea:** `strcmp()` from [Module 11](../Module-11/readme.md) already does this comparison:

```text
strcmp(a, b) < 0  →  a is smaller
strcmp(a, b) = 0  →  equal (print any)
strcmp(a, b) > 0  →  b is smaller
```

### Code

```c
#include <stdio.h>
#include <string.h>

int main()
{
    char a[25], b[25];
    scanf("%s %s", a, b);

    int lowest = strcmp(a, b);

    if (lowest <= 0)
    {
        printf("%s", a);
    }
    else
    {
        printf("%s", b);
    }

    return 0;
}
```

```text
Input:
acm
acpc

Output:
acm
```

### Important Correction — print the string, not the `strcmp` result

My running version ended with `printf("%d", lowest);`, which printed the **comparison number**
(`-3`), not the answer. The problem asks for the **smallest string**, so the program must print
`a` or `b` (with `%s`) based on whether `lowest` is negative, zero, or positive.

`strcmp()` returns a *sign* (`< 0`, `= 0`, `> 0`) — the exact number (`-3`) is not meaningful and
differs between implementations.

---

# Quick Revision

```text
frequency array    index = value, content = count of that value
                   fre[a[i]]++  for each input, start with fre[] = {0}
                   size must cover the largest possible value

strcmp(a, b) < 0   a smaller
strcmp(a, b) = 0   equal
strcmp(a, b) > 0   b smaller

answer needed is a STRING  →  printf("%s", ...)
answer needed is a SIGN    →  compare with < 0 / == 0 / > 0, never print it directly
```

---

# Common Mistakes to Remember

1. **Printing the `strcmp()` return value** — the problem wants the string, not `-3` / `1` / `0`.
2. **Frequency array too small** — `fre[value]` must stay inside the array bounds.
3. **Forgetting `= {0}`** — without it `fre[]` starts with garbage and counts are wrong.
4. **Using `==` on the full `strcmp()` result** — only the sign is guaranteed, so test `< 0` and
   `> 0`, not `== -1`.

---

# What to Learn Next

Directly connected to this practice set:

- **Counting characters** — frequency array over letters `a`–`z` (`fre[ch - 'a']`)
- **`strncmp()`** — compare only the first `n` characters
- **Distinct / most frequent value** — read a frequency array and find the largest count
- **Two-pointer problems** — pair sum on a sorted array
- **Mid-term practice** — mixed array + string problems (see `../Mid-Exam/`)
