#include <cs50.h>
#include <stdio.h>

int main(void)
{

    int pstart = 0;     // Start population size
    int pend = 0;       // End population size
    int years = 0;      // years required for the population to reach at least the size of the end value

    // TODO: Prompt for start size
    do
    {
        pstart = get_int("Start Size: ");               // To accept Start population from user
    }
    while (pstart < 9);                                 // Start population size should be more than or equal to 9


    // TODO: Prompt for end size
    do
    {
        pend = get_int("End Size: ");                   // To accept End population from user
    }
    while (pend < pstart);                             // End population size should be more than start population size


    // TODO: Calculate number of years until we reach threshold

    while (pstart < pend)
    {
        years = years + 1;
        int born = 0;
        int death = 0;

        born = pstart / 3;
        death = pstart /4;
        //printf("pstart before : %i \n", pstart);
        pstart = pstart + (born - death);

        //printf("born: %i \n", born);
        //printf("death: %i \n", death);
        //printf("pstart after: %i \n", pstart);
    }


    // TODO: Print number of years
    printf("Years: %i", years); // TODO: Print number of years
    printf("\n"); // Go to next row

}
