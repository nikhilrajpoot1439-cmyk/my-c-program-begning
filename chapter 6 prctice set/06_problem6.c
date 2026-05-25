
// Write a program to print the value of a variable "i" by using "pointer to pointer " type of variable


#include<stdio.h>
int main()
{
int i = 2;
int* ptr =&i;
int** ptr2 =&i;
printf("The address of i is %u\n" , &i);
printf("The value of i is %d\n" , *ptr);
printf("The value of i is %d\n" , **ptr2);
return 0;
}