# Credit Card Check
A program to check whether a credit card number is valid and print the type of card.

### Criterion
+ In a file called credit.c, implement a program in C that checks the validity of a given credit card number.
+ Luhn's algorithm is as follows:
  1. Multiply every other digit by 2, starting with the number’s second-to-last digit, and then add those products’ digits together.
  2. Add the sum to the sum of the digits that weren’t multiplied by 2.
  3. If the total’s last digit is 0 (or, put more formally, if the total modulo 10 is congruent to 0), the number is valid!
+ If the card number is valid, print out which card type it is. Visa, Mastercard, American Express..
+ If invalid it should print 'INVALID'
+ Should not accept a string or data type other than integers of the correct card length.

### Additional info

This program uses a cs50.h header file, available [here](https://cs50.readthedocs.io/libraries/cs50/c/).
