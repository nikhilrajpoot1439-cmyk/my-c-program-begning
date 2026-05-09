
// Write a program to print sum of first ten natural number using while loop


#include<stdio.h>

int main(){
    int i=1;
    int sum = 0;
    while (i<=10)
    {
        sum +=i;
        i++;
    }
    printf("The sum of first ten natural is %d\n" ,sum);
return 0;
}