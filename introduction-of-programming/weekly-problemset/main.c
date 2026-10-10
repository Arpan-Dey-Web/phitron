
// Zero or Non Zero
// Time Limit: 1 Seconds

// Memory Limit: 2.93 MB

// Statement
// In this problem you will be given an integer number N. Print "Zero" if the number is equals to 0 and "Non Zero" Otherwise.

// Constraints
// -1000 <= N <= 1000
// Input format
// The input consists of an integer N.
// Output Format
// Print  Zero if the number is equals to 0 and Non Zero Otherwise.
// Sample Input 1
// 5
// Sample Output 1
// Non Zero

// #include <stdio.h>
// int main (){
//     int num;
//     scanf("%d", &num);
    
//     if(num == 0){
//         printf("Zero");
//     }else{
//         printf("Non Zero");
//     }
//     return 0;
// }

// <----------------------------------------------------------------------------------------------------------------->

// 5 Marks for good hand writing
// Time Limit: 1 Seconds

// Memory Limit: 2.93 MB

// Statement
// In this problem you will be given an integer number N. You will have to add 5 with N and print it.

// Constraints
// - 1 <= N  <= 100

// Input format
// Input consists of an integer number N.
// Output Format
// Output the result after adding 5 with N.
// Sample Input 1
// 100
// Sample Output 1
// 105

// #include <stdio.h>

// int main() {
//     int a;
//     scanf("%d",&a);
//     if(a >0){
//         a +=5;
//         printf("%d",a);
//     }
//     else if( a < 0 ){
//          a -=5;
//         printf("%d",a);
//     }
//     return 0;
// }



// Multiple or not
// Time Limit: 1 Seconds

// Memory Limit: 2.93 MB

// Statement
// In this problem you will be given two integers a and b, you have to tell if one is the multiple of other. (a is the multiple of b or b is the multiple of a). 

// Constraints
//  1 <= a, b <= 10000
// Input format
//  Input will contain two integers a, b.
// Output Format
// Print "Yes" if one is the multiple of the other and "No" otherwise.
// Sample Input 1
// 5 9
// Sample Output 1
// No


// #include <stdio.h>

// int main (){
//     int a;
//     int b;
//     scanf("%d %d", &a, &b);
//     if(a%b==0){
//         printf("Yes");
//     }else{
//         printf("No");
//     }

//     return 0;
// }



// Floating Point Number
// Time Limit: 1 Seconds

// Memory Limit: 2.93 MB

// Statement
// In this problem you will be given a floating point number x. You have to print x upto 3 decimal points.

// Constraints
// 1.0 <= x <= 150.0

// Input format
// Input will contain a floating point number x.

// Output Format
//  Print the number x upto 3 decimal points.

// Sample Input 1
// 22.12344
// Sample Output 1
// 22.123

// #include <stdio.h>
// 
// int main(){
    // float num;
    // scanf("%f", &num);
    // printf("%.3f", num);
    // return 0;
// }


// Problem Statement

// You've learned about variables, right? Now its time to practice them. You need to take an integer A, a very big integer B, a floating value C and a character D as input and output them serially.

// Input Format

// First line will contain A
// Second line will contain B
// Third line will contain C
// Fourth line will contain D
// Constraints

// -10^9 <= A <= 10^9
// -10^18 <= B <= 10^18
// -10^9 <= C <= 10^9
// Output Format

// Output them serially and put a new line after each value. Output the floating value 2 points after decimal.
// Sample Input 0

// 100
// 1234567891234567
// 23.5675
// A
// Sample Output 0

// 100
// 1234567891234567
// 23.57
// A

#include <stdio.h>
int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    int A;
    long long B;
    float C;
    char D;
    scanf("%d %lf %f %c",&A,&B,&C,&D);
    printf("%d\n %lf\n %f %c ", A,B,C,D);
    return 0;
    
}





// Problem Statement

// You will be given a positive integer N, you need to print from 1 to N and besides the value, print Yes or No. Print Yes if the value is divisible by 5 and print No otherwise.

// Input Format

// Input will contain a positive integer N.
// Constraints

// 1 <= N <= 1000
// Output Format

// Output as mentioned in the question. See the sample input output for more clarifications. Put a new line after every line.
// Sample Input 0

// 10
// Sample Output 0

// 1 No
// 2 No
// 3 No
// 4 No
// 5 Yes
// 6 No
// 7 No
// 8 No
// 9 No
// 10 Yes
// Sample Input 1

// 5
// Sample Output 1

// 1 No
// 2 No
// 3 No
// 4 No
// 5 Yes



// #include <stdio.h>
// int main() {

//     /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
//     int n;
//     scanf("%d", &n );
    
//     for(int i =1; i<=n ; i++){
        
//         if(i%5==0){
//             printf("%d Yes\n",i);
//         } else{
//             printf("%d No\n",i);
//         };
//     }
//     return 0;
// }
