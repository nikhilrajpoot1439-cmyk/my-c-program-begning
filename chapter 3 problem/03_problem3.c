// Calculate the income tax paid by employee to the goverment as per the slabs given below :-
//       Income slab           Tax
// 2.5 lakh-5.0 lakh           5%
// 5.0 lakh-10.0 lakh          20%
// Above 10 Lakh               30%
// There is no tax  below 2.5 lakh


#include<stdio.h>

int main(){
    int income ;
     int tax=0;

     printf("Enter employee income\n");
     scanf("%d" , &income);

     if(income <= 250000){
       tax = 0;
     }
     else if(income >= 250000 && income <= 500000){
        tax = 0.05 * (income - 250000);
     }
     else if(income >= 500000 && income <= 1000000){
        tax = 0.05 * (income - 250000) + 0.2*(income - 500000);
     }
     else {
        tax = 0.05 * (income - 250000) + 0.2*(income - 500000) + 0.3*(income-1000000);
     }
     printf("The total tax you have to pay is %d" , tax);
return 0;
}