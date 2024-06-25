#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height = 0;
    do {
        height = get_int("Enter block height: ");
    }
    while (height < 1 || height > 8);

    char brick = '#';
    char space = ' ';

    for (int i = 0, j = height - 1; i < height; i++)
    {
        // Print spaces
        for (int k = 0; k < j; k++)
        {
            printf("%c", space);
        }

        // Print bricks
        for (int k = 0; k < i + 1; k++)
        {
            printf("%c", brick);
        }

        // Print gap
        printf("  ");

        // Print other bricks
        for (int k = 0; k < i + 1; k++)
        {
            printf("%c", brick);
        }
        printf("\n");
        j--;

    }
}
