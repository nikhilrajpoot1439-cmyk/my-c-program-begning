

//Write a function to convert Celcius temprature into fahrenheit



#include<stdio.h>


float c2f(float c);
    
float c2f(float c){
return ((9*c)/5) + 32;
}

int main()
{
float c;
printf("Enter Celcius\n");
scanf("%f" , &c);

printf("Celcius to fahrentrate for %f is %f" , c2f(c));
return 0;
}