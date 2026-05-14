#include<stdio.h>
  int sum(int , int);  // Function prototype

  int sum (int x , int y){      // Function Definition
    printf("The sum is %d\n",x+y);
    return x+y;
  }

int main (){
    int a,b;
    printf("Enter a number\n");
    scanf("%d",&a);

    printf("Enter a number\n");
    scanf("%d",&b);

    sum(a,b);   // Function call
 
return 0;
}