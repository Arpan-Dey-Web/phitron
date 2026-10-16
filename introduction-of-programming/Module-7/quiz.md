# Module 7 — Arrays Quiz

Practice quiz on **arrays in C**: declaration, indexes, access, initialization, and simple loop tracing.

How to use this file:

1. Attempt each question yourself first.
2. Check the answer and explanation below each question.

---

## Question 1

What is an array in the C programming language?

A. A group of similar type of data elements
B. A group of different type of data elements
C. An integer
D. An alien data type

<details>
<summary>Answer</summary>

**A) A group of similar type of data elements**

</details>

### Explanation

An array stores **many values of the same data type** under one name:

```c
int arr[5];    // 5 integers — one type
```

Mixing types (`int` + `char`, etc.) in one array is not allowed.

---

## Question 2

Which of the following is the correct syntax for declaring an array of integers?

A. `int arrayName[size];`
B. `int arrayName;`
C. `array arrayName[int];`
D. `array arrayName[size];`

<details>
<summary>Answer</summary>

**A) `int arrayName[size];`**

</details>

### Explanation

Array declaration syntax:

```text
data_type  array_name  [ size ];

int        arrayName   [ 10 ];    // integer array of size 10
```

C has no `array` keyword — the type comes first, like any variable.

---

## Question 3

What is the index number of the first element in an array in C?

A. 0
B. 1
C. -1
D. 2

<details>
<summary>Answer</summary>

**A) 0**

</details>

### Explanation

Array indexing always starts at `0`:

```text
Position:   1st   2nd   3rd
Index:       0     1     2
```

So the first element is at `arr[0]`.

---

## Question 4

What will be the output of the following code?

```c
int arr[4] = {10, 20, 30, 40};
printf("%d", arr[2]);
```

A. 10
B. 20
C. 30
D. 50

<details>
<summary>Answer</summary>

**C) 30**

</details>

### Explanation

```text
arr[0] = 10
arr[1] = 20
arr[2] = 30   ← arr[2] is the THIRD element, not the second
arr[3] = 40
```

Remember: index = position − 1.

---

## Question 5

How do you access the nth element of an array in C?

A. `arrayName[n]`
B. `arrayName[n - 1]`
C. `arrayName[n + 1]`
D. `arrayName[n * 2]`

<details>
<summary>Answer</summary>

**B) `arrayName[n - 1]`**

</details>

### Explanation

Because indexes start at `0`:

```text
1st element → arrayName[0]
2nd element → arrayName[1]
nth element → arrayName[n - 1]
```

The last element of an array of size `n` is also at index `n - 1`.

---

## Question 6

How do you assign a value to an element of an array in C?

A. `arrayName[index] = value;`
B. `arrayName.value(index);`
C. `arrayName(index) = value;`
D. `value.arrayName(index);`

<details>
<summary>Answer</summary>

**A) `arrayName[index] = value;`**

</details>

### Explanation

Each index acts like its own variable:

```c
arr[2] = 20;     // store 20 at index 2
x = arr[2];      // read it back → 20
```

The `[]` (square bracket) syntax is used for arrays in C.

---

## Question 7

What is the purpose of the `for` loop when working with arrays?

A. To initialize the array
B. To declare the array
C. To iterate over the array
D. To delete the array

<details>
<summary>Answer</summary>

**C) To iterate over the array**

</details>

### Explanation

Array indexes are `0, 1, 2, ..., size-1` — a natural sequence for a loop:

```c
for (int i = 0; i < n; i++) {
    // do something with arr[i]
}
```

C has no delete operation for arrays — their lifetime is managed by scope.

---

## Question 8

What is the index number of the last element of an array with 5 elements?

A. 5
B. 4
C. 0
D. 6

<details>
<summary>Answer</summary>

**B) 4**

</details>

### Explanation

```text
size 5 → indexes 0, 1, 2, 3, 4
last index = size - 1 = 4
```

`arr[5]` would be out of bounds — never access it.

---

## Question 9

What is the output of the following code?

```c
int arrayName[5] = {1, 2, 3, 4, 5};
int sum = 0;

for (int i = 0; i < 3; i++) {
    sum += arrayName[i];
}

printf("%d", sum);
```

A. 15
B. 6
C. 10
D. 0

<details>
<summary>Answer</summary>

**B) 6**

</details>

### Explanation

`i < 3` means the loop runs for `i = 0, 1, 2` only:

```text
sum = arrayName[0] + arrayName[1] + arrayName[2]
    = 1 + 2 + 3
    = 6
```

Indexes 3 and 4 (`4` and `5`) are never added. If all 5 elements were needed, the condition would be `i < 5`.

---

## Question 10

What is the output of the following code?

```c
int arrayName[5] = {1, 2, 3};
printf("%d", arrayName[4]);
```

A. 1
B. 2
C. 3
D. 0

<details>
<summary>Answer</summary>

**D) 0**

</details>

### Explanation

The size is `5` but only 3 values were given. The remaining slots are **filled with 0 automatically**:

```text
arrayName[0] = 1
arrayName[1] = 2
arrayName[2] = 3
arrayName[3] = 0    ← not given → 0
arrayName[4] = 0    ← not given → 0
```

So `arrayName[4]` is `0`.

**Contrast:** `int arr[5];` with **no** initializer at all holds **garbage values**, not zeros.

---

# Quick Revision

```text
declare     int arr[10];              indexes 0 .. 9
first index 0
last index  size - 1
nth element arrayName[n - 1]

assign      arrayName[i] = value;
read        arrayName[i]
& in scanf  scanf("%d", &arrayName[i]);

int arr[] = {1,2,3};        → size becomes 3
int arr[5] = {10, 20};      → 10, 20, 0, 0, 0
int arr[5];                 → garbage values
for loop                    → i from 0 to size-1
```

---

# Common Mistakes to Remember

1. **Thinking indexes start at 1** — `arr[0]` is the first element (Questions 3, 4, 8).
2. **`arr[n]` for the nth element** — it is `arr[n - 1]` (Question 5).
3. **Forgetting partially initialized arrays fill with 0** — `{1, 2, 3}` in a size-5 array gives two extra `0`s (Question 10).
4. **`&ar[i]` when printing** — `printf` needs the value `ar[i]`, not the address `&ar[i]` (see readme correction).
5. **Out-of-bounds access** — `arr[size]` is undefined behavior; last valid index is `size - 1`.

---

# What to Learn Next

Directly connected to this quiz:

- **Array problems** — sum, max, min, counting patterns (`extraPractice.c`)
- **Swap / reverse in place** — two indexes moving toward each other
- **Out-of-bounds bugs** — why `i <= n` in an array loop is often wrong
- **Functions and arrays** — passing arrays to functions
