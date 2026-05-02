#include<stdio.h>

int main(){
    int age ;
    printf("Enter age\n");
    scanf("%d", &age);

    if (age<20) {
printf("You are fall under child");
    }
else{
    printf("You fall under young");
}
return 0;
}