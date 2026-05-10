
// Write a program to print the factorial of the given  number using While  loop.


#include<stdio.h>

int main(){
    int product = 1;
    int n;
    int i = 1;
    printf("Enter a number\n");
    scanf("%d" , &n);
    // for ( int i = 1; i <=n; i++)
    // {
    //   product = product*i;
    // }

    while (i<=n)
    {
        product = product*i;
        i++;
    }
    
    printf(" The factorial is %d\n" , product);  
    
return 0;
}