#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Alphabet index
const char uppercase[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
const char lowercase[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

bool only_digits(string input);

int main(int argc, string argv[]) {
    // Look for exactly 2 arguments, and that the second argument is only digits
    if ((argc != 2) || !(only_digits(argv[1])))
    {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }

    string sentence = get_string("plaintext:  ");
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
            ciphertext[i] = lowercase[(((sentence[i] - 'a') + key) % 26)];
        }
        else
        {
            ciphertext[i] = sentence[i];
        }
    }

    printf("ciphertext: %s", ciphertext);
    printf("\n");
    return 0;
}

bool only_digits(string input)
{
    int non_digits = 0;
    for (int i = 0; i < strlen(input); i++)
    {
        if (!(isdigit(input[i])))
        {
            return false;
        }
    }
    return true;
}
