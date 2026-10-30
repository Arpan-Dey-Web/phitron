/*
  Mid-Exam — Problem Set (C)

  5 problems from the mid-term contest, mixing loops, conditions,
  arrays and strings (Modules 1-11).

  Each problem below is written as:
    - statement in a block comment
    - solution code commented out

  All solutions are kept commented out.
  To run one, comment out the others and uncomment its code.
*/


/*
=====================================================================
  Problem 1 : Divisible by 2 and by 3
=====================================================================

  Statement
    Given an integer array A of size N, count how many elements
    are divisible by 2 and how many are divisible by 3. A number
    divisible by BOTH counts only for 2.

  Input
    First line  : N (1 <= N <= 1e5)
    Second line : N numbers (0 <= A[i] <= 1e9)

  Output
    Count divisible by 2, then count divisible by 3.

  Examples
    Input :
      5
      1 4 2 5 3
    Output:
      2 1

    Input :
      4
      6 9 12 15
    Output:
      2 2

  Note
    The if / else-if order IS the "count only for 2" rule:
        if     (number % 2 == 0)  count2++;
        else if(number % 3 == 0)  count3++;

    A number like 6 or 12 is caught by the first branch, so it
    never reaches count3.

    My first version had a third, dead branch:
        else if (number % 2 == 0 && i % 3 == 0)
    It can never run (number % 2 == 0 was already handled) AND it
    checked the INDEX i instead of the VALUE number.
=====================================================================
*/

// #include <stdio.h>
//
// int main()
// {
//     int n;
//     scanf("%d", &n);
//
//     int devidedBy2 = 0, devidedBy3 = 0;
//
//     for (int i = 0; i < n; i++)
//     {
//         int number;
//         scanf("%d", &number);
//
//         if (number % 2 == 0)
//         {
//             devidedBy2++;
//         }
//         else if (number % 3 == 0)
//         {
//             devidedBy3++;
//         }
//     }
//
//     printf("%d %d", devidedBy2, devidedBy3);
//     return 0;
// }


/*
=====================================================================
  Problem 2 : Count the Consonants
=====================================================================

  Statement
    Given a string S of lowercase English letters (no spaces),
    count its consonants. Vowels are a, e, i, o, u; everything
    else is a consonant.

  Input
    One string S (1 <= |S| <= 100000).

  Output
    The number of consonants.

  Examples
    Input : thefoxisgone
    Output: 7

    Input : sjxapw
    Output: 5

  Note
    Every character that is NOT a vowel is a consonant, so the
    vowels are skipped with continue and everything else is
    counted. |S| can be 1e5, so one single pass is needed —
    no nested loops.
=====================================================================
*/

// #include <stdio.h>
// #include <string.h>
//
// int main()
// {
//     char a[100001];
//     scanf("%s", a);
//     int len = strlen(a);
//
//     int consonent = 0;
//     for (int i = 0; i < len; i++)
//     {
//         if (a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || a[i] == 'o' || a[i] == 'u')
//         {
//             continue;              // vowel → not a consonant
//         }
//         consonent++;
//     }
//
//     printf("%d", consonent);
//     return 0;
// }


/*
=====================================================================
  Problem 3 : Farmers and Days of Work
=====================================================================

  Statement
    M1 farmers complete a work in D days. M2 extra farmers
    appear. Print how many FEWER days the work takes now.
    If the answer is fractional, take its integer part.

  Input
    First line  : T (1 <= T <= 1000) number of test cases
    Next T lines: M1 M2 D (1 <= M1 <= 1000, 0 <= M2 <= 1000,
                  1 <= D <= 100)

  Output
    Fewer days for each test case, each on its own line.

  Examples
    Input :
      4
      10 5 15
      4 0 5
      4 1 5
      7 1000 1
    Output:
      5
      0
      1
      1

  Idea
    The amount of work is measured in "farmer-days" and never
    changes:

        work  = M1 * D
        now   = M1 + M2 farmers
        newD  = work / (M1 + M2)      (integer division)
        answer = D - newD

  Note
    Integer division IS the "take the integer part" rule:
        150 / 15 = 10  → 15 - 10 = 5
        150 / 1007 = 0 → 1 - 0 = 1

    My first attempt mixed the values up:
        dayNeedFor_All_People = (days * m1) / days;   // = m1 !!
    Dividing by `days` again throws the farmers away. The correct
    divisor is the NEW number of farmers (m1 + m2).
=====================================================================
*/

// #include <stdio.h>
//
// int main()
// {
//     int t;
//     scanf("%d", &t);
//
//     for (int i = 0; i < t; i++)
//     {
//         int m1, m2, days;
//         scanf("%d %d %d", &m1, &m2, &days);
//
//         int total_farmers = m1 + m2;
//         int new_days = (m1 * days) / total_farmers;
//         int fewer_days = days - new_days;
//
//         printf("%d\n", fewer_days);
//     }
//
//     return 0;
// }


/*
=====================================================================
  Problem 4 : Count Capital Letters, Small Letters and Digits
=====================================================================

  Statement
    Given a string S of capital letters, small letters and digits,
    count each group.

  Input
    First line  : T (1 <= T <= 1000) number of test cases
    Next T lines: a string S (1 <= |S| <= 10000)

  Output
    capital count, small count, digit count — one line per test
    case.

  Example
    Input :
      2
      theFox25IsBrave
      ILoveYou100TimesAndSay2Also
    Output:
      3 10 2
      7 16 4

  Note
    ASCII ranges (from Module 5):
        '0'..'9'  →  digits
        'A'..'Z'  →  capital
        'a'..'z'  →  small

    strlen(a) is stored in `len` BEFORE the loop. Calling
    strlen(a) inside the loop condition would recount the whole
    string on every iteration — wasted work, O(n^2) in the worst
    case.
=====================================================================
*/

// #include <stdio.h>
// #include <string.h>
//
// int main()
// {
//     int t;
//     scanf("%d", &t);
//
//     for (int i = 0; i < t; i++)
//     {
//         char a[10005];
//         scanf("%s", a);
//
//         int len = strlen(a);
//         int capitalLetters = 0, smallLetters = 0, digits = 0;
//
//         for (int j = 0; j < len; j++)
//         {
//             if (a[j] >= 'a' && a[j] <= 'z')
//             {
//                 smallLetters++;
//             }
//             else if (a[j] >= 'A' && a[j] <= 'Z')
//             {
//                 capitalLetters++;
//             }
//             else if (a[j] >= '0' && a[j] <= '9')
//             {
//                 digits++;
//             }
//         }
//
//         printf("%d %d %d\n", capitalLetters, smallLetters, digits);
//     }
//
//     return 0;
// }


/*
=====================================================================
  Problem 5 : Frequency of Each Letter
=====================================================================

  Statement
    Given a string of small English letters, print how many times
    each letter a..z appears — but only the letters that appear
    at least once.

  Input
    One string S (1 <= |S| <= 10000).

  Output
    One line per letter, in alphabetical order:
        a - 1
        b - 1
        ...

  Examples
    Input : thefoxisbrave
    Output:
      a - 1
      b - 1
      e - 2
      f - 1
      h - 1
      i - 1
      o - 1
      r - 1
      s - 1
      t - 1
      v - 1
      x - 1

  Note
    The outer loop runs over the 26 letters and the inner loop
    scans the string for each of them — 26 * n comparisons, fine
    for |S| = 1e4.

    Because the outer loop walks from 'a' to 'z', the output is
    automatically in alphabetical order, and `if (count > 0)`
    skips the letters that never appear.
=====================================================================
*/

// #include <stdio.h>
// #include <string.h>
//
// int main()
// {
//     char a[10005];
//     scanf("%s", a);
//
//     int length = strlen(a);
//
//     for (char ch = 'a'; ch <= 'z'; ch++)
//     {
//         int count = 0;
//
//         for (int i = 0; i < length; i++)
//         {
//             if (a[i] == ch)
//             {
//                 count++;
//             }
//         }
//
//         if (count > 0)
//         {
//             printf("%c - %d\n", ch, count);
//         }
//     }
//
//     return 0;
// }
