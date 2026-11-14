/*
  Final Exam — Problem Set (C)

  Each problem below is written as:
    1. a block comment  -> the statement (Statement, Input, Output, Examples, Note)
    2. a block comment  -> my solution, kept commented out

  All solutions are kept commented out.
  To run one, remove the block-comment markers around its code
  and wrap the others the same way.

  Problems:
    1. Missing Number        — M / (A*B*C), or -1
    2. Jadu Matrix           — both diagonals 1, everything else 0
    3. Last Row and Last Column
    4. Christmas Tree        — pyramid + trunk
    5. Copy, Sort, Difference
*/


/*
=====================================================================
  Problem 1 : Missing Number
=====================================================================

  Statement
    Given the multiplication of four numbers (M) and three of
    those numbers (A, B, C), find the missing fourth number.
    If it cannot be found, print -1. All numbers are
    non-negative integers.

  Input
    First line      : T, number of test cases (1 < T <= 100000)
    Every test case : M A B C on one line
      0 <= M <= 1e18
      1 <= A, B, C <= 1e6

  Output
    The missing number, each on its own line.

  Examples
    Input :
      4
      20 1 2 2
      10 2 2 1
      1 1 2 3
      0 3 10 15
    Output:
      5
      -1
      -1
      0

  Note
    missing = M / (A*B*C), but only when M is EXACTLY divisible:

      M % (A*B*C) == 0  ->  print the quotient
      otherwise         ->  print -1

    Special cases that made me think:
      M = 0 and A,B,C >= 1  ->  0 % x == 0, so 0/x = 0  ->  print 0
      A*B*C > M             ->  remainder != 0          ->  print -1

    A, B, C are at most 1e6, so A*B*C is at most 1e18 — fits
    inside a long long (max ~9.2e18). No overflow.
=====================================================================
*/

/*
#include <stdio.h>

int main()
{
    int t;
    scanf("%d", &t);

    for (int i = 0; i < t; i++)
    {
        long long total, a, b, c;
        scanf("%lld %lld %lld %lld", &total, &a, &b, &c);

        long long multiplication_Of_Three_Numbers = a * b * c;

        if (total % multiplication_Of_Three_Numbers == 0)
        {
            printf("%lld\n", total / multiplication_Of_Three_Numbers);
        }
        else
        {
            printf("-1\n");
        }
    }

    return 0;
}
*/


/*
=====================================================================
  Problem 2 : Jadu Matrix
=====================================================================

  Statement
    Given a matrix of size N * M, tell whether it is a Jadu
    Matrix or not.

    A Jadu Matrix is a SQUARE matrix where the values on the
    primary diagonal and the secondary diagonal are 1, and every
    other cell contains only 0.

  Input
    First line : N (rows) and M (columns), 1 <= N, M <= 100
    Next lines : the N * M matrix, 0 <= values <= 100

  Output
    YES  if it is a Jadu Matrix, otherwise NO

  Examples
    Input :
      5 5
      1 0 0 0 1
      0 1 0 1 0
      0 0 1 0 0
      0 1 0 1 0
      1 0 0 0 1
    Output:
      YES

    (a matrix with the centre 0, or with a 2 on a diagonal, or
     a non-square matrix -> NO)

  Note
    Three checks, in this order:
      1. n != m                 -> not square -> NO (stop early)
      2. on a diagonal (i == j or i + j == n-1)  -> must be 1
      3. anywhere else                        -> must be 0

    Both diagonal conditions in ONE line:

        if (i == j || i + j == n - 1)

    i == j            is the primary diagonal (top-left to
                      bottom-right)
    i + j == n - 1    is the secondary diagonal (top-right to
                      bottom-left)

    The flag pattern again: is_jadu is set inside the loop and
    the YES/NO is printed once after it.
=====================================================================
*/

/*
#include <stdio.h>

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    int arr[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    if (n != m)
    {
        printf("NO\n");
        return 0;
    }

    int is_jadu = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == j || i + j == n - 1)
            {
                if (arr[i][j] != 1)
                {
                    is_jadu = 0;
                }
            }
            else
            {
                if (arr[i][j] != 0)
                {
                    is_jadu = 0;
                }
            }
        }
    }

    if (is_jadu == 1)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }

    return 0;
}
*/


/*
=====================================================================
  Problem 3 : Last Row and Last Column
=====================================================================

  Statement
    Given a 2D matrix of N * M size with integer values, print
    the values of the LAST ROW first, then the values of the
    LAST COLUMN — both in the order they were given.

  Input
    First line : N and M, 2 <= N, M <= 100
    Next lines : the matrix, 0 <= element <= 100

  Output
    Line 1 : the values of the last row
    Line 2 : the values of the last column

  Examples
    Input :
      3 4
      1 2 3 4
      5 6 7 8
      6 5 4 2
    Output:
      6 5 4 2 
      4 8 2 

    Input :
      5 3
      1 2 3 
      5 6 7 
      6 5 4
      3 5 4
      1 2 3
    Output:
      1 2 3 
      3 7 4 4 3 

  Note
    Two one-dimensional walks through the same matrix:

      last row    : arr[n - 1][j]  for every column j (0..m-1)
      last column : arr[i][m - 1]  for every row    i (0..n-1)

    The corner element arr[n-1][m-1] appears in BOTH lines —
    that is expected, it belongs to the last row and to the
    last column.
=====================================================================
*/

/*
#include <stdio.h>

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    int arr[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    for (int j = 0; j < m; j++)
    {
        printf("%d ", arr[n - 1][j]);
    }
    printf("\n");

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i][m - 1]);
    }
    printf("\n");

    return 0;
}
*/


/*
=====================================================================
  Problem 4 : Christmas Tree
=====================================================================

  Statement
    Ranja wants a Christmas tree. Read the size N (odd,
    1 <= N <= 21) and print the tree: a pyramid on top and a
    5-row trunk below it.

  Input
    One odd integer N (1 <= N <= 21)

  Output
    The tree: the pyramid has N+5 rows (the widest row is
    N + 10 stars), then exactly 5 trunk rows, each with
    5 leading spaces and N stars.

  Examples
    Input : 1
    Output:
         *
        ***
       *****
      *******
     *********
   ***********
        *
        *
        *
        *
        *

    Input : 3
    Output:
          *
         ***
        *****
       *******
      *********
     ***********
    *************
         ***
         ***
         ***
         ***
         ***

  Note — the two formulas
    spaces     = (n + 9) / 2     first row's indent
    total_rows = (n + 11) / 2    pyramid rows (spaces + 1)

    The pyramid is pattern 10 from Pattern-Printing (spaces--,
    stars += 2), just starting from a wider indent so the base
    is N + 10 stars. The trunk is 5 identical rows of
    5 spaces + N stars.

    The whole tree is (n + 11) / 2 + 5 lines.
=====================================================================
*/

/*
#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int spaces = (n + 9) / 2;
    int stars = 1;
    int total_rows = (n + 11) / 2;

    for (int i = 0; i < total_rows; i++)
    {
        for (int s = 0; s < spaces; s++)
        {
            printf(" ");
        }
        for (int st = 0; st < stars; st++)
        {
            printf("*");
        }
        printf("\n");

        spaces--;
        stars += 2;
    }

    for (int i = 0; i < 5; i++)
    {
        for (int s = 0; s < 5; s++)
        {
            printf(" ");
        }
        for (int st = 0; st < n; st++)
        {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
*/


/*
=====================================================================
  Problem 5 : Copy, Sort, Difference
=====================================================================

  Statement
    Given an array A of size N, copy it into an array B and sort
    B in ascending order. Then build an array C where every
    index holds the absolute difference between A[i] and B[i]:

        C[i] = |A[i] - B[i]|

    Print C.

  Input
    First line      : T, number of test cases (1 <= T <= 100)
    Each test case  : N (1 <= N <= 1000), then N numbers
                      (0 <= A[i] <= 1000)

  Output
    For every test case: the array C, one line per test case.

  Examples
    Input :
      2
      5
      5 4 3 2 1
      6
      2 4 5 6 5 1
    Output:
      4 2 0 2 4 
      1 2 1 1 0 5 

    Test 1: A = 5 4 3 2 1, B = 1 2 3 4 5
            C = 4 2 0 2 4
    Test 2: A = 2 4 5 6 5 1, B = 1 2 4 5 5 6
            C = 1 2 1 1 0 5

  Note
    The copy b[i] = a[i] happens WHILE reading, so sorting B
    can never touch A — A must stay in its original order or
    the differences would all be 0.

    Sorting is selection sort (swap the smallest remaining into
    place), the same loop shape as Module 9.

    abs without a library function:

        int diff = a[i] - b[i];
        if (diff < 0) diff = -diff;

    (A value of 0 is its own absolute value — no special case.)
=====================================================================
*/

/*
#include <stdio.h>

int main()
{
    int t;
    scanf("%d", &t);

    for (int tc = 0; tc < t; tc++)
    {
        int n;
        scanf("%d", &n);

        int a[1005], b[1005];

        for (int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
            b[i] = a[i];            // copy while reading
        }

        // selection sort B ascending
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (b[i] > b[j])
                {
                    int temp = b[i];
                    b[i] = b[j];
                    b[j] = temp;
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            int diff = a[i] - b[i];
            if (diff < 0)
            {
                diff = -diff;       // absolute value
            }
            printf("%d ", diff);
        }
        printf("\n");
    }

    return 0;
}
*/
