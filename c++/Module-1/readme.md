# Module 1 — Introduction to C++

First **C++** session. The main things I learned today:

* Shape of a C++ program — `#include`, `int main()`, `return 0`
* Printing with `cout` and `<<`
* Taking input with `cin` and `>>`
* `using namespace std;`
* Type casting and ASCII values
* Formatting doubles with `fixed` / `setprecision`
* Conditions — `if / else` and the ternary operator
* `switch` case
* `min`, `max`, `swap` from `<algorithm>`
* Reading a whole line — `getline()` and `cin.ignore()`
* Reading until end of input — the EOF loop

All 12 demos from the class live in `main.cpp`, each kept as a commented-out
program. This note is the theory; `main.cpp` is the code.

Files:

| File | Purpose |
| ---- | ------- |
| `main.cpp` | 12 demos from the session (kept as block comments) |
| `quiz.md` | (empty — no quiz yet) |
| `extrapractice.cpp` | (empty — extra practice placeholder) |
| `input.txt` | empty — Demo 1 needs no input |
| `output.txt` | output of Demo 1 (`Hello World`) |

---

# 1. Basic Structure of a C++ Program

A basic C++ program has two parts, exactly like in C:

```text
Header File
    ↓
Actual Program / Function Body
```

The smallest complete C++ program:

```cpp
#include <iostream>

int main()
{
    std::cout << "Hello World" << std::endl;
    return 0;
}
```

Output:

```text
Hello World
```

```text
#include <iostream>   header — the input/output library
int main()            where the program starts
cout                  prints (C's printf in C++)
return 0              "everything went fine"
```

**Difference from C so far:** the file is `main.cpp` (not `.c`), the header is
`<iostream>` (not `<stdio.h>`), and printing is done with `cout` instead of
`printf()`.

---

# 2. `cout` — Printing

```cpp
std::cout << "Hello World" << std::endl;
```

`cout` means "character output". The `<<` operator sends a value into `cout`,
and it can be **chained** — one after another on the same line:

```cpp
int x = 10;
char c = 'A';
double d = 14.16;
std::cout << x << " " << c << " " << d << "\n";
```

Output:

```text
10 A 14.16
```

## `"\n"` versus `endl`

```cpp
std::cout << x << " " << c << " " << d << "\n";        // newline only
std::cout << x << " " << c << " " << d << std::endl;   // newline + flush
```

Both print a new line. `endl` additionally **flushes** the output buffer, which
is extra work — inside loops prefer `"\n"`.

## `std::` and namespaces

`cout`, `endl` live in the C++ standard library, which is packed into a
*namespace* called `std`. Before `using namespace std;` (section 4) every name
needs the prefix:

```text
std::cout      std::endl      std::cin
```

---

# 3. `cin` — Taking Input

```cpp
int m;
std::cin >> m;
std::cout << m;
```

Type a number, press Enter — it is printed back.

The two operators point in opposite directions:

```text
cin  >> variable     data flows INTO the variable
cout << value        data flows OUT of cout
```

`>>` looks like an arrow pointing at the variable; `<<` like an arrow pointing
away from `cout`.

---

# 4. `using namespace std;`

```cpp
#include <iostream>
using namespace std;

int main()
{
    int m;
    cin >> m;
    cout << m;
    return 0;
}
```

Placed after the headers, it opens the `std` namespace into the whole file —
so `std::cout` becomes just `cout`, `std::cin` becomes `cin`. We only write
the operation name.

**Important Note:** this is convenient in learning programs. In large projects
`std::` is often written on purpose, because two libraries could both define a
name like `string` and clash.

---

# 5. Type Casting and ASCII

A `char` **is** a small integer — every character has an ASCII number.

```cpp
char a = 'A';
int b = a;
cout << b << endl;      // 65
```

Assigning `char` to `int` converts silently: `b` becomes the ASCII value of
`'A'`, which is **65**.

The other direction needs an **explicit cast**:

```cpp
int y = 65;
cout << (char) y << endl;   // A
```

`(char) y` forces the integer back into a character.

Useful ASCII values:

| Value | Character |
| ----- | --------- |
| 48 | `'0'` |
| 65 | `'A'` |
| 97 | `'a'` |

```text
'A' -> 65    'a' -> 97    '0' -> 48    ' ' -> 32
```

---

# 6. Formatting Doubles — `fixed` and `setprecision`

```cpp
#include <iomanip>

double d = 23.45657;
cout << fixed << setprecision(2) << d << endl;
```

Output:

```text
23.46
```

These manipulators need `#include <iomanip>`:

```text
fixed            count the digits AFTER the point
setprecision(2)  how many of them
```

Together they do what `printf("%.2f")` does in C, but written as a chain flowing
into `cout`.

**Important Note:** without `fixed`, `setprecision(2)` means 2 *significant*
digits total (`23`) — `fixed` is what makes it "digits after the point".

---

# 7. Conditions — `if / else`

```cpp
int x = 6;
if (x % 2 == 0)
{
    cout << "EVEN\n";
}
else
{
    cout << "ODD\n";
}
```

Output:

```text
EVEN
```

Exactly one branch runs; the other is skipped completely. Same as C.

## Ternary operator

The same check in one line:

```cpp
int x = 6;
x % 2 == 0 ? cout << "EVEN\n" : cout << "ODD\n";
```

```text
condition ? value_if_true : value_if_false
```

The condition is evaluated first, then only the chosen side runs.

---

# 8. `switch` Case

```cpp
int day;
cin >> day;

switch (day)
{
    case 1:
        cout << "Saturday\n";
        break;
    case 2:
        cout << "Sunday\n";
        break;
    case 3:
        cout << "Monday\n";
        break;
    // ... cases 4 to 7 ...
    default:
        cout << "Wrong Input\n";
}
```

Input `3` → output `Monday`. Input `9` → `Wrong Input`.

Three rules:

1. Every `case` ends with `break` — without it execution **falls through** into
   the next case and keeps running.
2. `default` plays the role of `else`: it runs when nothing matched.
3. `case` labels are constant integers. No ranges like `1..7` here — that is
   what `if / else` is for.

---

# 9. `min`, `max`, `swap` — `<algorithm>`

```cpp
#include <algorithm>
```

```cpp
int a, b;
cin >> a >> b;

cout << min(a, b) << endl;                              // smaller of two
cout << min({10, 20, 30, 40, 50, 60}) << endl;          // smaller of six
cout << max(a, b) << endl;                              // bigger of two
cout << max({10, 20, 30, 40, 50, 60}) << endl;          // bigger of six

swap(a, b);
cout << a << " " << b << endl;
```

Input `10 20`:

```text
10
10
20
60
20 10
```

**Important Note:** after `swap(a, b)` the *variables* hold each other's old
values — `a` is 20 and `b` is 10 now. The braces `{10,20,...}` form one list,
so `min`/`max` can look at all six numbers at once.

---

# 10. Reading a Whole Line — `getline` and `cin.ignore`

`cin >> x` stops at the first space. For a line with spaces I need
`cin.getline()`:

```cpp
int age;
cin >> age;
cin.ignore();

char line[1000];
cin.getline(line, 100);
cout << age << " " << line << endl;
```

Input:

```text
25
Data Structure Lab
```

Output:

```text
25 Data Structure Lab
```

**Why `cin.ignore()` sits BETWEEN the two reads:**

```text
cin >> age       "25\n"  -> age = 25, the '\n' STAYS in the buffer
cin.ignore()     that leftover '\n' is thrown away (1 character)
cin.getline()    now reads the real next line
```

If `ignore()` were missing, `getline()` would read the leftover newline and
return an empty string.

---

# 11. EOF Loop — `while (cin >> x)`

```cpp
int x;
while (cin >> x)
{
    cout << x << endl;
}
```

Keeps reading integers until the input ends — **Ctrl+D** on Linux, **Ctrl+Z**
then Enter on Windows.

`cin >> x` returns the stream itself. The stream converts to `false` when
reading fails, which happens exactly at end of input (EOF). The same idea as
C's:

```c
while (scanf("%d", &x) == 1)
```

---

# Quick Revision

```text
program         #include <iostream> + int main() + return 0
print           cout << ... << "\n"      (endl also flushes)
read            cin >> var               (>> into, << out of)
namespace       using namespace std;     drops the std:: prefix
char <-> int    'A' is 65 — assignment converts, (char) forces
2 decimals      #include <iomanip> + fixed << setprecision(2)
conditions      if / else, or  condition ? a : b
switch          case + break + default — else it falls through
helpers         min / max / swap from <algorithm>
whole line      cin >> x;  cin.ignore();  cin.getline(s, n)
EOF loop        while (cin >> x) { ... }   until Ctrl+D / Ctrl+Z
```

---

# Important Corrections from My Original Notes

### 1. `std :: cout` is written `std::cout`

No spaces around `::` — it is one token: namespace `std`, scope `::`, name
`cout`.

### 2. `# include<iostream>` is `#include <iostream>`

One word, a space, then the header in angle brackets.

### 3. The first print example was incomplete

My note had `std :: cout << "Hello World"` with no `;`, no `main()` and no
return. Section 1 now shows the complete, working program.

### 4. `cin.ignore()` was in the wrong place

My raw note ran `getline()` first and `ignore()` after, with the comment
"enter e ignore korbe". The correct order is:

```text
cin >> x      then      cin.ignore()      then      cin.getline(...)
```

`ignore()` must delete the newline that `cin >>` left behind, **before**
`getline()` runs — otherwise `getline()` reads that newline as an empty line.

### 5. "ASCHII" → ASCII

**A**merican **S**tandard **C**ode for **I**nformation **I**nterchange — the
number behind every character (`'A'` = 65).

---

# What to Learn Next

Directly connected to this session:

- **`std::string`** — real C++ strings instead of `char` arrays
- **Loops in C++** — `for` / `while` recap, then the range-based `for`
- **Functions in C++** — default arguments, references (`&`) as parameters
