

// Write a program to illustrate the use of Arrow operator in c


#include<stdio.h>
#include<string.h>

typedef struct employee
{
    int salary;
    float score;

} Emp;

int main()
{
Emp e1;
Emp* ptr1 = &e1;
ptr1->salary = 56;      // (*ptr).salary
ptr1->score = 56.67656;   // (*ptr).score
printf("The value of salary is %d and the value of score is %f",ptr1->salary, ptr1->score );
return 0;
}