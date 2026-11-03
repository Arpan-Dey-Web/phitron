/*
  Week 2 — Problem solving practice (C)

  Each problem below is written as:
    - statement in a block comment
    - solution code commented out

  All solutions are kept commented out.
  To run one, comment out the others and uncomment its code.
*/


/*
=====================================================================
  Problem : C. Next Alphabet
  Limits  : 1 second, 256 MB
=====================================================================

  Statement
    Given a lowercase alphabet character, print the next character
    in the alphabet.

  Input
    One line containing a lowercase English letter C.

  Output
    Print the next letter to C in the alphabet.

  Example
    Input : a
    Output: b

  Note
    The next letter to z is a.
=====================================================================
*/

/*
#include <stdio.h>

int main() {
    char presentChar;
    scanf("%c", &presentChar);

    if (presentChar == 'z') {
        printf("a");               // wrap-around case
    } else {
        printf("%c", presentChar + 1);
    }

    return 0;
}

// Note: characters are consecutive ASCII values, so
// presentChar + 1 gives the next letter. Without the special
// case, 'z' + 1 would print '{' (ASCII 123).
*/


/*
=====================================================================
  Problem : D. Ali Baba and Puzzles
  Limits  : 1 second, 256 MB
=====================================================================

  Statement
    The puzzle consists of 4 numbers. The task is to check whether
    the fourth number can be obtained from the other three using
    the arithmetic operators +, - and x, each used exactly once:

      a □ b □ c = d

  Input
    One line containing four numbers a, b, c and d
    (-10^9 <= a, b, c <= 10^9), (-10^18 <= d <= 10^18).

  Output
    Print "YES" if d can be obtained, otherwise print "NO".

  Examples
    Input : 3 4 5 23
    Output: YES        (3 + 4 * 5 = 23)

    Input : 9 5 3 7
    Output: YES        (9 - 5 + 3 = 7)

    Input : 1 2 3 1
    Output: NO

  Note
    There are two operator slots between a, b and c. Trying every
    valid arrangement gives 10 cases:

      natural precedence : a+b*c  a+b-c  a-b+c  a-b*c  a*b+c  a*b-c
      parentheses first  : (a+b)*c  (a-b)*c  a*(b+c)  a*(b-c)

    Because a*b can reach 10^18, long long is required.
    Signed integer overflow is undefined behavior in C.
=====================================================================
*/

/*
#include <stdio.h>



int main() {
    long long a, b, c, d;
    scanf("%lld %lld %lld %lld", &a, &b, &c, &d);



    if (a + b * c == d ||
        a - b * c == d ||
        a * b + c == d ||
        a * b - c == d ||
        a + b - c == d ||
        a - b + c == d) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }



    return 0;
}
*/


/*
=====================================================================
  Problem : K. Divisors
  Limits  : 1 second, 256 MB
=====================================================================

  Statement
    Given a number N, print all the divisors of N in ascending
    order.

  Input
    One line containing a number N (1 <= N <= 10^4).

  Output
    Print all positive divisors of N, one number per line.

  Examples
    Input : 6
    Output:
      1
      2
      3
      6

    Input : 7
    Output:
      1
      7

    Input : 4
    Output:
      1
      2
      4

  Note
    A divisor divides the integer exactly, with no remainder.
    3 is a divisor of 12 because 12 / 3 = 4 exactly.
    5 is not a divisor of 12 because 12 / 5 = 2 remainder 2.
    A divisor is also called a factor.
=====================================================================
*/

/*
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int i = 1;
    while (i <= n) {
        if (n % i == 0) {
            printf("%d\n", i);
        }
        i++;
    }

    return 0;
}

// Note: checking i from 1 to n naturally prints divisors in
// ascending order.
*/


/*
=====================================================================
  Problem : I. Lucky Numbers
  Limits  : 1 second, 256 MB
=====================================================================

  Statement
    A two-digit number is lucky if one of its digits is divisible
    by the other.

    For example, 39, 82 and 55 are lucky, while 79 and 43 are not.

    Given a number between 10 and 99, determine whether it is
    lucky or not.

  Input
    One line containing a single number N (10 <= N <= 99).

  Output
    Print "YES" if the given number is lucky, otherwise "NO".

  Examples
    Input : 39
    Output: YES        (9 % 3 == 0)

    Input : 64
    Output: NO         (6 % 4 != 0 and 4 % 6 != 0)

  Note
    Split the number into its two digits:
      last digit    = n % 10
      remaining one = n / 10

    Numbers such as 10, 20 ... 90 contain a 0 digit. When the last
    digit is 0, the first check (0 % firstDigit == 0) is already
    true, so || short-circuits and the second check (which would be
    firstDigit % 0) is never evaluated — no division by zero.
    0 is divisible by any non-zero number, so these are lucky.
=====================================================================
*/

/*
#include <stdio.h>

int main() {
    int n;
    int firstNumber;
    int secondNumber;

    scanf("%d", &n);

    secondNumber = n % 10;      // last digit
    firstNumber = n / 10;       // remaining digit

    if (secondNumber % firstNumber == 0 || firstNumber % secondNumber == 0) {
        printf("YES");
    } else {
        printf("NO");
    }

    return 0;
}
*/
