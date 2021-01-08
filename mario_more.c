#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int hgt = 0;

    do
    {
      hgt = get_int("Pyramid Height: "); // To accept pyramid height from user
    }
    while( (hgt < 1) || (hgt >8) ); // payramid height should be between 1 and 8 else keep asking

    for (int i = 0; i<hgt; i++) // Loop for rows
    {
        for (int j = hgt-1; j>= 0; j--) // Loop for col for left aligned pyramid
        {
            if(j > i  )
            {
                printf(" "); // Print space
            }
            else
            {
                printf("#"); //Print #
            }
        }

        printf("  ");

        for (int x = 0; x<= i; x++) // Loop for col for right aligned pyramid
        {
            printf("#"); //Print #
        }

        printf("\n"); // Go to next row

    }

}