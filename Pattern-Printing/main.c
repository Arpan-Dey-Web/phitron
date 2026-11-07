/*
  Pattern-Printing — Nested Loop Patterns (C)

  Every pattern below is built from the same idea:
    - the OUTER loop chooses the row
    - the INNER loop prints one row (spaces, stars or numbers)

  Each problem is written as:
    - the pattern in a block comment
    - solution code commented out

  All solutions are kept commented out.
  To run one, comment out the others and uncomment its code.
*/


/*
=====================================================================
  Pattern 1 : Solid Square
=====================================================================

  Statement
    Print an N x N square of stars.

  Example
    Input : 5
    Output:
      *****
      *****
      *****
      *****
      *****

  Note
    Outer loop = row (N times), inner loop = N stars per row.
    Both limits are the same number, that is what makes it a
    square instead of a rectangle.
=====================================================================
*/

// #include <stdio.h>
//
// int main()
// {
//     int n;
//     scanf("%d", &n);
//
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             printf("*");
//         }
//         printf("\n");
//     }
//
//     return 0;
// }


/*
=====================================================================
  Pattern 2 : Rectangle (stars per row x rows)
=====================================================================

  Statement
    Print a rectangle: the first number is how many stars each
    row has, the second number is how many rows.

  Example
    Input : 4 3        (4 stars per row, 3 rows)
    Output:
      ****
      ****
      ****

  Note
    Two different limits now: the INNER loop uses n (width) and
    the OUTER loop uses m (height).
=====================================================================
*/

// #include <stdio.h>
//
// int main()
// {
//     int n, m;
//     scanf("%d %d", &n, &m);
//
//     for (int i = 0; i < m; i++)        // m rows
//     {
//         for (int j = 0; j < n; j++)    // n stars per row
//         {
//             printf("*");
//         }
//         printf("\n");
//     }
//
//     return 0;
// }


/*
=====================================================================
  Pattern 3 : Rectangle of Numbers
=====================================================================

  Statement
    Print m rows, each row containing the numbers 1..n.

  Example
    Input : 4 3
    Output:
      1234
      1234
      1234

  Note
    The inner counter is PRINTED this time instead of '*'.
    The inner loop restarts at 1 for every row, so each row
    begins with 1 again.
=====================================================================
*/

// #include <stdio.h>
//
// int main()
// {
//     int n, m;
//     scanf("%d %d", &n, &m);
//
//     for (int i = 0; i < m; i++)
//     {
//         for (int j = 1; j <= n; j++)
//         {
//             printf("%d", j);
//         }
//         printf("\n");
//     }
//
//     return 0;
// }


/*
=====================================================================
  Pattern 4 : Right Triangle (growing, with spaces after stars)
=====================================================================

  Statement
    Row i contains i stars.

  Example
    Input : 4
    Output:
      *
      * *
      * * *
      * * *

  Note
    Inner limit is the ROW NUMBER i, so every row is one star
    longer. The trailing space after each star is kept in the
    output (pattern 7 prints the same shape without spaces).
=====================================================================
*/

// #include <stdio.h>
//
// int main()
// {
//     int n;
//     scanf("%d", &n);
//
//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 1; j <= i; j++)
//         {
//             printf("* ");
//         }
//         printf("\n");
//     }
//
//     return 0;
// }


/*
=====================================================================
  Pattern 5 : Inverted Triangle (shrinking, with spaces)
=====================================================================

  Statement
    Row i contains (n - i + 1) stars — the mirror of pattern 4.

  Example
    Input : 4
    Output:
      * * * *
      * * *
      * *
      *

  Note
    Outer loop counts DOWN (i = n .. 1), so the first row has
    the most stars. The same shape can also be made by keeping
    i = 1..n and using n + 1 - i as the inner limit.
=====================================================================
*/

// #include <stdio.h>
//
// int main()
// {
//     int n;
//     scanf("%d", &n);
//
//     for (int i = n; i >= 1; i--)
//     {
//         for (int j = 1; j <= i; j++)
//         {
//             printf("* ");
//         }
//         printf("\n");
//     }
//
//     return 0;
// }


/*
=====================================================================
  Pattern 6 : Number Triangle (counting down inside each row)
=====================================================================

  Statement
    Row i prints the numbers 1, 2, ..., n-i+1, each followed by
    a space, so every row is one number shorter than the one
    above it.

  Example
    Input : 4
    Output:
      1 2 3 4
      1 2 3
      1 2
      1

  Note
    The inner counter always restarts at 1; only the LIMIT
    shrinks — a starts at n and is decreased after every row.
    This is the mirror of pattern 3 (which keeps the limit fixed
    and repeats the same row).
=====================================================================
*/

// #include <stdio.h>
//
// int main()
// {
//     int n;
//     scanf("%d", &n);
//
//     int a = n;
//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 1; j <= a; j++)
//         {
//             printf("%d ", j);
//         }
//         a--;
//         printf("\n");
//     }
//
//     return 0;
// }


/*
=====================================================================
  Pattern 7 : Right Triangle (growing, solid stars)
=====================================================================

  Statement
    Row i contains i stars with NO space after them.

  Example
    Input : 4
    Output:
      *
      **
      ***
      ****

  Note
    Same shape as pattern 4, only the printf differs ("*" vs
    "* "). Comparing the two files the effect of a single space
    in the format string becomes visible.
=====================================================================
*/

// #include <stdio.h>
//
// int main()
// {
//     int n;
//     scanf("%d", &n);
//
//     int star = 1;
//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 1; j <= star; j++)
//         {
//             printf("*");
//         }
//         star++;
//         printf("\n");
//     }
//
//     return 0;
// }


/*
=====================================================================
  Pattern 8 : Odd Number Pyramid
=====================================================================

  Statement
    Row i prints the first i odd numbers: 1, 3, 5, ...

  Example
    Input : 4
    Output:
      1
      1 3
      1 3 5
      1 3 5 7

  Note
    The value starts at 1 and grows by 2 each time (a += 2),
    independently of the loop counter j — that is why the row
    shows odd numbers instead of 1, 2, 3.
=====================================================================
*/

// #include <stdio.h>
//
// int main()
// {
//     int n;
//     scanf("%d", &n);
//
//     for (int i = 1; i <= n; i++)
//     {
//         int a = 1;
//         for (int j = 1; j <= i; j++)
//         {
//             printf("%d ", a);
//             a += 2;
//         }
//         printf("\n");
//     }
//
//     return 0;
// }


/*
=====================================================================
  Pattern 9 : Inverted Triangle (shrinking, solid stars)
=====================================================================

  Statement
    Row i contains (n - i + 1) stars, no spaces after them.

  Example
    Input : 4
    Output:
      ****
      ***
      **
      *

  Note
    The star counter starts at n and DECREASES after every row
    (star--), which is the mirror of pattern 7 (star++).
=====================================================================
*/

// #include <stdio.h>
//
// int main()
// {
//     int n;
//     scanf("%d", &n);
//
//     int star = n;
//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 1; j <= star; j++)
//         {
//             printf("*");
//         }
//         star--;
//         printf("\n");
//     }
//
//     return 0;
// }


/*
=====================================================================
  Pattern 10 : Pyramid (centred, odd widths)
=====================================================================

  Statement
    A triangle whose middle row has 2N-1 stars: leading spaces
    shrink while the star count grows by 2.

  Example
    Input : 5
    Output:
        *
       ***
      *****
     *******
    *********

  Note
    Row i: (n - i) spaces, then (2i - 1) stars.
    Two counters move in opposite directions:
        space  = n - 1, then space--   (fewer spaces)
        star   = 1,     then star += 2 (1, 3, 5, 7, ...)

    "Don't print extra spaces after the stars" — the spaces are
    only printed BEFORE the stars, never after them.
=====================================================================
*/

// #include <stdio.h>
//
// int main()
// {
//     int n;
//     scanf("%d", &n);
//
//     int star = 1;
//     int space = n - 1;
//
//     for (int i = 1; i <= n; i++)
//     {
//         for (int k = 1; k <= space; k++)
//         {
//             printf(" ");
//         }
//         space--;
//
//         for (int j = 1; j <= star; j++)
//         {
//             printf("*");
//         }
//         star += 2;
//
//         printf("\n");
//     }
//
//     return 0;
// }


/*
=====================================================================
  Pattern 11 : Diamond (pyramid + inverted pyramid)
=====================================================================

  Statement
    The pyramid of pattern 10 followed by its mirror image, so
    the widest row (2N-1 stars) sits in the middle.

  Example
    Input : 4
    Output:
       *
      ***
     *****
    *******
     *****
      ***
       *

  Idea
    First half  : exactly pattern 10 (space--, star += 2)
    Second half : starts below the middle — spaces grow (1..),
                  stars shrink from 2N-3 down by 2

    Total lines = 2N - 1 (N rows up, N-1 rows down — the middle
    row is printed only once).
=====================================================================
*/

// #include <stdio.h>
//
// int main()
// {
//     int n;
//     scanf("%d", &n);
//
//     // first half — pyramid
//     int star = 1;
//     int space = n - 1;
//
//     for (int i = 1; i <= n; i++)
//     {
//         for (int k = 1; k <= space; k++)
//         {
//             printf(" ");
//         }
//         space--;
//
//         for (int j = 1; j <= star; j++)
//         {
//             printf("*");
//         }
//         star += 2;
//
//         printf("\n");
//     }
//
//     // second half — inverted pyramid
//     space = 1;
//     star = n * 2 - 3;
//
//     for (int i = 2; i <= n; i++)
//     {
//         for (int k = 1; k <= space; k++)
//         {
//             printf(" ");
//         }
//         space++;
//
//         for (int j = 1; j <= star; j++)
//         {
//             printf("*");
//         }
//         star -= 2;
//
//         printf("\n");
//     }
//
//     return 0;
// }
