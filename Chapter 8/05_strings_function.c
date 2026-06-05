#include <stdio.h>
#include <string.h>
int main()
{

    // char st[] = "Nikhil";
    char a1[56] = "Nikhil";
    char a2[56] = "Rajput";
    // printf("%d\n", strlen(st));

    // char source[] = "Rajput";
    // char target[30];
    // strcpy(target, st); // Target now contains "Nikhil".
    // printf("%s %s", st, target);

    strcat(a1, a2);
    // printf("%s %s", a1, a2);

    int a = strcmp("far", "ajoke");
    printf("%d\n", a);
    return 0;
}