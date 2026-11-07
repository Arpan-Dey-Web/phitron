/*
  Module 15 — Pointers (C)

  Each problem below is written as:
    - statement in a block comment
    - solution code commented out

  All solutions are kept commented out.
  To run one, comment out the others and uncomment its code.
*/


/*
=====================================================================
  Concept : Pointer Variable — Address and Value
=====================================================================

  Statement
    Print a variable's value, its address, and the value reached
    through a pointer.

  Output
    10
    0x7ffd...      (address of x — differs every run)
    0x7ffd...      (ptr holds the same address)
    10             (*ptr = the value stored there)

  Note
    int *ptr = &x;   → ptr stores the ADDRESS of x
    &x               → address-of operator
    *ptr             → dereference: the value AT that address
    %p prints addresses, %d prints the integer value.
=====================================================================
*/

// #include <stdio.h>
//
// int main()
// {
//     int x = 10;
//     printf("%d\n", x);       // value
//     printf("%p\n", &x);      // address
//
//     int *ptr = &x;
//     printf("%p\n", ptr);     // same address, via the pointer
//     printf("%d\n", *ptr);    // value at that address
//
//     return 0;
// }


/*
=====================================================================
  Concept : Pass by Value
=====================================================================

  Statement
    Call a function with an integer and print the value and the
    address of the parameter inside the function, then the value
    and the address of main's variable.

  Note
    The function receives a COPY. Its x is a different variable
    in a different memory slot — the addresses printed inside
    the function and in main() are NOT the same.

    Nothing the function does can change main's x.
=====================================================================
*/

// #include <stdio.h>
//
// void func(int x)
// {
//     printf("function x value %d\n", x);
//     int *ptr = &x;
//     printf("function x address %p\n", ptr);
// }
//
// int main()
// {
//     int x = 10;
//     func(10);
//
//     printf("main function x value %d\n", x);
//     int *ptr = &x;
//     printf("main function x address %p\n", ptr);
//
//     return 0;
// }


/*
=====================================================================
  Concept : Pass by Reference
=====================================================================

  Statement
    Change main's variable from inside a function by handing the
    function its address.

  Output
    30

  Note
    func(&x)      → main passes the ADDRESS
    *ptr = 30     → the function writes through that address
    main's x      → becomes 30

    This is the same reason scanf() needs &:
    scanf must WRITE into the real variable, so it needs the
    address — not a copy that would be thrown away.
=====================================================================
*/

// #include <stdio.h>
//
// void func(int *ptr)
// {
//     *ptr = 30;
// }
//
// int main()
// {
//     int x = 10;
//     func(&x);
//
//     printf("main function x value %d\n", x);   // 30
//
//     return 0;
// }


/*
=====================================================================
  Concept : Pointers and Arrays
=====================================================================

  Statement
    Print the address of an array and of its elements, and read
    the first element through a pointer.

  Note
    a      ==  &a[0]        the array name IS the first address
    &a[1]  ==  &a[0] + 4    elements sit sizeof(int) apart
                            (typically 4 bytes — check with
                            sizeof(int))
    *a     ==  a[0]         dereference the first element
    *(a+1) ==  a[1]         pointer arithmetic moves by one
                            whole element, not one byte

    address of a[i] = base address + i * sizeof(int)
=====================================================================
*/

// #include <stdio.h>
//
// int main()
// {
//     int a[5] = {10, 20, 30, 40, 50};
//
//     printf("%p\n", a);       // same as &a[0]
//     printf("%p\n", &a[0]);
//     printf("%p\n", &a[1]);   // +4 bytes
//     printf("%p\n", &a[2]);   // +8 bytes
//
//     printf("%d\n", *a);      // 10
//
//     *(a + 1) = 200;          // changes a[1] to 200
//     printf("%d\n", a[1]);    // 200
//
//     return 0;
// }


/*
=====================================================================
  Concept : Function Receiving an Array (Pass by Reference)
=====================================================================

  Statement
    Print every element of an array from inside a function.

  Output
    10
    20
    30
    40
    50

  Note
    The array is NOT copied: func(arr, 5) hands over the
    address of main's array (arr[] in the parameter list really
    means a pointer). Copying int arr[1000000] on every call
    would waste megabytes.

    No & is needed — the array name already is the address.

    Because it is the same memory, the function could also
    MODIFY main's elements.
=====================================================================
*/

// #include <stdio.h>
//
// void func(int arr[], int n)
// {
//     for (int i = 0; i < n; i++)
//     {
//         printf("%d\n", arr[i]);
//     }
// }
//
// int main()
// {
//     int arr[5] = {10, 20, 30, 40, 50};
//     func(arr, 5);
//
//     return 0;
// }


/*
=====================================================================
  Concept : Function Receiving a String
=====================================================================

  Statement
    Read a word and print it from inside a function that takes
    the string as its parameter.

  Example
    Input : hello
    Output: hello

  Note
    A string is a char array, so it follows the array rule: the
    function receives a POINTER to the characters, not a copy.

        main's s  ──pointer──►  func's s   (same characters)

    That is also how strcpy()/strcat()/strcmp() from Module 11
    work, and why a function CAN change the caller's string
    (e.g. uppercase the first letter).
=====================================================================
*/

// #include <stdio.h>
//
// void func(char s[], int n)
// {
//     printf("%s", s);
// }
//
// int main()
// {
//     char s[10];
//     scanf("%s", s);
//     func(s, 10);
//
//     return 0;
// }
