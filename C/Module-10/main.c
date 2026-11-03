/*
  Module 10 — Strings (C)

  Each problem below is written as:
    - statement in a block comment
    - solution code commented out

  All solutions are kept commented out.
  To run one, comment out the others and uncomment its code.
*/


/*
=====================================================================
  Concept : String Input and Output with %s
=====================================================================

  Statement
    Read one word from the user and print it back.

  Input
    A single word (no spaces).

  Example
    Input : HELLO
    Output: HELLO

  Note
    %s is used for BOTH scanf and printf.
    scanf("%s", s)  -> the array name s is already an address,
                       so &s is not needed (and not correct).
    scanf("%s") stops at the first space, so only one word is read.
    Keep room for '\0': char s[10] fits at most 9 characters.
=====================================================================
*/

/*
#include <stdio.h>

int main()
{
    char s[10];
    scanf("%s", s);
    printf("%s", s);
    return 0;
}
*/


/*
=====================================================================
  Concept : Reading a Whole Line with fgets()
=====================================================================

  Statement
    Read a full line (spaces allowed) and print it.

  Input
    One line of text.

  Example
    Input :
      Arpan Dey

    Output:
      Arpan Dey
      (plus a newline, because fgets stores the Enter key as '\n')

  Note
    fgets(s, size, stdin) reads at most size-1 characters or up to
    ENTER — whichever comes first — and STORES the '\n'.
    fgets() is declared in <stdio.h>, NOT <string.h>.
    scanf("%s") cannot do this: it stops at the first space.
=====================================================================
*/

/*
#include <stdio.h>

int main()
{
    char s[30];
    fgets(s, 30, stdin);
    printf("%s", s);
    return 0;
}
*/


/*
=====================================================================
  Concept : String Initialization at Declaration
=====================================================================

  Statement
    Declare a string with a value and print it.

  Example
    Output:
      Arpan Dey

  Note
    char s[30] = "Arpan Dey";
    -> the characters AND the terminating '\0' are stored for me.
       Everything after '\0' stays unused.
=====================================================================
*/

/*
#include <stdio.h>

int main()
{
    char s[30] = "Arpan Dey";
    printf("%s", s);
    return 0;
}
*/


/*
=====================================================================
  Problem : Length of a String (manual loop)
=====================================================================

  Statement
    Read a word and print how many characters it has, by counting
    until the null terminator is reached.

  Example
    Input : HELLO
    Output: 5

  Note
    The loop condition s[i] != '\0' stops exactly at the end of
    the string, so '\0' itself is never counted.
=====================================================================
*/

/*
#include <stdio.h>

int main()
{
    char s[100];
    scanf("%s", s);

    int count = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        count++;
    }

    printf("%d", count);
    return 0;
}
*/


/*
=====================================================================
  Problem : Length of a String with strlen()
=====================================================================

  Statement
    Read a word and print its length using the library function.

  Example
    Input : HELLO
    Output: 5

  Note
    strlen() is declared in <string.h>.
    It counts the characters before '\0' and does not count '\0'.
=====================================================================
*/

/*
#include <stdio.h>
#include <string.h>

int main()
{
    char s[100];
    scanf("%s", s);

    int size = strlen(s);
    printf("%d", size);
    return 0;
}
*/


/*
=====================================================================
  Problem : Sum of Digits of a Very Large Number
=====================================================================

  Statement
    Given a number that does not fit in long long, print the sum
    of its digits.

  Input
    One line containing the number as text.

  Example
    Input : 351
    Output: 9          (3 + 5 + 1)

  Note
    Read the number as a STRING, then convert each character:

        s[i] - '0'   ->   '3' - '0' = 51 - 48 = 3

    This is char arithmetic from Module 5 applied to digits.
=====================================================================
*/

/*
#include <stdio.h>
#include <string.h>

int main()
{
    char s[1000001];
    scanf("%s", s);

    int length = strlen(s);
    int sum = 0;
    for (int i = 0; i < length; i++)
    {
//         sum += s[i] - '0';        // character -> digit value
    }

    printf("%d", sum);
    return 0;
}
*/
