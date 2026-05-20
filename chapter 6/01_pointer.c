#include<stdio.h>
int main()
{
int i =72;
int* j= &i; 
int k=45;   //  j is a pointer pointing to i .....j i ko address store gardai xa

printf("The address of value is %p\n",&i);

printf("The address of value is %p\n",j);

printf("The address of value is %u\n",&k);

printf("The value at address j is %d\n" , *(&i));
return 0;
}