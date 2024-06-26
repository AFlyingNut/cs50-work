#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

const int points[26] = {1,3,3,2,1,4,2,4,1,8,5,1,3,1,1,3,10,1,1,1,1,4,4,8,4,10};

int calculate_score(string word);

int main(void) {
    string player1 = get_string("Player 1: ");
    string player2 = get_string("Player 2: ");

    int score1 = calculate_score(player1);
    int score2 = calculate_score(player2);

    if (score1 > score2)
    {
        printf("Player 1 wins with %i points!\n", score1);
    }
    else if (score1 < score2)
    {
        printf("Player 2wins with %i points!\n", score2);
    }
    else
    {
        printf("Its a tie at %i points!\n", score1);
    }
}

int calculate_score(string word)
{
    // Get length of word to set limit on the for loop
    int length = strlen(word);

    // Calculate score
    int score = 0;

    for (int i = 0; i < length; i++)
    {
        word[i] = toupper(word[i]);
        if (word[i])
        {
            // Gather letter position in the points array by subtracting A, which is equal to 65 in ASCII, from the ASCII value of the current letter in the word, which should be a capital letter. Ranged 65 - 90.
            score = score + points[word[i] - 'A'];
        }
    }
    return score;
}
