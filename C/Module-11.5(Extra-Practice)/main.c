/*
  Module 11.5 — Extra Practice: Frequency Array + String Compare (C)

  Each problem below is written as:
    1. a block comment  -> the question (Statement, Input, Example, Note)
    2. a block comment  -> my answer code, kept commented out

  All answers are kept commented out.
  To run one, remove the block-comment markers around its code
  and wrap the other answers the same way.
*/


/*
=====================================================================
  Problem : Frequency Array
=====================================================================

  Statement
    Read N, then N numbers (each between 0 and 5). Count how many
    times every value appears using a frequency array, then print
    each value with its count.

  Input
    First line  : N
    Second line : N numbers

  Example
    Input :
      6
      1 3 1 5 3 1

    Output:
      0 -> 0
      1 -> 3
      2 -> 0
      3 -> 2
      4 -> 0
      5 -> 1

  Note
    fre[a[i]]++ counts one more occurrence of a[i].
    fre[] must start with {0} — otherwise it begins with garbage.
    Size 6 only fits values 0..5; any bigger input value would go
    out of bounds.
=====================================================================
*/

/*
#include <stdio.h>
int main()
{
  int n;
  scanf("%d",&n );
  int a[n];
  for (int i=0; i<n; i++)
  {
    scanf("%d", &a[i]);
  }

  int fre[6] ={0};

  for (int i =0 ;i<n; i++)
  {
    fre[a[i]]++;
  }

  for (int i =0; i<6 ; i++)
  {
    printf("%d -> %d\n",i,fre[i]);
  }
  return 0;
}
*/


/*
=====================================================================
  Problem : C. Compare — smallest lexicographical string
  Limits  : 1 second, 256 MB
=====================================================================

  Statement
    Given two strings X and Y, print the smallest lexicographical
    one. Lexicographical order = dictionary order of the letters.
    If both are equal, print any of them.

  Input
    One line with two lowercase strings X and Y
    (1 <= |X|, |Y| <= 20).

  Example
    Input :
      acm
      acpc

    Output:
      acm

  Note (my first attempt)
    My code printed the strcmp result with %d — the run gave -3,
    which is the comparison number, NOT the answer. The problem
    wants the smaller STRING.

    Correct approach:
      lowest = strcmp(a, b);
      if (lowest <= 0) print a;   else print b;

    strcmp only gives a sign (< 0, = 0, > 0); never print it as
    the answer. Fixed version is in readme.md.
=====================================================================
*/

/*
#include <stdio.h>
#include <string.h>
int main()
{
  char a[25], b[25];
  scanf("%s %s", a,b );
  // printf("%s %s",a,b);

  int len = strlen(a);
  // printf("%d", len);

  int lowest = strcmp(a,b);
  printf("%d" ,lowest);
  // for (int i =0; i<len; i++)
  // {
  // }

  return 0;
}
*/
