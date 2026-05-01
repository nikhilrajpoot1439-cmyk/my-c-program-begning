//Write a program to calculate simple interest for set of values representing principle , number of years ,, and rate of interest



#include<stdio.h>

int main(){
    float SI,P,T,R ;
    // printf("Enter SI");
    // scanf("%f" , SI);

    printf("Enter p\n");
    scanf("%f" , &P);

    printf("Enter T\n");
    scanf("%f" , &T);

    printf("Enter R\n");
    scanf("%f" , &R);

    SI = (P*T*R)/100 ;

    printf("\nThe simple interest of the dividend is %f" , SI);

return 0;
}