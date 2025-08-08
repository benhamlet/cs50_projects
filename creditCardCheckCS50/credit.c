// A program that checks the validity of a credit card number
#include <cs50.h>
#include <stdio.h>

void checksum(long number);
int findn(long number);

int main(void)
{
    // Define variables for card number and card number to use with loop
    long number = get_long("Card number: ");

    checksum(number);
}

void checksum(long number)
{
    // Create loop to work out every other number starting from 2nd to last digit, double the numbers
    int i = 0;
    int j = 0;
    int k = 0;
    int l = 0;
    int m = 0;
    int n = 0;
    long cardnum = number;
    int checksum = 0;
    int checksumlast = 0;
    int count = findn(number);
    long first_digits = 0;
    long first_digit = 0;
    long number_multiply = number;
    long number_addition = number;
    while (number_multiply > 0)
    {
        // Removes remainder and final number
        long last_number = number_multiply / 10;
        // Takes modulo 10 to give remainder which is the number required
        long alt_number = last_number % 10;
        number_multiply = number_multiply / 100;
        // Double each number returned
        alt_number = alt_number * 2;
        // Check for any numbers with 10s and split, store variables as i and j, add to k
        if (alt_number > 9)
        {
            // Obtains 2nd digit and stores variable
            i = alt_number % 10;
            k = k + i;
            // Obtains 1st digit and stores variable
            j = (alt_number / 10) % 10;
            k = k + j;
        }
        else
        {
            // Else adds the single digit to the variable k
            k = k + alt_number;
        }

        // Finds the final number
        long last_number2 = number_addition;
        // Takes modulo 10 to give remainder which is the number required
        long alt_number2 = last_number2 % 10;
        number_addition = number_addition / 100;

        if (alt_number2 > 9)
        {
            // Obtains 2nd digit and stores variable
            l = alt_number2 % 10;
            n = n + l;
            // Obtains 1st digit and stores variable
            m = (alt_number2 / 10) % 10;
            n = n + m;
        }
        else
        {
            // Else adds the single digit to the variable k
            n = n + alt_number2;
        }
    }
    // Create a variable to store the value of additions and check last digit is 0
    checksum = checksum + k + n;
    checksumlast = checksum % 10;

    // Create a loop to find the first digits of the card number
    first_digits = number;
    while (first_digits >= 100)
    {
        first_digits = first_digits / 10;
    }

    // Create a loop to find the first digit of the card number
    first_digit = number;
    while (first_digit >= 10)
    {
        first_digit = first_digit / 10;
    }

    // Set a conditional check to determine which card is used
    if (checksumlast != 0)
    {
        printf("INVALID\n");
    }
    else if (first_digits == 34 && (count == 15))
    {
        printf("AMEX\n");
    }
    else if ((first_digits == 37) && (count == 15))
    {
        printf("AMEX\n");
    }
    else if (first_digit == 4 && (count == 16 || count == 13))
    {
        printf("VISA\n");
    }
    else if ((first_digits >= 51 && first_digits <= 55) && count == 16)
    {
        printf("MASTERCARD\n");
    }
    else
    {
        printf("INVALID\n");
    }
}

// Create a function to count the number of digits in the card number
int findn(long number)
{
    if (number == 0)
        return 1;
    int n = 0;
    while (number)
    {
        number /= 10;
        n++;
    }
    return n;
}
