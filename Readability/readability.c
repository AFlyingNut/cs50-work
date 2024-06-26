#include <ctype.h>
#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string input);
int count_words(string input);
int count_sentences(string input);


int main(void)
{
    string text = get_string("Text: ");

    // Count the number of letters, words, and sentences in the text
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    printf("\nLetters: %i\nWords: %i\nSentences: %i\n", letters, words, sentences);
    // Compute the Coleman-Liau index

    float l = ((float) letters / words) * 100;
    float s = ((float) sentences / words) * 100;
    float cli = 0.0588 * l - 0.296 * s - 15.8;
    printf("\nAverage Letters: %f\n", l);
    printf("Average Sentences: %f\n", s);

    cli = round(cli);
    // Print the grade level
    printf("Reading Level: %i\n", (int)cli);

    if (cli <=1)
    {
        printf("Before Grade 1\n");
    }
    else if (cli >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n",(int) cli);
    }

}


int count_letters(string input)
{
    int length = strlen(input);
    int letters = 0;

    for (int i = 0; i < length; i++)
    // Convert to uppercase for easy calculation
    {
        input[i] = toupper(input[i]);
        if (input[i] >= 'A' && input[i] <= 'Z')
        {
            //printf("%c", input[i]);
            letters = letters + 1;
        }
    }
    return letters;
}

int count_words(string input)
{
    int length = strlen(input);
    int words = 0;

    for (int i = 0; i < length; i++)
    {
        // Each word will have a space after it, so just count all spaces
        if (input[i] == ' ')
        {
            words = words + 1;
        }
    }
    // Add 1 to the result as the end of the input text will have a word not followed with a space, but rather punctuation instead.
    return words + 1;
}

int count_sentences(string input)
{
    int length = strlen(input);
    int sentences = 0;

    for (int i = 0; i < length; i++)
    {
        input[i] = toupper(input[i]);
        if ((input[i] == '.' || input[i] == '?' || input[i] == '!') && !(input[i + 1] >= 'A' && input[i + 1] <= 'Z'))
        {
            sentences = sentences + 1;
        }
    }
    // If there is no punctuation at all, assume its one sentence
    if (sentences == 0)
    {
        return 1;
    }

    return sentences;
}
