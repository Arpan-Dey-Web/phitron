1. Take a number from user and check if its a even number or odd number.

```c
# include <stdio.h>
int main (){
  int a;
  printf("Enter an number : ");
  scanf("%d", &a);
  if(a%2 == 0){
    printf("Even Number");
  }else{
        printf("Odd Number");
  }
}

```

2. Take a number from user and check if its a positive or negative number.

```c
#include <stdio.h>

int main (){
  int a;
  printf("Enter Your Number");
  scanf("%d", &a);
  if(a<0){
      printf("Positive");
  }else {
          printf("Negative");
  }
  return 0;
}

```

3. Explain if else ladder.
Ans: if else Ladders means when we defind an if statement. after that if we need more if statement than we use else if statement. for more we can use else if statement again and again. the way we are defining if, else if, else that was called if else ladder 