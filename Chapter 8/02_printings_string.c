#include<stdio.h>
int main()
{
// char str[] = {'A' , 'B' , 'C', '\0'};
char str[] = "Nikhil";    // Same as doing{ char str[] = {'A' , 'B' , 'C', '\0'};}
//WHEN WE USE CHARACTER IN DOUBLE QUOTE (" ") THEN NULL CHARACTER IS AUTOMATICALLY GENERATED
// for (int i = 0; i < 6; i++)
// {
    
//     printf(" %c",str[i]);
// }

printf(" %s",str);

return 0;
}