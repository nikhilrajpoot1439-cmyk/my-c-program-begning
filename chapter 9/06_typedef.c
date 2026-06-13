#include <stdio.h>
#include <string.h>
typedef struct employee
{
    int code;
    float salary;
    char name[20];
} Emp;

int main()
{
    Emp e1;
    Emp* ptr1 = &e1;
    strcpy(e1.name, "Nikhil"); // We can not use = while using character in string
    e1.salary = 3545.45;
    e1.code = 34;

    printf(" %d\n %f\n %s\n", e1.code, e1.salary, e1.name);

    printf(" %d\n %f\n %s\n", ptr1->code, ptr1->salary, ptr1->name);
    return 0;
}