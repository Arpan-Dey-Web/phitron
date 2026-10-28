# Module 10 — Strings

Today I learned how C handles **text (strings)**: how a string is stored, how to take string input,
how to print it, how to read a full line with spaces, how to initialize a string, and how to find the
length of a string.

Main topics:

* What a string is in C (`char` array + `\0`)
* Reading a string with `scanf("%s")`
* Printing a string with `printf("%s")`
* The null terminator `\0` and the extra byte it needs
* Why `scanf("%s")` stops at a space, and how `fgets()` reads a whole line
* Initializing a string at declaration
* String length — manual loop and `strlen()`
* Problem: sum of the digits of a very large number

This continues from **characters** in [Module 5](../Module-5/readme.md) and **arrays** in
[Module 7](../Module-7/readme.md).

Files:

| File | Purpose |
| ---- | ------- |
| `main.c` | Problem statements + my solutions (kept as comments) |
| `quiz.md` | String quiz with explanations |
| `input.txt` | Last input I tested with |
| `output.txt` | Output produced for that input |

---

# 1. What Is a String?

A **string** is a sequence of characters stored in a `char` array.

C has **no built-in `string` type**. A string is just a character array that ends with a special
character: the **null terminator** `\0`.

```c
char s[10];
```

```text
Stored in memory:

Index:   0    1    2    3    4     5     6     7     8     9
Value:  'H'  'E'  'L'  'L'  'O'  '\0'   ?     ?     ?     ?
                                 ↑
                       string ENDS here
```

```text
H | E | L | L | O | \0 | garbage | garbage | ...
                ↑
     everything after \0 is not part of the string
```

### Important Note

`\0` is the **null character** (numeric value `0`). It is what makes the array a *string* — every
function that works with a string stops reading at `\0`.

When I store a string value, C **automatically adds `\0` after the last character**. Memory after
that `\0` holds leftover garbage values and is simply ignored.

---

# 2. String Input with `scanf("%s")`

For strings the specifier is **`%s`** — the same specifier is used for both printing and scanning.

```c
#include <stdio.h>

int main()
{
    char s[10];
    scanf("%s", s);
    printf("%s", s);
    return 0;
}
```

```text
Input:  HELLO
Output: HELLO
```

### Important Note — `s`, not `&s`

```c
scanf("%s", s);      // correct
scanf("%s", &s);     // works by accident, but wrong types
```

The name of an array **already is** its memory address, so `s` is enough. (`&s` gives the address of
the whole array, which has a different type — see [Module 7](../Module-7/readme.md) for why `scanf`
needs an address.)

### Important Note — always keep room for `\0`

```text
string "HELLO" → 5 characters + 1 null = 6 bytes needed
```

So for a string of up to 9 characters I need at least `char s[10]`. If the array is exactly the size
of the text, `\0` has nowhere to go.

---

# 3. `scanf("%s")` Stops at a Space

```text
input:  Arpan Dey
        ↑
scanf("%s") reads only "Arpan" and stops — the space ends the input.
```

`scanf("%s")` **stops reading at the first whitespace** (space, tab, newline). The rest stays in the
input buffer.

To read **one word**, `scanf("%s")` is enough. To read a **whole line including spaces**, use
`fgets()`.

---

# 4. Reading a Whole Line with `fgets()`

```c
fgets(arrayName, stringSize, stdin);
```

```text
fgets(arrayName, stringSize, stdin)
                  ^
                  |
                total input I want to take, including +1 for the '\0'
```

* `arrayName` — where to store the line
* `stringSize` — the size of the array (it reads at most `stringSize - 1` characters)
* `stdin` — read from the keyboard

```c
#include <stdio.h>

int main()
{
    char s[30];
    fgets(s, 30, stdin);
    printf("%s", s);
    return 0;
}
```

### How `fgets()` differs from `scanf("%s")`

```text
scanf("%s")  → stops at the first SPACE (or newline)
fgets()      → stops at ENTER, and stores that '\n' as a character
```

**Sample:**

```text
Input:
Arpan Dey

Output:
Arpan Dey
(moves to the next line, because the newline character '\n' was stored)
```

If I type `Arpan Dey` and press Enter, `fgets()` stores:

```text
'A' 'r' 'p' 'a' 'n' ' ' 'D' 'e' 'y' '\n' '\0'
```

So the printed output automatically moves to a new line — that is not an extra empty line in the
string, it is the Enter key stored as `\012` (`\n`).

### Important Note

* `fgets()` needs **`<stdio.h>`** (not `<string.h>`).
* `fgets()` keeps the `\n`. To remove it, delete the last character before `\0`.
* `gets()` could do this in old C, but it is **removed from modern C** (C11) because it cannot check
  the buffer size — always use `fgets()`.

---

# 5. String Initialization

A string can be given a value at the same time it is declared:

```c
#include <stdio.h>

int main()
{
    char s[30] = "Arpan Dey";
    printf("%s", s);
    return 0;
}
```

```text
Output:
Arpan Dey
```

```text
s → 'A' 'r' 'p' 'a' 'n' ' ' 'D' 'e' 'y' '\0' 0 0 0 ...
                           ↑
                    added automatically
```

The compiler writes the characters **and** the `\0` for me.

---

# 6. Length of a String

### Method 1 — count with a loop

Count characters until the null terminator appears:

```c
#include <stdio.h>

int main()
{
    char s[100];
    scanf("%s", s);

    int count = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        count++;
    }

    printf("%d", count);
    return 0;
}
```

```text
Input:  HELLO
Output: 5
```

```text
i = 0..4 → real characters, count grows to 5
i = 5    → s[5] == '\0' → loop stops
```

### Method 2 — `strlen()` from `<string.h>`

```c
#include <stdio.h>
#include <string.h>

int main()
{
    char s[100];
    scanf("%s", s);

    int size = strlen(s);
    printf("%d", size);
    return 0;
}
```

```text
Input:  HELLO
Output: 5
```

`strlen()` counts the same way (up to `\0`) and does **not** count the `\0` itself.

**Note:** the manual loop teaches what a string really is; in contests `strlen()` is fine and faster
to write.

---

# 7. Problem — Sum of the Digits of a Very Large Number

**Statement:** Given a number that may be far too large for `int`/`long long`, print the sum of its
digits.

**Idea:** Read it as a **string**, then add the numeric value of each character.

```text
'0' = 48, '1' = 49, ... '9' = 57

value of a digit character = s[i] - '0'
'3' - '0' = 51 - 48 = 3
```

### Code

```c
#include <stdio.h>
#include <string.h>

int main()
{
    char s[1000001];
    scanf("%s", s);

    int length = strlen(s);
    int sum = 0;
    for (int i = 0; i < length; i++)
    {
        sum += s[i] - '0';        // character → digit value
    }

    printf("%d", sum);
    return 0;
}
```

### Output

```text
Input:  351
Output: 9            (3 + 5 + 1 = 9)
```

### Important Note

`s[i] - '0'` is the standard trick for converting **one digit character to its integer value**. This
is why `char` arithmetic (Module 5) matters — `'\0'` is also just the number `0`.

---

# Quick Revision

```text
string      char array ending with '\0'        char s[10];
specifiers  %s works for BOTH scanf and printf
input       scanf("%s", s)     → one word, stops at space
line input  fgets(s, size, stdin) → whole line, keeps the '\n'
print       printf("%s", s)

size needed = characters + 1   (the +1 is for '\0')
array name is already an address → scanf("%s", s), not &s

init        char s[30] = "Arpan Dey";   → '\0' added automatically
length      loop until s[i] == '\0'   or   strlen(s)  (<string.h>)
digit value s[i] - '0'
```

---

# Important Corrections

### 1. `&s` is not needed in `scanf("%s", ...)`

The array name `s` already points to the first character's address.

### 2. `fgets()` belongs to `<stdio.h>`

`<string.h>` is for `strlen()`, `strcpy()`, `strcmp()`, `strcat()` — not for `fgets()`.

### 3. `fgets()` stores the Enter key

The printed line ends with a newline **because `\n` is part of the stored string**.

### 4. `scanf("%s")` never reads a full sentence

Anything after a space is left in the input buffer. Use `fgets()` for sentences.

### 5. Array size must include the `\0`

`char s[5]` fits `"HELLO"` **not** — that needs 6 bytes. Undersized arrays cause undefined behavior.

---

# What to Learn Next

Directly connected to this module:

- **String library functions** — `strlen()`, `strcpy()`, `strcmp()`, `strcat()` (usually next in the course)
- **Character by character processing** — counting vowels, converting case
- **Palindrome check on a string** — two pointers over characters
- **Buffer safety** — why `fgets()` needs the size, and what happens without it
- **Reading with `scanf` until EOF** — processing many inputs in one run
