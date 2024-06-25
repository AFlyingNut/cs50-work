#include <stdio.h>
#include <cs50.h>

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
    //printf("\nSeparated digits\n");

    int digits1[length / 2];
    int j = 0;
    for (int i = 1; i < length; i += 2)
    {
        //printf("\nJ Value: %d\n", j);
        //printf("Current Digit: %d", digits[i]);
        digits1[j] = digits[i];
        //printf("\nDigits1 Array: %d\n",digits1[j]);
        j++;
    }

    int digits2[(length / 2)];
    int k = 0;
    for (int i = 0; i < length; i += 2)
    {
       // printf("\nJ Value: %d\n", k);
        //printf("Current Digit: %d", digits[i]);
        digits2[k] = digits[i];
        //printf("\nDigits2 Array: %d\n",digits2[k]);
        k++;
    }

    // print digits1 array
    printf("Digits1: ");
    for (int i = 0; i < length / 2; i++)
    {
        printf("%d ", digits1[i]);
    }
    printf("\n");

    // print digits2 array
    printf("Digits2: ");
    for (int i = 0; i < length / 2; i++)
    {
        printf("%d ", digits2[i]);
    }
    printf("\n");

    // Multiply each digit from digits1 by two, then store back into the array
    int result1 = 0;
    for (int i = 0; i < length / 2; i++)
    {
        digits1[i] = digits1[i] * 2;
        printf("Digits1 x 2: %d\n",digits1[i]);
        result1 = result1 * 10 + digits1[i];
    }

    //printf("\nResult1: %d\n", result1);

    // Count length of result
    int length1 = 0;
    int result1length = result1;
    while (result1length !=0)
    {
        result1length /= 10;
        length1++;
    }
    printf("\nResult1 Length: %d\n", length1);
    printf("\nResult1: %d\n", result1);
    // Turn result1 back into an array
    int checksum1[length1];
    for (int i = 0; i < length1; i++)
    {
        //printf("\nResult1: %d\n", result1);
        checksum1[i] = result1 % 10;
        result1 /= 10;
        printf("%d", checksum1[i]);

    }
    result1 = 0;
    // Add checksum1 digits together
    for (int i = 0; i < length1; i++)
    {
        //printf("\nResult1: %d\n", result1);
        result1 = result1 + checksum1[i];
    }
    printf("\nResult1 total: %d\n", result1);

    // Add digits2 together
    int result2 = 0;
    for (int i = 0; i < length1; i++)
    {
        //printf("\nResult1: %d\n", result1);
        result2 = result2 + digits2[i];
    }
   printf("\nResult2 total: %d\n", result2);

   int result = result1 + result2;
   printf("\nResult: %d\n", result);
   result = result % 10;

    if (result == 0)
    {
        printf("\nThis is a valid card\n");
    }
        else
    {
        printf("\nThis is not a valid card\n");
    }

}
