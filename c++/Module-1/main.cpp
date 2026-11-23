/*
  Module 1 — Introduction to C++ (first C++ session)

  Every demo from the class is written as:
    1. a block comment  -> what it shows (statement, example, expected output)
    2. a block comment  -> the demo program, kept commented out

  All demos are kept commented out.
  To run one, remove the block-comment markers around its code
  and wrap the others the same way, then compile:

      g++ -Wall -Wextra -o main main.cpp
      ./main < input.txt

  Demos:
    1.  Hello World            — first C++ program with cout
    2.  Print variables        — chaining <<, "\n" vs endl
    3.  Read input with cin    — the extraction operator >>
    4.  using namespace std    — dropping the std:: prefix
    5.  Type casting and ASCII — char <-> int
    6.  fixed / setprecision   — printing a double with 2 decimals
    7.  if / else              — EVEN or ODD
    8.  Ternary operator       — the same check in one line
    9.  switch case            — day number -> weekday name
    10. min, max, swap         — three helpers from <algorithm>
    11. getline + ignore       — reading a whole line with spaces
    12. EOF loop               — while (cin >> x)

  input.txt / output.txt record Demo 1 (Hello World — no input needed).
*/


/*
=====================================================================
  Demo 1 : Hello World
=====================================================================

  Statement
    The smallest C++ program: include <iostream>, print one line
    with cout, return 0.

  Input
    none

  Expected output
    Hello World

  Note
    <iostream> is the C++ input/output library — the replacement
    for C's <stdio.h>. std::cout belongs to the standard
    namespace (std), so before "using namespace std" it must be
    written std::cout.
=====================================================================
*/

/*
#include <iostream>

int main()
{
    std::cout << "Hello World" << std::endl;
    return 0;
}
*/


/*
=====================================================================
  Demo 2 : Print variables
=====================================================================

  Statement
    Keep three different types in variables and print them on one
    line by chaining <<. Two ways to end the line:

        "\\n"  — only the newline character (cheap)
        endl   — newline + flush the output buffer (costs extra)

  Input
    none

  Expected output
    10 A 14.16
    10 A 14.16

  Note
    << reads LEFT to RIGHT: cout << x << " " << c << " " << d
    prints the three values with spaces between them. One cout,
    one line.
=====================================================================
*/

/*
#include <iostream>

int main()
{
    int x = 10;
    char c = 'A';
    double d = 14.16;

    std::cout << x << " " << c << " " << d << "\n";
    std::cout << x << " " << c << " " << d << std::endl;
    return 0;
}
*/


/*
=====================================================================
  Demo 3 : Read input with cin
=====================================================================

  Statement
    Read one integer from the keyboard and print it back.

  Input (example)
    42

  Expected output
    42

  Note — the two operators point in opposite directions

        cin  >> variable    data flows INTO the variable
        cout << value       data flows OUT of cout

    >> looks like an arrow pointing at the variable, << like an
    arrow pointing away from it.
=====================================================================
*/

/*
#include <iostream>
using namespace std;

int main()
{
    int m;
    cin >> m;
    cout << m;
    return 0;
}
*/


/*
=====================================================================
  Demo 4 : using namespace std
=====================================================================

  Statement
    After #include <iostream>, add:

        using namespace std;

    and every standard name (cin, cout, endl, ...) can be used
    WITHOUT the std:: prefix.

  Input (example)
    7

  Expected output
    7

  Note
    "namespace std" is the folder where the C++ standard library
    lives. using namespace std; opens that folder into the
    current file, so std::cout becomes just cout.

    It is convenient in small programs. In big projects std::
    is often written out on purpose — otherwise two libraries
    could both define a name like "string" and clash.
=====================================================================
*/

/*
#include <iostream>
using namespace std;

int main()
{
    int m;
    cin >> m;
    cout << m << endl;
    return 0;
}
*/


/*
=====================================================================
  Demo 5 : Type casting and ASCII
=====================================================================

  Statement
    A char IS a small integer — every character has an ASCII
    number. Assigning between char and int converts silently, so
    the number behind a letter shows itself.

  Input
    none

  Expected output
    65
    A

  Note
        char a = 'A';
        int  b = a;          // b becomes 65 — ASCII of 'A'

        int  y = 65;
        cout << (char) y;    // 65 printed as a character -> A

    (char) is an explicit cast: it FORCES the int back into a
    character. Useful ASCII values: 'A' = 65, 'a' = 97,
    '0' = 48.
=====================================================================
*/

/*
#include <iostream>
using namespace std;

int main()
{
    char a = 'A';
    int b = a;
    cout << b << endl;

    int y = 65;
    cout << (char) y << endl;
    return 0;
}
*/


/*
=====================================================================
  Demo 6 : fixed and setprecision
=====================================================================

  Statement
    Print a double with exactly 2 digits after the point.

  Input
    none (the number is inside the program)

  Expected output
    23.46

  Note
    These manipulators need #include <iomanip>.

        fixed            count the digits AFTER the point
        setprecision(2)  how many of them

    Together they do what printf("%.2f") does in C — but written
    as a chain that flows into cout.
=====================================================================
*/

/*
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    double d = 23.45657;
    cout << fixed << setprecision(2) << d << endl;
    return 0;
}
*/


/*
=====================================================================
  Demo 7 : if / else
=====================================================================

  Statement
    Print EVEN or ODD depending on x % 2.

  Input
    none (x = 6 inside the program)

  Expected output
    EVEN

  Note
    The condition (x % 2 == 0) is checked once. Exactly ONE of
    the two branches runs — the other is skipped completely.
=====================================================================
*/

/*
#include <iostream>
using namespace std;

int main()
{
    int x = 6;
    if (x % 2 == 0)
    {
        cout << "EVEN\n";
    }
    else
    {
        cout << "ODD\n";
    }
    return 0;
}
*/


/*
=====================================================================
  Demo 8 : Ternary operator
=====================================================================

  Statement
    The same EVEN/ODD check as Demo 7, in ONE line:

        condition ? value_if_true : value_if_false

  Input
    none (x = 6 inside the program)

  Expected output
    EVEN

  Note
    Here BOTH sides are cout statements. The condition is
    evaluated first, and only the chosen side runs — the other
    side is not executed.
=====================================================================
*/

/*
#include <iostream>
using namespace std;

int main()
{
    int x = 6;
    x % 2 == 0 ? cout << "EVEN\n" : cout << "ODD\n";
    return 0;
}
*/


/*
=====================================================================
  Demo 9 : switch case
=====================================================================

  Statement
    Read a day number 1..7 and print the weekday name. Any other
    number prints "Wrong Input".

  Input (example)
    3

  Expected output
    Monday

  Note — three rules of switch
    1. every case ends with break — without it execution FALLS
       THROUGH into the next case and keeps running
    2. default plays the role of else: it runs when nothing
       matched
    3. case labels are constant integers (no ranges like 1..7
       here — that is what if/else is for)

    Try input 9 -> "Wrong Input".
=====================================================================
*/

/*
#include <iostream>
using namespace std;

int main()
{
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
        case 4:
            cout << "Tuesday\n";
            break;
        case 5:
            cout << "Wednesday\n";
            break;
        case 6:
            cout << "Thursday\n";
            break;
        case 7:
            cout << "Friday\n";
            break;
        default:
            cout << "Wrong Input\n";
    }
    return 0;
}
*/


/*
=====================================================================
  Demo 10 : min, max and swap
=====================================================================

  Statement
    Three helpers from <algorithm>:

        min(a, b) / max(a, b)   smaller / bigger of two values
        min({..}) / max({..})   an initializer list of many values
        swap(a, b)              exchanges the two variables

  Input (example)
    10 20

  Expected output
    10
    10
    20
    60
    20 10

  Note
    After swap(a, b) the VARIABLES hold each other's old values:
    a is 20 and b is 10 now. The braces form {10,20,30,40,50,60}
    — one list, so min/max can look at all six numbers at once.
=====================================================================
*/

/*
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;

    cout << min(a, b) << endl;
    cout << min({10, 20, 30, 40, 50, 60}) << endl;
    cout << max(a, b) << endl;
    cout << max({10, 20, 30, 40, 50, 60}) << endl;

    swap(a, b);
    cout << a << " " << b << endl;
    return 0;
}
*/


/*
=====================================================================
  Demo 11 : getline and ignore
=====================================================================

  Statement
    Read an integer, then a whole line that may contain SPACES
    (scanf/ cin >> would stop at the first space), and print both.

  Input (example)
    25
    Data Structure Lab

  Expected output
    25 Data Structure Lab

  Note — why cin.ignore() sits BETWEEN the two reads
    cin >> age stops at the newline and LEAVES it in the input
    buffer. getline would then read that leftover newline as an
    empty line. cin.ignore() throws exactly that one character
    away:

        cin >> age;          // "25\\n"  -> age = 25, '\\n' stays
        cin.ignore();        // the leftover '\\n' is removed
        cin.getline(line, 100);  // now reads the real next line

    Order matters: ignore AFTER cin >> and BEFORE getline().
=====================================================================
*/

/*
#include <iostream>
using namespace std;

int main()
{
    int age;
    cin >> age;
    cin.ignore();

    char line[1000];
    cin.getline(line, 100);
    cout << age << " " << line << endl;
    return 0;
}
*/


/*
=====================================================================
  Demo 12 : EOF loop — while (cin >> x)
=====================================================================

  Statement
    Keep reading integers until the input ends (Ctrl+D on Linux,
    Ctrl+Z then Enter on Windows) and print each one.

  Input (example)
    1 2 3

  Expected output
    1
    2
    3

  Note
    cin >> x returns the stream itself. The stream converts to
    false when reading fails — that happens exactly at end of
    input (EOF). Same idea as C's:

        while (scanf("%d", &x) == 1)
=====================================================================
*/

/*
#include <iostream>
using namespace std;

int main()
{
    int x;
    while (cin >> x)
    {
        cout << x << endl;
    }
    return 0;
}
*/
