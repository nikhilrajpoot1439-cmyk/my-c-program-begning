#include<stdio.h>

int main(){
    int age ;
    printf("Enter age");
    scanf("%d", &age);

    if (age<20) {
printf("You are fall under child");
    }
    if(age>20){
printf("Congrats you fall under young");
    }
return 0;
}