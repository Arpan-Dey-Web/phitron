
// pre and post increment 
// #include <stdio.h>
// int main(){
//     int x =10;
//     int y=x++; // যেহেতু x++ এক্সপ্রেশনের কাজ শেষ হওয়ার সাথে সাথেই x-এর মান আপডেট হয়ে যায়, তাই পরবর্তী লাইনে x-প্রিন্ট করলে ১১ দেখায়।
//     printf("%d %d\n", x,y );
//     int z=++y;
//     printf("%d %d %d", x,y,z );
//   return 0;
// }


// Given a number N. Print all even numbers between 1 and N inclusive in separate lines.

// Input
// Only one line containing a number N (1 ≤ N ≤ 103).

// Output
// Print the answer according to the required above. If there are no even numbers print -1.

// Examples
// InputCopy
// 10
// OutputCopy
// 2
// 4
// 6
// 8
// 10
// InputCopy
// 5
// OutputCopy
// 2
// 4

// #include <stdio.h>
// int main(){
//     int n;
//     scanf("%d" , &n);
//     if(n==1){
//       printf("-1");
//     }else{
//         for(int i=1; i<=n; i++){
//             if (i%2 == 0){
//               printf("%d\n", i); 
//             }
//           }
//     }
 
//   return 0;
// }






// C. Even, Odd, Positive and Negative
// time limit per test1 second
// memory limit per test256 megabytes
// Given N numbers. Count how many of these values are even, odd, positive and negative.

// Input
// First line contains one number N (1 ≤ N ≤ 103) number of values.

// Second line contains N numbers (-105 ≤ Xi ≤ 105).

// Output
// Print four lines with the following format:

// First Line: "Even: X", where X is the number of even numbers in the given input.

// Second Line: "Odd: X", where X is the number of odd numbers in the given input.

// Third Line: "Positive: X", where X is the number of positive numbers in the given input.

// Fourth Line: "Negative: X", where X is the number of negative numbers in the given input.

// Example
// InputCopy
// 5
// -5 0 -3 -4 12
// OutputCopy
// Even: 3
// Odd: 2
// Positive: 1
// Negative: 3
// Note
// First Example :
// Even Numbers are : 0, -4 , 12
// Odd Numbers are : -5 , -3
// Positive Numbers are : 12
// Negative Numbers are : -5 , -3 , -4


// #include <stdio.h>
// int main(){
//   int takeInput;
//   int input;
//   int even =0,odd=0, positive=0, negative =0;
//   scanf("%d", &takeInput);

//   for (int i=1; i<=takeInput; i++)
//   {

//     scanf("%d", &input );
//       if(input > 0 )
//       {
//        positive+=1;
//       }
//       else if (input <0 )
//       {
//           negative+=1;
//       }
//     if(input %2==0 )
//     {
//       even+=1;
//     } else
//     {
//         odd+=1;
//     }
//   }

//       printf("Even: %d\n", even);
//       printf("Odd: %d\n", odd);
//       printf("Positive: %d\n", positive);
//       printf("Negative: %d\n", negative);
//   return 0;
// }



// D. Fixed Password
// time limit per test1 second
// memory limit per test256 megabytes
// Given multiple lines each line contains a number X which is a password. Print "Wrong" if the password is incorrect otherwise, print "Correct" and terminate the program.

// Note: The "Correct" password is the number 1999.

// Input
// The input contains several passwords.

// Each line contains a number X (103 ≤ X ≤ 104 - 1).

// Output
// Print "Wrong" if the password is typed wrong otherwise, print "Correct" if the password is typed correctly.

// Example
// InputCopy
// 2200
// 1020
// 1999
// 1000
// 9999
// OutputCopy
// Wrong
// Wrong
// Correct


// EOF-> Ebd of file
// #include <stdio.h>
// int main(){
//     int x;
//     while (scanf("%d", &x ) !=EOF){
//       if (x==1999){
//         printf("Correct");
//         break:
//       }else{
//         printf("Wrong");
//       }
//     }
//   return 0;
// }


  // #include <stdio.h>
  // int main(){
  //     int x;
  //     for(; scanf("%d", &x ) !=EOF;) {
  //       if (x==1999){
  //         printf("Correct\n");
  //         break;
  //       }else{
  //         printf("Wrong\n");
  //       }
  //     }
  //   return 0;
  // }


// E. Max
// time limit per test1 second
// memory limit per test256 megabytes
// Given a number N, and N numbers, find maximum number in these N numbers.

// Input
// First line contains a number N (1 ≤ N ≤ 103).

// Second line contains N numbers Xi (0 ≤ Xi ≤ 109).

// Output
// Print the maximum number.

// Example
// InputCopy
// 5
// 1 8 5 7 5
// OutputCopy
// 8

// #include <stdio.h>
// int main(){
//     int max=0;
//     int n;
//     scanf("%d", &n );
//     for(int i =1;i<=n;i++)
//     {
//       int val;
//           scanf("%d", &val );
//           if(val>max){
//             max=val;
//           }
//     }
//     printf("%d",max);
//   return 0;
// }

// #include <stdio.h>
// #include <limits.h>
// int main(){
//     int max=INT_MIN;
//     int n;
//     scanf("%d", &n );
//     for(int i =1;i<=n;i++)
//     {
//       int val;
//           scanf("%d", &val );
//           if(val>max){
//             max=val;
//           }
//     }
//     printf("%d",max);
//   return 0;
// }


// Multiplication table

// #include <stdio.h>
// int main(){
//     int n;
//     scanf("%d", &n );
//     for(int i =1; i<=12; i++)
//     {
//       printf("%d * %d = %d\n", n, i, n*i);
//     }
//     return 0;
// }


// Q. Digits
// time limit per test1 second
// memory limit per test256 megabytes
// Given a number N. Print the digits of that number from right to left separated by space.

// Input
// First line contains a number T (1 ≤ T ≤ 10) number of test cases.

// Next T lines will contain a number N (0 ≤ N ≤ 109)

// Output
// For each test case print a single line contains the digits of the number separated by space.

// Example
// Input
// 4
// 121
// 39
// 123456
// 1200
// Output
// 1 2 1
// 9 3
// 6 5 4 3 2 1
// 0 0 2 1



// #include <stdio.h>
// int main(){
//     int t;
//     scanf("%d ", &t );
  
//     for (int i=1; i<=t; i++){
//       int n;
//       scanf("%d",&n );
//       while(n!=0){ // n 0 na howya porjonto loop colbe
//          printf("%d", n%10); // 10 diye mod korle last digit ta print hobe 
//           n/=10;// vag korle last digit remove hoye jabe and sei value tai abr n r modde store hobe.
//       }
//       printf("\n");
//     }
//   return 0;
// }

// while loop 
    // #include <stdio.h>
    // int main(){
    // int t;
    // int n;
    // scanf("%d", &t);

    // for(int i=1; i<=t; i++){
    //   scanf("%d", &n );
    //   if(n==0){
    //     printf("%d", n);
    //   }
    //   while(n!=0){
    //       printf("%d ", n%10);
    //       n/=10;
    //     }
    //     printf("\n");
    // } 
    //   return 0;
    // }

//  do while loop 
    #include <stdio.h>
    int main(){
    int t;
    int n;
    scanf("%d", &t);

    for(int i=1; i<=t; i++){
      scanf("%d", &n );
     do{
          printf("%d ", n%10);
          n/=10;
        } while(n!=0);
        printf("\n");
    } 
      return 0;
    }
