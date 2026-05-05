// Write a program to check  weather a year entered by the user is a leap year or not.
// Take input from the user


#include<stdio.h>
int main(){
    int year ;
    printf("Enter name of year\n");
    scanf("%d" , &year);

    if((year %4 ==0 && year % 100 != 0) || year % 400==0){
        printf("The given year is leap year");
    } 
    else{
        printf("The given year is not leap year");
    }
return 0;
}