
/*
P. Shape1
time limit per test1 second
memory limit per test256 megabytes
Given a number N. Print a face down right angled triangle that has N rows.

For more clarification see the example below.

Input
Only one line containing a number N (1 ≤ N ≤ 99).

Output
Print the answer according to the required above.

Example
InputCopy
4
OutputCopy
****
***
**
*
Note
Don't print any extra spaces after symbol " * ".
*/

/*
#include <stdio.h>
int main() {
    int n;
    scanf("%d", &n);
    
   for (int i =n; i>=1; i--)
   {
        for(int j =0; j<i; j++)
        {
            printf("*");
        }

    printf("\n");
   }
   
    return 0;
}
*/ 





/*
T. Shape2
time limit per test1 second
memory limit per test256 megabytes
Given a number N. Print a pyramid that has N rows.

For more clarification see the example below.

Input
Only one line containing a number N (1 ≤ N ≤ 99).

Output
Print the answer according to the required above.

Example
InputCopy
4
OutputCopy
   *
  ***
 *****
*******
Note
Don't print any extra spaces after symbol " * ".
*/


// #include <stdio.h>

// int main() {
//     int n;
//     scanf("%d", &n);

//     for (int i = 1; i <= n; i++) {
//         // Print leading spaces
//         for (int j = 1; j <= n - i; j++) {
//             printf(" ");
//         }
//         // Print stars (1, 3, 5, 7, ...)
//         for (int k = 1; k <= (2 * i - 1); k++) {
//             printf("*");
//         }
//         printf("\n");
//     }

//     return 0;
// }

