# Module 10 — Strings Quiz

Practice quiz on **strings in C**: the null terminator, `%s`, `scanf` vs `fgets`, initialization,
`strlen()`, and digit conversion.

How to use this file:

1. Attempt each question yourself first.
2. Trace the characters in the array (including `\0`).
3. Check the answer and explanation below each question.

---

## Question 1

In C, what is a string actually made of?

A. A special `string` data type built into C
B. A `char` array that ends with the null character `'\0'`
C. An `int` array holding ASCII codes
D. A group of different data types

<details>
<summary>Answer</summary>

**B) A `char` array that ends with the null character `'\0'`**

</details>

### Explanation

C has no built-in string type. A string is a character array whose last "real" element is `\0`:

```c
char s[6] = "HELLO";
// 'H' 'E' 'L' 'L' 'O' '\0'
```

Every string function stops at `\0` — without it, the array is just characters, not a string.

---

## Question 2

Which specifier is used for **both** reading and printing a string in C?

A. `%c`
B. `%d`
C. `%s`
D. `%f`

<details>
<summary>Answer</summary>

**C) `%s`**

</details>

### Explanation

```c
scanf("%s", s);      // read a string
printf("%s", s);     // print a string
```

`%c` is for a single character, `%d` for an integer.

---

## Question 3

What is the minimum array size needed to store the string `"HELLO"`?

A. 4
B. 5
C. 6
D. 10

<details>
<summary>Answer</summary>

**C) 6**

</details>

### Explanation

```text
'H' 'E' 'L' 'L' 'O' '\0'
 5 characters     +  1 null = 6 bytes
```

```c
char s[6] = "HELLO";    // fits exactly
```

`char s[5]` has no room for `\0` — writing it there is out of bounds.

---

## Question 4

What does `scanf("%s", s)` do when the input is `Arpan Dey`?

A. Reads the whole sentence `Arpan Dey`
B. Reads only `Arpan` and stops at the space
C. Reads only `Dey`
D. Skips the input completely

<details>
<summary>Answer</summary>

**B) Reads only `Arpan` and stops at the space**

</details>

### Explanation

`scanf("%s")` stops at the **first whitespace** (space, tab, or newline). The word `Dey` stays in the
input buffer for the next read.

To read a whole line **including spaces**, use `fgets()`.

---

## Question 5

Which function reads a full line of text including spaces?

A. `gets()`
B. `fgets()`
C. `strlen()`
D. `scanf("%d")`

<details>
<summary>Answer</summary>

**B) `fgets()`**

</details>

### Explanation

```c
fgets(s, 30, stdin);
```

`fgets()` keeps reading until ENTER is pressed, so spaces are included.

**Note:** `gets()` did the same job in old C, but it was **removed in C11** because it cannot limit
the input size — always prefer `fgets()`.

---

## Question 6

`fgets(s, 10, stdin)` — what is the maximum number of characters it stores?

A. 10
B. 9
C. 11
D. 100

<details>
<summary>Answer</summary>

**B) 9**

</details>

### Explanation

```text
fgets(s, 10, stdin)
       ↑
  reads at most 10 - 1 = 9 characters, then adds '\0'
```

The array size always has to reserve one byte for the null terminator — the same rule as
`char s[10]` holding at most 9 characters of text.

---

## Question 7

What does `fgets()` do with the ENTER key at the end of the line?

A. Throws it away
B. Stores it as `'\n'` inside the string
C. Converts it to `'\0'`
D. Stops before it, like `scanf`

<details>
<summary>Answer</summary>

**B) Stores it `'\n'` inside the string**

</details>

### Explanation

```text
typed : Arpan Dey  + Enter
stored: 'A' 'r' 'p' 'a' 'n' ' ' 'D' 'e' 'y' '\n' '\0'
```

That is why the output of a `fgets()` program automatically moves to the next line. To remove it, the
last character must be replaced by `'\0'`.

Difference in one line:

```text
scanf("%s") → stops at SPACE
fgets()     → stops at ENTER and KEEPS it
```

---

## Question 8

What is the output of this code?

```c
char s[30] = "Arpan Dey";
printf("%s", s);
```

A. `Arpan`
B. `Arpan Dey`
C. Garbage values
D. Compile error

<details>
<summary>Answer</summary>

**B) `Arpan Dey`**

</details>

### Explanation

Initialization at declaration stores the characters **and** adds `\0` automatically:

```text
'A' 'r' 'p' 'a' 'n' ' ' 'D' 'e' 'y' '\0'
```

`%s` prints every character up to `\0` — including the space inside the text (printing is not limited
by the "stops at space" rule of `scanf`).

---

## Question 9

What will `strlen(s)` print for `s = "HELLO"`?

A. 4
B. 5
C. 6
D. 0

<details>
<summary>Answer</summary>

**B) 5**

</details>

### Explanation

`strlen()` counts the characters **before** `\0` and does not count `\0` itself:

```text
H   E   L   L   O   \0
1   2   3   4   5   → stops here
```

It is declared in `<string.h>`. The same result can be made with a manual loop:

```c
int count = 0;
for (int i = 0; s[i] != '\0'; i++) {
    count++;
}
```

---

## Question 10

What is the output of the following code (this is the digit-sum problem from `main.c`)?

```c
char s[1000001];
scanf("%s", s);           // input: 351

int sum = 0;
for (int i = 0; i < strlen(s); i++) {
    sum += s[i] - '0';
}
printf("%d", sum);
```

A. 351
B. 9
C. 153
D. 3

<details>
<summary>Answer</summary>

**B) 9**

</details>

### Explanation

Each character is converted to its digit value with `s[i] - '0'`:

```text
'3' - '0' = 51 - 48 = 3
'5' - '0' = 53 - 48 = 5
'1' - '0' = 49 - 48 = 1

sum = 3 + 5 + 1 = 9
```

This trick is what lets a number too big for `long long` be handled — it is processed as text, one
character at a time.

---

# Quick Revision

```text
string          char array + '\0'        char s[10];
size needed     characters + 1

%s              used by BOTH scanf and printf
scanf("%s")     stops at space/tab/newline → reads one word
fgets(s,n,stdin) reads a whole line, STORES the '\n', needs <stdio.h>
                stores at most n-1 characters

init            char s[30] = "Arpan Dey";  → '\0' added automatically
strlen(s)       characters before '\0', does not count '\0'  (<string.h>)
s[i] - '0'      digit character → integer value
s               array name is already an address (no & needed)
```

---

# Common Mistakes to Remember

1. **Writing `scanf("%s", &s)`** — the array name is already the address (Question 2's code).
2. **Allocating exactly `strlen` bytes** — one more byte is always needed for `\0` (Question 3).
3. **Expecting `scanf("%s")` to read a sentence** — it stops at the first space (Question 4).
4. **Forgetting `fgets()` keeps `'\n'`** — output looks like it has an extra line break (Question 7).
5. **Counting `\0` in the length** — `strlen("HELLO")` is 5, not 6 (Question 9).
6. **Printing a character's ASCII code by mistake** — `printf("%c", s[i])` prints the character,
   `s[i] - '0'` gives its number.
7. **`fgets()` prototype** — it lives in `<stdio.h>`, not `<string.h>`.

---

# What to Learn Next

Directly connected to this quiz:

- **String functions** — `strcpy()`, `strcmp()`, `strcat()` (usually the next class)
- **Palindrome string** — two pointers comparing characters from both ends
- **Character case conversion** — `+32` / `-32` with ASCII
- **Counting letters, digits, spaces** — loop + range conditions
- **Reading input until EOF** — handling many test cases in one run
