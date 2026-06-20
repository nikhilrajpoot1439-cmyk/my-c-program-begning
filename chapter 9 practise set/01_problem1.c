

// Create a two dimensional vector by using structure in C



#include<stdio.h>
#include<string.h>

struct vector
{
    int i;
    int j;
    
};

int main()
{
    
struct vector v = {1,2};
printf("The value of vector is %di + %dj" , v.i, v.j);
return 0;
}