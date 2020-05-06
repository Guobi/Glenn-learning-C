#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

void diceRoll(int rolls);

void main() {
    srand(time(0)); // set rng seed as current time
    diceRoll(100); // generates number from 1 - 6 for 100 times
}

void diceRoll(int rolls) {
    int i;
    for (i = 0; i < rolls; i++) {
        printf("%d\n",(rand() % 6) + 1);
    }
}