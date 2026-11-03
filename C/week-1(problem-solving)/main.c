/*
  Week 1 — Problem solving practice (C)

  Each problem below is written as:
    - statement in a block comment
    - solution code commented out

  All solutions are kept commented out.
  To run one, comment out the others and uncomment its code.
*/


/*
=====================================================================
  Problem : Zero or Non Zero
  Limits  : 1 second, 2.93 MB
=====================================================================

  Statement
    You will be given an integer number N. Print "Zero" if the
    number is equal to 0 and "Non Zero" otherwise.

  Constraints
    -1000 <= N <= 1000

  Input
    An integer N.

  Output
    "Zero" or "Non Zero".

  Sample
    Input : 5
    Output: Non Zero
=====================================================================
*/

/*
#include <stdio.h>

int main() {
    int num;
    scanf("%d", &num);

    if (num == 0) {
        printf("Zero");
    } else {
        printf("Non Zero");
    }

    return 0;
}
*/


/*
=====================================================================
  Problem : 5 Marks for good hand writing
  Limits  : 1 second, 2.93 MB
=====================================================================

  Statement
    You will be given an integer number N. You will have to add 5
    to N and print it.

  Constraints
    1 <= N <= 100

  Input
    An integer number N.

  Output
    The result after adding 5 to N.

  Sample
    Input : 100
    Output: 105

  Note
    The statement says "add 5" for every input, and the constraints
    guarantee N >= 1, so no condition is needed — just add 5.
=====================================================================
*/

/*
#include <stdio.h>

int main() {
    int a;
    scanf("%d", &a);

    a += 5;
    printf("%d", a);

    return 0;
}
*/


/*
=====================================================================
  Problem : Multiple or not
  Limits  : 1 second, 2.93 MB
=====================================================================

  Statement
    You will be given two integers a and b. You have to tell if one
    is a multiple of the other (a is a multiple of b, or b is a
    multiple of a).

  Constraints
    1 <= a, b <= 10000

  Input
    Two integers a and b.

  Output
    "Yes" if one is a multiple of the other, otherwise "No".

  Sample
    Input : 5 9
    Output: No
=====================================================================
*/

/*
#include <stdio.h>

int main() {
    int a, b;
    scanf("%d %d", &a, &b);

    // both directions must be checked, e.g. input "9 5" -> Yes
    if (a % b == 0 || b % a == 0) {
        printf("Yes");
    } else {
        printf("No");
    }

    return 0;
}
*/


/*
=====================================================================
  Problem : Floating Point Number
  Limits  : 1 second, 2.93 MB
=====================================================================

  Statement
    You will be given a floating point number x. You have to print
    x up to 3 decimal places.

  Constraints
    1.0 <= x <= 150.0

  Input
    A floating point number x.

  Output
    The number x with exactly 3 digits after the decimal point.

  Sample
    Input : 22.12344
    Output: 22.123

  Note
    %.3f means "print with 3 digits after the decimal point".
    printf() rounds to the requested precision.
=====================================================================
*/

/*
#include <stdio.h>

int main() {
    float num;
    scanf("%f", &num);

    printf("%.3f", num);

    return 0;
}
*/


/*
=====================================================================
  Problem : Read and Print 4 Variable Types
  Limits  : —
=====================================================================

  Statement
    Take an integer A, a very big integer B, a floating value C and
    a character D as input, and output them serially.

  Input Format
    First line  : A   (-10^9   <= A <= 10^9)    -> int
    Second line : B   (-10^18  <= B <= 10^18)   -> long long
    Third line  : C   (-10^9   <= C <= 10^9)    -> float
    Fourth line : D                              -> char

  Output Format
    Output them serially, a new line after each value.
    Print the floating value with 2 digits after the decimal point.

  Sample
    Input :
      100
      1234567891234567
      23.5675
      A

    Output:
      100
      1234567891234567
      23.57
      A

  Note
    Format specifiers must match the data types:
      int       -> %d
      long long -> %lld      (NOT %lf — %lf is for double)
      float     -> %f in scanf, %.2f in printf for 2 decimals
      char      -> %c

    Whitespace in a scanf() format string matches any whitespace
    (spaces, tabs, newlines), so one scanf() can read all 4 lines.
=====================================================================
*/

/*
#include <stdio.h>

int main() {
    int A;
    long long B;
    float C;
    char D;

    scanf("%d %lld %f %c", &A, &B, &C, &D);
    printf("%d\n%lld\n%.2f\n%c\n", A, B, C, D);

    return 0;
}
*/


/*
=====================================================================
  Problem : Print 1 to N with Yes/No
  Limits  : —
=====================================================================

  Statement
    You will be given a positive integer N. Print the values from
    1 to N; beside each value print "Yes" if the value is divisible
    by 5, otherwise print "No".

  Constraints
    1 <= N <= 1000

  Input
    A positive integer N.

  Output
    N lines, one per value, each ending with a new line.

  Sample
    Input : 10

    Output:
      1 No
      2 No
      3 No
      4 No
      5 Yes
      6 No
      7 No
      8 No
      9 No
      10 Yes
=====================================================================
*/

/*
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        if (i % 5 == 0) {
            printf("%d Yes\n", i);
        } else {
            printf("%d No\n", i);
        }
    }

    return 0;
}
*/
