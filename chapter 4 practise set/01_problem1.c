// Write a program to print multiplication table of giveb number n




#include<stdio.h>

int main(){
   int n;
   printf("Enter the value of n\n");
   scanf("%d" , &n) ;
   for (int i = 1; i < 11; i++)
   {
    printf("%d X %d = %d\n" , n ,i , n*i);
   }
   
return 0;
}