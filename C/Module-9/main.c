/*
  Module 9 — Array insert, delete, swap, reverse (C)

  Each problem below is written as:
    - statement in a block comment
    - solution code commented out

  All solutions are kept commented out.
  To run one, comment out the others and uncomment its code.
*/


/*
=====================================================================
  Problem : Insert an Element at a Given Index
=====================================================================

  Statement
    Given N, then N numbers, then an index IDX and a value V,
    insert V at index IDX so that every later element moves one
    step to the right. Print the array after the insertion.

  Input
    First line  : N
    Second line : N numbers
    Third line  : IDX V

  Example
    Input :
      4
      10 20 30 40
      1 100

    Output:
      10 100 20 30 40

  Note
    The shift loop runs BACKWARD (i = n down to idx + 1) so that
    a value is never overwritten before it is copied.
    The array needs one extra slot: int a[n + 1].
=====================================================================
*/

// #include <stdio.h>
//
// int main()
// {
//     int n;
//     scanf("%d", &n);
//
//     int a[n + 1];
//     for (int i = 0; i < n; i++)
//     {
//         scanf("%d", &a[i]);
//     }
//
//     int idx, value;
//     scanf("%d %d", &idx, &value);
//
//     for (int i = n; i >= idx + 1; i--)
//     {
//         a[i] = a[i - 1];
//     }
//
//     a[idx] = value;
//
//     for (int i = 0; i <= n; i++)
//     {
//         printf("%d ", a[i]);
//     }
//
//     return 0;
// }


/*
=====================================================================
  Problem : Delete an Element at a Given Index
=====================================================================

  Statement
    Given N, then N numbers, then an index IDX, remove the value
    at IDX so that every later element moves one step to the left.
    Print the array after the deletion.

  Input
    First line  : N
    Second line : N numbers
    Third line  : IDX

  Example
    Input :
      5
      10 20 30 40 50
      2

    Output:
      10 20 40 50

  Note
    The array must be declared int a[n] because we still READ n
    values first. Declaring int a[n - 1] would write out of bounds.
    After the shift, n-- only limits how many elements we print.
=====================================================================
*/

// #include <stdio.h>
//
// int main()
// {
//     int n;
//     scanf("%d", &n);
//
//     int a[n];
//     for (int i = 0; i < n; i++)
//     {
//         scanf("%d", &a[i]);
//     }
//
//     int idx;
//     scanf("%d", &idx);
//
//     for (int i = idx; i < n - 1; i++)
//     {
//         a[i] = a[i + 1];
//     }
//
//     n--;
//
//     for (int i = 0; i < n; i++)
//     {
//         printf("%d ", a[i]);
//     }
//
//     return 0;
// }


/*
=====================================================================
  Problem : Swap Two Variables
=====================================================================

  Statement
    Swap the values of two variables using a temporary variable.

  Example
    Input : (none — a and b are given in the code)

    Output:
      20 10

  Note
    temp = a; a = b; b = temp;   -> all three steps are needed.
    Without temp, both variables end up with b's value.
=====================================================================
*/

// #include <stdio.h>
//
// int main()
// {
//     int a = 10;
//     int b = 20;
//
//     int temp = a;
//     a = b;
//     b = temp;
//
//     printf("%d %d", a, b);
//     return 0;
// }


/*
=====================================================================
  Problem : Reverse an Array (Two Pointer Technique)
=====================================================================

  Statement
    Given N and then N numbers, reverse the array in place and
    print it.

  Input
    First line  : N
    Second line : N numbers

  Example
    Input :
      5
      1 2 3 4 5

    Output:
      5 4 3 2 1

  Note
    i starts at 0, j starts at n - 1. Swap a[i] and a[j] while
    i < j, then i++ and j--. The pointers meet in the middle.

    To only PRINT in reverse (without changing the array), use:
      for (int i = n - 1; i >= 0; i--) printf("%d ", a[i]);
=====================================================================
*/

// #include <stdio.h>
//
// int main()
// {
//     int n;
//     scanf("%d", &n);
//
//     int a[n];
//     for (int i = 0; i < n; i++)
//     {
//         scanf("%d", &a[i]);
//     }
//
//     for (int i = 0, j = n - 1; i < j; i++, j--)
//     {
//         int temp = a[i];
//         a[i] = a[j];
//         a[j] = temp;
//     }
//
//     for (int i = 0; i < n; i++)
//     {
//         printf("%d ", a[i]);
//     }
//
//     return 0;
// }
