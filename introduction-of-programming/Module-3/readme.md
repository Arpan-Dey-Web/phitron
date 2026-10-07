# Loop

3 types of loop in c programming

- for loop
- while loop
- do while loop

for loop

```c
for (int i =0;i<=10; i++){
  printf("I am Sorry");
}
```

int i = declare an varable for the loop; bcz variable is very important for the loop. based on the declared variable we can off the variable;

i<=10 means until i value less than or equal to 10 the loop will run.

i++ means every time we are increaseing the i value it can be write as i = i+1 or i+=1
difference between i++, i+=Number, i =i+Number
when we use i++ that will increase +1 on every single loop
but i+=Number and i=i+Number in the place of number we can enter any number that we want to increase
both are work as a same.

printf("I am sorry");
this line will runs until the loop was end

now lets sum of 1 to n

```c
# include <stdio.h>

int main (){
  int num;
  scanf("%d", &num );
  int totalSum=0;
  for(int i =1; i<=num;i++){
    totalSum+=i;
  }
  printf("%d\n", totalSum);
  return 0;
}

```

break
we can use break when we need stop the loop.

```c
#include <stdio.h>
int main(){
  for (int i=0; i<=10; i++){
    if(i==5){
      break;
    }
    printf("%d",i)
  }
}

```

this code will return output 1,2,3,4  
when ever 5 comes if condition will be true and it will break the loop. and exit from that loop

note: break should be written within an loop.

Continue
skip an specifiq step

```c
#include <stdio.h>
int main(){
  for (int i=0; i<=10; i++){
    if(i==5){
      continue;
    }
    printf("%d",i)
  }
}

```

this code will return output 1,2,3,4,6,7,8,9,10
when iterator value 5 if condiotion will be true and skip that loop goes to next step and start printing the other output.

note: Continue should be written within an loop.

While Loop

```c

int i =0;
while (i<=10){
  printf("%d\n",i)
  i++;
}
```

Do While Loop

```c
#include <stdio.h>
int main (){
int i =0;
do{
  printf("%d\n",i)
  i++;
}while (i<=10)

}
```
Note : do while loop will run atleast 1 time 