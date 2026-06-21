
// Create an array of 5 Complex number created in problem 5 and displlay them with the help of displaly function . The value must be taken as an input from the user

#include <stdio.h>
#include <string.h>
typedef struct vector
{
    int real;
    int imaginary;

} Complex;
void display(Complex c)
{
    printf("The value of Complex number is %d + i%d", c.real, c.imaginary);
}
int main()
{

    Complex carr[5];
    for (int i = 0; i < 4; i++)
    {
        printf("Enter real part\n");
        scanf("%d", &carr[i].real);
        printf("Enter imaginary part\n");
        scanf("%d", &carr[i].imaginary);
        display(carr[i]);
    }

    return 0;
}