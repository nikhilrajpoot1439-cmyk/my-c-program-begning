
// Write a program with a structure representing a complex number

#include <stdio.h>
#include <string.h>
typedef struct vector
{
    int real;
    int imaginary;

} Complex;
Complex SumVector(struct vector v1, struct vector v2)
{
    Complex v3 = {(v1.real + v2.real), (v1.imaginary + v2.imaginary)};
    return v3;
}

int main()
{

    Complex c = {1, 2};
    // Complex v2 = {5, 6};

    // Complex v3 = SumVector(v1, v2);
    printf("The value of Complex number is %d + i%d", c.real, c.imaginary);
    return 0;
}