/*
S. Sum of Consecutive Odd Numbers
time limit per test1 second
memory limit per test256 megabytes
Given two numbers X and Y. Print the sum of all odd numbers between them, excluding X and Y.
*/

/*
Input
First line contains a number T (1 ≤ T ≤ 10) number of test cases.
*/

/*
Next T lines will contain two numbers X and Y (0 ≤ X, Y ≤ 104).
*/

/*
Output
Print the sum of all odd numbers between X and Y (excluding X and Y).
*/

/*
Example
InputCopy
3
5 6
10 4
4 9
OutputCopy
0
21
12
*/




/*
#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    for(int i=1; i<=n; i++)
    {
      int a, b, total=0, smallNumber=0, largestNumber=0;
      scanf("%d %d",&a, &b);
      if(a<b)
      {
        smallNumber=a;
        largestNumber=b;
      }
      else
      {
        smallNumber=b;
        largestNumber=a;
      }

      for(int i=smallNumber+1; i<largestNumber;i++)
      {
        if(i%2==1)
        {
          total+=i;
        }
      }
        printf("%d \n", total);
    }

  return 0;
}
*/




