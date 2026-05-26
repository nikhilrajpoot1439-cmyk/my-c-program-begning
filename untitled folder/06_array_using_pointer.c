#include<stdio.h>
int main()
{

    int marks[] = {45 , 65, 67 , 98};
    int* ptr = &marks[0];

    for (int i = 0; i < 4; i++)
    {
        // printf("The marks at index %d is %d\n",i,marks[i]);
        printf("The marks at index %d is %d\n",i, *ptr);
        ptr++;
    }
    
   
   
    //int* ptr = marks;     // Same as int* ptr = &marks[0];


return 0;
}