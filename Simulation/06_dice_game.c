#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int roll_dice() {
    return (rand() % 6) + 1;
}

void diceRolls(int num_rolls) {
    for (int i = 0; i < num_rolls; i++) {
        // suppose if you roll two dice together
        int firstDice = roll_dice();
        int secondDice = roll_dice();
        int sum = firstDice + secondDice; 
        printf("Roll %d\nSum of dices: %d \nFirst Dice shows: %d \nSecond Dice shows: %d\n\n", i + 1, sum, firstDice, secondDice);
    }
}

int main() {
    int num;
    srand(time(0)); 
    printf("Enter the number of times you want to perform: ");
    scanf("%d", &num);

    diceRolls(num);

    return 0;
}