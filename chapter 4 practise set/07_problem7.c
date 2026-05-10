
// Write a program to print the sum of the numbers occuring in the multiplication table of 8.


#include<stdio.h>

int main(){
    int sum =0;
    int i ;
    int n =8;
    for ( i = 1; i <=10; i++)
    {
      sum += (8*i);
    }
    printf("The sum of multiplication table of 8 is %d\n" , sum);  
    
return 0;
}