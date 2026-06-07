

// Write Your Own version of strlen fuction from <string.h>


#include<stdio.h>
#include<string.h>
int main()
{
char str[] = "Nikhil";
char c;
int i;

while (c!='\0')
{
    c = str[i];

    i++;
}
printf("%d\n",i);
return 0;
}