

// WAP a program using function which calculates the sum and average of two numbers . use pointer and print the value of sum and average in main ()

#include<stdio.h>

int* sum(int a, int b);
int* sum(int a , int b){
int sum = a+b;
int* ptr = &sum;
    printf("The sum is %d\n" , sum);
    return ptr;
}

float* avg(int a, int b);
float* avg(int a , int b){
float avg = (a+b)/2.0;
float* ptr = &avg;
    printf("The average is %f\n" , avg);
    return ptr;
}

int main()
{
int x =4;
int y=5;
int* ptr1;
float* ptr2;

ptr1 = sum(x,y);
ptr2 = avg(x,y);
printf("The address of sum is %u and average is %u\n" , ptr1 , ptr2);
return 0;
}