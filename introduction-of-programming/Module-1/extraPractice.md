1. Explain why we need long long int data type?
ans: many times we need the long long integer for example

- mobile number
- database id
- long number operations

2. Write all the rules for naming a variable in C programming.
- can't use number infront of variable name ex: 123Arpan ->x. But name after Number is valid ex: arpan123 -> ok 
- we start our variable name _ and small laters ex: name, _name
- cannot use special symbol infront of variable name ex: @name ->x 

3. Write a C program that will take 2 numbers from the user and then print the 2nd number first and then first number.
Ans:
```
#include <stdio.h>
int main(){
  int a;
  int b;
  printf("Enter Your First Number\n");
  scanf("%d", &a);
  printf("Enter Your Second Number\n");
  scanf("%d", &b);
  printf("Your Second Number : %d\n",b);
  printf("Your First Number : %d\n",a);
  return 0;
}

```

