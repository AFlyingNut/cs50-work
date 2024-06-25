#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>

int main(void)
{
    // Take credit card number input
    long number_input = get_long("Input credit card number: ");
    long number = number_input;

    // Get length of input
    int length = 0;
    while (number_input !=0)
    {
        number_input /= 10;
        length++;
    }
    printf("Input Length: %d\n", length);
    // Start an array that can accept length in size of number input
    int digits[length];

    // Separate each digit and store in the array
    for (int i = 0; i < length; i++)
    {
        digits[i] = number % 10;
        number /= 10;
        //printf("%d", digits[i]);

    }

    int firsttwo[2];
    int m = 0;
    printf("First Two Starting Position: %d\n", length);
    printf("First Two Ending Position: %d\n", length - 2);
    for (int i = length - 1; i > length - 3; i--)
    {
        firsttwo[m] = digits[i];
        m++;
    }

    printf("FIRST TWO: %d %d\n",firsttwo[0], firsttwo[1]);

    printf("Digits input starting from last number: ");
    for (int i = 0; i < length; i++)
    {
        printf("%d ", digits[i]);
    }
    printf("\n");

    int digits1[length / 2];
    int j = 0;
    for (int i = 1; i < length; i += 2)
    {
        digits1[j] = digits[i];
        j++;
    }

    // Print digits1 array
    printf("Digit set 1: ");
    for (int i = 0; i < length / 2; i++)
    {
        printf("%d ", digits1[i]);
    }
    printf("\n");


    int digits2[length / 2];
    int k = 0;
    for (int i = 0; i < length; i += 2)
    {
        digits2[k] = digits[i];
        k++;
    }

    // Print digits2 array
    printf("Digit set 2: ");
    for (int i = 0; i < (length + 1) / 2; i++)
    {
        printf("%d ", digits2[i]);
    }
    printf("\n");

    // Multiply each digit from digits1 by two, then store back into the array
    int result1 = 0;
    for (int i = 0; i < length / 2; i++)
    {
        digits1[i] = digits1[i] * 2;
        //printf("Digits1 x 2: %d\n",digits1[i]);

    }

    printf("Digit set 1 * 2: ");
    for (int i = 0; i < length / 2; i++)
    {
        printf("%d ", digits1[i]);
    }
    printf("\n");

    // Convert double digits into single digits
    int l = 0;
    int digits1single[50];
    for  (int i = 0; i < length / 2; i++)
    {
        if (digits1[i] > 9) {
            int first_digit = digits1[i] / 10;
            int second_digit = digits1[i] % 10;
            digits1single[l] = first_digit;
            l++;
            digits1single[l] = second_digit;
            l++;
        } else {
            digits1single[l] = digits1[i];
            l++;
        }
    }

    printf("New single digit array: ");
    for (int i = 0; i < l; i++)
    {
        printf("%d ", digits1single[i]);
    }

    // Count length of result
    int length1 = 0;

    result1 = 0;
    // Add digits1single digits together
    for (int i = 0; i < l; i++)
    {
        //printf("\nResult1: %d\n", result1);
        result1 = result1 + digits1single[i];
    }
    printf("\nSum of digits1single: %d\n", result1);

    // Add digits2 together
    int result2 = 0;
    for (int i = 0; i < (length + 1) / 2; i++)
    {
        //printf("\nResult1: %d\n", result1);
        result2 = result2 + digits2[i];
    }
    printf("\nResult2 total: %d\n", result2);

    int result = result1 + result2;
    printf("\nResult: %d\n", result);
    result = result % 10;

    printf("One: %d Two: %d\n", firsttwo[0], firsttwo[1]);
    if (result == 0)
    {
        if (firsttwo[0] == 4)
        {
            printf("\nVISA\n");
        }
        else if (firsttwo[0] == 3)
        {
            if (firsttwo[1] == 4 || firsttwo[1] == 7)
            {
                printf("\nAMEX\n");
            }
            else
            {
                printf("\nINVALID\n");
            }
        }
        else if (firsttwo[0] == 5)
        {
            if (firsttwo[1] == 1 || firsttwo[1] == 2 || firsttwo[1] == 3 || firsttwo[1] == 4 || firsttwo[1] == 5)
            {
                printf("\nMASTERCARD\n");
            }
            else
            {
                printf("\nINVALID\n");
            }
        }
        else
        {
            printf("\nINVALID\n");
        }

    }
        else
    {
        printf("\nINVALID\n");
    }

}
