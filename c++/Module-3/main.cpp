/*
  Module 3 — Class and Object (C++)

  Every demo from the class is written as:
    1. a block comment  -> what it shows (statement, example, expected output, note)
    2. a block comment  -> the demo program, kept commented out

  All demos are kept commented out.
  To run one, remove the block-comment markers around its code
  and wrap the others the same way, then compile:

      g++ -Wall -Wextra -o main main.cpp
      ./main < input.txt

  Demos:
    1. Class and object     — members, dot operator, cin/cout
    2. Constructor          — setting members with this->
    3. Object from a func   — returning an object BY VALUE
    4. &local is wrong      — returning a pointer to a dead
                              frame (shown as a warning)
    5. Dynamic object       — new / -> on the heap
    6. Object from a func   — returning a NEW pointer (safe)
    7. sort()               — ascending and descending

  input.txt / output.txt record Demo 2 (constructor — it needs
  no input).
*/


/*
=====================================================================
  Demo 1 : Class and object
=====================================================================

  Statement
    A class is a blueprint for a user-defined data type. Here
    Student groups three values (name, roll, gpa). Two objects
    a and b are made from it, filled from input and printed.

  Input (example)
    rahim 26 3.16
    karim 45 3.25

  Expected output
    rahim
    26
    3.16
    karim
    45
    3.25

  Note
    a.name     dot operator — reach INTO the object
    cin >> a.name >> a.roll >> a.gpa   fills the members one
    by one, exactly like plain variables

    Members under public: are visible from outside the class.
    (private / protected come later.)
=====================================================================
*/

/*
#include <bits/stdc++.h>
using namespace std;

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
*/


/*
=====================================================================
  Demo 2 : Constructor
=====================================================================

  Statement
    A constructor is a function with the class's name and NO
    return type. It runs the moment an object is created, so
    the members can be filled in one step:

        Student rahim(26, 7, 3.16);

  Input
    none

  Expected output
    26 7 3.16
    45 5 3.25

  Note — the this pointer
    Inside the constructor, this points at the object being
    built. Two correct ways to write the assignment:

        this->roll = r;        arrow: this IS a pointer
        (*this).roll = r;      dereference first, then dot

    IMPORTANT CORRECTION — my original note wrote

        *(this).roll = r;      // WRONG, does not compile

    because . binds tighter than *: it reads as *(this.roll)
    and this.roll means "member roll of a pointer", which does
    not exist. Use this-> ... (what the class used) or
    (*this).roll ...

    (C++11 also allows assigning members directly: roll = r;)
=====================================================================
*/

/*
#include <bits/stdc++.h>
using namespace std;

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
*/


/*
=====================================================================
  Demo 3 : Returning an object from a function (by value)
=====================================================================

  Statement
    func() creates a Student locally and RETURNS IT. main()
    receives a copy:

        Student obj = func();

  Input
    none

  Expected output
    26 7 3.16

  Note
    Returning by value is always safe: C++ copies the object,
    so obj lives in main()'s frame and stays valid. The frame
    of func() is destroyed, but only the COPY inside it dies
    with it.
=====================================================================
*/

/*
#include <bits/stdc++.h>
using namespace std;

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

Student func()
{
    Student rahim(26, 7, 3.16);
    return rahim;
}

int main()
{
    Student obj = func();
    cout << obj.roll << " " << obj.cls << " " << obj.gpa << " " << endl;

    return 0;
}
*/


/*
=====================================================================
  Demo 4 : Returning a pointer to a local object — DON'T
=====================================================================

  Statement
    The WRONG way: func() keeps the ADDRESS of its local
    Student and returns it. main() then reads through that
    pointer — but func()'s stack frame is already gone.

  Input
    none

  Output
    UNDEFINED — this program is shown as a warning, not as a
    working example. It may print the old values, print
    garbage, or crash; the result can change between runs and
    compilers.

  Note
    The frame dies with the function (same rule as returning a
    local ARRAY — Module 2). The pointer is now dangling.

    Two ways to do it right:
      return by VALUE        (Demo 3 — copy is made)
      build it with new      (Demo 6 — heap, no frame)

    Also note the correct dereference: (*p).roll or p->roll.
    My original note wrote *(p).roll, which — like *(this).roll
    in Demo 2 — does not compile (precedence).
=====================================================================
*/

/*
#include <bits/stdc++.h>
using namespace std;

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

Student *func()
{
    Student rahim(26, 7, 3.16);
    Student *p = &rahim;
    return p;                  // address of a local -> dangling
}

int main()
{
    Student *p = func();
    cout << (*p).roll << " " << (*p).cls << " " << (*p).gpa << " " << endl;

    return 0;
}
*/


/*
=====================================================================
  Demo 5 : Dynamic object
=====================================================================

  Statement
    Create one object ON THE STACK (rahim) and one ON THE HEAP
    (karim) and read them back — dot for the stack object,
    arrow -> for the pointer to the heap object.

  Input
    none

  Expected output
    45 5 3.42
    30 6 3.25

  Note
        Student rahim(45, 5, 3.42);              // static
        Student *karim = new Student(30, 6, 3.25); // dynamic

    rahim.dot      karim->member      the same member access
                                      through a pointer

    The heap object lives until  delete karim;  — nothing frees
    it automatically (Module 2's rule applies to objects too).
=====================================================================
*/

/*
#include <bits/stdc++.h>
using namespace std;

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
    Student rahim(45, 5, 3.42);                    // stack object
    Student *karim = new Student(30, 6, 3.25);     // heap object

    cout << rahim.roll << " " << rahim.cls << " " << rahim.gpa << " " << endl;
    cout << karim->roll << " " << karim->cls << " " << karim->gpa << " " << endl;

    delete karim;
    return 0;
}
*/


/*
=====================================================================
  Demo 6 : Returning a dynamic object from a function
=====================================================================

  Statement
    func() builds the Student WITH new inside the function and
    returns its address. The object is on the heap, so it has
    no frame to die with — main() can read it safely.

  Input
    none

  Expected output
    26 7 3.16

  Note
    This is Demo 4 done RIGHT: the object created inside func()
    would be destroyed with func()'s frame, but the memory was
    allocated with new instead, so it survives the return.

        p->roll     same as (*p).roll

    Remember:  delete p;  in main() when the object is no
    longer needed.
=====================================================================
*/

/*
#include <bits/stdc++.h>
using namespace std;

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

Student *func()
{
    Student *rahim = new Student(26, 7, 3.16);
    return rahim;
}

int main()
{
    Student *p = func();
    cout << p->roll << " " << p->cls << " " << p->gpa << " " << endl;

    delete p;
    return 0;
}
*/


/*
=====================================================================
  Demo 7 : sort() — ascending and descending
=====================================================================

  Statement
    <algorithm>'s sort() puts an array in order. Two forms:

        sort(arr, arr + n);                 ascending
        sort(arr, arr + n, greater<int>()); descending

  Input (example)
    5
    1 4 2 3 5

  Expected output (ascending form)
    1 2 3 4 5

  Note — reading the two arguments
        sort(arr, arr + n)
             |       |
             |       one PAST the last element (the end)
             first element

    greater<int>() is a built-in compare function: "return true
    when the left value should come FIRST", which flips the
    order to descending.
=====================================================================
*/

/*
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + n);                  // ascending
    // sort(arr, arr + n, greater<int>());  // descending

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
*/
