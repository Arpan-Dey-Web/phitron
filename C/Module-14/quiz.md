# Module 14 — Functions Quiz

Practice quiz on **functions in C**: declaration format, calling, `void` vs value-returning
functions, parameters, `return`, and the built-in math functions.

How to use this file:

1. Attempt each question yourself first.
2. Trace what `main()` actually calls (and what it does **not** call).
3. Check the answer and explanation below each question.

---

## Question 1

Which of the following is the correct format for a function **declaration**?

A. `return-type function-name(parameters);`
B. `function-name(parameter name) return-type;`
C. `return-type (parameter type) function-name;`
D. All of the mentioned

<details>
<summary>Answer</summary>

**A) `return-type function-name(parameters);`**

</details>

### Explanation

ফাংশন ডিক্লেয়ার করার সঠিক ফরম্যাট হলো: `return-type function-name(parameters);`

```c
int add(int a, int b);
//  ↑        ↑
//  what comes back    what goes in
```

- `return-type` — ফাংশন যা রিটার্ন করবে তার ডাটা টাইপ (যেমন: `int`, `void`)
- `function-name` — ফাংশনের নাম
- `parameters` — ফাংশনের ইনপুট ভেরিয়েবল (অপশনাল)

---

## Question 2

What will be the output of the following C code?

```c
#include <stdio.h>
void m()
{
    printf("hi");
}
int main()
{
    m();
    return 0;
}
```

A. `hi`
B. Run time error
C. `hello`
D. None of the above

<details>
<summary>Answer</summary>

**A) `hi`**

</details>

### Explanation

`main()` ফাংশন থেকে `m()` ফাংশন কল করবে, যা `"hi"` প্রিন্ট করে।

`m()` is defined **above** `main`, and the call `m();` actually runs — so `hi` is printed with no
newline.

---

## Question 3

What will be the output of the following C code?

```c
#include <stdio.h>
void m()
{
    printf("hi ");
}
int main()
{
    printf("hello ");
    return 0;
}
```

A. `hi`
B. `hello`
C. `hi hello`
D. `hello hi`

<details>
<summary>Answer</summary>

**B) `hello`**

</details>

### Explanation

প্রোগ্রামটি শুধুমাত্র `main()` ফাংশনের ভিতরের কোড `printf("hello ");` এক্সিকিউট করবে। কারণ, `m()`
ফাংশন ডিফাইন করা থাকলেও, এটি কল করা হয় নি তাই এর ভিতরের কোড (`printf("hi ");`) রান হবে না।

```text
defining a function ≠ calling it
m() exists, but nothing ever says m();   → body never runs
```

---

## Question 4

What should be the return type of the `sum` function? Think deeply.

```c
#include <stdio.h>
___ sum()
{
    int a = 10, b = 10;
    printf("%d", a + b);
}
int main()
{
    sum();
    return 0;
}
```

A. `int`
B. `float`
C. `void`
D. None of the above

<details>
<summary>Answer</summary>

**C) `void`**

</details>

### Explanation

`sum()` ফাংশনটি `a + b` এর মান প্রিন্ট করছে, কিন্তু কোনো মান রিটার্ন করছে না। যেহেতু ফাংশনটি কোনো মান
রিটার্ন করছে না, এর রিটার্ন টাইপ `void` হবে।

```text
prints a value  → needs printf (what it does)
returns a value → needs return  (what gives back to the caller)
this one only prints → void
```

Also note `main` calls `sum();` with **no** stored result — correct for a `void` function.

---

## Question 5

What will be the output of the following C code?

```c
#include <stdio.h>
int sum(int x, int y)
{
    int res = x + y;
    return res;
}
int main()
{
    sum(5, 6);
    return 0;
}
```

A. `11`
B. `30`
C. `-1`
D. None of the above

<details>
<summary>Answer</summary>

**D) None of the above**

</details>

### Explanation

প্রোগ্রামটি কোনো আউটপুট প্রদর্শন করবে না, কারণ: `sum(5, 6)` ফাংশনটি 11 রিটার্ন করলেও, এই মানটি কোথাও
স্টোর বা প্রিন্ট করা হয়নি।

```text
sum(5, 6);      →  11 comes back... and is thrown away
printf("%d", sum(5, 6));   → 11 would appear
```

**Important:** calling a function and ignoring its return value produces no visible output.

---

## Question 6

What will be the output of the following C code?

```c
#include <stdio.h>
int sum(int x, int y)
{
    int res = x + y;
    return res;
}
int main()
{
    printf("%d", sum(5, 6));
    return 0;
}
```

A. `11`
B. `30`
C. `-1`
D. None of the above

<details>
<summary>Answer</summary>

**A) 11**

</details>

### Explanation

`sum(5, 6)` ফাংশনটি 5 ও 6 যোগ করে `res` ভেরিয়েবলে `x + y` (5+6=11) সংরক্ষিত হয় এবং এটি ফাংশন দ্বারা
রিটার্ন হয়। `printf("%d", sum(5, 6));` দ্বারা এই রিটার্ন ভ্যালু প্রিন্ট হয়।

```text
sum(5, 6)  →  returns 11  →  printf receives 11  →  prints "11"
```

Same code as Question 5 — the **only** difference is storing/printing the returned value.

---

## Question 7

What is the purpose of the **parameters** in a C function?

A. To specify the type of data that the function returns
B. To pass values to the function
C. To specify the function's name
D. To mark the end of the function

<details>
<summary>Answer</summary>

**B) To pass values to the function**

</details>

### Explanation

প্যারামিটার ব্যবহার করা হয় ফাংশনে ডাটা/মান পাঠানোর জন্য। ফাংশন কল করার সময় প্যারামিটারের মাধ্যমে
ভ্যালু পাঠানো হয়।

```c
int add(int a, int b);   // a, b receive whatever the call passes
add(x, y);               // x copied into a, y copied into b
```

Option A describes the **return type**, not parameters.

---

## Question 8

What is the purpose of the `return` statement in a C function?

A. To mark the start of the function
B. To specify the type of data that the function returns
C. To return a value to the caller of the function
D. To specify the function's name

<details>
<summary>Answer</summary>

**C) To return a value to the caller of the function**

</details>

### Explanation

`return` স্টেটমেন্টের কাজ হলো ফাংশন থেকে কলার ফাংশনে কোনো ভ্যালু ফেরত দেওয়া। `return` ফাংশনের
এক্সিকিউশন শেষ করে এবং নির্দিষ্ট ভ্যালু রিটার্ন করে।

```text
two jobs of return:
  1. send the value back   → return res;
  2. STOP the function     → code after return never runs
```

Option B describes the return **type** in the function header, not the `return` statement.

---

## Question 9

What will be the result of `ceil(4.5)`? (Suppose all header files are written.)

A. 4
B. 5
C. 4.5
D. 6

<details>
<summary>Answer</summary>

**B) 5**

</details>

### Explanation

`ceil()` ফাংশনটি সিলিং মান রিটার্ন করে, অর্থাৎ দশমিক সংখ্যাকে তার থেকে বড় নিকটতম পূর্ণ সংখ্যায়
রিটার্ন করে। `ceil(4.5)` এর ফলাফল 5 (কারণ 4.5 এর থেকে বড় নিকটতম পূর্ণসংখ্যা 5)।

```text
ceil   → always rounds UP   ceil(4.5) = 5
floor  → always rounds DOWN floor(4.5) = 4
```

---

## Question 10

What will be the result of `floor(4.5)`? (Suppose all header files are written.)

A. 5
B. 4
C. 4.5
D. 6

<details>
<summary>Answer</summary>

**B) 4**

</details>

### Explanation

`floor()` ফাংশনটি ফ্লোর মান রিটার্ন করে, অর্থাৎ দশমিক সংখ্যাকে তার থেকে ছোট নিকটতম পূর্ণ সংখ্যায়
রিটার্ন করে। `floor(4.5)` এর ফলাফল 4 (কারণ 4.5 এর থেকে ছোট নিকটতম পূর্ণসংখ্যা 4)।

```text
floor(4.5) = 4    ceil(4.5) = 5
floor(4.1) = 4    ceil(4.1) = 5
```

---

# Quick Revision

```text
declare        return-type name(parameters);
define         return-type name(parameters) { ... return value; }
call           name(arguments);

void           returns nothing → call stands alone:   m();
int            returns a value → store/print it:      int t = sum(5, 6);

defining ≠ calling      a function that is never called never runs (Q3)
return value ignored    sum(5, 6); alone prints nothing (Q5)

parameters  → pass values IN      (B, Q7)
return      → send value to caller + stop the function (C, Q8)

math.h      ceil(4.5) = 5     floor(4.5) = 4
```

---

# Common Mistakes to Remember

1. **Assuming a defined function runs by itself** — it only runs when **called** (Question 3).
2. **Throwing away a return value** — `sum(5, 6);` computes 11 but prints nothing (Question 5).
3. **`int` function with no `return`** — the caller gets an unpredictable value; use `void`
   instead (Question 4).
4. **`int total = add();` where `add` is `void`** — compile error; a `void` call stores nothing.
5. **Mixing up `ceil` and `floor`** — ceil = up, floor = down (Questions 9, 10).
6. **Confusing parameters with return type** — parameters pass data *in*; the return type says what
   comes *out* (Questions 7, 8).

---

# What to Learn Next

Directly connected to this quiz:

- **Function prototypes** — declaring `int add(int, int);` before `main`
- **Recursion** — a function calling itself
- **Pointers as parameters** — letting a function modify the caller's variables (a real `swap()`)
- **Scope deepening** — local vs global vs static lifetime
- **Library headers** — `<math.h>`, `<stdlib.h>` and which functions live where
