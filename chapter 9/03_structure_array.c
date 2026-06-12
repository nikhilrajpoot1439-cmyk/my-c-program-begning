#include<stdio.h>
struct employee
{
int code;
float salary;
char name[20];
}; 
int main()
{
struct employee facebook[100];
facebook[0].code = 100;
facebook[1].code = 101;
return 0;
}