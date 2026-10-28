/*
  Module 7 — Extra Practice (Arrays)

  Practice problems to solve on my own. Each task: statement +
  sample. Write the solution below the task (keep it commented
  after solving, like main.c).
*/


/*
=====================================================================
  Task 1 : Print All Even Numbers
=====================================================================

  Statement
    Take an array from input and print all the even numbers
    of that array.

  Sample
    Input :
      5
      1 2 3 4 5

    Output:
      2 4

  Hint
    Loop over the array, keep arr[i] when arr[i] % 2 == 0.
=====================================================================
*/

// #include <stdio.h>
// int main()
// {
//   int n;
//   scanf("%d", &n );
//   for (int i =1; i<=n; i++)
//     {
//       if(i%2==0){
//         printf("%d\n", i);
//       }
//     }
//   return 0;
// }


/*
=====================================================================
  Task 2 : Count Odd Numbers
=====================================================================

  Statement
    Take an array from input and count how many odd numbers
    are present in that array.

  Sample
    Input :
      5
      1 2 3 4 5

    Output:
      3

  Hint
    Counter variable starting at 0, += 1 when arr[i] % 2 != 0.
=====================================================================
*/
// #include <stdio.h>
// int main()
// {
//   int n;
//   int totalOddNumber=0;
//   scanf("%d", &n );
//   for (int i =1; i<=n; i++)
//     {
//       if(i%2==1){
//       totalOddNumber++;
//       }
//     }
//     printf("%d", totalOddNumber);
//   return 0;
// }

/*
=====================================================================
  Task 3 : Maximum Value
=====================================================================

  Statement
    Take an array from input and print the maximum value
    of that array.

  Sample
    Input :
      5
      1 8 5 7 3

    Output:
      8

  Hint
    Same running-max pattern as Module 6 problem E.
    Safe start: arr[0], or INT_MIN from <limits.h>.
=====================================================================
*/
// #include <stdio.h>
// int main()
// {
//   int n;
//   int currentNumber=0;
//   int maximumNumber=0;
//   scanf("%d", &n );
//   for (int i =1; i<=n; i++)
//     {
//       scanf("%d", &currentNumber );
//       if (currentNumber >maximumNumber)
//       {
//         maximumNumber=currentNumber;
//       }
//     }
//     printf("%d", maximumNumber);
//   return 0;
// }

/*
=====================================================================
  Task 4 : Minimum Value
=====================================================================

  Statement
    Take an array from input and print the minimum value
    of that array.

  Sample
    Input :
      5
      1 8 5 7 3

    Output:
      1

  Hint
    Same as Task 3, but compare with < instead of >.
=====================================================================
*/


// #include <stdio.h>
// int main()
// {
//   int n;
//   int currentNumber;
//   int minimumNumber;
//   scanf("%d", &n );
//   for (int i =1; i<=n; i++)
//     {
//       scanf("%d", &currentNumber );
//       if (currentNumber < minimumNumber)
//       {
//         minimumNumber=currentNumber;
//       }
//     }
//     printf("%d", minimumNumber);
//   return 0;
// }