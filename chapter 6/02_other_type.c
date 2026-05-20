#include<stdio.h>
int main()
{
char i ='A';
char* j= &i; 
  //  j is a pointer pointing to i .....(j i ko address store gardai xa)
float k = 5.32;
float*k1 = &k;
printf("The address of value is %p\n",&i);

printf("The address of value is %p\n",j);

printf("The value at address j is %d\n" , *(&i));


return 0;
}