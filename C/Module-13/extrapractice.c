/*
  Module 13 — Extra Practice: More Patterns (C)

  Each pattern below is written as:
    1. a block comment  -> the question (Statement, Example, Note)
    2. a block comment  -> my answer code, kept commented out

  All answers are kept commented out.
  To run one, remove the block-comment markers around its code
  and wrap the other answers the same way.

  Patterns:
    - pyramid
    - number triangle
    - decreasing star triangle
    - inverted pyramid
    - alphabet triangle
*/


/*
=====================================================================
  Problem : Pyramid Pattern
=====================================================================

  Statement
    Read N and print a centered pyramid:

       *
      ***
     *****
    *******

  Example
    Input :
      4

    Output:
       *
      ***
     *****
    *******

  Note
    spaces first (space = n-1), then stars (star = 1, star += 2).
=====================================================================
*/

/*
#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n );
    int star= 1;
    int space = n-1;
    for (int i =0; i<n; i++)
    {
      for (int j =1; j<=space; j++)
      {
        printf(" ");
      }

      for (int k = 1; k<=star; k++)
      {
        printf("*");
      }
      printf("\n");
      star +=2;
      space--;

    }
  return 0;
}
*/


/*
=====================================================================
  Problem : Number Triangle
=====================================================================

  Statement
    Read N and print:

         1
       1 2
     1 2 3
    1 2 3 4

  Example
    Input :
      4

    Output:
       1
      1 2
      1 2 3
      1 2 3 4

  Note
    Leading spaces = n - i, then print 1..i with a space after
    each number: printf("%d ", k).
=====================================================================
*/

/*
#include <stdio.h>
int main() {
    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n - i; j++) {
            printf(" ");
        }

        for (int k = 1; k <= i; k++) {
            printf("%d ", k);
        }
        printf("\n");
    }
    return 0;
}
*/


/*
=====================================================================
  Problem : Decreasing Star Triangle (left aligned)
=====================================================================

  Statement
    Read N and print:

    ****
     ***
      **
       *

  Example
    Input :
      4

    Output:
    ****
     ***
      **
       *

  Note
    Leading spaces = i - 1 (grows each row),
    stars = n - i + 1 (shrinks each row).
=====================================================================
*/

/*
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i - 1; j++) {
            printf(" ");
        }
        for (int k = 1; k <= n - i + 1; k++) {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
*/


/*
=====================================================================
  Problem : Inverted Pyramid
=====================================================================

  Statement
    Read N and print an upside-down pyramid:

        *******
         *****
          ***
           *

  Example
    Input :
      4

    Output:
        *******
         *****
          ***
           *

  Note
    Leading spaces = i - 1, stars = 2 * (n - i) + 1.
    The star count is always ODD: 7, 5, 3, 1.
=====================================================================
*/

/*
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i - 1; j++) {
            printf(" ");
        }
        for (int k = 1; k <= 2 * (n - i) + 1; k++) {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
*/


/*
=====================================================================
  Problem : Alphabet Triangle
=====================================================================

  Statement
    Read N and print:

       A
      A B
      A B C
      A B C D

  Example
    Input :
      4

    Output:
       A
      A B
      A B C
      A B C D

  Note
    'A' + k gives the k-th letter: 'A'+0 = 'A', 'A'+1 = 'B', ...
    Print with printf("%c ", 'A' + k) — the space keeps letters
    separated.
=====================================================================
*/

/*
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n - i; j++) {
            printf(" ");
        }
        for (int k = 0; k < i; k++) {
            printf("%c ", 'A' + k);
        }
        printf("\n");
    }
    return 0;
}
*/
