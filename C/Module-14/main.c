/*
  Module 14 — Functions: the 4 combinations (C)

  Each combination below is written as:
    1. a block comment  -> the question (Statement, Example, Note)
    2. a block comment  -> my answer code, kept commented out

  All answers are kept commented out.
  To run one, remove the block-comment markers around its code
  and wrap the other answers the same way.

  Combinations:
    1. return + parameter        int  add(int a, int b)
    2. return + no parameter     int  add()
    3. no return + parameter     void add(int a, int b)
    4. no return + no parameter  void add()
*/


/*
=====================================================================
  Problem : Combination 1 — return + parameter
=====================================================================

  Statement
    Write a function that takes two integers and returns their
    sum. main() reads two numbers, calls the function, and
    prints the returned total.

  Example
    Input :
      5 7

    Output:
      12

  Note
    Definition comes BEFORE main so the compiler already knows
    add() when main() calls it.
    return total; sends the value back; the caller stores it:
      int total = add(a, b);
=====================================================================
*/

/*
#include <stdio.h>

int add (int a, int b)
{
  int total = a+b;
  return total;
}

int main()
{
  int a, b;
  scanf("%d %d" , &a, &b);
  int total = add(a, b);
  printf("%d",total );
  return 0;
}
*/


/*
=====================================================================
  Problem : Combination 2 — return + no parameter
=====================================================================

  Statement
    Write a function that reads two integers itself, returns
    their sum, and main() prints the returned value.

  Example
    Input :
      5 7

    Output:
      12

  Note
    No parameters — the function does its own scanf().
    main() still gets the answer through return.
=====================================================================
*/

/*
#include <stdio.h>

int add ()
{
  int a, b;
  scanf("%d %d" , &a, &b);
  int total =a+b;
  return total;
}
int main()
{
  int total = add();
  printf("%d",total );
  return 0;
}
*/


/*
=====================================================================
  Problem : Combination 3 — no return + parameter
=====================================================================

  Statement
    Write a function that takes two integers and PRINTS their
    sum itself (gives nothing back to the caller).

  Example
    Input :
      5 7

    Output:
      12

  Note (my mistake)
    I first declared this as int add(int a, int b) with no
    return, and main did int total = add(a, b); — that stores an
    unpredictable garbage value.

    A function that returns nothing must be void:
      void add(int a, int b)

    Then main() can only call it as a statement:
      add(a, b);          // no variable can capture a result
=====================================================================
*/

/*
#include <stdio.h>

void add (int a, int b)
{
  int total =a+b;
  printf("%d",total );
}
int main()
{
  int a, b;
  scanf("%d %d" , &a, &b);
  add(a,b);
  return 0;
}
*/


/*
=====================================================================
  Problem : Combination 4 — no return + no parameter
=====================================================================

  Statement
    Write a void function with no parameters that reads two
    integers and prints their sum. main() just calls it.

  Example
    Input :
      5 7

    Output:
      12

  Note (my mistake)
    I first wrote main() as:
      int total = add();     // WRONG — add() is void

    A void call gives NO value, so it cannot be stored.
    Correct call:
      add();
=====================================================================
*/

/*
#include <stdio.h>

void add ()
{
  int a, b;
  scanf("%d %d" , &a, &b);
  int total =a+b;
  printf("%d",total );
}
int main()
{
  add();
  return 0;
}
*/
