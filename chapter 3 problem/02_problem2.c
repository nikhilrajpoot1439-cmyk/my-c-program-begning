// Write a C program to wrire weather a student pass or fail .To pass , a student requires a total of 40% and at least 33% in each subject . Assumr there are threee subject and take the marks as input fromn user


#include<stdio.h>

int main(){
    int marks1,marks2 ,marks3;
    printf("Enter marks1\n");
    scanf("%d" , &marks1);
    printf("Enter marks2\n");
    scanf("%d" , &marks2);
    printf("Enter marks3\n");
    scanf("%d" , &marks3);

    printf("The marks are %d %d and %d" , marks1,marks2 ,marks3);

    if(marks1<33 || marks2<33 || marks3 <33){
        printf("\nYou are failed due to less mark in individual subjectt");
    }
    else if ((marks1+marks2+marks3)/3 <40){
        printf("\nYou are failed due to less mark in overall subject");
    }
    else{
        printf("\nCongrats You passed the exam");
    }

return 0;
}