
// Write a program to take string as an input from the user using %c and %s confirm that strings are equal

/*
#include<stdio.h>
int main()
{
    char str[6];
scanf("%s", str);
printf("%s", str);
return 0;
}
*/

#include <stdio.h>
#include<string.h>
int main()
{
    char str[6];
    for (int i = 0; i < 5; i++)
    {
        scanf("%c", &str[i]);
        fflush(stdin);
    }
    str[5] = '\0';

    printf("%s", str);
    return 0;
}