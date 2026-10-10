# Day 1 — Introduction to Programming with C

Today I started learning the basics of programming with **C**.

The main topics I learned today are:

* Basic structure of a C program
* Header files
* `main()` function
* `printf()`
* Escape sequences
* Variables
* Basic data types
* Bits and bytes
* Format specifiers
* Boolean values
* Taking input with `scanf()`
* Basic understanding of memory consumption and integer limits

---

# 1. Basic Structure of a C Program

A C program has a defined structure.

A very basic C program looks like this:

```c
#include <stdio.h>

int main() {
    printf("Hello World!!!");

    return 0;
}
```

We can understand this program in two main parts:

```text
Header File
    ↓
Actual Program / Function Body
```

For a beginner, a simple way to imagine it is:

```text
Header = tools and information we need

Body = where we write the actual program logic
```

---

# 2. Header File

```c
#include <stdio.h>
```

This line is used to include the standard input/output library information in our program.

## What is `#include`?

`#include` is a **preprocessor directive**.

It tells the C preprocessor to include the contents of another file before the compilation process continues.

For example:

```c
#include <stdio.h>
```

means that our program wants to use functionality provided by the standard input/output library.

---

# 3. What is `stdio.h`?

`stdio.h` means:

```text
Standard Input Output Header
```

It belongs to the C standard library and provides declarations related to input and output functions.

For example:

```c
printf()
scanf()
```

are declared in `stdio.h`.

So when we write:

```c
#include <stdio.h>
```

we are telling the compiler that we want to use those standard input/output functions.

### Important understanding

It is not quite correct to say:

> "`stdio.h` contains the complete `printf()` function."

A better understanding is:

```text
stdio.h
   ↓
Provides the declaration/information
about functions such as printf() and scanf()
   ↓
The actual implementation is provided
by the C standard library
```

We don't need to write the internal implementation of `printf()` ourselves.

We simply call it:

```c
printf("Hello World");
```

This is one of the important ideas of programming:

> Someone has already built many useful functions, and we can use those functions instead of rebuilding everything ourselves.

---

# 4. What does `.h` mean?

The `.h` extension means:

```text
Header File
```

Some common header files are:

```text
stdio.h
stdlib.h
string.h
math.h
stdbool.h
```

For example:

```c
#include <stdio.h>
```

Here:

```text
stdio → file name
.h    → header file
```

---

# 5. The `main()` Function

Every executable C program needs a starting point.

That starting point is the:

```c
main()
```

function.

Example:

```c
int main() {
    printf("Hello World");

    return 0;
}
```

When a C program starts running, execution begins from `main()`.

So we can think of it as:

```text
Program starts
      ↓
   main()
      ↓
Statements execute
      ↓
return 0
```

---

# 6. Understanding `int main()`

This is very important.

```c
int main()
```

does **not** mean that `main()` returns nothing.

It means:

```text
int → return type
main → function name
() → parameter list
```

So:

```c
int main()
```

means:

> The `main` function returns an integer (`int`) value.

That integer is normally returned to the operating system.

---

# 7. Function Body

The code inside `{ }` is called the **function body**.

Example:

```c
int main() {

    printf("Hello World");

    return 0;
}
```

The body of `main()` is:

```c
{
    printf("Hello World");

    return 0;
}
```

More precisely, the statements between the opening `{` and closing `}` form the function body.

---

# 8. `return 0`

At the end of `main()` we usually write:

```c
return 0;
```

This means that `main()` returns the integer value `0`.

Conventionally:

```text
0       → successful execution
non-zero → some kind of error or other status
```

Example:

```c
int main() {
    printf("Hello World");

    return 0;
}
```

Here:

```text
main()
   ↓
returns 0
   ↓
program finishes successfully
```

---

# 9. `printf()` Function

`printf()` is a standard C function used to display formatted output.

Example:

```c
printf("Hello World");
```

We don't need to know how `printf()` internally sends characters to the terminal before we can use it.

We only need to know:

```text
Function name → printf()
Purpose       → print formatted output
Input         → data we want to print
```

For example:

```c
printf("Hello");
```

Here `"Hello"` is passed to `printf()`.

Another example:

```c
int age = 22;

printf("%d", age);
```

Here `age` is passed to `printf()`.

---

# 10. Escape Sequence — New Line `\n`

In C, `\n` is called a **newline escape sequence**.

It moves the cursor to the next line.

Example:

```c
int main() {
    printf("Hello\n");
    printf("World");

    return 0;
}
```

Output:

```text
Hello
World
```

Without `\n`:

```c
printf("Hello");
printf("World");
```

Output:

```text
HelloWorld
```

So:

```text
\n → move to the next line
```

---

# 11. Escape Sequence — Tab `\t`

`\t` is a **tab escape sequence**.

It inserts a horizontal tab.

Example:

```c
int main() {
    printf("Hello\t");
    printf("World");

    return 0;
}
```

Output will look similar to:

```text
Hello    World
```

The exact amount of visible spacing depends on the terminal/editor.

So:

```text
\t → insert a tab
```

### Important Note

A tab often **looks like 4 spaces**, but that is not a rule.

```text
\t → tab (spacing decided by terminal/editor, often 4 spaces wide)
```

If we need exactly 4 spaces every time, we should print 4 space characters directly instead of relying on `\t`.

---

# 12. Escape Sequence — Backslash `\\`

`\` has a special meaning in C: it starts an **escape sequence**.

That means a single `\` never prints itself. It always combines with the next character:

```text
\n → newline
\t → tab
\\ → one backslash
```

To print **one** backslash, we must type **two**:

```c
printf("C:\\Users\\Arpan\n");
```

Output:

```text
C:\Users\Arpan
```

How the compiler reads it:

```text
\\ → prints \
\\ → prints \
```

Compare:

```c
printf("a\b");     // \b = backspace escape, not a literal 'b'
printf("a\\b");    // prints: a\b
```

So:

```text
\  → never printed directly, starts an escape sequence
\\ → prints one backslash \
```

---

# 13. Escape Sequences — Quotes `\"` and `\'`

Double quotes `"` and single quotes `'` are special inside strings and character constants. Sometimes we need to print them as normal text.

To print a double quote inside a string:

```c
printf("He said \"Hello\"\n");
```

Output:

```text
He said "Hello"
```

Without the escape:

```c
printf("He said "Hello"");   // error: string ends at the second "
```

To print a single quote:

```c
printf("It's fine\n");
```

Inside a string, `\'` is optional — a single quote usually needs no escape.

But inside a **character constant** it becomes necessary, because an unescaped `'` would end the constant early:

```c
char ch = '\'';    // one character: '
char ch2 = ''';    // error: character constant ends at the second '
```

So:

```text
\" → prints "
\' → prints '
```

---

# 14. Other Common Escape Sequences

| Escape Sequence | Meaning                    | Example output |
| --------------- | -------------------------- | -------------- |
| `\n`            | new line                   | moves to next line |
| `\t`            | tab (often 4 spaces wide)  | `Hello    World` |
| `\\`            | one backslash              | `\`            |
| `\"`            | double quote               | `"`            |
| `\'`            | single quote               | `'`            |
| `\r`            | carriage return (cursor back to start of line) | overwrites from beginning |
| `\a`            | alert / bell sound         | terminal beep  |
| `\0`            | null character             | marks end of a string |

Example combining several:

```c
int main() {
    printf("Name:\t\"Arpan\"\nPath:\tC:\\code\n");

    return 0;
}
```

Output:

```text
Name:	"Arpan"
Path:	C:\code
```

### Important Note

`\r` does **not** create a new line. It moves the cursor back to the **start of the current line**, so new output overwrites the old text:

```c
printf("Hello\rWorld\n");
```

Output:

```text
World
```

(`World` overwrites `Hello`.)

The exact behavior of `\a` (bell) and `\r` depends on the terminal.

---

# 15. Variables

A **variable** is a named storage location in memory used to hold a value.

Example:

```c
int number = 20;
```

Here:

```text
int    → data type
number → variable name
20     → stored value
```

We can change the value later:

```c
int number = 20;

number = 50;
```

Now `number` contains:

```text
50
```

A variable allows us to store and work with data while the program is running.

---

# 16. Basic Data Types

A data type tells C what kind of data a variable will store.

Some basic data types are:

| No. | Data Type         | Keyword     | Example          | Typical Size             |
| --- | ----------------- | ----------- | ---------------- | ------------------------ |
| 1   | Integer           | `int`       | `20`             | 4 bytes                  |
| 2   | Long Long Integer | `long long` | `100000000000`   | 8 bytes                  |
| 3   | Floating Point    | `float`     | `2.5`            | 4 bytes                  |
| 4   | Double Precision  | `double`    | `3.1545215242`   | 8 bytes                  |
| 5   | Character         | `char`      | `'A'`            | 1 byte                   |
| 6   | Boolean           | `bool`      | `true` / `false` | implementation-dependent |

### Important

These are **typical sizes**, not universal guarantees for every C implementation.

We can check the actual size on our computer using:

```c
sizeof()
```

---

# 17. Integer — `int`

Example:

```c
int number = 20;
```

`int` is used to store whole numbers.

Examples:

```text
-100
0
20
500
1000000
```

A typical signed 32-bit `int` uses:

```text
32 bits
=
4 bytes
```

Its range is usually:

```text
-2,147,483,648
to
 2,147,483,647
```

So we should not think of `int` simply as:

```text
1 → 1,000,000,000
```

It can store both positive and negative values.

---

# 18. Long Long Integer — `long long`

Example:

```c
long long bigNumber = 10000000000000LL;
```

`long long` is used when we need to store a much larger integer than a typical `int`.

A typical `long long` uses:

```text
64 bits
=
8 bytes
```

A signed 64-bit `long long` can usually store values approximately from:

```text
-9.22 × 10^18
to
+9.22 × 10^18
```

For example:

```c
long long population = 1000000000000000000LL;
```

The `LL` suffix tells the compiler that the integer literal is intended to be a `long long`.

---

# 19. Float — `float`

Example:

```c
float number = 4.16f;
```

`float` is used to store floating-point or decimal values.

Examples:

```text
2.5
10.5
3.14
4.16
```

Typical size:

```text
4 bytes
=
32 bits
```

The `f` at the end:

```c
4.16f
```

indicates that the literal is a `float`.

Without `f`:

```c
4.16
```

the literal is normally treated as a `double`.

---

# 20. Double — `double`

Example:

```c
double bigFloatNumber = 4.165215215;
```

`double` is also used for decimal numbers, but it generally provides **more precision** than `float`.

Typical size:

```text
8 bytes
=
64 bits
```

Example:

```c
double pi = 3.141592653589793;
```

A `double` is useful when more floating-point precision is required.

---

# 21. Character — `char`

Example:

```c
char letter = 'A';
```

`char` is used to store a single character.

Examples:

```text
'A'
'z'
'5'
'#'
```

A character is written using **single quotes**:

```c
'A'
```

not:

```c
"A"
```

because:

```text
'A' → one character
"A" → a string containing one character
```

Typical size:

```text
1 byte
=
8 bits
```

---

# 22. String in C

C does not provide a built-in `string` data type like languages such as JavaScript, Java, or C++'s `std::string`.

Instead, a string is represented by an **array of characters**.

Example:

```c
char name[] = "Arpan";
```

This stores the characters of `"Arpan"` in memory, along with a special null character `'\0'` at the end.

Conceptually:

```text
A
r
p
a
n
\0
```

For now, the important thing to remember is:

```c
char letter = 'A';
```

means one character.

While:

```c
char name[] = "Arpan";
```

means a string.

---

# 23. Boolean — `bool`

Boolean data represents two logical states:

```text
true
false
```

In C, we can use the `bool` type by including:

```c
#include <stdbool.h>
```

Example:

```c
#include <stdio.h>
#include <stdbool.h>

int main() {
    bool isMarried = false;

    return 0;
}
```

Another example:

```c
bool isActive = true;
```

This is useful for conditions and decision-making.

For example:

```c
bool isLoggedIn = true;
```

We can later use this in conditions:

```c
if (isLoggedIn) {
    printf("Welcome");
}
```

---

# 24. Bits and Bytes

Computers represent data using binary.

Binary has only two possible values:

```text
0
1
```

Each `0` or `1` is called a **bit**.

For example:

```text
01011011
```

contains:

```text
8 bits
```

And:

```text
8 bits = 1 byte
```

Therefore:

```text
1 byte = 8 bits
```

---

# 25. Memory Units

Common binary-based memory units are:

```text
8 bits       = 1 byte
1024 bytes   = 1 KB
1024 KB      = 1 MB
1024 MB      = 1 GB
1024 GB      = 1 TB
```

So:

```text
bit
 ↓
byte
 ↓
KB
 ↓
MB
 ↓
GB
 ↓
TB
```

### Important idea

More bits generally mean that a data type can represent more possible values.

For `n` bits:

```text
Number of possible bit patterns = 2^n
```

For example:

```text
8 bits  → 2^8
32 bits → 2^32
64 bits → 2^64
```

For signed integer types, part of the available range is used for negative numbers.

---

# 26. Format Specifiers

A **format specifier** tells functions such as `printf()` and `scanf()` what kind of data we are working with.

Common format specifiers:

| Data Type         | `printf()` | `scanf()`                  |
| ----------------- | ---------- | -------------------------- |
| `int`             | `%d`       | `%d`                       |
| `long long`       | `%lld`     | `%lld`                     |
| `float`           | `%f`       | `%f`                       |
| `double`          | `%f`       | `%lf`                      |
| `char`            | `%c`       | `%c`                       |
| String (`char[]`) | `%s`       | `%s`                       |
| `bool`            | `%d`       | usually read as an integer |

### Very important difference

For `printf()`:

```text
float  → %f
double → %f
```

For `scanf()`:

```text
float  → %f
double → %lf
```

This difference is very important to remember.

---

# 27. Printing a Float with Decimal Precision

Suppose we have:

```c
float number = 3.56f;
```

If we write:

```c
printf("%f\n", number);
```

we normally get:

```text
3.560000
```

Why?

Because `%f` prints **6 digits after the decimal point by default**.

---

## Controlling the Number of Decimal Places

If we want only two digits after the decimal point:

```c
printf("%.2f\n", number);
```

Output:

```text
3.56
```

If we want three:

```c
printf("%.3f\n", number);
```

Output:

```text
3.560
```

So:

```text
%.2f → 2 digits after decimal
%.3f → 3 digits after decimal
%.4f → 4 digits after decimal
```

General pattern:

```text
%.Nf
```

where `N` is the number of digits we want after the decimal point.

---

# 28. Taking Input with `scanf()`

To take input from the user, we commonly use:

```c
scanf()
```

`scanf()` is declared in:

```c
#include <stdio.h>
```

Basic syntax:

```c
scanf("%format_specifier", &variable);
```

Example:

```c
int number;

scanf("%d", &number);
```

Here:

```text
%d       → tells scanf to read an integer
&number  → tells scanf where to store the value
```

---

# 29. What does `&` mean in `scanf()`?

This is a very important concept.

Suppose:

```c
int number;
```

and:

```c
scanf("%d", &number);
```

The `&` operator gives the **memory address** of `number`.

`scanf()` needs the variable's address because it has to **write the user's input into that variable**.

Think about it like this:

```text
User enters:
    25
     ↓
  scanf()
     ↓
gets the address of number
     ↓
stores 25 at that memory location
     ↓
number = 25
```

So:

```c
scanf("%d", &number);
```

means approximately:

> Read an integer from the user and store it in the memory location belonging to `number`.

### Simple difference

```c
number
```

means:

> The value stored in `number`

while:

```c
&number
```

means:

> The memory address of `number`

This concept will become much more important later when learning **pointers**.

---

# 30. Taking Multiple Inputs

We can take multiple values using one `scanf()` call.

Example:

```c
#include <stdio.h>

int main() {
    int a;
    float b;
    char c;

    printf("Enter an integer, float and character: ");

    scanf("%d %f %c", &a, &b, &c);

    printf("You entered: %d %f %c\n", a, b, c);

    return 0;
}
```

Here:

```text
%d → integer
%f → float
%c → character
```

And:

```c
&a
&b
&c
```

are the memory addresses where `scanf()` will store the input values.

The format specifiers and variables correspond in order:

```text
%d  → &a
%f  → &b
%c  → &c
```

---

# 31. Memory Consumption and Integer Limits

A typical `int` uses:

```text
4 bytes
```

Since:

```text
1 byte = 8 bits
```

therefore:

```text
4 bytes = 32 bits
```

A typical `long long` uses:

```text
8 bytes
=
64 bits
```

Because `long long` has more bits available, it can represent much larger integer values than `int`.

For example:

```c
int a = 1000000000;
```

is normally safe for a signed 32-bit `int`.

But:

```c
long long b = 1000000000000000000LL;
```

requires a much larger integer type.

---

## Integer Overflow

Suppose a typical signed 32-bit `int` has this maximum value:

```text
2,147,483,647
```

Now imagine:

```c
int x = 2147483647;
x = x + 1;
```

The resulting mathematical value is too large to be represented by a signed 32-bit `int`.

This is called:

> **Integer overflow**

For signed integer overflow in C, the behavior is **undefined**.

So it is better not to say:

> "It will definitely return garbage."

Instead:

> If a signed integer calculation goes outside the type's representable range, the behavior is undefined.

That is why understanding the range of a data type is important, especially in competitive programming.

---

# Quick Revision

## Basic C Program

```c
#include <stdio.h>

int main() {
    printf("Hello World");

    return 0;
}
```

## Header

```c
#include <stdio.h>
```

## Main Function

```c
int main()
```

Program execution starts from `main()`.

## Output

```c
printf("Hello World");
```

## New Line

```c
\n
```

## Tab

```c
\t
```

## More Escape Sequences

```text
\\ → one backslash \
\" → double quote "
\' → single quote '
\r → carriage return (back to start of line)
\a → alert / bell
\0 → null character
```

## Integer

```c
int number = 20;
```

## Long Long

```c
long long number = 1000000000000000000LL;
```

## Float

```c
float number = 3.56f;
```

## Double

```c
double number = 3.141592653589793;
```

## Character

```c
char letter = 'A';
```

## String

```c
char name[] = "Arpan";
```

## Boolean

```c
#include <stdbool.h>

bool isActive = true;
```

## Input

```c
scanf("%d", &number);
```

## Format Specifiers

```text
int         → %d
long long   → %lld
float       → %f
double      → %f   (printf)
char        → %c
string      → %s
bool        → %d   (printf)
```

## Memory

```text
8 bits = 1 byte
1024 bytes = 1 KB
1024 KB = 1 MB
1024 MB = 1 GB
1024 GB = 1 TB
```

---

# Important Corrections from My Original Notes

### 1. `main()` does not return nothing

Wrong:

```text
main is a function that doesn't return anything
```

Correct:

```text
int main()
```

returns an `int`.

---

### 2. `stdio.h` does not simply contain the complete `printf()` implementation

Better understanding:

```text
stdio.h → declaration/information
C standard library → implementation
```

---

### 3. C has no built-in `string` data type

Instead:

```c
char name[] = "Arpan";
```

is a character array representing a string.

---

### 4. `&` does not simply mean "assign a value"

In:

```c
scanf("%d", &number);
```

`&number` means:

> memory address of `number`

That address is given to `scanf()` so it can store the input there.

---

### 5. `int` does not simply mean `1 to 1,000,000,000`

A typical signed 32-bit `int` can represent:

```text
-2,147,483,648
to
 2,147,483,647
```

---

### 6. `long long` does not have "8 KB" of memory

It is typically:

```text
8 bytes
=
64 bits
```

not:

```text
8 KB
```

---

# What Should I Learn Next from Today's Topics?

These are the most useful next concepts to understand because they directly build on today's lesson:

```text
Variables
   ↓
Memory
   ↓
Addresses
   ↓
Pointers
```

Then:

```text
Data Types
   ↓
Type Conversion / Type Casting
   ↓
Operators
   ↓
Expressions
```

And from functions:

```text
Function
   ↓
Parameters
   ↓
Arguments
   ↓
Return Value
   ↓
Function Scope
```

For problem solving later, today's concepts should become completely comfortable before moving much further. In particular, make sure you understand **variables, memory addresses, `scanf()`, format specifiers, integer ranges, and basic data types** rather than only memorizing the syntax.
