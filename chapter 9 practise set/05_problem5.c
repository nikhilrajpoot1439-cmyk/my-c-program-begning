
// Write a program with a structure representing a complex number

#include <stdio.h>
#include <string.h>
typedef struct vector
{
    int real;
    int imaginary;

} Complex;
int main()
{

    Complex c = {1, 2};
   
    printf("The value of Complex number is %d + i%d", c.real, c.imaginary);
    return 0;
}