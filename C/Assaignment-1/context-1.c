/*
  Assignment 1 — Panta Vat (C)

  Each problem below is written as:
    - statement in a block comment
    - solution code commented out

  All solutions are kept commented out.
  To run one, comment out the others and uncomment its code.
*/


/*
=====================================================================
  Problem 1 : Panta Vat — Print Fixed Lines
=====================================================================

  Statement
    Print the following lines exactly as they are:

      Hello, world! I am learning C programming language. ^_^
      Programming is fun and challenging. /\/\/\
      I want to give my 100% dedication to learn!<TAB>I will succeed one day.

    The gap in the last line is a TAB character, not spaces.

  Input
    There is no input.

  Output
    The three lines above.

  Note
    In a C string:
      \\  prints one backslash \
      \t  prints a tab
      %%  prints one percent sign %  (plain % would start a format
           specifier and break printf)
=====================================================================
*/

// #include <stdio.h>
//
// int main() {
//     printf("Hello, world! I am learning C programming language. ^_^\n");
//     printf("Programming is fun and challenging. /\\/\\/\\\n");
//     printf("I want to give my 100%% dedication to learn!\tI will succeed one day.\n");
//
//     return 0;
// }


/*
=====================================================================
  Problem 2 : Multiplication
=====================================================================

  Statement
    You will be given two integers A and B. Output their
    multiplication.

  Input
    One line containing A and B.

  Constraints
    -10^9 <= A, B <= 10^9

  Output
    The value of A * B.

  Samples
    Input : 10 50          -> Output: 500
    Input : 10000000 10000000 -> Output: 100000000000000
    Input : -100 62        -> Output: -6200

  Note
    A * B can reach 10^18, which does not fit in a 32-bit int.
    long long (typically 64-bit) is required. %lld is its
    format specifier.
=====================================================================
*/

// #include <stdio.h>
//
// int main() {
//     long long a, b;
//     scanf("%lld %lld", &a, &b);
//
//     printf("%lld", a * b);
//
//     return 0;
// }


/*
=====================================================================
  Problem 3 : Divisible by 3
=====================================================================

  Statement
    You will be given a non-negative integer N. Tell whether it is
    divisible by 3. If yes, output "YES", otherwise "NO".

  Input
    One line containing N.

  Constraints
    0 <= N <= 10^9

  Output
    "YES" or "NO".

  Samples
    Input : 33 -> Output: YES
    Input : 29 -> Output: NO
    Input : 0  -> Output: YES    (0 is divisible by 3)
=====================================================================
*/

// #include <stdio.h>
//
// int main() {
//     int n;
//     scanf("%d", &n);
//
//     if (n % 3 == 0) {
//         printf("YES");
//     } else {
//         printf("NO");
//     }
//
//     return 0;
// }
//
// Note: 10^9 fits in a typical int (max ~2.1 * 10^9), so int is safe here.


/*
=====================================================================
  Problem 4 : Divisible by Both 3 and 7
=====================================================================

  Statement
    You will be given a non-negative integer N. Print all numbers
    from 1 to N that are divisible by both 3 and 7.

  Input
    One line containing N.

  Constraints
    21 <= N <= 10000

  Output
    Each matching number on its own line.

  Samples
    Input : 30
    Output: 21

    Input : 50
    Output:
      21
      42

    Input : 100
    Output:
      21
      42
      63
      84

  Note
    Divisible by 3 AND 7 means divisible by 21, so the condition
    i % 21 == 0 is equivalent (and shorter).
=====================================================================
*/

// #include <stdio.h>
//
// int main() {
//     int n;
//     scanf("%d", &n);
//
//     for (int i = 1; i <= n; i++) {
//         if (i % 3 == 0 && i % 7 == 0) {
//             printf("%d\n", i);
//         }
//     }
//
//     return 0;
// }


/*
=====================================================================
  Problem 5 : Punjabi and Shoes
=====================================================================

  Statement
    You will be given an integer N (money in Taka).

    - Buy a Punjabi only if N > 1000. After buying, 1000 is
      subtracted from N.
    - Buy shoes only if at least 500 Taka remains after the
      Punjabi purchase.
    - If you buy shoes, Alisa also buys shoes.

    Print, each on its own line:
      "I will buy Punjabi"           if you buy a Punjabi
      "I will buy new shoes"         if you buy shoes
      "Alisa will buy new shoes"     if Alisa buys shoes
      "Bad luck!"                    if no Punjabi is bought

  Input
    One line containing N.

  Constraints
    1 <= N <= 2^31

  Samples
    Input : 1000
    Output: Bad luck!          (1000 is NOT > 1000)

    Input : 1450
    Output:
      I will buy Punjabi       (1450 - 1000 = 450 left, < 500)

    Input : 1500
    Output:
      I will buy Punjabi
      I will buy new shoes
      Alisa will buy new shoes (1500 - 1000 = 500 left, >= 500)

  Note
    N can be up to 2^31 = 2147483648, which is just above the
    maximum of a 32-bit int (2147483647). Use long long to be
    safe.
=====================================================================
*/

// #include <stdio.h>
//
// int main() {
//     long long n;
//     scanf("%lld", &n);
//
//     if (n > 1000) {
//         printf("I will buy Punjabi\n");
//         n -= 1000;
//
//         if (n >= 500) {
//             printf("I will buy new shoes\n");
//             printf("Alisa will buy new shoes\n");
//         }
//     } else {
//         printf("Bad luck!\n");
//     }
//
//     return 0;
// }
