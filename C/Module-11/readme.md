# Module 11 — String Functions: `strcpy`, `strcat`, `strcmp`

Today I learned the three built-in string functions from `<string.h>` — and, more importantly, how to
**write each of them manually** with a loop. Writing them by hand shows exactly what the library
functions do with the hidden `\0`.

Main topics:

* Copying a string — manual loop and `strcpy()`
* Concatenating strings — manual loop and `strcat()`
* Comparing strings — manual loop and `strcmp()`
* Lexicographical (dictionary) comparison

This continues from **strings** in [Module 10](../Module-10/readme.md).

Files:

| File | Purpose |
| ---- | ------- |
| `main.c` | Problem statements + my solutions (kept as comments) |
| `quiz.md` | String-function quiz with explanations |
| `input.txt` | Last input I tested with |
| `output.txt` | Output produced for that input |

---

# 1. Copying a String Manually

### Definition

**Copy** means: make string `b` hold exactly the same characters as string `a`, including the `\0`.

### How It Works

```text
a → 'c' 'a' 't' '\0'
        ↓  copy one by one, INCLUDING '\0'
b → 'c' 'a' 't' '\0'
```

The loop must run `len + 1` times (`i <= len`), because position `len` is the `\0`:

```c
#include <stdio.h>
#include <string.h>

int main()
{
    char a[101], b[101];
    scanf("%s %s", a, b);

    int len = strlen(b);
    for (int i = 0; i <= len; i++)     // <= so that '\0' is copied too
    {
        b[i] = a[i];
    }

    printf("%s %s", a, b);
    return 0;
}
```

```text
Input:  cat dog
Output: cat cat
```

### Important Note

Here `b` receives everything from `a`, **including the null value**. Without the `\0`, `b` would not
be a valid string — `printf("%s")` would keep printing garbage after the last copied character.

---

# 2. Copying with `strcpy()`

### Definition

```c
strcpy(destination, source);
```

It copies the **source** into the **destination**, overwriting whatever was there.

### Code

```c
#include <stdio.h>
#include <string.h>

int main()
{
    char a[101], b[101];
    scanf("%s %s", a, b);

    strcpy(a, b);        // b is copied INTO a

    printf("%s %s", a, b);
    return 0;
}
```

```text
Input:  cat dog
Output: dog dog
```

### Important Correction — argument order

```text
strcpy(dest, src)   →   dest becomes a copy of src
strcpy(a, b)        →   a becomes "dog"  (b stays "dog")
```

In my manual loop above I copied `a` into `b`, but `strcpy(a, b)` copies `b` into `a` — **the
destination comes first**. Before writing a copy, decide clearly which string must end up with the
value, and match the direction.

---

# 3. Concatenating Strings Manually

### Definition

**Concatenate** means: join two strings end to end, so the destination becomes `destination +
source`.

### How It Works

```text
a → 'c' 'a' 't' '\0'
b → 'd' 'o' 'g' '\0'

start writing at index strlen(a) = 3:
a → 'c' 'a' 't' 'd' 'o' 'g' '\0'
                     ↑ copy b's characters here, then the '\0'
```

```c
#include <stdio.h>
#include <string.h>

int main()
{
    char a[101], b[101];
    scanf("%s %s", a, b);

    int lengthB = strlen(b);
    int lengthA = strlen(a);

    for (int i = 0; i <= lengthB; i++)          // <= copies the '\0' too
    {
        a[lengthA + i] = b[i];
    }

    printf("%s %s", a, b);
    return 0;
}
```

```text
Input:  cat dog
Output: catdog dog
```

### Important Correction — do not forget the `\0`

My first version used `i < lengthB`, which copies only the real characters:

```text
a[3] = 'd', a[4] = 'g'... a[5] never written → old garbage stays there
printf("%s", a) then prints "catdog" + garbage
```

The loop must run `lengthB + 1` times (`i <= lengthB`) so that `a[lengthA + lengthB] = '\0'`.

---

# 4. Concatenating with `strcat()`

```c
strcat(destination, source);
```

```c
#include <stdio.h>
#include <string.h>

int main()
{
    char a[101], b[101];
    scanf("%s %s", a, b);

    strcat(a, b);        // a becomes a + b

    printf("%s %s", a, b);
    return 0;
}
```

```text
Input:  cat dog
Output: catdog dog
```

### Important Note

* The **first argument is the destination** — it must already be a valid string (the one that gets
  extended).
* The destination array must be big enough for both strings **plus** `\0`:
  `char a[101]` is fine for two words of ≤ 50 characters each.
* Only `a` changes; `b` stays as it was.

---

# 5. Comparing Strings Manually (Lexicographical)

### Definition

**Lexicographical comparison** = dictionary order: compare character by character. The first position
where the characters differ decides the result.

```text
"apple"  vs  "mango"
   a   ≠   m    →  'a' (97) < 'm' (109)  →  "apple" is smaller
```

Rules:

```text
equal strings                → Equal
first differing char of A
  is smaller                 → A is smaller
otherwise                    → B is smaller
```

If one string is a **prefix** of the other, the shorter one is smaller (because `\0` = 0 is smaller
than any real character):

```text
"abc"  vs  "abcd"   →  at index 3: '\0' vs 'd'  →  A is smaller
```

### Code

```c
#include <stdio.h>

int main()
{
    char a[101], b[101];
    scanf("%s %s", a, b);

    int i = 0;
    while (a[i] != '\0' && b[i] != '\0' && a[i] == b[i])
    {
        i++;                          // skip equal characters
    }

    if (a[i] == b[i])                 // both hit '\0' at the same place
    {
        printf("Equal");
    }
    else if (a[i] < b[i])
    {
        printf("A is smaller");
    }
    else
    {
        printf("B is smaller");
    }

    return 0;
}
```

```text
Input:  apple mango
Output: A is smaller

Input:  tiger tiger
Output: Equal
```

### Important Corrections — two mistakes in my first version

My original loop checked `a[1]` and `'0'`:

```c
if (a[1] == '\0' && b[1] == '\0')   // WRONG: index 1 is always the SECOND character
if (a[1] == '0')                    // WRONG: '0' is the digit ZERO, '\0' is the NULL character
```

1. **`a[1]` instead of `a[i]`** — index `1` never moves, so the loop only ever looked at the second
   character. The end-of-string test must use the moving index `i`.
2. **`'0'` instead of `'\0'`** — `'0'` is the printable digit with value `48`; `\0` is the null
   terminator with value `0`. Different characters entirely.

The clean version above simply walks forward while the characters are equal, then compares the first
different position — no `while (1)` and no repeated `break` needed.

---

# 6. Comparing with `strcmp()`

```c
int val = strcmp(a, b);
```

```text
val < 0   →  a is lexicographically smaller
val = 0   →  the strings are equal
val > 0   →  a is greater
```

### Code

```c
#include <stdio.h>
#include <string.h>

int main()
{
    char a[101], b[101];
    scanf("%s %s", a, b);

    int val = strcmp(a, b);
    if (val < 0)
    {
        printf("A is smaller");
    }
    else if (val > 0)
    {
        printf("B is smaller");
    }
    else
    {
        printf("Equal");
    }

    return 0;
}
```

```text
Input:  apple mango
Output: A is smaller
```

### Important Note

`strcmp()` never compares the strings **lengths** directly — it compares characters until either a
difference is found or a `\0` is reached. That is why `"abc" < "abcd"` (a shorter prefix is smaller)
and why comparison is called *lexicographical*, not *by length*.

---

# Quick Revision

```text
copy          b[i] = a[i] for i <= len        (include '\0')
strcpy(a, b)  a becomes b                      (DESTINATION first)
              strcpy(dest, src)

concat        a[lengthA + i] = b[i] for i <= lengthB   (include '\0')
strcat(a, b)  a becomes a + b, b unchanged     (DESTINATION first)

compare       walk forward while characters are equal, stop at the
              first difference (or at '\0')
strcmp(a,b)   < 0 → a smaller    = 0 → equal    > 0 → a greater

'\0' = null terminator, value 0
'0'  = digit zero,      value 48          ← never mix them up
```

---

# Important Corrections

### 1. Every manual loop that builds a string must copy `\0`

Copy: `i <= len`. Concat: `i <= lengthB`. Missing the terminator turns the string into garbage.

### 2. Destination comes first — in both `strcpy` and `strcat`

```c
strcpy(a, b);   // a receives b
strcat(a, b);   // a becomes a + b
```

### 3. `a[1]` is not "the current character"

The current character is `a[i]` with a moving index — hard-coded indexes only ever look at one fixed
position.

### 4. `'\0'` ≠ `'0'`

```text
'\0'  →  ends a string   (value 0)
'0'   →  the character 0 (value 48)
```

### 5. `strcmp()` result is a sign, not a distance

Only `< 0`, `== 0`, `> 0` are reliable — the exact number differs between implementations.

---

# What to Learn Next

Directly connected to this module:

- **`strncmp()` and `strncpy()`** — the "n" versions that work on a limited number of characters
- **Counting characters** — vowels, digits, spaces with one pass
- **Substring / prefix problems** — checking if one string starts with another
- **`string.h` overview** — `strlen`, `strcpy`, `strcat`, `strcmp` and their `<string.h>` siblings
- **Mid-term practice** — combining arrays + strings (see `../Mid-Exam/`)
