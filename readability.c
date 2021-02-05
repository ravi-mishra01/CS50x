#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int compute_grade(string text);

int main(void)
{
    // Get input text from user
    string input_text = get_string("Text: ");

    // Grade the text
    int text_grade = compute_grade(input_text);

    if (text_grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        if (text_grade < 1)
        {
            printf("Before Grade 1\n");
        }
        else
        {
            printf("Grade %i\n", text_grade);
        }
    }
}

int compute_grade(string text)
{

    int grade = 0;
    double letters = 0;
    double words = 0;
    double lines = 0;

    for (int i = 0; i <= strlen(text) - 1; i++)
    {
        if ((text[i] >= 65 && text[i] <= 90) || (text[i] >= 97 && text[i] <= 122))
        {
            letters = letters + 1;
        }
        else
        {
            if (text[i] == ' ')
            {
                words = words + 1;
            }
            else
            {
                if ((text[i] == '.') || (text[i] == '!') || (text[i] == '?'))
                {
                    lines = lines + 1;
                }
            }
        }
    }

    //printf("letters : %f \n", letters);
    //printf("words : %f \n", words+1);
    //printf("lines : %f \n", lines);

    double L = (letters / (words + 1)) * 100;     // Average number of letters per 100 words in the text

    double S = (lines / (words + 1)) * 100;          // Average number of sentences per 100 words in the text

    //printf("L : %f \n", L);
    //printf("S : %f \n", S);

    double index = (0.0588 * L) - (0.296 * S) - 15.8;

    grade = round(index);

    return grade;
}
