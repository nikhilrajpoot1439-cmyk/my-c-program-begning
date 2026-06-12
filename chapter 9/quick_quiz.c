/*
Write a program to store the details of 3 employee from user defined data
*/
#include<stdio.h>
struct employee
{
    int code;
    float salary;
    char name[10];
};

int main()
{
struct employee e1,e2,e3;
printf("Enter first employee name\n");
scanf("%s",&e1.name);
printf("Enter the code of the employee\n");
scanf("%d",&e1.code);
printf("Enter the salry of first employee\n");
scanf("%f", &e1.salary);
printf("%s %d %f", e1.name, e1.code, e1.salary);
printf("\n");

printf("Enter second employee name\n");
scanf("%s",&e2.name);
printf("Enter the code of the employee\n");
scanf("%d",&e2.code);
printf("Enter the salry of second employee\n");
scanf("%f", &e2.salary);
printf("%s %d %f", e2.name, e2.code, e2.salary);
printf("\n");

printf("Enter third employee name\n");
scanf("%s",&e3.name);
printf("Enter the code of the employee\n");
scanf("%d",&e3.code);
printf("Enter the salry of third employee\n");
scanf("%f", &e3.salary);
printf("%s %d %f", e3.name, e3.code, e3.salary);
printf("\n");

return 0;
}