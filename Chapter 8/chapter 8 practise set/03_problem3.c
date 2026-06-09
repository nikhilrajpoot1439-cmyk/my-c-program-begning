

// Write Your Own version of strlen fuction from <string.h>

#include <stdio.h>
// #include <string.h>
int strlen(char str[]);
int strlen(char str[])
{
    int i = 0, count;
    char c = str[i];

    while (c != '\0')
    {
        c = str[i];

        i++;
    }
    count = i - 1;
    return count;
}
int main()
{
    char str[] = "Nikhil";

    printf("%d\n", strlen(str));
    return 0;
}