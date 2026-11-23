/*
  Test Contest — Problem Set (C)

  Five problems from a practice contest. Each problem below is
  written as:
    1. a block comment  -> the statement (Statement, Input, Output, Examples, Note)
    2. a block comment  -> my solution, kept commented out

  All solutions are kept commented out.
  To run one, remove the block-comment markers around its code
  and wrap the others the same way.

  Problems:
    0. Sum of 2 Numbers             — read two numbers, print the sum
    1. The Four Friends             — highest scorer, or Tie
    2. Phitron Marks Challenge      — minimum marks for a target average
    3. Maximum Difference           — biggest A[j] - A[i] with j > i
    4. Jhankar's Programming Journey — walk while difficulty increases
*/


/*
=====================================================================
  Problem 0 : Sum of 2 Numbers
=====================================================================

  Statement
    Read two integers and print their sum.

  Input
    One line with two integers A and B.

  Output
    A + B.

  Examples
    Input : 80 65
    Output: 145

    Input : -10 4
    Output: -6

  Note
    The warmup problem: two scanf, one addition, one printf.
=====================================================================
*/

/*
#include <stdio.h>

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);

    int total = a + b;
    printf("%d", total);
    return 0;
}
*/


/*
=====================================================================
  Problem 1 : The Four Friends
  Limits  : 15 seconds, 2.93 MB
=====================================================================

  Statement
    Rahim, Karim, Sakib and Nabil scored A, B, C and D points in
    a contest. Print the name of the HIGHEST scorer. If two or
    more friends share the highest score, print Tie.

  Input
    One line with four integers A B C D — the scores.

  Output
    Rahim / Karim / Sakib / Nabil / Tie, each on its own line.

  Examples
    Input : 80 65 70 90
    Output: Nabil          (90 is the highest)

    Input : 5 5 5 5
    Output: Tie

  Note
    The test for a UNIQUE maximum is "strictly greater than
    EVERYONE else":

        a > b && a > c && a > d   ->  a alone is the highest

    Four such checks in an if / else-if chain. The final else
    runs whenever NO value is strictly above all the others —
    and that happens exactly when the maximum is shared, i.e. a
    tie (including all four equal).

    This is the test in input.txt / output.txt.
=====================================================================
*/

/*
#include <stdio.h>

int main()
{
    long long a, b, c, d;
    scanf("%lld %lld %lld %lld", &a, &b, &c, &d);

    if (a > b && a > c && a > d)
    {
        printf("Rahim\n");
    }
    else if (b > a && b > c && b > d)
    {
        printf("Karim\n");
    }
    else if (c > a && c > b && c > d)
    {
        printf("Sakib\n");
    }
    else if (d > a && d > b && d > c)
    {
        printf("Nabil\n");
    }
    else
    {
        printf("Tie\n");
    }

    return 0;
}
*/


/*
=====================================================================
  Problem 2 : Phitron Marks Challenge
  Limits  : 15 seconds, 2.93 MB
=====================================================================

  Statement
    Atiq must average at least K marks across N subjects. Every
    subject is out of M marks. He already wrote N - 1 of them
    with scores A1 .. A(N-1). Print the minimum marks he needs
    in the LAST exam — or -1 if even full marks cannot reach the
    target average.

  Input
    First line  : three integers N M K
                  (total subjects, max marks per subject,
                   target average)
    Second line : N - 1 integers A1 .. A(N-1)

  Output
    The minimum marks needed, or -1.

  Constraints
    2 <= N <= 100, 1 <= M <= 100, 0 <= K <= M, 0 <= Ai <= M
    All values are integers.

  Examples
    Input :
      5 10 7
      10 7 8 10
    Output: 0
      (35 already scored, target total = 5 * 7 = 35 -> need 0)

    Input :
      4 100 60
      100 0 0
    Output: -1
      (target total = 240; 100 scored + at most 100 more = 200
       max, so 240 is impossible)

  Note — three steps
    target_total = N * K              total the average needs
    current      = sum of the N-1 scores
    need         = target_total - current

    need > M   ->  even M marks is not enough  -> print -1
    need <= 0  ->  already on target           -> print 0
    otherwise  ->  print need

    Comparing against M (the most the last exam can give) is
    what turns "impossible" into -1.
=====================================================================
*/

/*
#include <stdio.h>

int main()
{
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);

    int total = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int score;
        scanf("%d", &score);
        total += score;
    }

    int target_total = n * k;
    int need = target_total - total;

    if (need > m)
    {
        printf("-1\n");
    }
    else if (need <= 0)
    {
        printf("0\n");
    }
    else
    {
        printf("%d\n", need);
    }

    return 0;
}
*/


/*
=====================================================================
  Problem 3 : Maximum Difference
  Limits  : 15 seconds, 2.93 MB
=====================================================================

  Statement
    Given an array of N integers, choose two positions with
    j > i (the second element comes AFTER the first) and make

        A[j] - A[i]

    as large as possible. Print that maximum difference.

  Input
    First line  : N (2 <= N <= 1000)
    Second line : N integers (-10000 <= Ai <= 10000)

  Output
    The maximum A[j] - A[i] with j > i.

  Examples
    Input : 6
            7 1 5 3 6 4
    Output: 5          (6 - 1)

    Input : 5
            -8 -3 -10 4 2
    Output: 14         (4 - (-10))

    Input : 5
            9 7 5 3 1
    Output: -2         (the array only goes DOWN!)

  Note
    The answer CAN be negative: when the array is strictly
    decreasing, every valid A[j] - A[i] is below zero and the
    best pair is the first two values (7 - 9 = -2).

    Brute force over every pair (i, j) with i < j:
    N <= 1000 -> about 500,000 comparisons, well inside the
    time limit.

    max_diff starts from a[1] - a[0] because N >= 2 means at
    least one pair always exists — no empty-array case.
=====================================================================
*/

/*
#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    int max_diff = a[1] - a[0];

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int diff = a[j] - a[i];
            if (diff > max_diff)
            {
                max_diff = diff;
            }
        }
    }

    printf("%d\n", max_diff);
    return 0;
}
*/


/*
=====================================================================
  Problem 4 : Jhankar's Programming Journey
  Limits  : 15 seconds, 2.93 MB
=====================================================================

  Statement
    Jhankar has N programming topics in the order he studies
    them, each with a difficulty level. He starts at the first
    topic and moves to the next one ONLY while its difficulty is
    STRICTLY greater than the current topic's difficulty. If the
    next topic is equal or lower, he stops. Print the difficulty
    level of the LAST topic he reaches.

  Input
    First line  : N (1 <= N <= 100)
    Second line : N integers (1 <= Ai <= 10^9)

  Output
    The difficulty of the last topic reached.

  Examples
    Input : 5
            1 5 10 4 2
    Output: 10        (next is 4 <= 10, so he stops at 10)

    Input : 3
            5 5 9
    Output: 5         (equal difficulty also stops him)

  Note
    last = a[0], then walk i = 1 .. N-1:

        a[i] > last  ->  study it: last = a[i], continue
        otherwise    ->  break (stop studying)

    STRICTLY greater is the rule — an equal difficulty counts
    as stopping, which is why the second example prints 5 and
    never reaches 9.

    N = 1: the loop never runs and the answer is a[0].
=====================================================================
*/

/*
#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    int last_topic = a[0];

    for (int i = 1; i < n; i++)
    {
        if (a[i] > last_topic)
        {
            last_topic = a[i];
        }
        else
        {
            break;
        }
    }

    printf("%d\n", last_topic);
    return 0;
}
*/
