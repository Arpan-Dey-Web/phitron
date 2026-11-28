# Module 2 — Dynamic Memory Allocation

Today I learned how C++ manages memory at **run time** — creating variables and arrays whose
size is not known at compile time, and freeing them again.

Main topics:

* Stack memory vs heap memory
* `new` and `delete`
* Dynamic variables
* Dynamic arrays (`new[]` / `delete[]`)
* Returning heap memory from a function
* Growing a dynamic array

The 5 demos from class live in `main.cpp`; the 5 practice problems live in `extrapractice.cpp`.
This note is the theory to revise.

Files:

| File | Purpose |
| ---- | ------- |
| `main.cpp` | 5 demos from the session (kept as block comments) |
| `extrapractice.cpp` | 5 practice problems (kept as block comments) |
| `quiz.md` | (empty — no quiz yet) |
| `input.txt` | Last input I tested with (extrapractice problem K) |
| `output.txt` | Output produced for that input |

---

# 1. Stack Memory vs Heap Memory

```text
stack memory              heap memory
     ^                        ^
     |                        |
static memory           dynamic memory
     ^                        ^
     |                        |
compile-time memory     run-time memory
```

| | Stack | Heap |
| - | ----- | ---- |
| Created | automatically with the scope | manually, with `new` |
| Removed | automatically when scope ends | only when YOU write `delete` |
| Speed | fast | slower, managed by the allocator |
| Size | small, fixed by the system | large, grows as needed |

**Stack:** "after execution completes, stack memory automatically deletes the variable and the
function" — the frame dies together with the function.

**Heap:** nothing is removed until the user gives the instruction. That is a gift and a
responsibility: forget `delete` and the block stays forever (a *memory leak*).

---

# 2. Dynamic Variable

```cpp
int x = 10;          // stack — dies with its scope
int *p = new int;    // heap  — lives until delete
*p = 10;
cout << *p << endl;

delete p;            // give the block back
```

```text
new type        allocate ONE variable of that type on the heap
delete ptr      free it again
```

Because the variable was created with `new`, it is **inside heap memory** — its lifetime is no
longer tied to the surrounding block.

---

# 3. Proof That the Heap Survives the Function

```cpp
int *p;                      // global pointer

void fun()
{
    int *x = new int;
    *x = 10;
    p = x;                   // hand the heap address to the global
    cout << "Fun ->" << *p << endl;
    return;
}

int main()
{
    fun();
    cout << "Main ->" << *p << endl;   // still 10!
    return 0;
}
```

Output:

```text
Fun ->10
Main ->10
```

The local pointer `x` dies when `fun()` ends — but the **heap block** it pointed to does not.
Only `delete` removes it. (If nothing ever deletes it, it leaks.)

---

# 4. Dynamic Array

```cpp
int *a = new int[5];

for (int i = 0; i < 5; i++)
{
    cin >> a[i];
}
for (int i = 0; i < 5; i++)
{
    cout << a[i] << endl;
}

delete[] a;
```

```text
new int[n]      an array of n elements on the heap — n can be a VARIABLE
delete[] ptr    free it — the [] is required for arrays
```

**Important Note:** plain `delete` on an array is undefined behaviour, and `delete[]` on a single
variable is wrong too. Match them: scalar → `delete`, array → `delete[]`.

---

# 5. Returning a Dynamic Array From a Function

```cpp
int *fun()
{
    int *a = new int[5];
    for (int i = 0; i < 5; i++)
    {
        cin >> a[i];
    }
    return a;                 // heap address, still valid after return
}

int main()
{
    int *x = fun();
    for (int i = 0; i < 5; i++)
    {
        cout << x[i] << endl;
    }
    delete[] x;
}
```

**Why this works but a local array does not:**

```text
local array   lives on fun()'s stack frame -> frame destroyed at return
              -> reading it afterwards is undefined behaviour
              (usually a crash or garbage: "segmentation error")

heap array    has no frame -> stays until delete[] -> safe to use in main()
```

This is the whole reason `new` exists.

---

# 6. Growing a Dynamic Array

```cpp
int *a = new int[3];
// ... read 3 values into a ...

int *b = new int[5];
for (int i = 0; i < 3; i++)
{
    b[i] = a[i];              // copy the old elements
}
b[3] = 40;                    // add the new ones by hand
b[4] = 50;

delete[] a;                   // old block is no longer needed
```

`new[]` gives a **fixed** size — there is no real "resize" operation. The pattern is always the
same: allocate bigger, copy, extend, free the old block. (Later, `std::vector` does exactly this
for you.)

---

# Quick Revision

```text
stack vs heap    scope dies automatically  vs  lives until delete
variable         int *p = new int;   *p = value;   delete p;
array            int *a = new int[n]; ...          delete[] a;
returning        local array -> gone (UB)
                 heap array  -> still valid after return
growing          new bigger -> copy old -> add new -> delete[] old
leak             heap block nobody deletes stays forever
```

---

# Important Corrections from My Original Notes

### 1. `delete vaiable_name` → `delete variable_name`

Spelling, and the real rule: `delete` for one variable, `delete[]` for an array — never mix them.

### 2. "it will return segmentation error"

A local array returned from a function does not *guarantee* a crash — reading it afterwards is
**undefined behaviour**: it may crash, print garbage, or appear to work. The correct statement
is: the stack frame is gone, so the memory must not be touched.

### 3. "heap memory dont delete the value" → "is not deleted automatically"

The heap is not magic — the value simply has no owner that frees it. Only an explicit `delete`
does that.

---

# What to Learn Next

Directly connected to this session:

- **`std::vector`** — the RAII wrapper that grows and frees dynamic arrays for you
- **Memory leaks and `delete` discipline** — valgrind and what a leak looks like
- **Objects on the heap** — `new Student(...)` (that is Module 3)
