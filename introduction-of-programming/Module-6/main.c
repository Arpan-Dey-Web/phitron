// I. Welcome for you with Conditions
// time limit per test1 second
// memory limit per test64 megabytes
// Given two numbers A and B. Print "Yes" if A is greater than or equal to B. Otherwise print "No".

// Input
// Only one line containing two numbers A and B (0  ≤  A, B  ≤  100).

// Output
// Print "Yes" or "No" according to the statement.

// Examples
// InputCopy
// 10 9
// OutputCopy
// Yes
// InputCopy
// 5 5
// OutputCopy
// Yes
// InputCopy
// 5 7
// OutputCopy
// No
// #include <stdio.h>
// int main(){
//     int a, b;
//     scanf("%d %d", &a, &b );
//     if(a>=b){
//       printf("Yes");
//     }else{
//       printf("No");
//     }
//   return 0;
// }



// J. Multiples
// time limit per test1 second
// memory limit per test256 megabytes
// Given two numbers A and B. Print "Multiples" if A is multiple of B or vice versa. Otherwise print "No Multiples".

// Input
// Only one line containing two numbers A, B (1  ≤  A, B  ≤  106)

// Output
// Print the "Multiples" or "No Multiples" corresponding to the read numbers.

// Examples
// InputCopy
// 9 3
// OutputCopy
// Multiples
// InputCopy
// 6 24
// OutputCopy
// Multiples
// InputCopy
// 12 5
// OutputCopy
// No Multiples
// Note
// ***A is said to be Multiple of B if B is divisible by A.

// First Example :

// 9 is divisible by 3 , So the answer is: Multiples.

// Second Example :

// 6 is not divisible by 24 but

// 24 is divisible by 6 , So the answer is: Multiples.

// Third Example :

// 12 is not divisible by 5 and 5 is not divisible by 12.

// So the answer is: No Multiples.



// #include <stdio.h>
// int main(){
//   int a, b;
//   scanf("%d %d", &a, &b );
//   if(a %b ==0|| b%a==0){
//     printf("Multiples");
//   }else{
//     printf("No Multiples");
//   }
    
//   return 0;
// }



// P. First digit !
// time limit per test0.25 seconds
// memory limit per test64 megabytes
// Given a number X. Print "EVEN" if the first digit of X is even number. Otherwise print "ODD".

// For example: In 4569 the first digit is 4, the second digit is 5, the third digit is 6 and the fourth digit is 9.

// Input
// Only one line containing a number X (999 < X  ≤  9999)

// Output
// If the first digit is even print "EVEN" otherwise print "ODD".

// Examples
// InputCopy
// 4569
// OutputCopy
// EVEN
// InputCopy
// 3569
// OutputCopy
// ODD
// Note
// Second Example :

// In 3569 the first digit is 3 and its ODD.





// #include <stdio.h>
// int main(){
//   int a;
//   scanf("%d" , &a);
//   int evenOrOdd =a/1000;
 
//   if(evenOrOdd%2==0)
//   {
//     printf("EVEN");
//   }else{
//     printf("ODD");
//   }
    
//   return 0;
// }

// Note for remove somenumber from last we can divide that number with 1 and 0 for 4569 we have to divide by 1000 bcz thats and 4 digit number then we will get and float value but we will assaign that value into int so int will take the int value only 
//  for get last digit of that number we 4569 we have divide by 10 than we wil get the vagshes of 9 that means we will get the last digit



// N. Char
// time limit per test0.25 seconds
// memory limit per test64 megabytes
// Given a letter X. If the letter is lowercase print the letter after converting it from lowercase letter to uppercase letter. Otherwise print the letter after converting it from uppercase letter to lowercase letter

// Note : difference between 'a' and 'A' in ASCII is 32 .

// Input
// Only one line containing a character X which will be a capital or small letter.

// Output
// Print the answer to this problem.

// Examples
// InputCopy
// a
// OutputCopy
// A
// InputCopy
// A
// OutputCopy
// a


// #include <stdio.h>
// int main(){
//     char ch;
//     scanf("%c", &ch );

//     if(ch >='a' &&  ch <='z'){
//       ch=ch-32;
//       printf("%c", ch );
//     }else{
//       ch=ch+32;
//       printf("%c", ch );
//     }
//   return 0;
// }

// M. Capital or Small or Digit
// time limit per test1 second
// memory limit per test256 megabytes
// Given a letter X. Determine whether X is Digit or Alphabet and if it is Alphabet determine if it is Capital Case or Small Case.

// Note:

// Digits in ASCII '0' = 48,'1' = 49 ....etc
// Capital letters in ASCII 'A' = 65, 'B' = 66 ....etc
// Small letters in ASCII 'a' = 97,'b' = 98 ....etc
// Input
// Only one line containing a character X which will be a capital or small letter or digit.

// Output
// Print a single line contains "IS DIGIT" if X is digit otherwise, print "ALPHA" in the first line followed by a new line that contains "IS CAPITAL" if X is a capital letter and "IS SMALL" if X is a small letter.

// Examples
// InputCopy
// A
// OutputCopy
// ALPHA
// IS CAPITAL
// InputCopy
// 9
// OutputCopy
// IS DIGIT
// InputCopy
// a
// OutputCopy
// ALPHA
// IS SMALL
// Note
// ** recommended to read this to know more about ASCII Code https://www.javatpoint.com/ascii.




// #include <stdio.h>
// int main(){
//     char ch;
//     scanf("%c", &ch );

//     if(ch>='0' && ch<='9' ){
//       printf("IS DIGIT\n");
//     }
//     else if( ch >='a' && ch <='z' || ch >='A' && ch <='Z') {
//       printf("ALPHA\n");
//       if (ch >='a' && ch <='z') {
//         printf("IS SMALL\n");
//       }else{
//         printf("IS CAPITAL\n");
//       }
//     }
//   return 0;
// }




// Given 3 numbers A, B and C, Print the minimum and the maximum numbers.

// Input
// Only one line containing 3 numbers A, B and C ( - 105 ≤ A, B, C ≤ 105)

// Output
// Print the minimum number followed by a single space then print the maximum number.

// Examples
// InputCopy
// 1 2 3
// OutputCopy
// 1 3
// InputCopy
// -1 -2 -3
// OutputCopy
// -3 -1
// InputCopy
// 10 20 -5
// OutputCopy
// -5 20

// #include <stdio.h>
// int main(){
//   int maximumNumber = 0;
//   int minimumNumber = 0;
//   int a, b, c;
//     scanf("%d %d %d", &a, &b, &c );

//     if(a>=b && a>=c ){
//       maximumNumber=a;
//     }else if ( b>=a && b>=c){
//       maximumNumber=b;
//     }else{
//       maximumNumber =c;
//     }

//     if(a<=b && a<=c ){
//       minimumNumber=a;
//     }else if ( b<=a && b<=c){
//       minimumNumber=b;
//     }else{
//       minimumNumber =c;
//     }
//     printf("%d %d", minimumNumber, maximumNumber );
//   return 0;
// }
