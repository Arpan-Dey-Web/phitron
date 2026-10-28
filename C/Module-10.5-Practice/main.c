/*
  Module 10.5 — Practice: Arrays + Strings (C)

  Practice set mixing Module 9 (arrays) and Module 10 (strings).
  Each problem below is written as:
    - statement in a block comment
    - solution code commented out

  All solutions are kept commented out.
  To run one, comment out the others and uncomment its code.
*/


/*
=====================================================================
  Problem : F. Reversing
  Limits  : 1 second, 64 MB
=====================================================================

  Statement
    Given a number N and an array A of N numbers, print the array
    in reversed order.
    Note: Don't use built-in functions.

  Input
    First line  : N (1 <= N <= 1000)
    Second line : N numbers (0 <= Ai <= 1e9)

  Output
    The array in reversed order.

  Examples
    Input :
      4
      5 1 3 2
    Output:
      2 3 1 5

    Input :
      5
      1 2 3 4 5
    Output:
      5 4 3 2 1

  Note (my mistake)
    I first wrote `int arr[n - 1]` while still READING n values —
    that writes past the end of the array (undefined behavior).
    The size must be int arr[n]. Shrinking the array only matters
    when deleting, not when printing in reverse.

    Print from the last index n-1 down to 0.
=====================================================================
*/

// #include <stdio.h>
//
// int main()
// {
//     int n;
//     scanf("%d", &n);
//
//     int arr[n];
//     for (int i = 0; i < n; i++)
//     {
//         scanf("%d", &arr[i]);
//     }
//
//     for (int i = n - 1; i >= 0; i--)
//     {
//         printf("%d ", arr[i]);
//     }
//
//     return 0;
// }


/*
=====================================================================
  Problem : G. Palindrome Array
  Limits  : 1 second, 256 MB
=====================================================================

  Statement
    Given N and an array A of N numbers, determine if it is a
    palindrome or not.
    An array is a palindrome if it reads the same backward and
    forward, e.g. {1}, {1,2,3,2,1} are palindromes; {1,12} and
    {4,7,5,4} are not.

  Input
    First line  : N (1 <= N <= 1e5)
    Second line : N numbers (1 <= Ai <= 1e9)

  Output
    "YES" if A is a palindrome, otherwise "NO".

  Examples
    Input :
      5
      1 3 2 3 1
    Output:
      YES

    Input :
      4
      1 2 3 4
    Output:
      NO

  Note
    Two pointers again: i from the start, j from the end.
    Compare a[i] with a[j]; one mismatch means "NO" and we can
    stop immediately. If the loop finishes, every pair matched.
    For N = 1 the loop never runs -> "YES" (a single element is a
    palindrome).
=====================================================================
*/

// #include <stdio.h>
//
// int main()
// {
//     int n;
//     scanf("%d", &n);
//
//     int a[n];
//     for (int i = 0; i < n; i++)
//     {
//         scanf("%d", &a[i]);
//     }
//
//     int flag = 1;
//     for (int i = 0, j = n - 1; i < j; i++, j--)
//     {
//         if (a[i] != a[j])
//         {
//             printf("NO");
//             flag = 0;
//             break;
//         }
//     }
//
//     if (flag == 1)
//     {
//         printf("YES");
//     }
//
//     return 0;
// }


/*
=====================================================================
  Problem : F. Way Too Long Words
  Limits  : 1 second, 256 MB
=====================================================================

  Statement
    Given a string S, print it unchanged if it is not too long,
    otherwise abbreviate it:
      - first character
      - number of characters between first and last
      - last character
    A word is "too long" when its length is strictly more than 10.

  Input
    First line  : T (1 <= T <= 100) number of test cases
    Next T lines: a string S (1 <= |S| <= 100), lowercase letters

  Output
    The original word or its abbreviation, one per line.

  Example
    Input :
      4
      word
      localization
      internationalization
      pneumonoultramicroscopicsilicovolcanoconiosis
    Output:
      word
      l10n
      i18n
      p43s

  Note
    middle length = strLength - 2
      "localization"  -> 12 - 2 = 10  -> "l10n"
    Each test case prints with '\n' so the results stay on
    separate lines.
=====================================================================
*/

// #include <stdio.h>
// #include <string.h>
//
// int main()
// {
//     int n;
//     scanf("%d", &n);
//
//     for (int i = 0; i < n; i++)
//     {
//         char str[105];
//         scanf("%s", str);
//         int strLength = strlen(str);
//
//         if (strLength <= 10)
//         {
//             printf("%s\n", str);
//         }
//         else
//         {
//             printf("%c%d%c\n", str[0], strLength - 2, str[strLength - 1]);
//         }
//     }
//
//     return 0;
// }


/*
=====================================================================
  Problem : G. Conversion
  Limits  : 2 seconds, 64 MB
=====================================================================

  Statement
    Given a string S, print it after:
      - replacing every ',' with a space
      - swapping the case of every letter (upper -> lower,
        lower -> upper)

  Input
    One line: S (1 <= |S| <= 1e5), letters and commas only.

  Output
    The converted string.

  Example
    Input :  happy,NewYear,enjoy
    Output:  HAPPY nEWyEAR ENJOY

  Note
    ASCII case conversion, same idea as Module 5:
        'a' - 'A' = 32
        lowercase -> uppercase : -= 32   (or -32)
        uppercase -> lowercase : += 32   (or +32)
    The loop modifies the array in place, then prints it once.
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
//     for (int i = 0; i < len; i++)
//     {
//         if (a[i] == ',')
//         {
//             a[i] = ' ';
//         }
//         else if (a[i] >= 'A' && a[i] <= 'Z')
//         {
//             a[i] += 32;        // upper -> lower
//         }
//         else if (a[i] >= 'a' && a[i] <= 'z')
//         {
//             a[i] -= 32;        // lower -> upper
//         }
//     }
//
//     printf("%s", a);
//     return 0;
// }


/*
=====================================================================
  Problem : I. Palindrome
  Limits  : 1 second, 256 MB
=====================================================================

  Statement
    Given a string S, determine whether S is a palindrome.

    A string is a palindrome if its reverse equals itself, e.g.
    "abba" and "mam" are palindromes, "abbc" and "icpcassiut"
    are not.

  Input
    One line: S (1 <= |S| <= 1000), lowercase letters only.

  Output
    "YES" if S is a palindrome, otherwise "NO".

  Examples
    Input : abba
    Output: YES

    Input : icpcassiut
    Output: NO

    Input : mam
    Output: YES

  Note
    Same two-pointer idea as the palindrome ARRAY, but here we
    compare characters: s[i] != s[j] -> print "NO" and stop.
=====================================================================
*/

// #include <stdio.h>
// #include <string.h>
//
// int main()
// {
//     char a[10001];
//     scanf("%s", a);
//     int len = strlen(a);
//
//     int num = 1;
//     for (int i = 0, j = len - 1; i < j; i++, j--)
//     {
//         if (a[i] != a[j])
//         {
//             num = 0;
//             printf("NO");
//             break;
//         }
//     }
//
//     if (num == 1)
//     {
//         printf("YES");
//     }
//
//     return 0;
// }


/*
=====================================================================
  Problem : D. Strings
=====================================================================

  Statement
    Given two strings A and B, print three lines:
      1. size of A and size of B, separated by a space
      2. the concatenation A + B
      3. both strings separated by a space, after swapping their
         first characters

  Input
    First line : A (1 <= |A| <= 10)
    Second line: B (1 <= |B| <= 10)

  Output
    Three lines as described above.

  Example
    Input :
      abcd
      ef
    Output:
      4 2
      abcdef
      ebcd af

  Note
    strlen() gives the size, "%s%s" concatenates for printing
    only (the strings themselves are unchanged), and the first
    characters are swapped with the temp-variable technique from
    Module 9.
=====================================================================
*/

// #include <stdio.h>
// #include <string.h>
//
// int main()
// {
//     char s[15], t[15];
//     scanf("%s %s", s, t);
//
//     int len_s = strlen(s);
//     int len_t = strlen(t);
//     printf("%d %d\n", len_s, len_t);
//     printf("%s%s\n", s, t);
//
//     char temp = s[0];
//     s[0] = t[0];
//     t[0] = temp;
//     printf("%s %s\n", s, t);
//
//     return 0;
// }
