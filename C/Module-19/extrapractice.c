/*
  Module 19 — Extra Practice: Recursion Problems (C)

  Extra-practice set after the Module 19 session. Each problem
  below is written as:
    1. a block comment  -> the statement (Statement, Input, Output, Examples, Note)
    2. a block comment  -> my solution, kept commented out

  All solutions are kept commented out.
  To run one, remove the block-comment markers around its code
  and wrap the others the same way.

  Problems:
    K. Max Number     — recursive maximum of an array
    L. Summation      — recursive sum (long long)
    J. Lucky Division — is n divisible by a lucky number?
    B. Watermelon     — split w into two even positive parts
*/


/*
=====================================================================
  Problem : K. Max Number
  Limits  : 1 second, 64 MB
=====================================================================

  Statement
    Given a number N and an array A of N numbers, print the
    maximum value in this array. Solve it using recursion.

  Input
    First line  : N (1 <= N <= 1000)
    Second line : N numbers (-1e9 <= Ai <= 1e9)

  Output
    The maximum value in the array.

  Example
    Input :
      5
      1 -3 5 4 -6
    Output:
      5

  Idea
    find_max_number(arr, n) = max of the first n elements:

        base      : n == 1            -> arr[0] is the only max
        otherwise : max of the REST (arr[0..n-2]) compared
                    with arr[n-1]

    The recursion shrinks the array from the RIGHT side, so the
    comparison happens on the way back:

        max_of_rest = find_max_number(arr, n - 1);
        arr[n - 1] > max_of_rest ? arr[n - 1] : max_of_rest

    This is the test in input.txt / output.txt (5 -> 5).
=====================================================================
*/

/*
#include <stdio.h>

int find_max_number(int arr[], int n)
{
    if (n == 1)                 // base case: one element
    {
        return arr[0];
    }

    int max_of_rest = find_max_number(arr, n - 1);

    if (arr[n - 1] > max_of_rest)
    {
        return arr[n - 1];
    }
    else
    {
        return max_of_rest;
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int max_val = find_max_number(arr, n);
    printf("%d\n", max_val);

    return 0;
}
*/


/*
=====================================================================
  Problem : L. Summation
  Limits  : 1 second, 256 MB
=====================================================================

  Statement
    Given a number N and an array A of N numbers, print the
    summation of the array elements. Solve it using recursion.

  Input
    First line  : N (1 <= N <= 1000)
    Second line : N numbers (-1e9 <= Ai <= 1e9)

  Output
    The sum of the N numbers.

  Examples
    Input :
      4
      1 4 2 7
    Output:
      14

    Input :
      4
      5 5 5 5
    Output:
      20

  Note — why long long
    Worst case: 1000 values of -1e9 = -1e12, far beyond int
    (max about 2.1e9). long long holds it, so the array, the
    return type and the %scanf/%printf specifiers are all
    long long / %lld.

    Base case n == 0 -> sum of nothing is 0. Every call adds
    one element on the way back:

        find_sum(arr, n) = arr[n-1] + find_sum(arr, n-1)
=====================================================================
*/

/*
#include <stdio.h>

long long find_sum(long long arr[], int n)
{
    if (n == 0)                 // base case: empty sum = 0
    {
        return 0;
    }
    return arr[n - 1] + find_sum(arr, n - 1);
}

int main()
{
    int n;
    scanf("%d", &n);

    long long arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &arr[i]);
    }

    long long total_sum = find_sum(arr, n);
    printf("%lld\n", total_sum);

    return 0;
}
*/


/*
=====================================================================
  Problem : J. Lucky Division
  Limits  : 2 seconds, 256 MB
=====================================================================

  Statement
    Lucky numbers are positive integers whose decimal
    representation contains only the digits 4 and 7 (47, 744, 4
    are lucky; 5, 17, 467 are not). A number is almost lucky if
    it can be evenly divided by SOME lucky number. Print YES if
    n is almost lucky, otherwise NO.

  Input
    One integer n (1 <= n <= 1000)

  Output
    YES or NO

  Examples
    Input : 47   Output: YES   (47 is lucky, divides itself)
    Input : 16   Output: YES   (16 / 4 = 4)
    Input : 78   Output: NO

  Note
    No recursion needed here — just try every candidate
    divisor. All lucky numbers up to 1000 are:

        4, 7, 44, 47, 74, 77,
        444, 447, 474, 477, 744, 747, 774, 777

    (the next one, 4444, is already bigger than 1000), so a
    fixed array of 14 values covers every case.

    n % lucky[i] == 0  ->  print YES and stop (return 0).
    n = 1 divides none of them -> NO.
=====================================================================
*/

/*
#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int lucky[] = {4, 7, 44, 47, 74, 77, 444, 447, 474, 477,
                   744, 747, 774, 777};
    int size = 14;

    for (int i = 0; i < size; i++)
    {
        if (n % lucky[i] == 0)
        {
            printf("YES\n");
            return 0;           // found a divisor, done
        }
    }

    printf("NO\n");
    return 0;
}
*/


/*
=====================================================================
  Problem : B. Watermelon
  Limits  : 1 second, 64 MB
=====================================================================

  Statement
    A watermelon weighs w kilos. Pete and Billy want to split
    it into two parts, each of EVEN weight and each of POSITIVE
    weight (the parts do not have to be equal). Print YES if
    that is possible, otherwise NO.

  Input
    One integer w (1 <= w <= 100)

  Output
    YES or NO

  Examples
    Input : 8    Output: YES   (2 + 6, or 4 + 4)
    Input : 16   Output: YES
    Input : 78   Output: NO

  Note — the two conditions
    Both parts even  ->  their SUM is even  ->  w must be even
    Both parts > 0   ->  w cannot be 2 (the only split is 1 + 1,
                        and 1 is odd)

    So exactly:

        w > 2 && w % 2 == 0   ->  YES
        otherwise             ->  NO

    w = 1: odd -> NO.  w = 2: even but not > 2 -> NO.
    w = 4: 2 + 2 -> YES.
=====================================================================
*/

/*
#include <stdio.h>

int main()
{
    int w;
    scanf("%d", &w);

    if (w > 2 && w % 2 == 0)
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
