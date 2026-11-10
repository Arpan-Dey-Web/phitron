/*
  Module 18 — 2D Arrays and Matrices (C)

  Each concept below is written as:
    1. a block comment  -> the idea (Statement, Example, Note)
    2. a block comment  -> my code, kept commented out

  All code is kept commented out.
  To run one, remove the block-comment markers around its code
  and wrap the others the same way.

  Concepts:
    1. take input into a 2D array and print it
    2. print one specific row and one specific column
    3. check row matrix
    4. check column matrix
    5. check square matrix
    6. check zero matrix
    7. check primary diagonal matrix
    8. check secondary diagonal matrix   (the test in input.txt)
*/


/*
=====================================================================
  Concept : Take Input Into a 2D Array
=====================================================================

  Statement
    Read r and c, then r*c numbers, then print the matrix back
    row by row.

  Example
    Input :
      2 3
      1 2 3 4 5 6
    Output:
      1 2 3 
      4 5 6 

  Note
    Outer loop = rows (i), inner loop = columns (j). Input and
    output use the SAME double loop, only scanf and printf
    change.

    int arr[r][c] is a variable-length array (C99): r and c
    come from input, so the size must be small enough for the
    stack.
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
        for (int j = 0; j < c; j++)
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
  Concept : Print One Specific Row and Column
=====================================================================

  Statement
    Read the matrix, then a row number and a column number, and
    print that whole row and that whole column.

  Note — MY BUG (fixed)
    My column loop was  for (i = 0; i < c; i++)
    but a COLUMN has r elements, not c. With c > r it reads past
    the last row (out of bounds); with c < r it stops early. It
    only looked correct because every test matrix was square.

        row loop    ->  i < c   (a row is c columns wide)
        column loop ->  i < r   (a column is r rows tall)
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

    int rowNumber;
    scanf("%d", &rowNumber);
    for (int i = 0; i < c; i++)              // row: c elements
    {
        printf("%d ", arr[rowNumber][i]);
    }
    printf("\n------------------------------\n");

    int colNumber;
    scanf("%d", &colNumber);
    for (int i = 0; i < r; i++)              // column: r elements
    {
        printf("%d ", arr[i][colNumber]);
    }

    return 0;
}
*/


/*
=====================================================================
  Concept : Check Row Matrix
=====================================================================

  Statement
    A row matrix has exactly ONE row (r == 1). Read the matrix
    and say which it is.

  Example
    Input :
      1 3
      4 5 6
    Output:
      This is a row matrix

  Note
    r == 1 is the whole definition — no loop needed for the
    test, only for reading the matrix.

    MY BUG (fixed): my printf had no semicolon
        printf("This is an row metrix")    // does not compile
    and the wording was wrong: "a row matrix", "matrix" (not
    "metrix").
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

    if (r == 1)
    {
        printf("This is a row matrix");
    }
    else
    {
        printf("This is not a row matrix");
    }

    return 0;
}
*/


/*
=====================================================================
  Concept : Check Column Matrix
=====================================================================

  Statement
    A column matrix (vector matrix) has exactly ONE column
    (c == 1).

  Example
    Input :
      3 1
      4
      5
      6
    Output:
      This is a column matrix

  Note
    Mirror of the row check: c == 1.
    Same missing-semicolon bug here, same fix.
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

    if (c == 1)
    {
        printf("This is a column matrix");
    }
    else
    {
        printf("This is not a column matrix");
    }

    return 0;
}
*/


/*
=====================================================================
  Concept : Check Square Matrix
=====================================================================

  Statement
    A square matrix has the same number of rows and columns
    (r == c). Diagonals only exist in square matrices, so this
    test comes first in every diagonal problem.

  Example
    Input :
      3 3
      1 2 3 4 5 6 7 8 9
    Output:
      This is a square matrix

  Note
    r == c — the one condition every diagonal check needs.
    Same missing-semicolon bug here, same fix.
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

    if (r == c)
    {
        printf("This is a square matrix");
    }
    else
    {
        printf("This is not a square matrix");
    }

    return 0;
}
*/


/*
=====================================================================
  Concept : Check Zero Matrix
=====================================================================

  Statement
    A zero (null) matrix has EVERY element equal to 0 — count
    the zeros and compare with the total number of elements.

  Example
    Input :
      2 2
      0 0 0 0
    Output:
      This is a zero matrix

  Note
    total elements = r * c
    if count(0) == r * c  ->  every element is 0

    No need to check "is it square" — a zero matrix can have
    any shape (2×3 of zeros is still a zero matrix).
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

    int totalValue = r * c;
    int zero = 0;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (arr[i][j] == 0)
            {
                zero++;
            }
        }
    }

    if (totalValue == zero)
    {
        printf("This is a zero matrix");
    }
    else
    {
        printf("This is not a zero matrix");
    }

    return 0;
}
*/


/*
=====================================================================
  Concept : Check Primary Diagonal Matrix
=====================================================================

  Statement
    A primary-diagonal matrix is square and every element OFF
    the main diagonal (top-left -> bottom-right, i == j) is 0.

  Example
    Input :
      3 3
      1 0 0
      0 2 0
      0 0 3
    Output:
      This is a primary diagonal matrix

  Note — MY BUG (fixed)
    My first version printed the "not" message INSIDE the
    loop:

        if (arr[i][j] != 0) printf("not a diagonal matrix");

    so a matrix with several non-zero off-diagonal elements
    printed the message MANY times. The fix is the flag pattern:

        set is_Diagonal = false inside the loop
        print ONCE after the loop

    Also: the diagonal test only makes sense when r == c, so
    the whole check starts with if (r == c).
=====================================================================
*/

/*
#include <stdio.h>
#include <stdbool.h>

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

    bool is_Diagonal = true;

    if (r == c)
    {
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (i != j && arr[i][j] != 0)   // off the diagonal
                {
                    is_Diagonal = false;        // remember, print later
                }
            }
        }

        if (is_Diagonal == true)
        {
            printf("This is a primary diagonal matrix\n");
        }
        else
        {
            printf("This is not a primary diagonal matrix\n");
        }
    }
    else
    {
        printf("This is not a primary diagonal matrix\n");
    }

    return 0;
}
*/


/*
=====================================================================
  Concept : Check Secondary Diagonal Matrix
=====================================================================

  Statement
    A secondary-diagonal matrix is square and every element OFF
    the anti-diagonal (bottom-left -> top-right) is 0. On that
    diagonal the indexes add up to rows - 1:  i + j == r - 1.

  Example
    Input :
      3 3
      1 0 0
      0 2 0
      0 0 3
    Output:
      This is not a Secondary Diagonal Matrix

  Note — this is the test in input.txt
    The matrix IS a diagonal matrix, but its values 1, 2, 3 sit
    on the PRIMARY diagonal (i == j):

        arr[0][0] = 1, arr[1][1] = 2, arr[2][2] = 3

    The check tests every element that is NOT on the secondary
    diagonal (i + j != r - 1) and requires it to be 0:

        arr[0][0] = 1  ->  off the secondary diagonal, non-zero
                          => not a secondary diagonal matrix

    So a matrix can be diagonal without being SECONDARY
    diagonal — "diagonal" alone does not say which one.

    The flag pattern (set in the loop, print once after) is
    used here too — one message, never repeated.
=====================================================================
*/

/*
#include <stdio.h>
#include <stdbool.h>

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

    bool is_Diagonal = true;

    if (r == c)
    {
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (i + j != r - 1 && arr[i][j] != 0)   // off it
                {
                    is_Diagonal = false;
                }
            }
        }

        if (is_Diagonal)
        {
            printf("This is a Secondary Diagonal Matrix\n");
        }
        else
        {
            printf("This is not a Secondary Diagonal Matrix\n");
        }
    }
    else
    {
        printf("This is not a Secondary Diagonal Matrix\n");
    }

    return 0;
}
*/
