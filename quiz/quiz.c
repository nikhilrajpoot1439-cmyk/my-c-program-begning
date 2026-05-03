#include<stdio.h>

int main(){
    float percentage;

    printf("Enter percentage: ");
    scanf("%f",&percentage);

    if (percentage >= 90 && percentage <= 100){
        printf("Your grade is A+");
    }
    else if (percentage >= 80){
        printf("Your grade is A");
    }
    else if (percentage >= 70){
        printf("Your grade is B+");
    }
    else if (percentage >= 60){
        printf("Your grade is B");
    }
    else if (percentage >= 50){
        printf("Your grade is C+");
    }
    else if (percentage >= 40){
        printf("Your grade is C");
    }
    else{
        printf("You failed");
    }

    return 0;
}