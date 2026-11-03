/*
  Module 13 — Nested loops: star patterns + pair sum (C)

  Each problem below is written as:
    1. a block comment  -> the question (Statement, Example, Note)
    2. a block comment  -> my answer code, kept commented out

  All answers are kept commented out.
  To run one, remove the block-comment markers around its code
  and wrap the other answers the same way.

  Topics:
    - upward star triangle (two ways)
    - downward star triangle
    - pyramid (spaces + stars)
    - pair sum problem (flag + nested loop)
*/


/*
=====================================================================
  Problem : Print the Star Triangle (upward)
=====================================================================

  Statement
    Read N and print this pattern:

      *
      **
      ***
      ****
      *****

  Input
    One integer N

  Example
    Input :
      5

    Output:
      *
      **
      ***
      ****
      *****

  Note
    Outer loop = row, inner loop = stars in that row.
    printf("\n") goes AFTER the inner loop, not inside it.

    Two ways to control the inner loop:
      My way     : for (j = 1; j <= i; j++)   — use the row number
      Module way : keep a counter star = 1; star++
=====================================================================
*/

/*
#include <stdio.h>
int main()
{
  int n;
  scanf("%d", &n );

  for(int i =1 ; i<=n; i++)
  {
    for(int j= 1; j<=i; j++)
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
  Problem : Upward Star Triangle — counter way (module way)
=====================================================================

  Statement
    Same upward triangle, but control the star count with a
    separate counter variable instead of the row number i.

  Example
    Input :
      5

    Output:
      *
      **
      ***
      ****
      *****

  Note
    star starts at 1 and star++ after every row.
    This style is useful later: a pyramid only changes star++
    into star += 2.
=====================================================================
*/

/*
#include <stdio.h>
int main()
{
  int n, star=1;
  scanf("%d", &n );

  for(int i =1 ; i<=n; i++)
  {
    for(int j= 1; j<=star; j++)
    {
      printf("*");
    }
    printf("\n");
    star++;
  }

  return 0;
}
*/


/*
=====================================================================
  Problem : Downward Star Pattern
=====================================================================

  Statement
    Read N and print the triangle upside down:

      ****
      ***
      **
      *

  Input
    One integer N

  Example
    Input :
      4

    Output:
      ****
      ***
      **
      *

  Note
    Same as the upward pattern, but the counter starts at n
    and decreases: int star = n; star--
=====================================================================
*/

/*
#include <stdio.h>
int main()
{
  int n;
  scanf("%d", &n );
  int star=n;
  for(int i =1 ; i<=n; i++)
  {
    for(int j= 1; j<=star; j++)
    {
      printf("*");
    }
    printf("\n");
    star--;
  }

  return 0;
}
*/


/*
=====================================================================
  Problem : Pyramid Pattern (spaces + stars)
=====================================================================

  Statement
    Read N and print a centered pyramid:

       *
      ***
     *****
    *******

  Input
    One integer N

  Example
    Input :
      4

    Output:
       *
      ***
     *****
    *******

  Note
    Every row = spaces FIRST, then stars, then newline.
      space = n-1 at first, space-- after each row
      star  = 1   at first, star  += 2 after each row

    star += 2, not star++ — a pyramid grows 1 star on EACH
    side, so the count goes 1, 3, 5, 7 ...
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
      for (int j = 1; j<=star; j++)
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
  Problem : Triangle with star++ (my wrong pyramid attempt)
=====================================================================

  Statement
    Same structure as the pyramid, but the counter increases
    by 1 instead of 2. What does it print?

  Example
    Input :
      4

    Output:
       *
      **
     ***
    ****

  Note (my mistake)
    star++ after the spaces does NOT make a pyramid — the stars
    grow 1, 2, 3, 4, which leans like a diagonal. A real pyramid
    needs star += 2 so both sides grow together.
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
      for (int j = 1; j<=star; j++)
      {
        printf("*");
      }
      printf("\n");
      star ++;
      space--;

    }
  return 0;
}
*/


/*
=====================================================================
  Problem : Sum of Two Values — does any pair add up to X?
=====================================================================

  Statement
    Read N, then N numbers, then a value X. Print YES if any two
    elements of the array sum to X, otherwise print NO.

  Input
    First line  : N
    Second line : N numbers
    Third line  : X

  Example
    Input :
      4
      2 7 11 15
      9

    Output:
      YES

  Note (my mistakes)
    1. Inner loop started at j = 0, so an element paired with
       ITSELF (i == j). Fix: j = i + 1.
    2. printf("YES") was inside the loop — a match found twice
       printed YESYES. Fix: set a flag, print once after.
    3. No break — after finding one pair the loops kept running.
=====================================================================
*/

/*
#include <stdio.h>
int main()
{
  int n;
  scanf("%d", &n );
  int a[n];
  for (int i =0; i<n; i++)
  {
    scanf("%d", &a[i] );
  }
  int x;
  scanf("%d", &x);
  int flag = 0;
  for(int i=0; i<n-1; i++)
  {
    for (int j =i+1; j<n; j++)
    {
      if (a[i] + a[j]==x )
      {
        flag = 1;
        break;
      }
    }
    if (flag == 1)
    {
      break;
    }
  }

  if(flag ==1)
  {
    printf("YES");
  }
  else
  {
    printf("NO");
  }

  return 0;
}
*/
