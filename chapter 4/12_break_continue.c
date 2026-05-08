#include<stdio.h>

int main(){
    for (int i = 0; i <15; i++)
    
    {
        if(i == 5){
            //break;  // Break means exit the loop now
            continue;   // Continue means skip this iteration now
        }
        printf("i is %d\n" ,i);
    }
    printf("The for loop is done");
    
    return 0;
}