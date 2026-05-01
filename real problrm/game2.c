#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int user, computer;

    srand(time(0));

    printf("🎮 Rock Paper Scissors Game\n");
    printf("1 = Rock\n2 = Paper\n3 = Scissors\n");

    printf("Enter your choice: ");
    scanf("%d", &user);

    computer = rand() % 3 + 1;

    printf("Computer chose: %d\n", computer);

    if (user == computer) {
        printf("It's a Draw!\n");
    }
    else if ((user == 1 && computer == 3) ||
             (user == 2 && computer == 1) ||
             (user == 3 && computer == 2)) {
        printf("🎉 You Win!\n");
    }
    else {
        printf("💀 You Lose!\n");
    }

    return 0;
}