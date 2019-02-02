#include <stdio.h>
#include <cs50.h>
#include <math.h>

// Spec
// - Prompt user for input
// - Multiply every other digit
// - Sum those digits
// - Add to remaining digits
// - Validate checksum
// - Validate company's identifier
// - Validate number's length

int main(void)
{

    unsigned long long cc_number = 0;
    // unsigned long long cc_type = cc_number;
    int first_digit = 0; // For when double digit number needs to be split
    int second_digit = 0; // For when double digit number needs to be split

    do{
        cc_number = get_long("Enter Card Number: ");

    } while(cc_number == 0);

        unsigned long long digits = cc_number;
        unsigned long long digit_counter = 0; // Need to create logic for this if cc_number is 13, 15, or 16 digits
        unsigned long long last_digit = 0;
        unsigned long long times_two = 0;
        unsigned long long double_last_digit = 0;
        unsigned long long validation = 0;
        unsigned long long base_count = 0;
        unsigned long long combine_digits = 0;

    while(digits > 0)
    {
        digit_counter++;
        last_digit = digits % 10;
        digits = digits / 10;
        // printf("Digits: %llu\n", digits);
        double_last_digit = last_digit * 2; // Double the last digit of every other credit card number

        if(digit_counter % 2 != 0)
        {
            base_count += last_digit;
            // printf("Base Count: %i\n", base_count);
        }

        if(digit_counter % 2 == 0) // Get every other number of card number
        {

            if(double_last_digit > 9) // If last digit, when doubled, becomes a double digit number, split the digits
            {
                first_digit = double_last_digit / 10; // Dividing by 10 will only return the first digit
                second_digit = double_last_digit % 10; // Mod of 10 will only return last digit

                // printf("Double Digit: %i\n", double_last_digit);
                // printf("Combine Digits: %i\n", combine_digits);
                // printf("First Digit: %i\n", first_digit);
                // printf("Second Digit: %i\n", second_digit);

                combine_digits = first_digit + second_digit;
                double_last_digit = combine_digits;

            }

            times_two += double_last_digit;
        }

    }

    validation = base_count + times_two; // Validation should end in '0' to pass check

    // Print total number of digits
    // printf("Digit Counter: %llu\n", digit_counter);
    // printf("Validation: %llu\n", validation);

        if(digit_counter != 13 && digit_counter != 15 && digit_counter != 16 | validation % 10 != 0)
        {
            printf("INVALID\n");
        }

        else if(validation % 10 == 0) // If validation ends in 0, print card type
        {
            if(digit_counter == 13 && cc_number >= 5100000000000000 && cc_number < 5600000000000000)
            {
                printf("VISA\n");
            }
            if(digit_counter == 16 && cc_number >= 4000000000000000 && cc_number < 5000000000000000)
            {
                printf("VISA\n");
            }
            if(digit_counter == 16 && cc_number >= 5100000000000000 && cc_number < 5600000000000000)
            {
                printf("MASTERCARD\n");
            }
            if(digit_counter == 15 && cc_number >= 340000000000000 && cc_number < 350000000000000)
            {
                printf("AMEX\n");
            }
            if(digit_counter == 15 && cc_number >= 370000000000000 && cc_number < 380000000000000)
            {
                printf("AMEX\n");
            }
            else{
                printf("INVALID\n");
            }
        }

    return 0;
}


// TESTS
// 378282246310005 => AMEX
// 371449635398431 => AMEX
// 5555555555554444 => MASTERCARD
// 5105105105105100 => MASTERCARD
// 4111111111111111 => VISA
// 4012888888881881 => VISA
// 1234567890 => INVALID
// 4062901840 => INVALID
// 369421438430814 => INVALID
// 5673598276138003 => INVALID
// 4111111111111113 => INVALID

// HELPERS
// check50 cs50/2018/spring/credit
// style50 credit.c