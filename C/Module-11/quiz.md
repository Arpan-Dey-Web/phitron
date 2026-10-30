# Module 11 — String Functions Quiz

Practice quiz on **`strcpy()`, `strcat()` and `strcmp()`**: argument order, return values, and what
the manual loops do with `\0`.

How to use this file:

1. Attempt each question yourself first.
2. Trace what happens to the destination string.
3. Check the answer and explanation below each question.

---

## Question 1

What is the function to copy one string to another in C programming?

A. `strcpy()`
B. `memcpy()`
C. `copy()`
D. None of the above

<details>
<summary>Answer</summary>

**A) `strcpy()`**

</details>

### Explanation

`strcpy()` এর মাধ্যমে আমরা দুটি স্ট্রিং এর একটি কে অপর টিতে কপি করে রাখতে পারি।

```c
strcpy(a, b);    // b is copied INTO a
```

`memcpy()` also copies memory, but it is not string-aware (no `\0` handling) and lives in
`<string.h>` too — for text, `strcpy()` is the right tool.

---

## Question 2

What is lexicographical comparison of strings in C programming?

A. Checking if two strings have the same number of characters
B. Comparing strings alphabetically using character-by-character comparison
C. Comparing strings by converting each character to binary
D. Comparing the lengths of two strings

<details>
<summary>Answer</summary>

**B) Comparing strings alphabetically using character-by-character comparison**

</details>

### Explanation

Dictionary / lexicographical order এ একটি স্ট্রিং এর সাথে অপরটি কম্পারিজন করা হয় ক্যারেক্টার বাই
ক্যারেক্টার। কোনো ক্যারেক্টার অর্ডার আগে পরে থাকলে এর উপর স্ট্রিং lexicographically কম্পারিজন করে
থাকে।

```text
"apple" vs "mango"
    a   ≠   m   →  'a' (97) < 'm' (109)  →  "apple" is smaller
```

Length is never compared directly — `"abc" < "abcd"` because `'\0'` (value 0) is smaller than any
real character.

---

## Question 3

What is the function to compare two strings lexicographically in C programming?

A. `strcmp()`
B. `memcmp()`
C. `strncmp()`
D. None of the above

<details>
<summary>Answer</summary>

**A) `strcmp()`**

</details>

### Explanation

দুটি স্ট্রিং কে lexicographical comparison করার জন্য `strcmp()` এই built-in ফাংশনটি ব্যবহার করা
হয়।

`strncmp()` compares only the first `n` characters, and `memcmp()` compares raw bytes — neither is
the plain "compare two whole strings" function.

---

## Question 4

What does the `strcmp()` function return when the first string is greater than the second string?

A. Positive value
B. 0
C. Negative value
D. None of the above

<details>
<summary>Answer</summary>

**A) Positive value**

</details>

### Explanation

দুটি স্ট্রিং এর প্রথম টি অপরটি হতে lexicographically বড় হলে `strcmp()` ফাংশনটি একটি পজিটিভ ভ্যালু
রিটার্ন করে।

```c
strcmp("mango", "apple") > 0     // 'm' > 'a'
```

Only the **sign** is guaranteed — the exact number differs between implementations.

---

## Question 5

What does the `strcmp()` function return when the first string is smaller than the second string?

A. Positive value
B. 0
C. Negative value
D. None of the above

<details>
<summary>Answer</summary>

**C) Negative value**

</details>

### Explanation

দুটি স্ট্রিং এর প্রথম টি অপরটি হতে lexicographically ছোট হলে `strcmp()` ফাংশনটি একটি নেগেটিভ ভ্যালু
রিটার্ন করে।

```c
strcmp("apple", "mango") < 0
```

In code this is written as `if (strcmp(a, b) < 0)` — comparing with `0`, never with an exact value
like `-1`.

---

## Question 6

What does the `strcmp()` function return when both strings are equal?

A. Positive value
B. 0
C. Negative value
D. None of the above

<details>
<summary>Answer</summary>

**B) 0**

</details>

### Explanation

দুটি স্ট্রিং যদি পরস্পর সমান হয়ে সেক্ষেত্রে `strcmp()` ফাংশনটি ভ্যালু হিসেবে ০ রিটার্ন করে।

Two strings are equal only when **every character matches and both end at the same place** —
`"abc"` and `"abcd"` are NOT equal, even though they share three characters.

---

## Question 7

What is the function to concatenate two strings in C programming?

A. `strcat()`
B. `strncat()`
C. `strccat()`
D. None of the above

<details>
<summary>Answer</summary>

**A) `strcat()`**

</details>

### Explanation

দুটি স্ট্রিং এর একটির সাথে অপরটি যুক্ত করার জন্য স্ট্রিং এর `strcat()` built-in ফাংশনটি ব্যবহৃত
হয়।

```c
strcat(a, b);    // a becomes a + b
```

---

## Question 8

What is string concatenation in C programming?

A. Adding two integers
B. Adding two strings
C. Subtracting two strings
D. Comparing two strings

<details>
<summary>Answer</summary>

**B) Adding two strings**

</details>

### Explanation

দুটি স্ট্রিং এর একটির সাথে অপরটি যুক্ত করাকে স্ট্রিং concatenation বলা হয়।

```text
"cat" + "dog"  →  "catdog"
```

The joined string is stored in the **destination** array, which therefore must be big enough for
both strings plus the `\0`.

---

## Question 9

What is the first argument (the thing we pass first in the function) of the `strcat()` function in C
programming?

A. The destination string
B. The source string
C. The number of characters to concatenate
D. None of the above

<details>
<summary>Answer</summary>

**A) The destination string**

</details>

### Explanation

দুটি স্ট্রিং এর একটির সাথে অপরটি যোগ করার জন্য আমরা `strcat()` ফাংশনের প্রথম আরগুমেন্ট হিসেবে ঐ
স্ট্রিং কে দিই যার মধ্যে আমরা অপর স্ট্রিং কে রাখতে চাই।

```c
strcat(a, b);   // a = destination → a becomes "a + b", b stays unchanged
strcpy(a, b);   // same order rule: destination FIRST
```

---

## Question 10

How do you initialize an array of integers with integer 0?

A. `int ar[size] = {0};`
B. `int ar[size] = 0;`
C. `int ar[size];`
D. `int ar[size] = {'0'};`

<details>
<summary>Answer</summary>

**A) `int ar[size] = {0};`**

</details>

### Explanation

এটি একটি previous quiz — array এর মডিউলে দেখানো হয়েছে। এইভাবে আমরা একটি array ডিক্লেয়ার করে তার
প্রত্যেকটি ইনডেক্স ০ দিয়ে ইনিশিয়ালাইজ করতে পারি।

Careful with the trap in option D: `'0'` is the **character** zero (value 48), not the number `0`.

---

# Quick Revision

```text
strcpy(dest, src)   dest becomes a copy of src
strcat(dest, src)   dest becomes dest + src, src unchanged
strcmp(a, b)        < 0 → a smaller    = 0 → equal    > 0 → a greater

both copy functions need <string.h>
destination argument comes FIRST in strcpy and strcat

manual copy   loop i <= len        (must copy '\0')
manual concat loop i <= lengthB    (must copy '\0')
manual compare: walk while equal, stop at first difference

'\0' = null terminator, 0        '0' = digit zero, 48
```

---

# Common Mistakes to Remember

1. **Swapping the arguments** — `strcpy(b, a)` copies `a` into `b`; `strcpy(a, b)` does the opposite
   (Question 9).
2. **Forgetting `\0` in the manual loops** — `i < lengthB` copies characters only; the string keeps
   garbage after it (see readme corrections).
3. **Using `a[1]` instead of `a[i]`** — index `1` is always the second character; the moving index
   is `i`.
4. **`'0'` instead of `'\0'`** — the digit zero (48) is not the string terminator (0).
5. **Expecting `strcmp()` to return `-1` or `1`** — only the sign is guaranteed.
6. **`strcat()` into an array that is too small** — the destination must hold both strings plus
   `\0`, otherwise memory is overwritten.

---

# What to Learn Next

Directly connected to this quiz:

- **`strncmp()` / `strncpy()`** — limited-length versions of the same functions
- **Counting characters** — one pass to count vowels, digits, spaces
- **Frequency counting** — how often each letter `a`–`z` appears
- **Mid-term practice** — mixed array + string problems (see `../Mid-Exam/`)
- **Reading input until EOF** — solving many test cases in one run
