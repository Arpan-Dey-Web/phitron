/*
  Module 2 — Dynamic Memory Allocation (C++)

  Every demo from the class is written as:
    1. a block comment  -> what it shows (statement, example, expected output, note)
    2. a block comment  -> the demo program, kept commented out

  All demos are kept commented out.
  To run one, remove the block-comment markers around its code
  and wrap the others the same way, then compile:

      g++ -Wall -Wextra -o main main.cpp
      ./main < input.txt

  Demos:
    1. Dynamic variable        — new int, dereference, delete
    2. Proof the heap survives — global pointer keeps a value
                                 after fun() returns
    3. Dynamic array           — new int[5], read, print
    4. Array from a function   — returning new[] memory works,
                                 returning a local array does not
    5. Growing an array        — copy 3 elements into new[5],
                                 delete[] the old block

  input.txt / output.txt record extrapractice problem K
  (Max and Min), like Module 19 does.
*/


/*
=====================================================================
  Demo 1 : Dynamic variable
=====================================================================

  Statement
    Create an integer ON THE HEAP with new, fill it through the
    pointer, print it, then free it with delete.

  Input
    none

  Expected output
    10

  Note — stack vs heap
    int x = 10;         stack  — created and destroyed with the
                                surrounding scope, automatically
    int *p = new int;   heap   — lives until YOU delete it

    *p = 10;   writes through the pointer into the heap block
    delete p;  gives the block back (only ONE variable ->
               plain delete)
=====================================================================
*/

/*
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int *p = new int;
    *p = 10;
    cout << *p << endl;

    delete p;
    return 0;
}
*/


/*
=====================================================================
  Demo 2 : Proof that the heap survives the function
=====================================================================

  Statement
    fun() creates a heap integer, stores its address in a GLOBAL
    pointer and prints it. After fun() returns, main() reads the
    same pointer again — the value is still there.

  Input
    none

  Expected output
    Fun ->10
    Main ->10

  Note
    The local pointer x dies when fun() ends, but the HEAP block
    it pointed to does not — heap memory is only removed by
    delete. That is the whole difference from a local variable
    (and exactly why a leaked block is a memory leak: if nobody
    ever deletes it, it stays forever).
=====================================================================
*/

/*
#include <bits/stdc++.h>
using namespace std;

int *p;

void fun()
{
    int *x = new int;
    *x = 10;
    p = x;
    cout << "Fun ->" << *p << endl;
    return;
}

int main()
{
    fun();
    cout << "Main ->" << *p << endl;
    return 0;
}
*/


/*
=====================================================================
  Demo 3 : Dynamic array
=====================================================================

  Statement
    Create an array of 5 integers on the HEAP with new[], read
    the values, print them.

  Input (example)
    10
    20
    30
    40
    50

  Expected output
    10
    20
    30
    40
    50

  Note
        new int[5]     one heap block for 5 ints
        delete[] p     give it back — the [] is REQUIRED for
                       arrays (plain delete on an array is
                       undefined behaviour)

    The size can be a VARIABLE: new int[n] is decided at RUN
    time — a normal int a[n] in C++ is also allowed but its
    lifetime is still tied to the scope.
=====================================================================
*/

/*
#include <bits/stdc++.h>
using namespace std;

int main()
{
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
    return 0;
}
*/


/*
=====================================================================
  Demo 4 : Dynamic array returned from a function
=====================================================================

  Statement
    fun() builds a 5-element array ON THE HEAP inside the
    function and returns its address. main() keeps using it
    after fun() has finished.

  Input (example)
    1 2 3 4 5   (five separate lines)

  Expected output
    1
    2
    3
    4
    5

  Note — why this works and a local array would not
    A LOCAL array lives on the function's stack frame, which is
    destroyed the moment the function returns — reading it
    afterwards is undefined behaviour (usually a crash or
    garbage values).

    A heap array has no frame. It stays until delete[], so the
    returned pointer is still valid in main().
=====================================================================
*/

/*
#include <bits/stdc++.h>
using namespace std;

int *fun()
{
    int *a = new int[5];
    for (int i = 0; i < 5; i++)
    {
        cin >> a[i];
    }
    return a;
}

int main()
{
    int *x = fun();
    for (int i = 0; i < 5; i++)
    {
        cout << x[i] << endl;
    }

    delete[] x;
    return 0;
}
*/


/*
=====================================================================
  Demo 5 : Growing a dynamic array
=====================================================================

  Statement
    new[] gives a FIXED size. To "resize": allocate a BIGGER
    block, copy the old elements over, add the new ones, then
    delete[] the old block.

  Input (example)
    1
    2
    3

  Expected output
    1 2 3 40 50

  Note
    b[3] and b[4] are set by hand — there is no real "resize"
    operation. std::vector (later) does exactly this for you.

        delete[] a;   the 3-element block is freed here; b is
                      the only block left
=====================================================================
*/

/*
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int *a = new int[3];
    for (int i = 0; i < 3; i++)
    {
        cin >> a[i];
    }

    int *b = new int[5];
    for (int i = 0; i < 3; i++)
    {
        b[i] = a[i];
    }
    b[3] = 40;
    b[4] = 50;

    delete[] a;

    for (int i = 0; i < 5; i++)
    {
        cout << b[i] << " ";
    }
    cout << endl;

    delete[] b;
    return 0;
}
*/
