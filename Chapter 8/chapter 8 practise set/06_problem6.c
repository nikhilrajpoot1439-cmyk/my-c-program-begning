/*
Write a program to encrypt a string by adding 1 to the ASCII value of its character

*/
#include<stdio.h>
int main()
{
char str[] = "Mera pizza ka last slice ghar par hai" ;

for (int i = 0; i < strlen(str); i++)
{
    str[i] = str[i] +1;
}
printf("%s" , str);
return 0;
}