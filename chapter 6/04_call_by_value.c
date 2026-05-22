#include<stdio.h>

int sum(int a, int b);
int sum(int a, int b){
    a=6;   // Sum function cannot change X using A because copy of x is  provided to sum in A
    return a+b;
}

int main()
{
    int x,y;
printf("The sum of 1 and 6 is %d\n" , sum(x,y));
printf("The address of sum is %u\n",sum);
return 0;
}