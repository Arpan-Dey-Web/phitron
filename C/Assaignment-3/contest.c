/*
  Assignment 3 — Functions and Patterns (C)

  Each problem below is written as:
    - statement in a block comment
    - solution code commented out

  All solutions are kept commented out.
  To run one, comment out the others and uncomment its code.
*/


/*
=====================================================================
  Problem 1 : odd_even() — Count Even and Odd Values
=====================================================================

  Statement
    Given an array A of size N, write a function odd_even() that
    takes the input INSIDE the function (the function returns
    nothing). Count the even and the odd values and print both
    counts inside the function.

  Input
    First line  : N (1 <= N <= 1000)
    Second line : N numbers (0 <= A[i] <= 1e9)

  Output
    number of even elements, then number of odd elements,
    separated by a space.

  Examples
    Input :
      5
      1 2 3 4 5
    Output:
      2 3

    Input :
      6
      0 4 0 6 5 3
    Output:
      4 2

  Note
    % 2 == 0 is the even test; everything else is odd, so an
    else branch is enough — no second condition is needed.

    The reading happens inside odd_even() as the statement
    demands, and main() only calls the function.
=====================================================================
*/

// #include <stdio.h>
//
// void odd_even()
// {
//     int num, even = 0, odd = 0;
//     scanf("%d", &num);
//
//     for (int i = 0; i < num; i++)
//     {
//         int n;
//         scanf("%d", &n);
//
//         if (n % 2 == 0)
//         {
//             even++;
//         }
//         else
//         {
//             odd++;
//         }
//     }
//
//     printf("%d %d", even, odd);
// }
//
// int main()
// {
//     odd_even();
//     return 0;
// }


/*
=====================================================================
  Problem 2 : is_palindrome() — Return 1 or 0
=====================================================================

  Statement
    Take a string S as input in main(). Write a function
    is_palindrome() that receives the string and returns an
    integer: 1 if the string is a palindrome, 0 otherwise. Print
    "Palindrome" or "Not Palindrome" in main() from that value.

    A palindrome reads the same forward and backward.

  Input
    One string S (1 <= |S| <= 1000), no spaces.

  Output
    Palindrome  or  Not Palindrome

  Examples
    Input : madam     Output: Palindrome
    Input : abccba    Output: Palindrome
    Input : x         Output: Palindrome
    Input : abca      Output: Not Palindrome

  Note
    The two indexes start at opposite ends and walk toward each
    other — the two-pointer technique from Module 9/11.

    My loop runs the full length with i++ and j--, which compares
    every pair twice; stopping at i < j is enough because by then
    all pairs have already been checked. It still returns the
    right answer, but i < j is cleaner.

    main() only PRINTS from the returned 0/1 — the decision is
    made inside the function, exactly as the statement requires.
=====================================================================
*/

// #include <stdio.h>
// #include <string.h>
//
// int is_palindrome(char str[])
// {
//     int strLength = strlen(str);
//     int isPalindrome = 1;
//
//     for (int i = 0, j = strLength - 1; i < j; i++, j--)
//     {
//         if (str[i] != str[j])
//         {
//             isPalindrome = 0;
//             break;
//         }
//     }
//
//     return isPalindrome;
// }
//
// int main()
// {
//     char str[1005];
//     scanf("%s", str);
//
//     int isPalindrome = is_palindrome(str);
//     if (isPalindrome == 0)
//     {
//         printf("Not Palindrome");
//     }
//     else
//     {
//         printf("Palindrome");
//     }
//
//     return 0;
// }


/*
=====================================================================
  Problem 3 : count_before_one() — Elements Before the First 1
=====================================================================

  Statement
    Given an array A and its size N, write a function
    count_before_one() that receives the array and its size and
    returns how many elements appear BEFORE the first 1. Print
    that count in main().

  Input
    First line  : N (1 <= N <= 1000)
    Second line : N numbers (0 <= A[i] <= 1000)

  Output
    The number of elements before the first 1.

  Examples
    Input :
      5
      5 4 3 1 2
    Output:
      3

    Input :
      5
      1 2 3 4 5
    Output:
      0

  Note
    The loop breaks the moment arr[i] == 1, so the counter holds
    exactly the elements seen before it.

    Edge case: if the array contains no 1 at all, the loop runs
    to the end and returns N — every element is "before the first
    1", because there is none.

    The array is passed as int arr[] — a function receiving an
    array gets a pointer to the caller's data (pass by reference),
    so no copy of N integers is made (see Module 15).
=====================================================================
*/

// #include <stdio.h>
//
// int count_before_one(int arr[], int length)
// {
//     int number_Of_Elements = 0;
//
//     for (int i = 0; i < length; i++)
//     {
//         if (arr[i] == 1)
//         {
//             break;
//         }
//         number_Of_Elements++;
//     }
//
//     return number_Of_Elements;
// }
//
// int main()
// {
//     int n;
//     scanf("%d", &n);
//
//     int arr[n];
//     for (int i = 0; i < n; i++)
//     {
//         scanf("%d", &arr[i]);
//     }
//
//     int number_Of_Elements = count_before_one(arr, n);
//     printf("%d", number_Of_Elements);
//
//     return 0;
// }


/*
=====================================================================
  Problem 4 : Number Pattern (downward counting rows)
=====================================================================

  Statement
    Given a positive integer N, print the pattern below.

  Input
    One integer N (1 <= N <= 9).

  Output
    N rows: row i starts with (N - i) spaces, then the numbers
    i, i-1, ..., 1 with no spaces between them.

  Examples
    Input : 4
    Output:
       1
      21
     321
    4321

    Input : 5
    Output:
        1
       21
      321
     4321
    54321

  Note — my first attempt was broken in TWO ways
    for (int j = 1; j >= i; j--)   → starts at 1, so for i > 1
                                     the condition fails at once
                                     and NOTHING is printed
    int space = n - 1;             → never decreased, so every
                                     row got the same indent

    The two correct ideas are equivalent:
        spaces = n - i   (formula, no extra variable)
        space starts at n-1 and is decreased after each row
    Either works; the formula version below is the shorter one.
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
//         for (int k = 1; k <= n - i; k++)   // leading spaces
//         {
//             printf(" ");
//         }
//
//         for (int j = i; j >= 1; j--)        // i, i-1, ... 1
//         {
//             printf("%d", j);
//         }
//
//         printf("\n");
//     }
//
//     return 0;
// }


/*
=====================================================================
  Problem 5 : Diamond Pattern with # and -
=====================================================================

  Statement
    Given a positive integer N, print the diamond pattern: the
    top half grows to the middle row, then it shrinks back.
    Odd-numbered levels print '#', even levels print '-'.

  Input
    One integer N (1 <= N <= 100).

  Output
    2 * N - 1 lines forming the diamond.

  Examples
    Input : 4
    Output:
       #
      ---
     #####
    -------
     #####
      ---
       #

    Input : 1
    Output:
      #

    Input : 7
    Output:
          #
         ---
        #####
       -------
      #########
     -----------
    #############
     -----------
      #########
       -------
        #####
         ---
          #

  Idea
    Rows 1..N go up, rows N+1..2N-1 come back down. One loop
    over 2N-1 lines with

        level = (i <= N) ? i : 2N - i        (height of that row)

    gives the shape for BOTH halves — spaces are N - level and
    the symbol count is 2 * level - 1.

  Note
    My earlier version printed the upper half and the lower half
    in two separate loops with their own space/hash counters.
    It works too, but it repeats the same logic twice; the level
    trick above keeps one loop and one pair of counters.
=====================================================================
*/

// #include <stdio.h>
//
// int main()
// {
//     int N;
//     scanf("%d", &N);
//
//     for (int i = 1; i <= 2 * N - 1; i++)
//     {
//         int level;
//         if (i <= N)
//         {
//             level = i;               // still growing
//         }
//         else
//         {
//             level = 2 * N - i;       // coming back down
//         }
//
//         for (int j = 1; j <= N - level; j++)   // indent
//         {
//             printf(" ");
//         }
//
//         int count = 2 * level - 1;             // width
//         for (int j = 1; j <= count; j++)
//         {
//             if (level % 2 == 1)
//             {
//                 printf("#");
//             }
//             else
//             {
//                 printf("-");
//             }
//         }
//
//         printf("\n");
//     }
//
//     return 0;
// }
