
// Write a program to implement program 5 ....by using for and Do-While loop



#include<stdio.h>

int main(){
    int sum = 0;
    int i =1;
    do {
        sum = sum +i;
        i++;
    } while (i<=10);
    printf("The sum of first ten natural number is %d\n" , sum);
    
    return 0;
}