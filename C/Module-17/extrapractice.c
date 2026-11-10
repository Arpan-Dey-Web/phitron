/*
  Module 17 — Extra Practice: Recursion Problems (C)

  Each problem below is written as:
    1. a block comment  -> the statement (Statement, Input, Output, Note)
    2. a block comment  -> my solution, kept commented out

  All solutions are kept commented out.
  To run one, remove the block-comment markers around its code
  and wrap the others the same way.

  Problems:
    A. Print Recursion      — print "I love Recursion" N times
    B. Print from 1 to N    — one number per line
    C. Print from N to 1    — one line, single spaces
    F. Print Even Indices   — even indices, reversed order
*/


/*
=====================================================================
  Problem : A. Print Recursion
  Limits  : 1 second, 256 MB
=====================================================================

  Statement
    Given a number N, print "I love Recursion" N times.
    Note: solve it using recursion.

  Input
    One integer N (1 <= N <= 100)

  Output
    N lines, each containing "I love Recursion"

  Example
    Input : 3
    Output:
      I love Recursion
      I love Recursion
      I love Recursion

  Note
    The base case is N == 0 (print nothing, stop). The print
    happens BEFORE the recursive call, so the lines come out in
    the normal top-to-bottom order.

    Counting down (n - 1) instead of up makes the base case
    trivial: 0 lines left = done.
=====================================================================
*/

/*
#include <stdio.h>

void print_N_times(int n)
{
    if (n == 0)                        // base case
    {
        return;
    }
    printf("I love Recursion\n");
    print_N_times(n - 1);
}

int main()
{
    int n;
    scanf("%d", &n);
    print_N_times(n);
    return 0;
}
*/


/*
=====================================================================
  Problem : B. Print from 1 to N
  Limits  : 1 second, 64 MB
=====================================================================

  Statement
    Given a number N, print the numbers from 1 to N, one per line.
    Note: solve it using recursion.

  Input
    One integer N (1 <= N <= 1000)

  Output
    N lines: 1, 2, ..., N

  Example
    Input : 5
    Output:
      1
      2
      3
      4
      5

  Note
    Same count-down structure as problem A, but the print sits
    AFTER the recursive call — so the deepest call (n = 1)
    prints first and the numbers come out ascending.

    That is the "print on the way back" trick from main.c.
=====================================================================
*/

/*
#include <stdio.h>

void print_N_times(int n)
{
    if (n == 0)                        // base case
    {
        return;
    }
    print_N_times(n - 1);              // recurse first
    printf("%d\n", n);                 // print on the way back
}

int main()
{
    int n;
    scanf("%d", &n);
    print_N_times(n);
    return 0;
}
*/


/*
=====================================================================
  Problem : C. Print from N to 1
  Limits  : 1 second, 64 MB
=====================================================================

  Statement
    Given a number N, print all numbers from N to 1 separated by
    a single space, with NO leading or trailing spaces.
    Note: solve it using recursion.

  Input
    One integer N (1 <= N <= 1000)

  Output
    One line: N N-1 ... 2 1

  Example
    Input : 4
    Output:
      4 3 2 1

  Note — the trailing-space trap
    printf("%d ", n) for every number would leave a space at the
    END of the line, which the judge rejects. So:

      n == 1  -> printf("%d", n)     no space (last number)
      else    -> printf("%d ", n)    space after every other

    The space is printed BEFORE the number is passed on, so the
    line never starts with one either.
=====================================================================
*/

/*
#include <stdio.h>

void print_N_times(int n)
{
    if (n == 0)                        // base case
    {
        return;
    }

    if (n == 1)
    {
        printf("%d", n);               // last number: no space
    }
    else
    {
        printf("%d ", n);              // everything else: space
    }

    print_N_times(n - 1);
}

int main()
{
    int n;
    scanf("%d", &n);
    print_N_times(n);
    return 0;
}
*/


/*
=====================================================================
  Problem : F. Print Even Indices
  Limits  : 1 second, 256 MB
=====================================================================

  Statement
    Given a number N and an array A of N numbers, print the
    numbers at EVEN indices in REVERSED order, separated by
    spaces.
    Note: assume 0-based indexing, solve it using recursion.

  Input
    First line  : N (1 <= N <= 1000)
    Second line : N numbers (-1e9 <= Ai <= 1e9)

  Output
    The even-index values, last one first, single spaces

  Examples
    Input :
      4
      1 4 2 7
    Output:
      2 1

    Input :
      7
      1 5 8 2 3 9 11
    Output:
      11 3 8 1

  Note
    Even indices of [1 5 8 2 3 9 11] are
        idx 0 -> 1, idx 2 -> 8, idx 4 -> 3, idx 6 -> 11
    Reversed: 11 3 8 1  (this is the test in input.txt)

    Two tricks in one:
      idx + 2   — jump straight to the next even index
      printf AFTER the call — prints during unwinding, so the
                  first even index (0) comes out LAST, which is
                  exactly "reversed order"
=====================================================================
*/

/*
#include <stdio.h>

void print_even_numbers_from_array(int arr[], int n, int idx)
{
    if (idx >= n)                       // base case: past the end
    {
        return;
    }
    print_even_numbers_from_array(arr, n, idx + 2);  // deeper first
    printf("%d ", arr[idx]);            // print on the way back
}

int main()
{
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    print_even_numbers_from_array(arr, n, 0);   // start at 0
    return 0;
}
*/
