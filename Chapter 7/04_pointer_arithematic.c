#include<stdio.h>
int main()
{
int a = 5;
int* ptr = &a;
printf("The address of a is %u\n",&a);
printf("The address of a is %u\n",ptr);
ptr ++;  // hamro variable kati bits le increment hudai xa tei aanusar
printf("The value  of ptr is %u", ptr);

return 0;
}