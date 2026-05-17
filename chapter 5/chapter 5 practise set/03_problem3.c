
// Write a function to calculate the force of attraction on a body  of mass "M" Exerted by earth.
//          Consider ...........g = 9.8 m/s2




#include<stdio.h>

float force_of_attraction(float m);
float force_of_attraction(float m) {
    return (m*9.8);
}
int main()
{
float m ;
printf("Enter the value of mass\n");
scanf("%f" , &m);
printf("The force of attraction in m/s^2 on a body of mass m for  %f Newton" ,force_of_attraction(m));
return 0;
}