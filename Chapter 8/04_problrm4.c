
// Write a function slice() to slice a string. It should change the original string such that it now the sliced string. Take 'm' and 'N' as start and ending point for the slice

#include <stdio.h>

char* slice(char str[], int m, int n)
{
    int i = 0, count;
    char *ptr1 = &str[m];
    char *ptr2 = &str[n];

    str = ptr1;
    str[n] = '\0';
    return str;
}
int main()
{
    char str[] = "Nikhil Rajput";

    printf("%s", slice(str, 1, 8));
    return 0;
    
}