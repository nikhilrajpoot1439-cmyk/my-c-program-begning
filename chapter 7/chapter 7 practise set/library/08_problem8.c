

// Repeat problem 7 for a custom input given by the user



#include <stdio.h>
int main()
{
    int a ,b,c;
    printf("Enter value of a , b ,c" ,a,b,c);
    scanf("%d%d%d" ,&a ,&b ,&c);
    int arr[3][10];
    int mul[] = {a, b, c};
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            arr[i][j] = mul[i] * (j + 1);
        }
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            printf("%d X %d = %d\n", mul[i], j+1, arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}