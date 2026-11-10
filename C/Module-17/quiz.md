# Module 17 — Recursion Quiz

Practice quiz on **recursion and the call stack**: predicting output of calling functions,
identifying recursion, the base case, and infinite recursion.

How to use this file:

1. Attempt each question yourself first.
2. Trace the calls by hand — write one line per function call.
3. Check the answer and explanation below each question.

---

## Question 1

What will be the output of the following C code?

```c
#include <stdio.h>
void gello()
{
    printf("Gello ");
}
void hello()
{
    gello();
    printf("Hello ");
}
int main()
{
    printf("Main ");
    hello();
}
```

A. `Main Hello Gello`
B. `Main Gello`
C. `Main Gello Hello`
D. `Main Hello`

<details>
<summary>Answer</summary>

**C) `Main Gello Hello`**

</details>

### Explanation

প্রথমে `main()` থেকে "Main " প্রিন্ট হয়। তারপর `hello()` কল হয়, যা `gello()` কে কল করে — `gello()`
"Gello " প্রিন্ট করে এবং ফিরে আসে। তারপর `hello()` থেকে "Hello " প্রিন্ট হয়। তাই আউটপুট
**Main Gello Hello** — যে ফাংশনটি আগে কল হয়েছে, তার print আগেই শেষ হয়ে গেছে, তারপর ডাকার
ফাংশনের print হয়।

---

## Question 2

"A function is calling itself" — what is this process called?

A. Call by value
B. Call by name
C. Recursion
D. Call by reference

<details>
<summary>Answer</summary>

**C) Recursion**

</details>

### Explanation

যখন কোনো ফাংশন নিজেকে নিজেই কল করে, তখন সেই প্রক্রিয়াকে **রিকার্শন (Recursion)** বলে। এটি একটি
লুপের মতো কাজ করে এবং একটি **বেস কেসের** মাধ্যমে থামে।

---

## Question 3

What will be the problem if we run this code?

```c
#include <stdio.h>
void fun()
{
    printf("fun\n");
    fun();
}
int main()
{
    fun();
}
```

A. Syntax error
B. Compilation error
C. Infinite Recursion
D. Both A and B

<details>
<summary>Answer</summary>

**C) Infinite Recursion**

</details>

### Explanation

কোডে কোনো syntax বা compile error নেই — ঠিকমতো compile হবে। কিন্তু `fun()` কোনো base case ছাড়াই
বারবার নিজেকে কল করে, তাই এটি **ইনফিনিট রিকার্শনে** চলতে থাকে। নতুন নতুন stack frame একের পর
এক তৈরি হতে থাকে, শেষে স্ট্যাক পূর্ণ হয়ে **Stack Overflow** হয় এবং প্রোগ্রাম ক্র্যাশ করে।

---

## Question 4

What will be the output if we run this code?

```c
#include <stdio.h>
void fun()
{
    printf("fun\n");
}
int main()
{
    fun();
}
```

A. Syntax error
B. Compilation error
C. `fun`
D. No output

<details>
<summary>Answer</summary>

**C) `fun`**

</details>

### Explanation

`main()` শুধু `fun()` কে একবার কল করে, `fun()` "fun" প্রিন্ট করে ফিরে আসে। কোনো error নেই, তাই
আউটপুট হলো শুধু **fun**। এখানে recursion-ও নেই — শুধু একটা সাধারণ function call।

---

## Question 5

What will be the output of the following C code?

```c
#include <stdio.h>
void f2()
{
    printf("f1 ");
}
void f1()
{
    printf("f2 ");
    f2();
}
int main()
{
    printf("Main ");
    f1();
}
```

A. `Main f1 f2`
B. `Main f2 f1`
C. `Main`
D. No output

<details>
<summary>Answer</summary>

**B) `Main f2 f1`**

</details>

### Explanation

এখানে ফাংশনের **নাম আর print-এর টেক্সট উল্টো** — সেটায় মনে নষ্ট হবে না। ধাপে ধাপে:

```text
main()      -> "Main "
f1() কল     -> "f2 " প্রিন্ট, তারপর f2() কল
f2() কল     -> "f1 " প্রিন্ট, return
f1() ফিরে   -> return
```

তাই আউটপুট **Main f2 f1**। যেকোনো কোড trace করার সময় function-এর definition-এর ভেতরের printf
গুলোই বিবেচনা করতে হবে, ফাংশনের নাম নয়।

---

## Question 6

Recursion is similar but not exactly the same as which of the following?

A. If-else
B. Loop
C. Both of the above
D. None of the above

<details>
<summary>Answer</summary>

**B) Loop**

</details>

### Explanation

রিকার্শন আর **লুপ** দুটোই পুনরাবৃত্তিমূলক কাজ করে — তাই দুটো একই রকম। কিন্তু লুপ একটা condition
চেক করে আর ঘুরতে থাকে, আর রিকার্শন প্রতিবার **নতুন function call** করে (নতুন stack frame তৈরি
হয়)। তাই ধারণা একই, implementation আলাদা — recursion লুপের মতো, কিন্তু হুবহু এক নয়।

---

## Question 7

Can you print from N to 1 and from 1 to N using recursion?

A. Yes
B. No

<details>
<summary>Answer</summary>

**A) Yes**

</details>

### Explanation

সম্ভব — দুটোই করা যায়। শুধু `printf`-এর জায়গাটা বদলাতে হয়:

```text
printf BEFORE the recursive call  ->  N, N-1, ... 1   (on the way down)
printf AFTER  the recursive call  ->  1, 2, ... N     (on the way back)
```

মডিউলের "print 1 to 5" আর "the tricky one" দুটো code ঠিক এটাই দেখিয়েছে।

---

## Question 8

A recursive function must always have a base case to prevent infinite recursion.

A. False
B. True

<details>
<summary>Answer</summary>

**B) True**

</details>

### Explanation

বেস কেস ছাড়া ফাংশন নিজেকে কখনো থামবে না — ফলে স্ট্যাক ওভারফ্লো (Stack Overflow) হয়ে প্রোগ্রাম
ক্র্যাশ করবে। তাই প্রতিটি recursive function-এ অবশ্যই একটা base case থাকতে হবে যাতে recursion
stop হয়।

---

## Question 9

In recursion, the condition for which the function stops calling itself is called?

A. Best case
B. Worse case
C. Base case
D. Nothing

<details>
<summary>Answer</summary>

**C) Base case**

</details>

### Explanation

রিকার্শনে ফাংশন নিজেকে কল করা বন্ধ করার শর্তকে **বেস কেস (Base Case)** বলে। সাধারণত এটা একটা
`if` condition যা সবচেয়ে ছোট ইনপুটে `return` করে — যেমন `if (n == 1) return;`।

---

## Question 10

"A base case is not necessary for a recursive function to work correctly."

A. True
B. False

<details>
<summary>Answer</summary>

**B) False**

</details>

### Explanation

বেস কেস **অপরিহার্য** — ছাড়া রিকার্শন ফাংশন সঠিকভাবে কাজ করতে পারে না। বেস কেসই রিকার্শনকে
থামানোর শর্ত দেয়; এটি না থাকলে ফাংশন নিজেকে অসীমভাবে কল করতে থাকবে এবং stack overflow হবে।
তাই এই বক্তব্যটি **False**।
