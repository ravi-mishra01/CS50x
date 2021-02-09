#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

char changetext(char inptext, int minlimit, int maxlimit, string ckey);


int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    string argument = argv[1];
    string argument_real = argv[1];
    char argument_temp[] = "";
    argument_temp[0] = argument_real[1];
    for (int k = 0; k <= strlen(argument) - 1; k++)
    {
        if ((islower(argument_real[k])) || (isupper(argument_real[k])))       // check if 1st argument is NOT numeric
        {
            if (strlen(argument_real) != 26)
            {
                printf("1 - Key must contain 26 characters.\n");
                return 1;
            }
        }
        else
        {
            printf("2 - Key must contain 26 characters.\n");
            return 1;
        }
    }
    for (int k = 1; k <= strlen(argument) - 1; k++)
    {
        for (int j = 0; j < k; j++)
        {
            if (argument_real[k] == argument_real[j])
            {
                printf("3 - Key must contain 26 distinct characters.\n");
                return 1;
            }
        }
    }
    string input_msg = get_string("plaintext:  ");          // accept input text
    string ciphertext = input_msg;

    int j = 0;

    for (int i = 0; i <= strlen(input_msg) - 1; i++)
    {
        if ((input_msg[i] >= 65 && input_msg[i] <= 90))     // For capital alphabets
        {
            int min = 65;
            int max = 90;
            ciphertext[i] = changetext(input_msg[i], min, max, argument);        // changing the text as per key
        }
        else
        {
            if ((input_msg[i] >= 97 && input_msg[i] <= 122))        // For small alphabets
            {
                int min = 97;
                int max = 122;
                ciphertext[i] = changetext(input_msg[i], min, max, argument);       // changing the text as per key
            }
            else
            {
                ciphertext[i] = input_msg[i];
            }
        }
    }

    printf("ciphertext: %s\n", ciphertext);        //Print ciphertext
    return 0;
}

char changetext(char inptext, int minlimit, int maxlimit, string ckey)
{
    //printf(" inptext : %c\n", inptext);
    //printf(" ckey : %s\n", ckey);

    char cptext;
    int j = inptext - minlimit;

    //printf(" j : %i\n", j);

    cptext = ckey[j];
    //printf(" cptext : %i\n", cptext);
    if (islower(inptext))
    {
        return tolower(cptext);
    }
    else
    {
        return  toupper(cptext);
    }
}