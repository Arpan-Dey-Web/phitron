/*
  Module 14 — Extra Practice: Functions in Problems (C)

  Each problem below is written as:
    1. a block comment  -> the question (Statement, Example, Note)
    2. a block comment  -> my answer code, kept commented out

  All answers are kept commented out.
  To run one, remove the block-comment markers around its code
  and wrap the other answers the same way.

  Problems:
    - M. Distinct Numbers (count distinct values with a function)
    - E. Swap (print two numbers swapped, using a function)
*/


/*
=====================================================================
  Problem : M. Distinct Numbers
  Limits  : 1 second, 256 MB
=====================================================================

  Statement
    Given an array A of size N, print the number of distinct
    numbers in the array.
    Solve this problem using a function.

  Input
    First line  : N (0 <= N <= 1000)
    Second line : N numbers (-1000 <= Ai <= 1000)

  Example
    Input 1 :
      3
      1 2 2

    Output 1:
      2

    Input 2 :
      5
      1 8 9 2 9

    Output 2:
      4

  Note
    Idea: a frequency array (Module 11.5) counts occurrences;
    every value whose count is >= 1 is one distinct number.
    Put the counting/counting-up logic inside a function because
    the statement says "solve using function".
=====================================================================
*/

/*
  Solution not written yet — add it here after solving:
#include <stdio.h>

int main()
{
    return 0;
}
*/


/*
=====================================================================
  Problem : E. Swap
  Limits  : 1 second, 64 MB
=====================================================================

  Statement
    Given two numbers X and Y, print X and Y after swapping
    them.
    Solve this problem using a function.

  Input
    One line with two numbers X and Y (0 <= X, Y <= 100000)

  Example
    Input :
      5 2

    Output:
      2 5

  Note
    The function prints the values in swapped order:
      temp = a; firstNumber = b; secondNumber = temp;

    Pass by value: main()'s own a and b do NOT change — the
    function only receives copies. To really swap the caller's
    variables, pointers are needed (a later topic).
=====================================================================
*/

/*
#include <stdio.h>

int swap (int a, int b)
{
  int temp=0, firstNumber, secondNumber;
  temp = a;
  firstNumber=b;
  secondNumber=temp;
  printf("%d %d", firstNumber, secondNumber );
  return 0;
}

int main()
{
  int a, b;
  scanf("%d %d", &a, &b );
  int result = swap(a, b);
  return 0;
}
*/
