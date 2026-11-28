# Module 3 — Class and Object

Today I learned how C++ lets me build my **own data types** — grouping several values into one
name, creating objects from them, and controlling how objects are created and returned.

Main topics:

* Built-in vs user-defined data types
* Class structure and naming convention
* Access modifiers — `public`, `private`, `protected`
* Objects and the dot operator
* Constructors and the `this` pointer
* Returning an object from a function
* Why dynamic objects exist
* Dynamic objects (`new` / `->` / `delete`)
* `sort()` — ascending and descending

The 7 demos from class live in `main.cpp`. This note is the theory to revise.

Files:

| File | Purpose |
| ---- | ------- |
| `main.cpp` | 7 demos from the session (kept as block comments) |
| `extrapractice.cpp` | (empty — extra practice placeholder) |
| `quiz.md` | (empty — no quiz yet) |
| `input.txt` | empty — Demo 2 (constructor) needs no input |
| `output.txt` | output of Demo 2 |

---

# 1. Two Kinds of Data Type

```text
Built-in data types      int, char, double, bool ...
User-defined data types  class, struct, enum, ...
```

A **class** is a blueprint: it says which members a type has, and from that blueprint I can make
as many objects as I need.

---

# 2. Class Structure

```cpp
// className first letter has to be capital letter
class class_name
{
    // here will be the class data
public:
    char name[100];
    int roll;
    char section;
    double gpa;
};
```

```text
class     keyword
Student   the new type's name (capital first letter — convention)
public:   everything below is reachable from outside
;         the class declaration ends with a semicolon (unlike a function)
```

---

# 3. Access Modifiers

| Modifier | Who can touch the members |
| -------- | ------------------------- |
| `public` | everybody |
| `private` | only the class itself (default inside `class`) |
| `protected` | the class and its subclasses (later, with inheritance) |

In every demo here the members are `public` so `main()` can read and write them directly. As
soon as I learn encapsulation, data becomes `private` and gets read through functions.

---

# 4. Object and the Dot Operator

```cpp
class Student
{
public:
    char name[100];
    int roll;
    double gpa;
};

int main()
{
    Student a, b;
    cin >> a.name >> a.roll >> a.gpa;
    cin >> b.name >> b.roll >> b.gpa;

    cout << a.name << endl << a.roll << endl << a.gpa << "\n";
    cout << b.name << endl << b.roll << endl << b.gpa << "\n";
    return 0;
}
```

Input:

```text
rahim 26 3.16
karim 45 3.25
```

Output:

```text
rahim
26
3.16
karim
45
3.25
```

`a.name` — the **dot operator** reaches into an object. The members behave exactly like plain
variables; only the path to them (`a.` / `b.`) is new.

---

# 5. Constructor and the `this` Pointer

```cpp
class Student
{
public:
    int roll;
    int cls;
    double gpa;

    Student(int r, int c, double g)
    {
        this->roll = r;
        this->cls = c;
        this->gpa = g;
    }
};

int main()
{
    Student rahim(26, 7, 3.16);
    Student karim(45, 5, 3.25);

    cout << rahim.roll << " " << rahim.cls << " " << rahim.gpa << " " << endl;
    cout << karim.roll << " " << karim.cls << " " << karim.gpa << " " << endl;
    return 0;
}
```

Output:

```text
26 7 3.16
45 5 3.25
```

A **constructor** has the class's name, no return type, and runs automatically when the object is
created — `Student rahim(26, 7, 3.16)` fills the three members in one step.

## `this`

Inside the constructor, `this` points at the object being built. Two correct spellings:

```text
this->roll = r;      arrow      — this IS a pointer
(*this).roll = r;    dereference, then dot
```

C++11 even allows the plain form `roll = r;` (the names are unambiguous here).

---

# 6. Returning an Object From a Function (by value)

```cpp
Student func()
{
    Student rahim(26, 7, 3.16);
    return rahim;                 // a COPY is made
}

int main()
{
    Student obj = func();
    cout << obj.roll << " " << obj.cls << " " << obj.gpa << " " << endl;
}
```

Output: `26 7 3.16`

Returning **by value** is always safe: `obj` is a copy living in `main()`'s own frame. `func()`'s
frame (and the original `rahim` inside it) dies — the copy does not.

---

# 7. Why We Need Dynamic Objects

```cpp
Student *func()
{
    Student rahim(26, 7, 3.16);
    Student *p = &rahim;
    return p;                     // address of a LOCAL object
}

int main()
{
    Student *p = func();
    cout << (*p).roll << " " << (*p).cls << " " << (*p).gpa << " " << endl;
}
```

**This is the wrong way — shown as a warning.** `rahim` lives in `func()`'s stack frame; the
frame is destroyed at `return`, so `p` becomes a *dangling pointer*. Reading it is **undefined
behaviour**: in practice the numbers come back as garbage (my run printed
`26 32765 6.78249e-310`), but it may also crash or "happen to work" — never rely on it.

Same rule as returning a local **array** in Module 2: frames die with their function.

Two correct alternatives:

```text
return by VALUE      (section 6 — a copy is made)
build it with new    (section 8 — heap memory, no frame)
```

---

# 8. Dynamic Object

```cpp
Student rahim(45, 5, 3.42);                    // stack object
Student *karim = new Student(30, 6, 3.25);     // heap object

cout << rahim.roll << " " << rahim.cls << " " << rahim.gpa << " " << endl;
cout << karim->roll << " " << karim->cls << " " << karim->gpa << " " << endl;

delete karim;
```

Output:

```text
45 5 3.42
30 6 3.25
```

| Form | Use with |
| ---- | -------- |
| `obj.member` | a direct object |
| `ptr->member` | a pointer to an object — same as `(*ptr).member` |

The heap object lives until `delete karim;` — Module 2's rule applies to objects too: nothing
frees it automatically.

---

# 9. Returning a Dynamic Object From a Function

```cpp
Student *func()
{
    Student *rahim = new Student(26, 7, 3.16);
    return rahim;                 // heap address, valid after return
}

int main()
{
    Student *p = func();
    cout << p->roll << " " << p->cls << " " << p->gpa << " " << endl;
    delete p;
}
```

Output: `26 7 3.16`

This is section 7 done right: the object was created with `new`, so it has no frame to die with.
`delete p` in `main()` when the object is no longer needed.

---

# 10. `sort()` — Ascending and Descending

```cpp
sort(arr, arr + n);                     // ascending
sort(arr, arr + n, greater<int>());     // descending
```

Reading the two arguments:

```text
sort(arr, arr + n)
         |     |
         |     one PAST the last element (the end)
         first element
```

`greater<int>()` is a built-in compare function — "the left value should come first" flips the
order to descending. Needs `#include <algorithm>` (or `<bits/stdc++.h>`).

---

# Quick Revision

```text
class           blueprint for a user-defined type, capital name, ends with ;
public:         members visible from outside (private is the class default)
object          Student a;   a.name  = dot operator
constructor     Student(int r, ...)  runs on creation, no return type
this            this->roll  or  (*this).roll   — NOT *(this).roll
return by value copy is made -> always safe
return &local   dangling pointer -> undefined behaviour (garbage/crash)
dynamic object  new Student(...) / ptr->member / delete ptr
sort            sort(arr, arr+n)  ascending
                sort(arr, arr+n, greater<int>())  descending
```

---

# Important Corrections from My Original Notes

### 1. `*(this).roll = r;` does not compile

Precedence: `.` binds tighter than `*`, so it reads as `*(this.roll)` — "member `roll` of a
pointer", which does not exist. The compiler says *maybe you meant `->`*. Correct:
`this->roll = r;` or `(*this).roll = r;`.

### 2. `*(p).roll` — same mistake, same fix

In the "return object from a function" demo. Use `p->roll` or `(*p).roll`.

### 3. "2 types of data type exist"

Built-in types come with the language; **user-defined** types are the ones I write myself
(`class`, `struct`, `enum`). C++ also has more built-ins than my note listed (`bool`, `long
long`, `unsigned ...`) — Module 1 covered those.

### 4. `Acesss` → `access`, `asending` → `ascending`

Spelling, for searchability later.

---

# What to Learn Next

Directly connected to this session:

- **`private` members + getter/setter functions** — encapsulation, the reason access modifiers exist
- **Destructor** — the constructor's twin, runs when an object dies (and pairs with `delete`)
- **String Class in C++** — Module 05 of the DSA track
