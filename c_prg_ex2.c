#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int RNG_bubble_sort(int rolls, int list[]);

int main()
{
    int x = 100;
    int list[x];
    RNG_bubble_sort(x, list);
    return 0;
}

int RNG_bubble_sort(int rolls, int list[])
{
    printf("Generating List:\n\n");
    int i = 0;
    srand(time(0) + 1); // set rng seed as current time
    for (i = 0; i < rolls; i++)
    {
        list[i] = (rand());
        printf("%d\n", list[i]);
    }
    i = 0;
    int j = 0;
    for (j = 0; j < rolls; j++)
    {

        for (i = 0; i < rolls; i++)
        {

            if (list[i] > list[i + 1])
            {
                if (i + 1!= rolls)
                {
                    int biggerNumber = list[i];
                    list[i] = list[i + 1];
                    list[i + 1] = biggerNumber;
                    // printf("%d\n", biggerNumber);
                }
            }
        }
        i = 0;
    }
    printf("Sorted List:\n\n");
    for (i = 0; i < rolls; i++)
    {
        printf("%d\n", list[i]);
    }
}