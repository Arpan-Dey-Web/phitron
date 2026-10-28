# Module 9 — Array Insert, Delete, Swap Quiz

Practice quiz on **changing array contents in C**: inserting at an index, deleting at an index,
swapping variables, and reversing an array.

How to use this file:

1. Attempt each question yourself first.
2. Trace the array by hand after the operation.
3. Check the answer and explanation below each question.

---

## Question 1

We have an array containing these values: `10, 20, 30, 40`. We want to insert 2 more values. What
will be the size of our array?

A. 4
B. 5
C. 6
D. 7

<details>
<summary>Answer</summary>

**C) 6**

</details>

### Explanation

প্রাথমিক অ্যারের সাইজ 4 (মান: 10, 20, 30, 40)। আরও 2টি মান যোগ করলে মোট সাইজ হবে 4 + 2 = 6।

```text
size 4  +  2 insertions  =  6
```

Every single insertion grows the array by exactly 1.

---

## Question 2

We have an array containing these values: `10, 20, 30, 40, 50`. We insert `100` at index 1. Now what
will be the value at index 2?

A. 30
B. 20
C. 100
D. 40

<details>
<summary>Answer</summary>

**B) 20**

</details>

### Explanation

প্রাথমিক অ্যারে: `[10, 20, 30, 40, 50]`
ইনডেক্স 1 এ 100 ইনসার্ট করলে অ্যারে হবে: `[10, 100, 20, 30, 40, 50]`
এখন ইনডেক্স 2 এ থাকবে 20 (কারণ অ্যারে ইনডেক্সিং 0 থেকে শুরু হয়)।

```text
index :   0     1     2     3     4     5
value :  10   100    20    30    40    50
                      ↑
                old index 1 (20) was pushed one step right
```

---

## Question 3

We have an array containing these values: `10, 20, 30, 40, 50`. We removed the value at index 2. Now
what will be the value at index 3?

A. 50
B. 40
C. 30
D. 20

<details>
<summary>Answer</summary>

**A) 50**

</details>

### Explanation

প্রাথমিক অ্যারে: `[10, 20, 30, 40, 50]`
ইনডেক্স 2 এর মান (30) রিমুভ করলে অ্যারে হবে: `[10, 20, 40, 50]`
এখন ইনডেক্স 3 এ থাকবে 50 (কারণ রিমুভের পর পরের মানগুলো বামদিকে চলে আসে)।

```text
before :  10   20   30   40   50
after  :  10   20   40   50
index  :   0    1    2    3          → 50 moved from index 4 to index 3
```

---

## Question 4

What technique did we use to reverse an array today?

A. Reverse the loop
B. Swapping values
C. Two pointers technique
D. None of the above

<details>
<summary>Answer</summary>

**C) Two pointers technique**

</details>

### Explanation

আজকের মডিউলে আমরা অ্যারে রিভার্স করতে Two pointers technique ব্যবহার করেছি।

```c
for (int i = 0, j = n - 1; i < j; i++, j--) {
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}
```

```text
i moves from the start →
j moves from the end   ←
they swap values and stop when they meet
```

Note: the loop *is* written backwards only when we simply **print** from the end. The in-place
reverse technique itself is the two-pointer swap.

---

## Question 5

What is array deletion in C programming?

A. Removing an element from an array
B. Sorting an array in ascending order
C. Adding an element to an array at a specified position
D. None of the above

<details>
<summary>Answer</summary>

**A) Removing an element from an array**

</details>

### Explanation

অ্যারে ডিলিশন মানে অ্যারে থেকে একটি উপাদান মুছে ফেলা বা রিমুভ করা। এটি করতে হলে, ডিলিট পজিশনের
পরের সব উপাদান বাম দিকে সরিয়ে নিয়ে আসতে হয় এবং অ্যারের সাইজ ১ কমিয়ে দিতে হয়।

```text
delete at idx :
  1. shift every later element left   (a[i] = a[i+1])
  2. reduce the printed size by 1     (n--)
```

---

## Question 6

We have an array of size 5 with these values `10, 20, 30, 40, 50`. We want to delete the value at
index 1. What will be the value at index 2 after deletion?

A. 50
B. 40
C. 30
D. 20

<details>
<summary>Answer</summary>

**B) 40**

</details>

### Explanation

প্রাথমিক অ্যারে: `[10, 20, 30, 40, 50]`
ইনডেক্স 1 (মান = 20) ডিলিট করলে নতুন অ্যারে: `[10, 30, 40, 50]`
সুতরাং ইনডেক্স 2 এ থাকবে 40।

```text
before :  10   20   30   40   50
after  :  10   30   40   50
index  :   0    1    2    3
```

---

## Question 7

We have an array containing these values: `10, 20, 30, 40, 50`. We insert `100` at index 2. Now what
will be the value at index 1?

A. 100
B. 10
C. 20
D. 30

<details>
<summary>Answer</summary>

**C) 20**

</details>

### Explanation

প্রাথমিক অ্যারে: `[10, 20, 30, 40, 50]`
ইনডেক্স 2 এ 100 ইনসার্ট করলে নতুন অ্যারে: `[10, 20, 100, 30, 40, 50]`
ইনডেক্স 1-এর মান 20 অপরিবর্তিত থাকবে।

```text
insert only pushes elements at index >= idx
index 1 < idx 2 → untouched
```

---

## Question 8

We have an array of size 5 with these values `10, 20, 30, 40, 50`. We want to delete the value at
index 2. What will be the value at index 1 **before** deletion?

A. 50
B. 40
C. 30
D. 20

<details>
<summary>Answer</summary>

**D) 20**

</details>

### Explanation

প্রাথমিক অ্যারে: `[10, 20, 30, 40, 50]`
যেহেতু ডিলিট করার পূর্বে অ্যারের ইনডেক্স 1 এর মান চেয়েছে, সুতরাং ইনডেক্স 1 এর মান 20 থাকবে।

```text
BEFORE deletion : index 1 = 20
AFTER  deletion : index 1 = 20   (deletion at index 2 does not touch index 1)
```

Read the question carefully — it asks for the state **before** the operation.

---

## Question 9

We have an array of size 5 with these values `10, 20, 30, 40, 50`. We want to delete the value at
index 5. What will be the size of the array after deletion?

A. 5
B. 4
C. 3
D. 6

<details>
<summary>Answer</summary>

**A) 5**

</details>

### Explanation

প্রাথমিক অ্যারে: `[10, 20, 30, 40, 50]` (সাইজ 5)
এই অ্যারেতে ভ্যালিড ইনডেক্স রেঞ্জ 0 থেকে 4 (কারণ সাইজ = 5) এবং ইনডেক্স 5 অ্যারেতে নেই, তাই ডিলিশন
করা সম্ভব না। সুতরাং, অ্যারের সাইজ অপরিবর্তিত থাকবে।

```text
valid indexes for size 5 : 0, 1, 2, 3, 4
index 5                  : out of bounds → nothing is deleted
```

---

## Question 10

What will be the value of `a` and `b` after swapping in the following code?

```c
int a = 5, b = 8, temp;
temp = a;
a = b;
b = temp;
```

A. `a = 5, b = 8`
B. `a = 8, b = 5`
C. `a = 5, b = 5`
D. `a = 8, b = 8`

<details>
<summary>Answer</summary>

**B) `a = 8, b = 5`**

</details>

### Explanation

এই কোডটি a এবং b-এর মান পরস্পর swap করে:

```text
temp = a;   → temp = 5    (a-এর মান সংরক্ষণ করা হয়)
a = b;      → a = 8       (b-এর মান a-তে বসানো হয়)
b = temp;   → b = 5       (সংরক্ষিত মান b-তে বসানো হয়)
```

ফলাফল: a-এর নতুন মান = 8, b-এর নতুন মান = 5।

---

# Quick Revision

```text
insert idx   → array grows +1, shift RIGHT from the end (backward loop)
delete idx   → array shrinks 1, shift LEFT  from idx forward, then n--

insert at 1 into [10,20,30,40,50] with 100 → [10,100,20,30,40,50]
delete 2    from [10,20,30,40,50]          → [10,20,40,50]

reverse     → two pointers i = 0, j = n-1, swap while i < j
swap        → temp = a; a = b; b = temp;

valid indexes for size n → 0 .. n-1   (index n does not exist)
```

---

# Common Mistakes to Remember

1. **Shifting in the wrong direction on insert** — start from the end, or values get overwritten
   (Questions 2, 7).
2. **Forgetting that everything after the deleted index moves** — index 3 changes after a delete at
   index 2 (Question 3).
3. **Confusing "before deletion" with "after deletion"** — read the question twice (Question 8).
4. **Trying to delete index `n`** — the last valid index is `n - 1`, so nothing happens (Question 9).
5. **Swapping without `temp`** — both variables end up holding the same value (Question 10).
6. **Declaring `int a[n-1]` while reading `n` values** — out-of-bounds write (see readme correction).

---

# What to Learn Next

Directly connected to this quiz:

- **Insert/delete in a sorted array** — finding the position first, then shifting
- **Palindrome array with two pointers** — the same `i`/`j` movement, comparing instead of swapping
- **Frequency counting** — counting how often each value appears
- **Why shifting is slow** — insert/delete in the middle is `O(n)`
- **Functions and arrays** — writing `insert()` and `delete()` as reusable functions
