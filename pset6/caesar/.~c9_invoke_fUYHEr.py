import sys
import string
from cs50 import get_string



if len(sys.argv) != 2:
    print('Please enter a key')

else:
    plaintext = get_string('plaintext: ')

    for c in plaintext:
        key = ord(c)
        # print(k)

    print('ciphertext: ')

    n = len(plaintext)
    # print(f'n: {n}')

    # for i in range(0, n, 1):
    for i in range(len(plaintext)):

        if plaintext[i].isalpha():
            if plaintext[i].isupper():

                ascii = ord(plaintext[i])
                ascii -= 65

                print( ( ( ascii + k ) % 26 ) + 65 )

            if plaintext[i].islower():

                ascii = ord(plaintext[i])
                ascii -= 97

                char = chr( ( ( ascii + k ) % 26 ) + 97 )
                print( ( ( ascii + k ) % 26 ) + 97 )
                print(char)

        else:
            print(plaintext[i])

    print()




