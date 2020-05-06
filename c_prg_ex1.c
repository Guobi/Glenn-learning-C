#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void diceRoll(int rolls);

int main()
{
    diceRoll(10000000); // generates number from 1 - 6 for 100 times
    return 0;
}

void diceRoll(int rolls)
{
    int i = 0;
    int count[6];
    for (i = 0; i < 6; i++)
    {
        count[i] = 0;
    }

    // set rng seed as current time
    srand(time(0));
    int myRand = 0;
    for (i = 0; i < rolls; i++)
    {
        myRand = (rand() % 6) + 1;
        count[myRand - 1]++;
        // printf("%d\n", myRand);
    }
    for (i = 0; i < 6; i++)
    {
        printf("%d\n", count[i]);
    }
    return;
}