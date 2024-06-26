#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Alphabet index
const char uppercase[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
const char lowercase[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

int main(int argc, string argv[]) {
    // Look for exactly 2 arguments
    if (argc != 2)
    {
        printf("Command Usage, %s [INT]\n", argv[0]);
        return 1;
    }

    // Check for if there are any non-digits in the arguments
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (isdigit(argv[1][i]))
        {
            continue;
        }
        else
        {
            printf("Command Usage, %s [INT]\n", argv[0]);
            return 1;
        }
    }

    string sentence = get_string("Text: ");
    int length = strlen(sentence);

    int key = atoi(argv[1]);

    // Initialize empty string
    string ciphertext = malloc(length + 1);

    for (int i = 0; i < length; i++)
    {
        // If current letter is capital
        if (isupper(sentence[i]))
        {
            ciphertext[i] = uppercase[(((sentence[i] - 'A') + key) % 26)];
        }
        else if (islower(sentence[i]))
        {
            //printf("Current Letter: %i", sentence[i] + key);
            ciphertext[i] = lowercase[(((sentence[i] - 'a') + key) % 26)];
        }
        else
        {
            //printf("Current Letter: %i", sentence[i] + key);
            ciphertext[i] = sentence[i];
        }
    }

    printf("%s\n", ciphertext);
}
