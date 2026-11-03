# Module 13 — Nested Loop & Pair Sum Quiz

Practice quiz on **nested loops**: predicting pattern output, tracing inner/outer loop roles, the
pair sum problem, and basic sorting order.

How to use this file:

1. Attempt each question yourself first.
2. Trace the loops by hand — write one line per outer-loop value.
3. Check the answer and explanation below each question.

---

## Question 1

What will be the output of this pattern printing code?

```c
for (int i = 1; i <= 3; i++) {
    for (int j = 1; j <= i; j++) {
        printf("%d ", j);
    }
}
```

A. `1 1 2 1 2 3`
B. `1 2 3`
C. `1 2 3 1 2 1`
D. None

<details>
<summary>Answer</summary>

**A) `1 1 2 1 2 3`**

</details>

### Explanation

এই কোডে i এর মান 1 থেকে 3 পর্যন্ত চলবে এবং প্রতিটি i এর জন্য j-এর মান 1 থেকে শুরু করে i পর্যন্ত প্রিন্ট হয়।

যখন i=1 হয় তখন শুধু 1 প্রিন্ট হয়
যখন i=2 হয় তখন 1 2 প্রিন্ট হয়
যখন i=3 হয় তখন 1 2 3 প্রিন্ট হয়

সুতরাং ফাইনাল উত্তর `1 1 2 1 2 3`

```text
i=1 → 1
i=2 → 1 2
i=3 → 1 2 3
```

No `printf("\n")` anywhere, so every group stays on **one single line**.

---

## Question 2

Given an array `[2, 7, 11, 15]` and `X = 9`, which two elements sum to `X`?

A. 2 & 7
B. 7 & 11
C. 11 & 15
D. No pair

<details>
<summary>Answer</summary>

**A) 2 & 7**

</details>

### Explanation

অ্যারেতে 2 এবং 7 এর যোগফল 9 (X=9)। অন্য কোনো জোড়ার যোগফল 9 সম্ভব না।

```text
2 + 7   = 9   ✓
7 + 11  = 18  ✗
11 + 15 = 26  ✗
```

---

## Question 3

How many stars (`*`) will this code print?

```c
for (int i = 1; i <= 4; i++) {
    for (int j = 1; j <= i; j++) {
        printf("*");
    }
}
```

A. 4
B. 10
C. 6
D. 16

<details>
<summary>Answer</summary>

**B) 10**

</details>

### Explanation

এই কোডে i এর মান 1 থেকে 4 পর্যন্ত চলবে।

i=1 হলে 1 টি `*` প্রিন্ট করবে।
i=2 হলে 2 টি `*` প্রিন্ট করবে।
i=3 হলে 3 টি `*` প্রিন্ট করবে।
i=4 হলে 4 টি `*` প্রিন্ট করবে।

সর্বমোট স্টার (`*`) প্রিন্ট হবে = 1+2+3+4 = 10 বার।

```text
1 + 2 + 3 + 4 = 10
```

---

## Question 4

What pattern will this code print?

```c
for (int i = 1; i <= 3; i++) {
    for (int j = 1; j <= 3; j++) {
        printf("%d ", i);
    }
}
```

A. `1 2 3 1 2 3 1 2 3`
B. `1 1 1 2 2 2 3 3 3`
C. `1 2 3`
D. None

<details>
<summary>Answer</summary>

**B) `1 1 1 2 2 2 3 3 3`**

</details>

### Explanation

বাইরের লুপের চলক i-এর মান হয় 1 থেকে 3 এবং ভিতরের লুপ প্রতিটি i-এর মানকে 3 বার প্রিন্ট করে।

যখন i=1 তখন `1 1 1`
যখন i=2 তখন `2 2 2`
যখন i=3 তখন `3 3 3`

যেহেতু লুপের ভিতরে নিউ লাইন নাই তাই সব একই লাইনে দেখাবে।

```text
printf("%d ", i);   // prints i — the OUTER variable — 3 times per row
```

---

## Question 5

How many lines will this code print?

```c
for (int i = 1; i <= 5; i += 2) {
    for (int j = 1; j <= i; j++) {
        printf("*");
    }
    printf("\n");
}
```

A. 2
B. 3
C. 5
D. 6

<details>
<summary>Answer</summary>

**B) 3**

</details>

### Explanation

বাইরের লুপটি চলবে i=1, i=3, i=5 (মোট 3 বার)। প্রতিটি লুপে:

i=1 হলে 1 টি `*` প্রিন্ট করে নতুন লাইনে যায়
i=3 হলে 3 টি `*` প্রিন্ট করে নতুন লাইনে যায়
i=5 হলে 5 টি `*` প্রিন্ট করে নতুন লাইনে যায়

মোট লাইন সংখ্যা: 3 টি

```text
i = 1 → 1 + 2 → 3 → 5 → stop
```

The `printf("\n")` is inside the **outer** loop, so each row gets its own line.

---

## Question 6

What replaces `?` to print:

```text
1
2 3
4 5 6
```

Code:

```c
int num = 1;
for (int i = 1; i <= 3; i++) {
    for (int j = 1; j <= ?; j++) {
        printf("%d ", num++);
    }
    printf("\n");
}
```

A. 3
B. `i`
C. `j`
D. `num`

<details>
<summary>Answer</summary>

**B) `i`**

</details>

### Explanation

বাইরের লুপ (i): এটি সারি নিয়ন্ত্রণ করে (১ম সারি, ২য় সারি, ৩য় সারি)

i=1 → ১ম সারি
i=2 → ২য় সারি
i=3 → ৩য় সারি

ভিতরের লুপ (j): এটি প্রতিটি সারিতে কতগুলো সংখ্যা প্রিন্ট হবে তা নির্ধারণ করে

১ম সারিতে 1 টি সংখ্যা (1)
২য় সারিতে 2 টি সংখ্যা (2 3)
৩য় সারিতে 3 টি সংখ্যা (4 5 6)

num ভেরিয়েবল: এটি 1 থেকে শুরু হয় এবং প্রতিবার প্রিন্ট করার পর 1 করে বাড়ে (num++)

আমাদের দরকার প্রতিটি সারিতে i সংখ্যক মান প্রিন্ট হবে অর্থাৎ ভিতরের লুপটি i বার চলবে। তাই, প্রশ্ন চিহ্নের
(?) স্থানে `i` আসবে।

```text
row 1: 1 print      → j <= 1
row 2: 2 prints     → j <= 2
row 3: 3 prints     → j <= 3
```

---

## Question 7

Given array: `[4, 9, 3, 2, 5]` and target sum `X = 8`. Which **0-indexed** pair of elements sum
to 8?

A. Index 0 & 1
B. Index 1 & 3
C. Index 2 & 4
D. No such pair

<details>
<summary>Answer</summary>

**C) Index 2 & 4**

</details>

### Explanation

প্রদত্ত অ্যারে: `[4, 9, 3, 2, 5]` (0-ইনডেক্স ভিত্তিক)।

```text
index :   0   1   2   3   4
value :   4   9   3   2   5

index 2 → 3
index 4 → 5
3 + 5 = 8  ✓
```

ইনডেক্স 2 এর মান 3 এবং ইনডেক্স 4 এর মান 5, যার যোগফল 3 + 5 = 8।

---

## Question 8

What's the output?

```c
for (int i = 3; i >= 1; i--) {
    for (int j = 1; j <= i; j++) {
        printf("*");
    }
    printf(" ");
}
```

A. `*** ** *`
B. `******`
C. `* * *`
D. None

<details>
<summary>Answer</summary>

**A) `*** ** *`**

</details>

### Explanation

বাইরের লুপ (i): i-এর মান শুরু হয় 3 থেকে এবং 1 পর্যন্ত কমতে থাকে (i--) অর্থাৎ লুপটি চলবে 3 বার:
i=3, i=2, i=1

ভিতরের লুপ (j): প্রতিটি i-এর মানের জন্য j (1 থেকে i) পর্যন্ত চলবে, অর্থাৎ

i=3 হলে j (1 থেকে 3) পর্যন্ত → 3 টি `*` প্রিন্ট হবে
i=2 হলে j (1 থেকে 2) পর্যন্ত → 2 টি `*` প্রিন্ট হবে
i=1 হলে j (1 থেকে 1) পর্যন্ত → 1 টি `*` প্রিন্ট হবে

প্রতিটি ভিতরের লুপের শেষে space প্রিন্ট হবে (এখানে `\n` নয়, তাই সব এক লাইনে)।

আউটপুট: `*** ** *`

---

## Question 9

What is the output after sorting this array in **ascending** order?
`[5, 2, 9, 1]`

A. `[1, 2, 5, 9]`
B. `[9, 5, 2, 1]`
C. `[1, 5, 2, 9]`
D. No change

<details>
<summary>Answer</summary>

**A) `[1, 2, 5, 9]`**

</details>

### Explanation

আসেন্ডিং অর্ডারে সাজানোর অর্থ হলো ছোট থেকে বড় সংখ্যার ক্রমে সাজানো। প্রদত্ত অ্যারে
`[5, 2, 9, 1]`-কে আসেন্ডিং অর্ডারে সাজালে পাওয়া যায় `[1, 2, 5, 9]`

```text
before :  5  2  9  1
after  :  1  2  5  9     (small → large)
```

---

## Question 10

What is the output after sorting this array in **descending** order?
`[5, 2, 9, 1]`

A. `[1, 2, 5, 9]`
B. `[9, 5, 2, 1]`
C. `[1, 5, 2, 9]`
D. No change

<details>
<summary>Answer</summary>

**B) `[9, 5, 2, 1]`**

</details>

### Explanation

ডিসেন্ডিং অর্ডারে সাজানোর অর্থ হলো বড় থেকে ছোট সংখ্যার ক্রমে সাজানো। প্রদত্ত অ্যারে
`[5, 2, 9, 1]`-কে ডিসেন্ডিং অর্ডারে সাজালে পাওয়া যায় `[9, 5, 2, 1]`।

```text
before :  5  2  9  1
after  :  9  5  2  1     (large → small)
```

---

# Quick Revision

```text
outer loop   = row
inner loop   = work inside that row (print that row's content)

printf("%d ", i)  prints the OUTER variable — repeats the same value
printf("%d ", j)  prints a counting sequence 1 2 3 ...
printf("\n")      goes on the next line → placed after the inner loop

i += 2          skip every other value → 1, 3, 5 (3 lines)
pair sum        check a[i] + a[j] == X, j starts at i+1
0-indexed       first element is index 0 → third element is index 2

ascending       small → large      [1, 2, 5, 9]
descending      large → small      [9, 5, 2, 1]
```

---

# Common Mistakes to Remember

1. **Forgetting `printf("\n")`** — every row prints on one single line (Questions 1, 4).
2. **Putting `printf("\n")` inside the inner loop** — every single item gets its own line.
3. **Printing `i` instead of `j`** — `"%d", i` repeats one number; `"%d", j` counts up (Question 4).
4. **Wrong step size** — `i += 2` from 1 gives only 3 rows for `i <= 5` (Question 5).
5. **Counting indexes from 1** — arrays are 0-indexed, so the third element is index 2
   (Question 7).
6. **Mixing up ascending and descending** — ascending = small to large, descending = large to small
   (Questions 9, 10).

---

# What to Learn Next

Directly connected to this quiz:

- **Bubble sort** — writing the loop that actually sorts an array
- **Counting in loops** — total stars/characters without printing a pattern first
- **Pair sum with two pointers** — faster approach on a sorted array
- **Functions** — moving a pattern or sum problem into its own function (see
  [Module 14](../Module-14/readme.md))
