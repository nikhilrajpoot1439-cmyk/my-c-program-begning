

// For Sum of matrix

#include <stdio.h>

int main()
{
    int a[2][2];
    int sum = 0;

    printf("Enter 4 elements:\n");

    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            sum = sum + a[i][j];
        }
    }

    printf("Sum = %d", sum);

    return 0;
}