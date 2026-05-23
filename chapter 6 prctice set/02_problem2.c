
// Write a program to have a variable "i" . Print the address of "i".Pass this variable to a function and prints its address . Are these address same ? Why?

#include<stdio.h>

int returning_5(int* ptr){
    printf("The value of ptr is %d\n" , ptr);
    printf("The value at ptr is %d\n" , *ptr);
    return 5;
}
int main()
{
int i =6;
int* ptr = &i;
printf("The address of i is %u\n" , &i);
returning_5(ptr);
return 0;
}