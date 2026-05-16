
//Write a program using function to find average of three numbers

#include<stdio.h>

float average (int a,int b,int c);

float average (int a,int b,int c){
    return(a+b+c)/3;
}


int main(){
int a=7,b=9,c=54;
    printf("The average of a ,b and c is %f",average(a,b,c));

return 0;
}