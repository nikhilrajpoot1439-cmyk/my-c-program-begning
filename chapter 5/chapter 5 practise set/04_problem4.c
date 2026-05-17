
// Write a program using recursion to calculate nth element of fibonacci series

// 0, 1, 1, 2, 3, 5, 8, 13, 21, .....n (Fibonacci series)
// Fibonacci(n) = fibonacci(n-1)  + fibonacci(n-2)
#include<stdio.h>

int fibonacci(int n);

int fibonacci(int n){ 

if (n == 1 || n==2)
{
    return n-1;
}
      return fibonacci(n-1)  + fibonacci(n-2);
}
int main()
{

int n;
printf("Enter a number\n");
scanf("%d" ,&n);

printf("The fabonacci series of given number %d is %d" , n ,fibonacci(n));

return 0;
}