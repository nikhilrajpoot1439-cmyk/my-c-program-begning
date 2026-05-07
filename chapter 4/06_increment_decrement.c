#include<stdio.h>

int main(){
int i =5;
printf("The value of i is %d\n" , i);

i = i+5;
printf("The value of i is %d\n" , i);

printf("The value of i is %d\n" , i++);
printf("The value of i is %d\n" , i);

i +=2; //Same as i+2
printf("The value of i is %d\n" , i);

return 0;
}



//++i and  i++ Is not same.


// i++    prints  i first and then incremens i (Post incremenr operator)
// ++i    Increment i first and then prints  i (Post incremenr operator)