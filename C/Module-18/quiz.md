# Module 18 — 2D Array and Matrix Quiz

Practice quiz on **2D arrays and matrices**: declaration and indexing, capacity, reading values
from a matrix, and the matrix types (square, diagonal, primary/secondary diagonal).

> ট্রিকি কুইজগুলো এখানে এক্সপ্লেইন করে দেওয়া আছে। তারপরও কোথাও ডাউট থাকলে কুইজের উত্তর শো করে
> গ্রুপে পোস্ট না করে সাপোর্ট সেশনে জয়েন হয়ে ক্লিয়ার হয়ে নিয়েন।

How to use this file:

1. Attempt each question yourself first.
2. Draw the matrix and mark the indexes before answering.
3. Check the answer and explanation below each question.

---

## Question 1

What is a 2D array in C programming?

A. An array of integers with 2 elements
B. An array of arrays
C. An array of integer pointers
D. An array of strings

<details>
<summary>Answer</summary>

**B) An array of arrays**

</details>

### Explanation

2D এরে হচ্ছে একটি এরে যার প্রতিটি ইনডেক্সে একটি করে এরে আছে। যেমন `arr[3][4]` — ৩টি রো, প্রতিটি রো-তে
৪টি করে মান। বাইরের এরেটি রো গুলোকে, ভেতরের এরেটি প্রতিটি রো-র কলাম গুলোকে ধরে রাখে।

---

## Question 2

What type of matrix is this?

```text
2 0 0
0 0 0
0 0 9
```

A. Square matrix
B. Diagonal matrix
C. Both of the above
D. None of the above

<details>
<summary>Answer</summary>

**C) Both of the above**

</details>

### Explanation

রো ৩টি, কলাম ৩টি — সমান তাই এটি **স্কয়ার ম্যাট্রিক্স**। আবার মূল ডায়াগনাল (বাম উপরে থেকে ডান
নিচে) বাদে বাকি সব ভেলু ০ — তাই এটি **ডায়াগনাল ম্যাট্রিক্সও**। দুটোই সঠিক, তাই **C**।

---

## Question 3

Is the following matrix a Diagonal matrix?

```text
3 0 0
0 3 0
0 0 0
```

A. Yes
B. No

<details>
<summary>Answer</summary>

**A) Yes**

</details>

### Explanation

রো আর কলাম সংখ্যা সমান (৩ = ৩) তাই স্কয়ার। মূল ডায়াগনালের বাইরে সব জায়গায় ০ আছে
(`arr[0][1]`, `arr[0][2]`, `arr[1][0]`, `arr[1][2]`, `arr[2][0]`, `arr[2][1]` সব ০)। তাই **Yes** —
ডায়াগনাল ম্যাট্রিক্স।

(ডায়াগনালে থাকা মানগুলো সমান না হলেও চলে — সমান হলে তা **স্কেলার ম্যাট্রিক্স**, সব ১ হলে **ইউনিট
ম্যাট্রিক্স**। এখানে ৩, ৩, ০ — তাই শুধু ডায়াগনাল, স্কেলার নয়।)

---

## Question 4

We have a matrix like this:

```text
1  2 -5  0
-3 0  2 -5
4  5 -6  7
-2 -2 -1  0
```

What is the value on the **secondary diagonal at 2nd row**? (1-based index)

A. 0
B. 2
C. 5
D. -5

<details>
<summary>Answer</summary>

**B) 2**

</details>

### Explanation

সেকেন্ডারি ডায়াগনাল = ডান উপরে থেকে বাম নিচে। ১-বেসড রো ২ মানে ০-বেসড ইনডেক্স `i = 1`।
সেকেন্ডারি ডায়াগনালে কলাম হবে `i + j = rows - 1` থেকে:

```text
i + j = 4 - 1 = 3   →   j = 2
arr[1][2] = 2
```

তাই উত্তর **2**।

---

## Question 5

We have the same matrix:

```text
1  2 -5  0
-3 0  2 -5
4  5 -6  7
-2 -2 -1  0
```

What is the value on the **secondary diagonal at 3rd row**? (0-based index)

A. 0
B. 2
C. -2
D. 5

<details>
<summary>Answer</summary>

**C) -2**

</details>

### Explanation

এখানে রোর ইনডেক্স **০-বেসড** — তাই "৩য় রো" বলতে ইনডেক্স `i = 3` (সবার শেষ রোটি) বোঝানো হয়েছে:

```text
i = 3   →   i + j = 3   →   j = 0
arr[3][0] = -2
```

তাই উত্তর **-2**। (০-বেসড ইনডেক্সে সংখ্যা গুনতে গেলে প্রথমটা হয় ০ — "৩য় রো" মানে ৪র্থ ভিজ্যুয়াল লাইন।)

---

## Question 6

We have a matrix like this:

```text
2 3  5
4 5 -6
1 0  2
0 0  3
```

What is the value on the primary diagonal at 1st row? (1-based index)

A. 2
B. 5
C. 3
D. There is no primary diagonal in this matrix.

<details>
<summary>Answer</summary>

**D) There is no primary diagonal in this matrix.**

</details>

### Explanation

এখানে রো ৪টি, কলাম ৩টি। রো আর কলাম সংখ্যা সমান না তাই এটি **স্কয়ার ম্যাট্রিক্স না**। ডায়াগনাল বা
কর্ণ শুধুমাত্র স্কয়ার ম্যাট্রিক্সে থাকে — তাই এখানে কোন প্রাইমারি ডায়াগনাল নেই, উত্তর **D**।

---

## Question 7

We have a 2D array `arr[3][3]`. How many elements at max can we store in it?

A. 6
B. 8
C. 9
D. Unlimited

<details>
<summary>Answer</summary>

**C) 9**

</details>

### Explanation

৩টি রো × ৩টি কলাম = ৩ × ৩ = **৯**টি ভেলু। ২ডি এরের সাইজ ডিক্লেয়ার করার সময়ই ফিক্স হয়ে যায়, তাই
সর্বোচ্চ ৯টির বেশি রাখা যায় না (D ভুল — "unlimited" নয়)।

---

## Question 8

We have a 2D array `arr[3][3]`. We store these values into it:
`2, 5, 6, 1, 4, 7, 10, 22, 14`.
What is the value at `arr[1][2]?` (0-based index)

A. 5
B. 7
C. 4
D. Error

<details>
<summary>Answer</summary>

**B) 7**

</details>

### Explanation

ভেলুগুলো একটার পর একটা রো-ভরে বসে (row by row):

|        | col 0 | col 1 | col 2 |
| ------ | ----- | ----- | ----- |
| row 0  | 2     | 5     | 6     |
| row 1  | 1     | 4     | **7** |
| row 2  | 10    | 22    | 14    |

`arr[1][2]` = রো ১, কলাম ২ = **7**। মনে রাখবে: ভেলু বসে আগে পুরো রো ০, তারপর রো ১, তারপর রো ২ —
সোজা সারিতে নয়।

---

## Question 9

We want to store these values: `1, 0, -2, 4, 3, 9, 0, 5, 7, 1, -3, 5` into a 2D array declared as
`arr[3][?]`. What is the **minimum** value of `?`

A. 3
B. 4
C. 5
D. None of the above

<details>
<summary>Answer</summary>

**B) 4**

</details>

### Explanation

মোট ভেলু ১২টি। ১২টি রাখতে হলে টোটাল সাইজ অন্তত ১২ হতে হবে। রো ৩টি ফিক্স, তাই কলাম হবে
১২ ÷ ৩ = **৪**। `arr[3][4]` = ১২টি ঘর — ঠিক কাজের। `?` = ৩ হলে ৯টি ঘর, ১১টি ভেলু বাইরে থেকে যেত।

---

## Question 10

We have a matrix like this:

```text
-2 -3 -6
 4  5 -6
 0  1  0
```

Which value is present **both** at the primary and the secondary diagonal?

A. 0
B. -6
C. 5
D. 3

<details>
<summary>Answer</summary>

**C) 5**

</details>

### Explanation

দুই ডায়াগনালের পজিশন আলাদা করে লিখি:

```text
primary   (i == j)          secondary  (i + j == 2)
arr[0][0] = -2              arr[0][2] = -6
arr[1][1] =  5              arr[1][1] =  5   ← দুটোতেই আছে
arr[2][2] =  0              arr[2][0] =  0
```

দুই ডায়াগনাল কেবল **মাঝখানের ঘরে** ছেঁড়া হয় (odd-sized ম্যাট্রিক্সের সেন্টার) — সেখানেই `arr[1][1] = 5`।
তাই উত্তর **5**। (D-তে ৩ আছে কিন্তু ম্যাট্রিক্সে ৩ নামে কোনো ভেলুই নেই।)
