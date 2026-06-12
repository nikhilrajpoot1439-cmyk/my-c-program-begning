#include <stdio.h>
#include <string.h>
struct employee
{
    int code;
    float salary;
    char name[20];
};

int main()
{
    struct employee e1, e2;
    strcpy(e1.name, "Nikhil"); // We can not use = while using character in string
    e1.salary = 3545.45;
    e1.code = 34;

    printf("%d\n %f\n %s\n", e1.code, e1.salary, e1.name);
    return 0;
}