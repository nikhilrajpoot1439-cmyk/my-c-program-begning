// Repet the problem 3 for general input provided by the user using scanf.



#include<stdio.h>
int main()
{
    int a;
    printf("Please enter the value of a\n");
    scanf("%d" , &a);

int arr[10];

for (int i = 0; i < 10; i++)
{
    arr[i] = a*(i+1);
}
for (int i = 0; i < 10; i++)
{
    printf("%d X %d = %d\n" , a,i+1,arr[i]);
}


return 0;
}