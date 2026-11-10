/*
  Module 17 — Recursion (C)

  Each concept below is written as:
    1. a block comment  -> the idea (Statement, Example, Note)
    2. a block comment  -> my code, kept commented out

  All code is kept commented out.
  To run one, remove the block-comment markers around its code
  and wrap the others the same way.

  Concepts:
    1. call stack (function calling function)
    2. infinite recursion -> stack overflow  (DO NOT RUN)
    3. print 1 to 5            (base case, print before call)
    4. print N to 1            (base case, print before call)
    5. print N to 1 the tricky way (print AFTER call)
    6. print an array with recursion (index parameter)
*/


/*
=====================================================================
  Concept : The Call Stack
=====================================================================

  Statement
    Three functions where hello() calls two other functions, so
    the stack has to remember where to return to each time.

  Output
    Arpan
    Hello	Good Morning!!!
    Good Night!!!

  Note
    LIFO — Last In, First Out. good_Morning() is called last
    inside hello(), so it finishes first and its frame is popped
    first. Every frame stays until its function fully finishes.

    The two prototypes on top are required: good_Morning() and
    good_Night() are used BEFORE their definitions, and modern
    compilers reject (or warn about) that "implicit declaration".
=====================================================================
*/

/*
#include <stdio.h>

void good_Morning();
void good_Night();

void hello()
{
    printf("Hello\t");
    good_Morning();
    good_Night();
}

void good_Morning()
{
    printf("Good Morning!!!\n");
}

void good_Night()
{
    printf("Good Night!!!\n");
}

int main()
{
    printf("Arpan\n");
    hello();
    return 0;
}
*/


/*
=====================================================================
  Concept : Infinite Recursion (stack overflow)
=====================================================================

  Statement
    A function that calls itself with nothing to stop it.

  IMPORTANT — do not run this one
    It compiles perfectly (no syntax error). At runtime it keeps
    pushing frames until the stack is full, then the program
    crashes with a Stack Overflow.

  Note
    Syntax error / compile error  -> found BEFORE running
    missing base case             -> found WHILE running
=====================================================================
*/

/*
#include <stdio.h>

void hello()              // recursive function
{
    printf("Hello\t");
    hello();              // calls itself, forever
}

int main()
{
    hello();
    return 0;
}
*/


/*
=====================================================================
  Concept : Print 1 to 5 (base case, print BEFORE the call)
=====================================================================

  Statement
    Print 1 2 3 4 5 using recursion. Stop at 6.

  Output
    1
    2
    3
    4
    5

  Note
    The base case is `if (i == 6) return;` — without it the
    function would recurse until stack overflow.

    printf runs BEFORE the call, so the numbers print on the way
    DOWN: hello(1) prints 1, then hello(2) prints 2, ...
=====================================================================
*/

/*
#include <stdio.h>

void hello(int i)
{
    if (i == 6)             // base case: stop
    {
        return;
    }

    printf("%d\n", i);      // print first
    hello(i + 1);           // then recurse
}

int main()
{
    int i = 1;
    hello(i);
    return 0;
}
*/


/*
=====================================================================
  Concept : Print N to 1 (base case, print BEFORE the call)
=====================================================================

  Statement
    Read N and print N, N-1, ..., 1 — one per line.

  Example
    Input : 4
    Output:
      4
      3
      2
      1

  Note
    Same shape as "print 1 to 5", only two things changed:
      the print comes FIRST      (so 4 prints before anything else)
      the base case is n == 1    (stop after printing 1)
      the recursion goes DOWN    (n - 1)
=====================================================================
*/

/*
#include <stdio.h>

void hello(int n)
{
    printf("%d\n", n);      // print first
    if (n == 1)             // base case
    {
        return;
    }
    hello(n - 1);
}

int main()
{
    int n;
    scanf("%d", &n);
    hello(n);
    return 0;
}
*/


/*
=====================================================================
  Concept : The Tricky One — Print AFTER the Call
=====================================================================

  Statement
    Start at 1 with the base case at 4, but put printf AFTER the
    recursive call.

  Output (for the start value n = 1)
    3
    2
    1

  Note — why 3 2 1 and not 1 2 3?
    call order  : hello(1) -> hello(2) -> hello(3) -> hello(4)
                                                       returns
    print order : nothing on the way down... then 3, then 2,
                  then 1 while every call UNWINDS

    printf AFTER the call  =>  prints on the way back up.
    Last called is first printed — the same LIFO rule the call
    stack itself follows.

    This one is tricky because the print order is the REVERSE
    of the call order.
=====================================================================
*/

/*
#include <stdio.h>

void hello(int n)
{
    if (n == 4)             // base case
    {
        return;
    }

    hello(n + 1);           // recurse FIRST
    printf("%d\n", n);      // print on the way back
}

int main()
{
    int n = 1;
    hello(n);
    return 0;
}
*/


/*
=====================================================================
  Concept : Print an Array with Recursion
=====================================================================

  Statement
    Read N and N numbers, then print every element — one per
    line — using a recursive function instead of a loop.

  Example
    Input :
      3
      10 20 30
    Output:
      10
      20
      30

  Note
    The index idx is the recursion's state:
      idx == n   -> base case, stop (exactly n elements done)
      print a[idx], then recurse with idx + 1

    MY BUG (fixed): the read loop was
        for (int i = 0; i <= n; i++)
    which reads n+1 values into an array of size n — one write
    past the end (undefined behaviour). The bound must be i < n.

    int a[] in the parameter list is a pointer to main's array
    (Module 15) — the array is not copied.
=====================================================================
*/

/*
#include <stdio.h>

void print_Array(int a[], int n, int idx)
{
    if (idx == n)                // base case
    {
        return;
    }
    printf("%d\n", a[idx]);
    print_Array(a, n, idx + 1);  // next element
}

int main()
{
    int n;
    scanf("%d", &n);

    int a[n];
    for (int i = 0; i < n; i++)  // i < n  (NOT i <= n)
    {
        scanf("%d", &a[i]);
    }

    print_Array(a, n, 0);        // start at index 0
    return 0;
}
*/
