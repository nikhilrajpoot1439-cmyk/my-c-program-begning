#include<stdio.h>
int main()
{
// char str[] = {'A' , 'B' , 'C', '\0'};
char str[] = "Nikhil";    // Same as doing{ char str[] = {'A' , 'B' , 'C', '\0'};}
//WHEN WE USE CHARACTER IN DOUBLE QUOTE (" ") THEN NULL CHARACTER IS AUTOMATICALLY GENERATED
for (int i = 0; i < 3; i++)
{
    
    printf("Character is %c\n",str[i]);
}

return 0;
}