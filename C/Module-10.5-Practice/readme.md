# Module 10.5 — Practice: Arrays + Strings

This folder is a **practice set mixing Module 9 (arrays) and Module 10 (strings)** — 6 problems solved
from the problem sheet.

I did not write a full theory note for this session. All problem statements and my solutions are kept
as comments inside `main.c`. This readme is the revision index for that folder.

Files:

| File | Purpose |
| ---- | ------- |
| `main.c` | Problem statements + my solutions (kept as comments) |
| `input.txt` | Last input I tested with |
| `output.txt` | Output produced for that input |
| `quiz.md` | (empty for now — practice only) |

---

# Problems Solved

| No. | Problem | Main Concept |
| --- | ------- | ------------ |
| 1 | F. Reversing | Print an array backwards (`i = n-1 … 0`) |
| 2 | G. Palindrome Array | Two pointers comparing from both ends |
| 3 | F. Way Too Long Words | `strlen()`, condition + abbreviation formula |
| 4 | G. Conversion | Case swap with ASCII `±32`, in-place edit |
| 5 | I. Palindrome | Two pointers over characters |
| 6 | D. Strings | `strlen()`, concatenation print, swap first chars |

---

# 1. F. Reversing

**Problem:** Given `N` and then `N` numbers, print them in reversed order (no built-in functions).

**Idea:** Start printing at the last index `n - 1` and go down to `0`.

```c
for (int i = n - 1; i >= 0; i--) {
    printf("%d ", arr[i]);
}
```

**Sample:**

```text
Input:
4
5 1 3 2

Output:
2 3 1 5
```

**Important Correction — `int arr[n - 1]` was wrong**

My first version declared:

```c
int arr[n - 1];              // WRONG — we READ n values
for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);    // writes one slot past the end
}
```

That is an **out-of-bounds write** (undefined behavior). The correct declaration while reading `n`
values is `int arr[n]`. Reducing the size only matters when *deleting* an element — printing in
reverse never changes the array size.

---

# 2. G. Palindrome Array

**Problem:** Given `N` and `N` numbers, print `YES` if the array reads the same forwards and
backwards, otherwise `NO`.

**Idea:** Two pointers — `i` from the start, `j` from the end. Compare `a[i]` with `a[j]`; one
mismatch means `NO` and we can stop immediately.

```c
int flag = 1;
for (int i = 0, j = n - 1; i < j; i++, j--) {
    if (a[i] != a[j]) {
        printf("NO");
        flag = 0;
        break;
    }
}
if (flag == 1) {
    printf("YES");
}
```

**Sample:**

```text
Input:  5 / 1 3 2 3 1   →  YES
Input:  4 / 1 2 3 4     →  NO
```

**Edge cases:**

```text
N = 1        → loop never runs → YES (a single element is a palindrome)
N even/odd   → i < j handles both; the middle element never needs a partner
```

**Note:** `flag` must be checked **after** the loop — otherwise `NO` would be followed by `YES`.

---

# 3. F. Way Too Long Words

**Problem:** For each word, print it unchanged if its length ≤ 10, otherwise abbreviate it:
first character + (length − 2) + last character.

**Idea:** `strlen()` gives the length; one `if` decides which format to print.

```c
if (strLength <= 10) {
    printf("%s\n", str);
} else {
    printf("%c%d%c\n", str[0], strLength - 2, str[strLength - 1]);
}
```

**Sample:**

```text
Input:
4
word
localization
internationalization
pneumonoultramicroscopicsilicovolcanoconiosis

Output:
word
l10n
i18n
p43s
```

**How the number is computed:**

```text
"localization"  → length 12 → 12 - 2 = 10 → "l" + "10" + "n"
                   characters between first and last = length - 2
```

**Note:** each line prints with `\n`, because `T` test cases run in one loop — without it all results
would appear on a single line.

---

# 4. G. Conversion

**Problem:** Replace every `,` with a space, and swap the case of every letter.

**Idea:** ASCII case conversion from [Module 5](../Module-5/readme.md):

```text
'a' - 'A' = 32
lowercase → uppercase :  -= 32
uppercase → lowercase :  += 32
```

```c
if (a[i] == ',') {
    a[i] = ' ';
} else if (a[i] >= 'A' && a[i] <= 'Z') {
    a[i] += 32;        // upper → lower
} else if (a[i] >= 'a' && a[i] <= 'z') {
    a[i] -= 32;        // lower → upper
}
```

**Sample:**

```text
Input:  happy,NewYear,enjoy
Output: HAPPY nEWyEAR ENJOY
```

**Note:** the array is edited **in place** and printed once at the end — no second array needed.
`scanf("%s")` works here because the input contains no spaces (only letters and commas).

---

# 5. I. Palindrome

**Problem:** Given a string, print `YES` if it is a palindrome, otherwise `NO`.

**Idea:** Same two-pointer comparison as the palindrome **array**, but on characters:

```c
int num = 1;
for (int i = 0, j = len - 1; i < j; i++, j--) {
    if (a[i] != a[j]) {
        num = 0;
        printf("NO");
        break;
    }
}
if (num == 1) {
    printf("YES");
}
```

**Sample:**

```text
abba           → YES
icpcassiut     → NO
mam            → YES
```

**Note:** comparing strings character by character is what `strcmp()` does internally — writing it
by hand first shows exactly why the two-pointer pattern keeps appearing.

---

# 6. D. Strings

**Problem:** Given two strings `A` and `B`, print their sizes, their concatenation, and both strings
after swapping their **first** characters.

**Idea:** `strlen()` for the sizes, `printf("%s%s")` to print them joined, and the `temp` swap from
Module 9 for the first characters.

```c
int len_s = strlen(s);
int len_t = strlen(t);
printf("%d %d\n", len_s, len_t);
printf("%s%s\n", s, t);

char temp = s[0];
s[0] = t[0];
t[0] = temp;
printf("%s %s\n", s, t);
```

**Sample:**

```text
Input:
abcd
ef

Output:
4 2
abcdef
ebcd af
```

**Important Note:** `printf("%s%s")` only *prints* the two strings next to each other — `s` and `t`
themselves are unchanged. Only the explicit swap modifies the arrays.

---

# Quick Revision

```text
print reversed array     for (i = n-1; i >= 0; i--)
palindrome array/string  two pointers i and j, compare a[i] vs a[j]
                         mismatch → print NO/YES and break

strlen(s)                length without '\0'
abbreviation formula     first char + (length - 2) + last char
case swap                upper -= 32, lower += 32
swap first characters    temp = s[0]; s[0] = t[0]; t[0] = temp

array size while reading n values → int arr[n]  (never arr[n-1])
flag/result checks happen AFTER the loop, not inside it
```

---

# Common Mistakes to Remember

1. **`int arr[n - 1]` while reading `n` values** — out-of-bounds write (Problem 1).
2. **Printing `YES` after already printing `NO`** — the result check must be outside the loop
   (Problems 2 and 5).
3. **Forgetting `\n` between test cases** — all answers end up on one line (Problem 3).
4. **Mixing up `+= 32` and `-= 32`** — converting twice returns the original letter (Problem 4).
5. **Thinking `printf("%s%s")` merges the strings in memory** — it only prints them together;
   the arrays stay as they were (Problem 6).

---

# What to Learn Next

Directly connected to this practice set:

- **More two-pointer problems** — pair sum with a sorted array, checking palindromes in place
- **String library functions** — `strcmp()`, `strcpy()`, `strcat()` and what they do internally
- **Counting patterns** — vowels, digits, spaces in a line
- **Reading until EOF** — solving many test cases without a leading `T`
- **Time complexity of reversing** — why one pass over `N` elements is `O(N)`
