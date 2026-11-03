/*
  Module 5 — Conditions problem set (C)

  Each problem below is written as:
    - statement in a block comment
    - solution code commented out

  All solutions are kept commented out.
  To run one, comment out the others and uncomment its code.
*/


/*
=====================================================================
  Problem : I. Welcome for you with Conditions
  Limits  : 1 second, 64 MB
=====================================================================

  Statement
    Given two numbers A and B. Print "Yes" if A is greater than or
    equal to B. Otherwise print "No".

  Input
    One line containing two numbers A and B (0 <= A, B <= 100).

  Output
    Print "Yes" or "No" according to the statement.

  Examples
    Input : 10 9
    Output: Yes

    Input : 5 5
    Output: Yes

    Input : 5 7
    Output: No
=====================================================================
*/

/*
#include <stdio.h>

int main() {
    int a, b;
    scanf("%d %d", &a, &b);

    if (a >= b) {
        printf("Yes");
    } else {
        printf("No");
    }

    return 0;
}
*/


/*
=====================================================================
  Problem : J. Multiples
  Limits  : 1 second, 256 MB
=====================================================================

  Statement
    Given two numbers A and B. Print "Multiples" if A is a multiple
    of B or vice versa. Otherwise print "No Multiples".

  Input
    One line containing two numbers A, B (1 <= A, B <= 10^6).

  Output
    Print "Multiples" or "No Multiples" according to the input.

  Examples
    Input : 9 3
    Output: Multiples

    Input : 6 24
    Output: Multiples

    Input : 12 5
    Output: No Multiples

  Note
    A is a multiple of B when A % B == 0. Because the problem asks
    about either direction, both divisibility checks are required.

    9  % 3 == 0  -> Multiples
    24 % 6 == 0  -> Multiples (second direction)
    12 % 5 != 0 and 5 % 12 != 0 -> No Multiples
=====================================================================
*/

/*
#include <stdio.h>

int main() {
    int a, b;
    scanf("%d %d", &a, &b);

    if (a % b == 0 || b % a == 0) {
        printf("Multiples");
    } else {
        printf("No Multiples");
    }

    return 0;
}
*/


/*
=====================================================================
  Problem : P. First digit!
  Limits  : 0.25 second, 64 MB
=====================================================================

  Statement
    Given a number X. Print "EVEN" if the first digit of X is an
    even number. Otherwise print "ODD".

    Example: in 4569 the first digit is 4, the second is 5,
    the third is 6 and the fourth is 9.

  Input
    One line containing a number X (999 < X <= 9999).

  Output
    If the first digit is even print "EVEN", otherwise print "ODD".

  Examples
    Input : 4569
    Output: EVEN

    Input : 3569
    Output: ODD
=====================================================================
*/

/*
#include <stdio.h>

int main() {
    int a;
    scanf("%d", &a);

    int firstDigit = a / 1000;   // integer division: 4569 / 1000 = 4

    if (firstDigit % 2 == 0) {
        printf("EVEN");
    } else {
        printf("ODD");
    }

    return 0;
}

// Notes:
//   - a / 1000 removes the last 3 digits. This works because the
//     problem guarantees X has exactly 4 digits (999 < X <= 9999).
//     In C this is integer division: the result is truncated, no
//     float value is produced.
//   - a % 10 gives the last digit of a number (4569 % 10 = 9).
*/


/*
=====================================================================
  Problem : N. Char
  Limits  : 0.25 second, 64 MB
=====================================================================

  Statement
    Given a letter X. If the letter is lowercase, print it after
    converting it to uppercase. Otherwise print it after converting
    it to lowercase.

  Input
    One line containing a character X (a capital or small letter).

  Output
    Print the answer to this problem.

  Examples
    Input : a
    Output: A

    Input : A
    Output: a

  Note
    The ASCII difference between 'a' and 'A' is 32:
    'a' = 97, 'A' = 65.
=====================================================================
*/

/*
#include <stdio.h>

int main() {
    char ch;
    scanf("%c", &ch);

    if (ch >= 'a' && ch <= 'z') {
        ch = ch - 32;          // lowercase -> uppercase
        printf("%c", ch);
    } else {
        ch = ch + 32;          // uppercase -> lowercase
        printf("%c", ch);
    }

    return 0;
}
*/


/*
=====================================================================
  Problem : M. Capital or Small or Digit
  Limits  : 1 second, 256 MB
=====================================================================

  Statement
    Given a letter X. Determine whether X is a digit or an alphabet,
    and if it is an alphabet, whether it is capital or small.

  Input
    One line containing a character X (a capital letter, a small
    letter, or a digit).

  Output
    If X is a digit, print "IS DIGIT".
    Otherwise print "ALPHA", followed by a line containing
    "IS CAPITAL" or "IS SMALL".

  Examples
    Input : A
    Output:
      ALPHA
      IS CAPITAL

    Input : 9
    Output:
      IS DIGIT

    Input : a
    Output:
      ALPHA
      IS SMALL

  Note (ASCII ranges)
    digits  : '0' = 48 ... '9' = 57
    capitals: 'A' = 65 ... 'Z' = 90
    smalls  : 'a' = 97 ... 'z' = 122
=====================================================================
*/

/*
#include <stdio.h>

int main() {
    char ch;
    scanf("%c", &ch);

    if (ch >= '0' && ch <= '9') {
        printf("IS DIGIT\n");
    } else if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
        printf("ALPHA\n");

        if (ch >= 'a' && ch <= 'z') {
            printf("IS SMALL\n");
        } else {
            printf("IS CAPITAL\n");
        }
    }

    return 0;
}
*/


/*
=====================================================================
  Problem : Min and Max of 3 Numbers
  Limits  : —
=====================================================================

  Statement
    Given 3 numbers A, B and C, print the minimum and the maximum
    numbers.

  Input
    One line containing 3 numbers A, B and C (-10^5 <= A, B, C <= 10^5).

  Output
    Print the minimum number, a single space, then the maximum number.

  Examples
    Input : 1 2 3
    Output: 1 3

    Input : -1 -2 -3
    Output: -3 -1

    Input : 10 20 -5
    Output: -5 20
=====================================================================
*/

/*
#include <stdio.h>

int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    int maximumNumber;
    int minimumNumber;

    if (a >= b && a >= c) {
        maximumNumber = a;
    } else if (b >= a && b >= c) {
        maximumNumber = b;
    } else {
        maximumNumber = c;
    }

    if (a <= b && a <= c) {
        minimumNumber = a;
    } else if (b <= a && b <= c) {
        minimumNumber = b;
    } else {
        minimumNumber = c;
    }

    printf("%d %d", minimumNumber, maximumNumber);

    return 0;
}
*/
