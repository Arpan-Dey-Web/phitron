/*
  Module 6 — Loops problem set (C)

  Each problem below is written as:
    - statement in a block comment
    - solution code commented out (some problems keep more than
      one version, showing how the solution evolved)

  All solutions are kept commented out.
  To run one, comment out the others and uncomment its code.

  Quiz: see quiz.md in this folder
*/


/*
=====================================================================
  Concept : Pre and Post Increment
=====================================================================

  Statement
    x++ (post-increment)  -> use the current value first, then +1
    ++x (pre-increment)   -> +1 first, then use the new value

  Demo
    x = 10, y = x++  -> y = 10, x = 11
    z = ++y          -> y = 11, z = 11
=====================================================================
*/

/*
#include <stdio.h>

int main() {
    int x = 10;

//      post-increment: y takes the old value (10), x becomes 11
    int y = x++;
    printf("%d %d\n", x, y);

//      pre-increment: y becomes 11 first, then z = 11
    int z = ++y;
    printf("%d %d %d", x, y, z);

    return 0;
}
*/


/*
=====================================================================
  Problem : Print Even Numbers from 1 to N
  Limits  : —
=====================================================================

  Statement
    Given a number N. Print all even numbers between 1 and N
    inclusive, in separate lines.

  Input
    One line containing a number N (1 <= N <= 10^3).

  Output
    Print the answer as required. If there are no even numbers,
    print -1.

  Examples
    Input : 10
    Output:
      2
      4
      6
      8
      10

    Input : 5
    Output:
      2
      4
=====================================================================
*/

/*
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    if (n == 1) {
        printf("-1");
    } else {
        for (int i = 1; i <= n; i++) {
            if (i % 2 == 0) {
                printf("%d\n", i);
            }
        }
    }

    return 0;
}

// Note: n == 1 is the only value with no even numbers.
// Alternative: start at 2 and step by 2 (i += 2).
*/


/*
=====================================================================
  Problem : C. Even, Odd, Positive and Negative
  Limits  : 1 second, 256 MB
=====================================================================

  Statement
    Given N numbers. Count how many of these values are even, odd,
    positive and negative.

  Input
    First line contains one number N (1 <= N <= 10^3), the number
    of values.
    Second line contains N numbers (-10^5 <= Xi <= 10^5).

  Output
    Print four lines:
      Even: X
      Odd: X
      Positive: X
      Negative: X

  Example
    Input :
      5
      -5 0 -3 -4 12

    Output:
      Even: 3
      Odd: 2
      Positive: 1
      Negative: 3

  Note
    Even numbers : 0, -4, 12
    Odd numbers  : -5, -3
    Positive     : 12
    Negative     : -5, -3, -4
    (0 is even, but 0 is neither positive nor negative)
=====================================================================
*/

/*
#include <stdio.h>

int main() {
    int takeInput;
    int input;
    int even = 0, odd = 0, positive = 0, negative = 0;

    scanf("%d", &takeInput);

    for (int i = 1; i <= takeInput; i++) {
        scanf("%d", &input);

        if (input > 0) {
            positive += 1;
        } else if (input < 0) {
            negative += 1;
        }

        if (input % 2 == 0) {
            even += 1;
        } else {
            odd += 1;
        }
    }

    printf("Even: %d\n", even);
    printf("Odd: %d\n", odd);
    printf("Positive: %d\n", positive);
    printf("Negative: %d\n", negative);

    return 0;
}
*/


/*
=====================================================================
  Problem : D. Fixed Password
  Limits  : 1 second, 256 MB
=====================================================================

  Statement
    Given multiple lines, each containing a number X which is a
    password. Print "Wrong" if the password is incorrect, otherwise
    print "Correct" and terminate the program.

    The correct password is the number 1999.

  Input
    The input contains several passwords, each on its own line.
    Each line contains a number X (10^3 <= X <= 10^4 - 1).

  Output
    Print "Wrong" for each wrong password, or "Correct" when the
    right password is typed.

  Example
    Input :
      2200
      1020
      1999
      1000
      9999

    Output:
      Wrong
      Wrong
      Correct

  Note
    EOF = End Of File. scanf() returns EOF when there is no more
    input to read.
=====================================================================
*/

/*
// Version 1: while loop reading until EOF

#include <stdio.h>

int main() {
    int x;

    while (scanf("%d", &x) != EOF) {
        if (x == 1999) {
            printf("Correct\n");
            break;
        } else {
            printf("Wrong\n");
        }
    }

    return 0;
}
*/


/*
// Version 2: same logic with a for loop (empty update section)

#include <stdio.h>

int main() {
    int x;

    for (; scanf("%d", &x) != EOF; ) {
        if (x == 1999) {
            printf("Correct\n");
            break;
        } else {
            printf("Wrong\n");
        }
    }

    return 0;
}
*/


/*
=====================================================================
  Problem : E. Max
  Limits  : 1 second, 256 MB
=====================================================================

  Statement
    Given a number N, and N numbers, find the maximum number among
    these N numbers.

  Input
    First line contains a number N (1 <= N <= 10^3).
    Second line contains N numbers Xi (0 <= Xi <= 10^9).

  Output
    Print the maximum number.

  Example
    Input :
      5
      1 8 5 7 5

    Output:
      8
=====================================================================
*/

/*
// Version 1: start from 0 — safe here because every Xi >= 0

#include <stdio.h>

int main() {
    int max = 0;
    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        int val;
        scanf("%d", &val);
        if (val > max) {
            max = val;
        }
    }

    printf("%d", max);
    return 0;
}
*/


/*
// Version 2: start from INT_MIN — the general way (works for
// negative numbers too)

#include <stdio.h>
#include <limits.h>

int main() {
    int max = INT_MIN;
    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        int val;
        scanf("%d", &val);
        if (val > max) {
            max = val;
        }
    }

    printf("%d", max);
    return 0;
}
*/


/*
=====================================================================
  Problem : Multiplication Table
  Limits  : —
=====================================================================

  Statement
    Given a number N, print its multiplication table from 1 to 12.

  Example
    Input : 5
    Output:
      5 * 1 = 5
      5 * 2 = 10
      ...
      5 * 12 = 60
=====================================================================
*/

/*
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 1; i <= 12; i++) {
        printf("%d * %d = %d\n", n, i, n * i);
    }

    return 0;
}
*/


/*
=====================================================================
  Problem : Q. Digits
  Limits  : 1 second, 256 MB
=====================================================================

  Statement
    Given a number N. Print the digits of that number from right to
    left, separated by space.

  Input
    First line contains a number T (1 <= T <= 10), the number of
    test cases.
    Next T lines contain a number N (0 <= N <= 10^9).

  Output
    For each test case, print one line containing the digits of the
    number separated by space.

  Example
    Input :
      4
      121
      39
      123456
      1200

    Output:
      1 2 1
      9 3
      6 5 4 3 2 1
      0 0 2 1
=====================================================================
*/

/*
// Version 1: while loop
// n % 10 prints the last digit, n /= 10 removes it.
// Bug kept in mind: when n == 0 the loop body never runs, so this
// version prints nothing for input 0 (the problem allows N = 0).

#include <stdio.h>

int main() {
    int t;
    int n;
    scanf("%d", &t);

    for (int i = 1; i <= t; i++) {
        scanf("%d", &n);

        while (n != 0) {
            printf("%d ", n % 10);
            n /= 10;
        }
        printf("\n");
    }

    return 0;
}
*/


/*
// Version 2: while loop + special case for n == 0

#include <stdio.h>

int main() {
    int t;
    int n;
    scanf("%d", &t);

    for (int i = 1; i <= t; i++) {
        scanf("%d", &n);

        if (n == 0) {
            printf("%d ", n);
        }
        while (n != 0) {
            printf("%d ", n % 10);
            n /= 10;
        }
        printf("\n");
    }

    return 0;
}
*/


/*
// Version 3: do-while loop
// The body runs at least once, so n == 0 prints "0" naturally —
// no special case needed.

#include <stdio.h>

int main() {
    int t;
    int n;
    scanf("%d", &t);

    for (int i = 1; i <= t; i++) {
        scanf("%d", &n);

        do {
            printf("%d ", n % 10);   // last digit
//             n /= 10;                 // remove last digit
        } while (n != 0);

        printf("\n");
    }

    return 0;
}
*/
