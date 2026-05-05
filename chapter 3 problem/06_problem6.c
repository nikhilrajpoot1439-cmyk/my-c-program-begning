// Write a program to find greatest of four number entered by the user


#include<stdio.h>

int main(){
    int a,b,c,d ;
    printf("Enter a number\n",a);
    scanf("%d" ,&a);

    printf("Enter a number\n",b);
    scanf("%d" ,&b);

    printf("Enter a number\n",c);
    scanf("%d" ,&c);

    printf("Enter a number\n",d);
    scanf("%d" ,&d);
    
    if(a > b && a>c && a>d){
        printf("The gretest number is %d" , a);
    }

    if(b > a && b>c && b>d){
        printf("The gretest number is %d" , b);
    }

    if(b > a && b>c && b>d){
        printf("The gretest number is %d" , b);
    }

    if(c > a && c>b && c>d){
        printf("The gretest number is %d" , c);
    }

    // if(d > a && d>c && d>b){
    //     printf("The gretest number is %d" , d);
    // }
else{
    printf("The greatest number is %d" ,d);
}

return 0;
}