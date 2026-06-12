/*
Write a program to decrypt a string by adding 1 to the ASCII value of its character

*/
#include<stdio.h>
int main()
{
char str[] = "Nfsb!qj{{b!lb!mbtu!tmjdf!hibs!qbs!ibj" ;

for (int i = 0; i < strlen(str); i++)
{
    str[i] = str[i] -1;
}
printf("%s" , str);
return 0;
}