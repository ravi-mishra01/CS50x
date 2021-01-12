#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    float owed = 0.00;
    int qtr = 25;
    int dimes = 10;
    int nickels = 5;
    int pennies = 1;

    int Cqtr = 0;
    int Cdimes = 0;
    int Cnickels = 0;
    int Cpennies = 0;


    do
    {
        owed = get_float("Change owed: ");          //change is owed
    }
    while (owed < 0);

    //printf("Change owed : %f \n", owed);
    //printf("Dollar : %f \n", floor(owed));

    //owed = owed - floor(owed); // Get cents outs of dollars

    int cents = round((owed) * 100);
    //printf("Cents : %i \n", cents);

    if (cents >= 25)
    {
        Cqtr = cents / qtr;
        cents = cents % qtr;
    }

    //printf("quater : %i \n", Cqtr);
    //printf("Remaining Cents : %i \n", cents);

    if (cents < 25 && cents >= 10)
    {
        Cdimes = cents / dimes;
        cents = cents % dimes;
    }

    //printf("Cdimes : %i \n", Cdimes);
    //printf("Remaining Cents : %i \n", cents);

    if (cents < 10 && cents >= 5)
    {
        Cnickels = cents / nickels;
        cents = cents % nickels;
    }

    //printf("Cnickels : %i \n", Cnickels);
    //printf("Remaining Cents : %i \n", cents);

    if (cents < 5)
    {
        Cpennies = cents / pennies;
        cents = cents % pennies;
    }

    //printf("Cpennies : %i \n", Cpennies);
    //printf("Remaining Cents : %i \n", cents);

    printf("%i \n", (Cqtr + Cdimes + Cnickels + Cpennies));

}