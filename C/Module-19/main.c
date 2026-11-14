/*
  Module 19 — Practice: 2D Arrays and Recursion (C)

  Practice set mixing Module 18 (2D arrays) and Module 17
  (recursion). Each problem below is written as:
    1. a block comment  -> the statement (Statement, Input, Output, Examples, Note)
    2. a block comment  -> my solution, kept commented out

  All solutions are kept commented out.
  To run one, remove the block-comment markers around its code
  and wrap the others the same way.

  Problems:
    W. Mirror Array        — reverse every row of a 2D array
    D. Print Digits        — digits of N, with recursion
    I. Count Vowels        — vowels in a whole line, recursion
    J. Factorial           — N!, recursion
*/


/*
=====================================================================
  Problem : W. Mirror Array
  Limits  : 1 second, 256 MB
=====================================================================

  Statement
    Given two numbers N, M and a 2D array of size N * M, print
    the inverted array that appeared in the mirror — every row
    printed backwards.

  Input
    First line : N (rows) and M (columns), 1 <= N, M <= 100
    Next N lines : M numbers each (1 <= A[i][j] <= 1e9)

  Output
    The array with every row reversed.

  Example
    Input :
      3 3
      2 3 5
      7 9 20
      35 1 12
    Output:
      5 3 2 
      20 9 7 
      12 1 35 

  Note
    The rows stay in place — only the COLUMN order inside each
    row flips. So the outer loop is unchanged and the inner
    loop counts DOWN:

        for (int j = c - 1; j >= 0; j--)

    Mirror of the input loop: same two loops, one walks
    j = 0..c-1, the other j = c-1..0.
=====================================================================
*/

/*
#include <stdio.h>

int main()
{
    int r, c;
    scanf("%d %d", &r, &c);

    int arr[r][c];

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    for (int i = 0; i < r; i++)
    {
        for (int j = c - 1; j >= 0; j--)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}
*/


/*
=====================================================================
  Problem : D. Print Digits using Recursion
  Limits  : 1 second, 256 MB
=====================================================================

  Statement
    Given a number N, print the digits of N separated by a
    space. Solve it using recursion.

  Input
    First line : T (1 <= T <= 10), number of test cases
    Next T lines : a number N each (0 <= N <= 1e9)

  Output
    For each test case one line with the digits separated by
    spaces.

  Example
    Input :
      3
      121
      39
      123456
    Output:
      1 2 1 
      3 9 
      1 2 3 4 5 6 

  Note
    n / 10 cuts off the last digit, n % 10 keeps it. Recursing
    FIRST (n / 10) walks to the leftmost digit, and the prints
    happen on the way back — so the digits come out in the
    right order:

        print_digits(121)
          -> print_digits(12)
               -> print_digits(1)
                    -> print_digits(0) returns (base case)
                    -> print 1
               -> print 2
          -> print 1
        = "1 2 1 "

    N can be 0, and the recursion would print nothing for it
    (0 / 10 is already 0) — so main() checks n == 0 and prints
    "0" itself before calling the function.
=====================================================================
*/

/*
#include <stdio.h>

void print_digits(int n)
{
    if (n == 0)                 // base case
    {
        return;
    }
    print_digits(n / 10);       // go to the leftmost digit first

    int last = n % 10;
    printf("%d ", last);        // print on the way back
}

int main()
{
    int t, n;
    scanf("%d", &t);

    for (int i = 0; i < t; i++)
    {
        scanf("%d", &n);

        if (n == 0)             // recursion alone would print nothing
        {
            printf("0");
        }
        print_digits(n);
        printf("\n");
    }

    return 0;
}
*/


/*
=====================================================================
  Problem : I. Count Vowels
  Limits  : 1 second, 256 MB
=====================================================================

  Statement
    Given a string S, print the number of vowels in it. Vowel
    letters are ['a', 'e', 'i', 'o', 'u'] and can be capital or
    small. Solve it using recursion.

  Input
    One line containing the string S (1 <= |S| <= 200). It can
    contain capital letters, small letters and SPACES.

  Output
    The number of vowels in S.

  Example
    Input :
      Data Structure Lab
    Output:
      6

  Note
    Two traps in this one:

    1. scanf("%s") would stop at the first space — the string
       has spaces, so I read the whole line with fgets().

    2. The recursion walks to the END first (rec(s, i + 1)
       before the check) and counts on the way back:

           count = rec(s, i + 1);      // rest of the string
           if s[i] is a vowel -> return count + 1
           else               -> return count

       The end-of-string marker '\0' is the base case.

    Both cases of every vowel are checked ('a'..'u' and
    'A'..'U') — no need to convert the letter.
=====================================================================
*/

/*
#include <stdio.h>

int rec(char s[], int i)
{
    if (s[i] == '\0')           // base case: end of string
    {
        return 0;
    }

    int count = rec(s, i + 1);  // count the REST first

    if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' ||
        s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
    {
        return count + 1;       // this letter IS a vowel
    }
    else
    {
        return count;           // not a vowel, pass it on
    }
}

int main()
{
    char s[201];
    fgets(s, 201, stdin);       // whole line, spaces included

    int ans = rec(s, 0);
    printf("%d", ans);

    return 0;
}
*/


/*
=====================================================================
  Problem : J. Factorial
  Limits  : 1 second, 64 MB
=====================================================================

  Statement
    Given a number N, print the factorial of N. Solve it using
    recursion.

  Input
    One integer N (1 <= N <= 20)

  Output
    N!

  Example
    Input : 5
    Output:
      120

  Note
    factorial(n) = n * factorial(n - 1), base case n == 1.

    N starts at 1, so the recursion never reaches 0 — no
    infinite recursion and no "0!" special case needed.

    Why long long: 20! = 2432902008176640000, far bigger than
    int can hold (max about 2.1e9). 20! still fits in long long
    (max about 9.2e18), which is why the function returns long
    long and main prints with %lld.

    This is the solution recorded in input.txt / output.txt
    (5 -> 120).
=====================================================================
*/

/*
#include <stdio.h>

long long int factorial(int n)
{
    if (n == 1)                 // base case
    {
        return 1;
    }
    long long int multi = factorial(n - 1);
    return n * multi;           // n promotes to long long
}

int main()
{
    int n;
    scanf("%d", &n);

    long long int ans = factorial(n);
    printf("%lld", ans);

    return 0;
}
*/
