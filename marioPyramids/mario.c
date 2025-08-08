// A program to print a right facing and left facing pyramid of varying height, defined by user input 1 -8
#include <cs50.h>
#include <stdio.h>

void print_pyramid(int length);

int main(void)
{
    // Run a loop that asks the user to input a integer for the height of the pyramids. Check between 1 and 8
    // prompt again if outside this range.
    int height = 0;
    do
    {
        height = get_int("What height should the pyramids be? ");
    }
    while (height < 1 || height > 8);

    // Loop to set height of pyramid

    print_pyramid(height);
}

// Create function for placing spaces in between pyramids
void print_pyramid(int length)
{
    // Loop to add a new row
    for (int i = 0; i < length; i++)
    {
        // Loop to add spaces
        for (int j = length - i; j > 1; j--)
        {
            printf(" ");
        }
        // Loop to add #s
        for (int k = 0; k <= i; k++)
        {
            printf("#");
        }
        // Add 2 brick space between pyramids
        printf("  ");
        // Create loop to print right
        for (int l = 0; l <= i; l++)
        {
            printf("#");
        }
        printf("\n");
    }
}
