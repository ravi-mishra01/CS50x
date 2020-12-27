#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string name = get_string("What is your name?\n"); // To accept name from user
    printf("Hello World .... \n"); // Print hello world
    printf("Hello ...%s...\n", name); // Print Hello to the name entered by user
}