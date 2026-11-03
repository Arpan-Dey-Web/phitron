/*
  Module 11 — String functions: copy, concat, compare (C)

  Each problem below is written as:
    - statement in a block comment
    - solution code commented out

  All solutions are kept commented out.
  To run one, comment out the others and uncomment its code.
*/


/*
=====================================================================
  Concept : Copy a String Manually
=====================================================================

  Statement
    Read two words and copy the first one into the second, using
    a loop instead of a library function.

  Example
    Input : cat dog
    Output: cat cat

  Note
    The loop runs i <= len so that the '\0' is copied too —
    without it, b is not a valid string and printf keeps reading
    garbage.

    Here a is copied INTO b:  b[i] = a[i]
=====================================================================
*/

/*
#include <stdio.h>
#include <string.h>

int main()
{
    char a[101], b[101];
    scanf("%s %s", a, b);

    int len = strlen(b);
    for (int i = 0; i <= len; i++)
    {
        b[i] = a[i];
    }

    printf("%s %s", a, b);
    return 0;
}
*/


/*
=====================================================================
  Concept : Copy a String with strcpy()
=====================================================================

  Statement
    Read two words and copy the second into the first with the
    library function.

  Example
    Input : cat dog
    Output: dog dog

  Note
    strcpy(destination, source) — the DESTINATION comes first.
    strcpy(a, b) makes a a copy of b; b itself stays unchanged.
    Declared in <string.h>.
=====================================================================
*/

/*
#include <stdio.h>
#include <string.h>

int main()
{
    char a[101], b[101];
    scanf("%s %s", a, b);

    strcpy(a, b);

    printf("%s %s", a, b);
    return 0;
}
*/


/*
=====================================================================
  Concept : Concatenate Strings Manually
=====================================================================

  Statement
    Join the second word to the end of the first one, using a
    loop instead of a library function.

  Example
    Input : cat dog
    Output: catdog dog

  Note
    Writing starts at index strlen(a) and must ALSO store the
    '\0': the loop runs i <= lengthB, so
    a[lengthA + lengthB] = '\0'.

    With i < lengthB the last slot keeps old garbage and printf
    prints garbage after the joined text.
=====================================================================
*/

/*
#include <stdio.h>
#include <string.h>

int main()
{
    char a[101], b[101];
    scanf("%s %s", a, b);

    int lengthA = strlen(a);
    int lengthB = strlen(b);

    for (int i = 0; i <= lengthB; i++)          // <= copies '\0' too
    {
        a[lengthA + i] = b[i];
    }

    printf("%s %s", a, b);
    return 0;
}
*/


/*
=====================================================================
  Concept : Concatenate Strings with strcat()
=====================================================================

  Statement
    Join the second word to the first with the library function.

  Example
    Input : cat dog
    Output: catdog dog

  Note
    strcat(destination, source) — destination first.
    Only a changes (a becomes a + b); b stays as it was.
    The destination array must be big enough for BOTH strings
    plus '\0'.
=====================================================================
*/

/*
#include <stdio.h>
#include <string.h>

int main()
{
    char a[101], b[101];
    scanf("%s %s", a, b);

    strcat(a, b);

    printf("%s %s", a, b);
    return 0;
}
*/


/*
=====================================================================
  Problem : Compare Two Strings Manually (Lexicographical)
=====================================================================

  Statement
    Read two words and print "Equal", "A is smaller" or
    "B is smaller" using dictionary order — without strcmp().

  Examples
    Input : apple mango    Output: A is smaller
    Input : mango apple    Output: B is smaller
    Input : tiger tiger    Output: Equal
    Input : abc abcd       Output: A is smaller

  Note
    Walk forward while the characters are equal, then compare
    the first different position.

    My first version had two bugs:
      a[1] == '\0'   → index 1 never moves; must be a[i]
      a[1] == '0'    → '0' is the digit ZERO (48), not '\0' (0)

    "abc" < "abcd" because at index 3: '\0' (0) < 'd' (100) —
    a shorter prefix is smaller.
=====================================================================
*/

/*
#include <stdio.h>

int main()
{
    char a[101], b[101];
    scanf("%s %s", a, b);

    int i = 0;
    while (a[i] != '\0' && b[i] != '\0' && a[i] == b[i])
    {
        i++;
    }

    if (a[i] == b[i])
    {
        printf("Equal");
    }
    else if (a[i] < b[i])
    {
        printf("A is smaller");
    }
    else
    {
        printf("B is smaller");
    }

    return 0;
}
*/


/*
=====================================================================
  Problem : Compare Two Strings with strcmp()
=====================================================================

  Statement
    Read two words and compare them with the library function.

  Examples
    Input : apple mango    Output: A is smaller
    Input : tiger tiger    Output: Equal
    Input : mango apple    Output: B is smaller

  Note
    strcmp(a, b) returns
        < 0  when a is lexicographically smaller
        = 0  when the strings are equal
        > 0  when a is greater
    Only the SIGN is guaranteed, so compare with 0 — never with
    an exact value like -1.
=====================================================================
*/

/*
#include <stdio.h>
#include <string.h>

int main()
{
    char a[101], b[101];
    scanf("%s %s", a, b);

    int val = strcmp(a, b);
    if (val < 0)
    {
        printf("A is smaller");
    }
    else if (val > 0)
    {
        printf("B is smaller");
    }
    else
    {
        printf("Equal");
    }

    return 0;
}
*/
