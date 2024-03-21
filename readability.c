#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // Prompt the user to put a text
    string reading = get_string("Write your text: ");
    // Create variables that will help you determine the level of the text
    // A variable for letters
    int letters = 0;
    // A variable for words
    int words = 1;
    // A variable for sentences
    int sentences = 0;
    // Create a loop that counts number of alphabets, letters, words, and sentences
    for (int i = 0; i < strlen(reading); i++)
    {
        // Check if the character is an alphabet
        if (isalpha(reading[i]))
        {
            letters++;
        }
        // Check if the character is a space and add one to the number of words
        else if (reading[i] == ' ')
        {
            words++;
        }
        // Check whether the character is a dot, exclamation mark, or a question mark, and increase the number of sentences by 1
        else if (reading[i] == '.' || reading[i] == '!' || reading[i] == '?')
        {
            sentences++;
        }
    }
    // Calculate the number of letters and sentences present in 100 words and indicate the level using the formula
    float L = ((float) letters / (float) words) * 100;
    float S = ((float) sentences / (float) words) * 100;
    float level = 0.0588 * L - 0.296 * S - 15.8;
    if (level < 1)
    {
        // If grade level is below 1
        printf("Before Grade 1\n");
    }
    else if (level > 16)
    {
        // if grade level is above 16
        printf("Grade 16+\n");
    }
    else
    {
        // if grade level if 1-16
        printf("Grade %i\n", (int) round(level));
    }
}
