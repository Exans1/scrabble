#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10,0};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    if (score1 > score2)
    {
        printf("Player 1 Wins!\n");
    }
    else if ( score1 < score2)
    {
        printf("Player 2 Wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
    //printf("Player1: %i\nPlayer2: %i\n", score1, score2);
}

int compute_score(string word)
{
    // TODO: Compute and return score for string
    int wordlen = strlen(word);

    int i = 0;
    int CAP;
    while (word[i])
    {
        CAP = word[i];
        int UP = toupper(CAP) - 64;
        word[i] = UP;
        i++;
    }
    int j = 0;
    int PD;

    while (word[j])
    {
        if (word[j]>26)
        {
            word[j]=27;
        }
        else
        {
        PD = word[j]-1;
        int score = POINTS[PD];
        word[j] = score;
        }
        j++;
    }
    int sum = 0;
    for(i =0; i<wordlen; i++)
    {
        sum += word[i];
    }
    return sum;
}