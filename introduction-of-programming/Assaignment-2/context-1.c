/*
  Assignment 2 — Loops and Arrays (C)

  Each problem below is written as:
    - statement in a block comment
    - solution code commented out

  All solutions are kept commented out.
  To run one, comment out the others and uncomment its code.
*/


/*
=====================================================================
  Problem 1 : I Want More Assignments
=====================================================================

  Statement
    You will be given a positive integer N. Print
    "I Want More Assignments" N times, numbered from 1 to N.

  Input
    One line containing N.

  Constraints
    1 <= N <= 10^5

  Output
    N lines, each:  <i>. I Want More Assignments

  Samples
    Input : 5
    Output:
      1. I Want More Assignments
      2. I Want More Assignments
      3. I Want More Assignments
      4. I Want More Assignments
      5. I Want More Assignments

    Input : 3
    Output:
      1. I Want More Assignments
      2. I Want More Assignments
      3. I Want More Assignments
=====================================================================
*/

// #include <stdio.h>
//
// int main() {
//     int n;
//     scanf("%d", &n);
//
//     for (int i = 1; i <= n; i++) {
//         printf("%d. I Want More Assignments\n", i);
//     }
//
//     return 0;
// }


/*
=====================================================================
  Problem 2 : Positive Range or Negative Range
=====================================================================

  Statement
    You will be given an integer N. If N is positive, print from
    1 to N. Otherwise (N <= 0), print from N to 0.
    A positive number is strictly greater than 0.

  Input
    One line containing N.

  Constraints
    -10^5 <= N <= 10^5

  Output
    The values with a space between them.

  Samples
    Input : 5
    Output: 1 2 3 4 5

    Input : -4
    Output: -4 -3 -2 -1 0

  Note
    For N = 0 the second branch prints just "0".
=====================================================================
*/

// #include <stdio.h>
//
// int main() {
//     int n;
//     scanf("%d", &n);
//
//     if (n > 0) {
//         for (int i = 1; i <= n; i++) {
//             printf("%d ", i);
//         }
//     } else if (n < 0) {
//         for (int j = n; j <= 0; j++) {
//             printf("%d ", j);
//         }
//     } else {
//         printf("%d", n);    // n == 0
//     }
//
//     return 0;
// }


/*
=====================================================================
  Problem 3 : Odd Indexes in Reverse
=====================================================================

  Statement
    You will be given a positive integer N and an array A of size
    N (indexes start from 0). Print all values at ODD indexes in
    reverse order.

    Example: input array 10 20 30 40 50 60 has odd indexes
    5, 3, 1 holding values 60, 40, 20 — printed as: 60 40 20

  Input
    First line  : N
    Second line : the array A

  Constraints
    1 <= N <= 10^5
    1 <= A[i] <= 1000

  Output
    The values at odd indexes, reverse order, space separated.

  Samples
    Input :
      5
      10 20 30 40 50

    Output:
      40 20

    Input :
      6
      0 1 2 3 4 5

    Output:
      5 3 1

  Note
    Odd index means i % 2 == 1 (indexes 1, 3, 5, ...).
    Reverse order: loop from i = n-1 down to 0.
=====================================================================
*/

// #include <stdio.h>
//
// int main() {
//     int n;
//     scanf("%d", &n);
//
//     int currentNumber[n];
//
//     for (int i = 0; i < n; i++) {
//         scanf("%d", &currentNumber[i]);
//     }
//
//     for (int i = n - 1; i >= 0; i--) {
//         if (i % 2 == 1) {
//             printf("%d ", currentNumber[i]);
//         }
//     }
//
//     return 0;
// }


/*
=====================================================================
  Problem 4 : Sum of Positive and Negative
=====================================================================

  Statement
    You will be given a positive integer N and N numbers. Output
    the sum of the positive numbers and the sum of the negative
    numbers, separated by a space.

  Input
    First line  : N
    Second line : N values named V

  Constraints
    1 <= N <= 10^5
    -1000 <= V <= 1000

  Output
    <sum of positives> <sum of negatives>

  Samples
    Input :
      6
      5 -3 9 -10 2 8

    Output:
      24 -13

    Input :
      4
      1 0 -5 3

    Output:
      4 -5

  Note
    0 is neither positive nor negative — it is skipped.
    The loop must read exactly N values: i < n, not i <= n
    (i <= n would read N + 1 values).
=====================================================================
*/

// #include <stdio.h>
//
// int main() {
//     int n;
//     scanf("%d", &n);
//
//     int positiveSum = 0, negativeSum = 0;
//
//     for (int i = 0; i < n; i++) {
//         int currentNumber;
//         scanf("%d", &currentNumber);
//
//         if (currentNumber > 0) {
//             positiveSum += currentNumber;
//         } else if (currentNumber < 0) {
//             negativeSum += currentNumber;
//         }
//     }
//
//     printf("%d %d", positiveSum, negativeSum);
//
//     return 0;
// }


/*
=====================================================================
  Problem 5 : Update Index then Print Reverse
=====================================================================

  Statement
    You will be given a positive integer N, an array A of size N,
    then two values X and V. Change the value at index X to V,
    then print the whole array in reverse order.

    Indexes start from 0.

  Input
    First line  : N
    Second line : the array A
    Third line  : X and V

  Constraints
    1 <= N <= 10^5
    1 <= A[i] <= 100
    0 <= X < N
    1 <= V <= 100

  Output
    The final array in reverse order, space separated.

  Samples
    Input :
      5
      10 20 30 40 50
      1 100

    Output:
      50 40 30 100 10

    Explanation: after arr[1] = 100 the array is
    10 100 30 40 50, reversed: 50 40 30 100 10.

    Input :
      5
      10 20 30 40 50
      4 10

    Output:
      10 40 30 20 10
=====================================================================
*/

// #include <stdio.h>
//
// int main() {
//     int n;
//     int indexNumber, value;
//     scanf("%d", &n);
//
//     int arr[n];
//
//     for (int i = 0; i < n; i++) {
//         scanf("%d", &arr[i]);
//     }
//
//     scanf("%d %d", &indexNumber, &value);
//     arr[indexNumber] = value;
//
//     for (int i = n - 1; i >= 0; i--) {
//         printf("%d ", arr[i]);
//     }
//
//     return 0;
// }
