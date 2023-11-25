#include <stdio.h>

// Greedy approach to the Coin Change Problem

void reverseSortCoins(int coins[], const int size)
{
    for (int i = 0; i < size - 1; i++) 
    {
        for (int j = 0; j < size - i - 1; j++) 
        {
            if (coins[j] < coins[j + 1]) 
            {
                int temp = coins[j];
                coins[j] = coins[j + 1];
                coins[j + 1] = temp;
            }
        }
    }
}

int coinChangeProblem(int coins[], const int size, int wantedNumber)
{
    reverseSortCoins(coins, size);

    int counter = 0;

    printf("Coins used: [");

    for(int i = 0; i < size; i++)
    {
        if((wantedNumber / coins[i]) > 0) // Check if the current coin fits
        {
            int amountOfFills = wantedNumber / coins[i];

            for(int j = 0; j < amountOfFills; j++) 
            {
                printf("%d, ", coins[i]); // Print each coin used
            }

            wantedNumber = wantedNumber % coins[i];
            counter += amountOfFills;
        }

        if(wantedNumber == 0)
        {
            printf("\b\b]\n");
            return counter;
        }
    }

    return -1;
}

/*
//Example array

int main()
{
    int coins[5] = {1, 7, 4, 5, 3};
    int wantedNumber = 16;

    printf("The minimum number of coins the used (with Greedy approach) is: %d", 
            coinChangeProblem(coins, 5, wantedNumber));    // Expected: 4 [7, 7, 1, 1]

    return 0;
}
*/