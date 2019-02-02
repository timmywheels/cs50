from cs50 import get_int

cc_number = get_int('Enter credit card number: ')

if cc_number != 0:

    digits = cc_number
    digit_counter = 0
    last_digit = 0
    times_two = 0
    double_last_digit = 0
    validation = 0
    base_count = 0
    combine_digits = 0

    while digits > 0:

        digit_counter += 1
        last_digit = digits % 10
        digits = digits // 10
        double_last_digit = last_digit * 2

        if digit_counter % 2 != 0:
            base_count += last_digit


        if digit_counter % 2 == 0:

            if double_last_digit > 9:
                first_digit = double_last_digit // 10
                second_digit = double_last_digit % 10

                combine_digits = first_digit + second_digit
                double_last_digit = combine_digits

            times_two += double_last_digit


    validation = base_count + times_two

    # print(digit_counter)

    if digit_counter != 13 and digit_counter != 15 and digit_counter != 16 or validation % 10 != 0:
        print('INVALID')

    elif validation % 10 == 0:

        if digit_counter == 13 and cc_number >= 5100000000000000 and cc_number < 5600000000000000:
            print('VISA')

        if digit_counter == 16 and cc_number >= 4000000000000000 and cc_number < 5000000000000000:

            print("VISA")

        if digit_counter == 16 and cc_number >= 5100000000000000 and cc_number < 5600000000000000:

            print("MASTERCARD")

        if digit_counter == 15 and cc_number >= 340000000000000 and cc_number < 350000000000000:

            print("AMEX")

        if digit_counter == 15 and cc_number >= 370000000000000 and cc_number < 380000000000000:

            print("AMEX")

        else:
            print("INVALID")




