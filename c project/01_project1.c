#include <stdio.h>  // printf() use garna
#include <stdlib.h> // rand() ra srand() use garna
#include <time.h>   // time() function use garna

int main()
{

    // random number ko starting point (seed) set garxa
    // time(0) use gareko le program chaleko time anusar
    // harek choti different random number aauxa
    srand(time(0));
    // rand() le random number dinxa
    // %100 le number lai 0-99 samma limit garxa
    // +1 le 1-100 banaidinxa

    int randomNumber = rand() % 100 + 1;
    int no_of_guesses = 0;
    int guessed_number;


    // printf("Random number is %d\n", randomNumber);

    do
    {
        printf("Guess the number\n");
        scanf("%d", &guessed_number);
        if (guessed_number > randomNumber)
        {
            printf("Please guess smaller number\n");
        }
        else if (guessed_number<randomNumber){
            printf("please Guess Higher Number\n");
        }
        else{
            printf("Congrats");
            
        }
        
        no_of_guesses++;

    } while (guessed_number != randomNumber);

    printf("You gussed the number in %d guesses\n", no_of_guesses);

    return 0;
}