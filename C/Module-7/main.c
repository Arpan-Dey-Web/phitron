/*
  Module 7 — Arrays problem set (C)

  Each problem below is written as:
    - statement in a block comment
    - solution code commented out

  All solutions are kept commented out.
  To run one, comment out the others and uncomment its code.
*/


/*
=====================================================================
  Concept : Basic Array — Declare, Assign, Access
=====================================================================

  Statement
    Declare an array of 10 integers, store 20 at index 2, and
    print that value.

  Note
    Syntax:  data_type name[size];

    int arr[10];   -> room for 10 ints, indexes 0 .. 9
    arr[2] = 20;   -> assign a value to index 2
    arr[2]         -> read the value at index 2
=====================================================================
*/

// #include <stdio.h>
//
// int main() {
//     int arr[10];
//
//     arr[2] = 20;
//     printf("%d", arr[2]);   // 20
//
//     return 0;
// }


/*
=====================================================================
  Problem : Take Input into an Array
=====================================================================

  Statement
    Read 5 integers from the user and store them in an array.

  Note
    &arr[i] is required in scanf() — scanf needs the memory
    address where it should store each value.
=====================================================================
*/

// #include <stdio.h>
//
// int main() {
//     int ar[5];
//
//     for (int i = 0; i <= 4; i++) {
//         scanf("%d", &ar[i]);
//     }
//
//     return 0;
// }


/*
=====================================================================
  Problem : Output of an Array
=====================================================================

  Statement
    Print all 5 elements of an array, one per line.

  Note (common mistake)
    printf("%d", &ar[i]) prints the MEMORY ADDRESS of ar[i],
    not its value — and %d is the wrong specifier for an address.

    Correct: printf("%d", ar[i])   (no &)
=====================================================================
*/

// #include <stdio.h>
//
// int main() {
//     int ar[5];
//
//     for (int i = 0; i <= 4; i++) {
//         printf("%d\n", ar[i]);   // value, not &ar[i]
//     }
//
//     return 0;
// }


/*
=====================================================================
  Problem : Reverse an Array
  Limits  : —
=====================================================================

  Statement
    Given N and then N numbers, print them in reverse order
    (last element first), one per line.

  Input
    First line  : N
    Second line : N numbers

  Example
    Input :
      3
      10 20 30

    Output:
      30
      20
      10

  Note
    int a[n] is a variable-length array (VLA): the size is decided
    at runtime. This is allowed in C99 and later.
    Last index is n - 1, so the reverse loop starts at i = n - 1.
=====================================================================
*/

// #include <stdio.h>
//
// int main() {
//     int n;
//     scanf("%d", &n);
//
//     int a[n];
//     for (int i = 0; i < n; i++) {
//         scanf("%d", &a[i]);
//     }
//
//     for (int i = n - 1; i >= 0; i--) {
//         printf("%d\n", a[i]);
//     }
//
//     return 0;
// }


/*
=====================================================================
  Problem : Sum of All Array Elements
=====================================================================

  Statement
    Given N and then N numbers, print the sum of all elements.

  Input
    First line  : N
    Second line : N numbers

  Example
    Input :
      3
      10 20 30

    Output:
      60

  Note
    sum is an accumulator: it starts at 0 and collects a running
    total inside the loop.
=====================================================================
*/

// #include <stdio.h>

// int main() {
//     int n;
//     scanf("%d", &n);

//     int arr[100]={0};
//     for (int i = 0; i < n; i++) {
//         scanf("%d", &arr[i]);
//     }

//     int sum = 0;
//     for (int i = 0; i < n; i++) {
//         sum += arr[i];
//     }

//     printf("%d", sum);

//     return 0;
// }
