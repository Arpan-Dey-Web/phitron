/*
  Module 2 — Extra Practice: Problems (C++)

  Extra-practice set from the Dynamic Memory session. Each
  problem below is written as:
    1. a block comment  -> the statement (Statement, Input, Output, Examples, Note)
    2. a block comment  -> my solution, kept commented out

  All solutions are kept commented out.
  To run one, remove the block-comment markers around its code
  and wrap the others the same way.

  Problems:
    M. Capital or Small or Digit — classify one character
    C. Simple Calculator         — sum, product, difference
    F. Reversing                 — print an array backwards
    E. Max                       — maximum of N numbers
    K. Max and Min               — min and max of 3 numbers
*/


/*
=====================================================================
  Problem : M. Capital or Small or Digit
  Limits  : 1 second, 256 MB
=====================================================================

  Statement
    Given one character X, tell whether it is a digit or an
    alphabet — and if it is an alphabet, whether it is capital
    or small case.

  Input
    One line with a single character X (a capital letter, a
    small letter or a digit).

  Output
    If X is a digit      -> one line: IS DIGIT
    If X is a capital    -> line 1: ALPHA,  line 2: IS CAPITAL
    If X is a small      -> line 1: ALPHA,  line 2: IS SMALL

  Examples
    Input : A    Output: ALPHA / IS CAPITAL
    Input : 9    Output: IS DIGIT
    Input : a    Output: ALPHA / IS SMALL

  Note — ASCII ranges
        '0'..'9'  = 48..57    'A'..'Z' = 65..90
        'a'..'z'  = 97..122

    So a digit is   X >= '0' && X <= '9'
    a capital is    X >= 'A' && X <= 'Z'
    a small letter  X >= 'a' && X <= 'z'

    Three checks in an if / else-if chain — the order matters
    only for clarity here, the ranges never overlap.
=====================================================================
*/

/*
#include <bits/stdc++.h>
using namespace std;

int main()
{
    char input;
    cin >> input;

    if (input >= '0' && input <= '9')
    {
        cout << "IS DIGIT" << endl;
    }
    else if (input >= 'A' && input <= 'Z')
    {
        cout << "ALPHA" << endl;
        cout << "IS CAPITAL" << endl;
    }
    else if (input >= 'a' && input <= 'z')
    {
        cout << "ALPHA" << endl;
        cout << "IS SMALL" << endl;
    }
    return 0;
}
*/


/*
=====================================================================
  Problem : C. Simple Calculator
  Limits  : 1 second, 256 MB
=====================================================================

  Statement
    Given two numbers X and Y, print their summation,
    multiplication and subtraction — each on its own line in
    the exact format shown below.

  Input
    One line with two integers X and Y (1 <= X, Y <= 10^5).

  Output
    Three lines, in this order:
        X + Y = <sum>
        X * Y = <product>
        X - Y = <difference>

  Example
    Input : 5 10
    Output:
      5 + 10 = 15
      5 * 10 = 50
      5 - 10 = -5

  Note
    Be careful with the SPACES: number, space, operator, space,
    number, space, =, space, result. long long keeps the
    product safe (10^5 * 10^5 = 10^10 > int's limit).
=====================================================================
*/

/*
#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long x, y;
    cin >> x >> y;

    long long sum = x + y;
    long long multi = x * y;
    long long sub = x - y;

    cout << x << " + " << y << " = " << sum << endl;
    cout << x << " * " << y << " = " << multi << endl;
    cout << x << " - " << y << " = " << sub << endl;
    return 0;
}
*/


/*
=====================================================================
  Problem : F. Reversing
  Limits  : 1 second, 64 MB
=====================================================================

  Statement
    Given a number N and an array A of N numbers, print the
    array in reversed order.

    Note: don't use built-in functions — walk the indexes
    yourself.

  Input
    First line  : N (1 <= N <= 1000)
    Second line : N numbers (0 <= Ai <= 10^9)

  Output
    The array printed backwards.

  Examples
    Input :
      4
      5 1 3 2
    Output:
      2 3 1 5

    Input :
      5
      1 2 3 4 5
    Output:
      5 4 3 2 1

  Note
    The input loop walks i = 0 .. n-1 (left to right), the
    output loop walks i = n-1 .. 0 (right to left). Same array,
    opposite direction — no second array and no swap needed.
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

    for (int i = n - 1; i >= 0; i--)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
*/


/*
=====================================================================
  Problem : E. Max
  Limits  : 1 second, 256 MB
=====================================================================

  Statement
    Given a number N and N numbers, find the maximum of them.

  Input
    First line  : N (1 <= N <= 1000)
    Second line : N numbers Xi (0 <= Xi <= 10^9)

  Output
    The maximum number.

  Example
    Input :
      5
      1 8 5 7 5
    Output:
      8

  Note — the max pattern
    start with the FIRST element as the best answer seen so
    far, then walk the whole array and replace it whenever a
    bigger one shows up:

        maxNumber = arr[0];
        for every arr[i]: if (arr[i] > maxNumber) maxNumber = arr[i];

    Starting at arr[0] (not 0!) matters — 0 would be wrong as
    soon as every value is negative. The same shape with < finds
    the minimum.
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

    int maxNumber = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > maxNumber)
        {
            maxNumber = arr[i];
        }
    }
    cout << maxNumber;

    return 0;
}
*/


/*
=====================================================================
  Problem : K. Max and Min
  Limits  : 0.25 seconds, 64 MB
=====================================================================

  Statement
    Given 3 numbers A, B and C, print the minimum and the
    maximum of them.

  Input
    One line with 3 numbers (-10^5 <= A, B, C <= 10^5).

  Output
    The minimum, a single space, then the maximum.

  Examples
    Input : 1 2 3       Output: 1 3
    Input : -1 -2 -3    Output: -3 -1
    Input : 10 20 -5    Output: -5 20

  Note
    Same max/min walk as problem E, but on 3 fixed values: start
    both answers at arr[0], then one pass with > and < updates
    each. Order of output is min FIRST, then max.

    This is the test in input.txt / output.txt.
=====================================================================
*/

/*
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[3];
    for (int i = 0; i < 3; i++)
    {
        cin >> arr[i];
    }

    int maxNumber = arr[0];
    int minNumber = arr[0];

    for (int i = 1; i < 3; i++)
    {
        if (arr[i] > maxNumber)
        {
            maxNumber = arr[i];
        }
        if (arr[i] < minNumber)
        {
            minNumber = arr[i];
        }
    }

    cout << minNumber << " " << maxNumber << '\n';

    return 0;
}
*/
