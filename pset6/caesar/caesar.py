import sys
import string
from cs50 import get_string



if len(sys.argv) != 2:
    print('Please enter a key')
    exit(1)

else:
    plaintext = get_string('plaintext: ')

    key = int(sys.argv[1])

    print('ciphertext: ', end='')

    n = len(plaintext)

    for i in range(len(plaintext)):

        if plaintext[i].isalpha():
            if plaintext[i].isupper():

                ascii = ord(plaintext[i])
                ascii -= 65

                char = chr( ( ( ascii + key ) % 26 ) + 65 )
                print(char, end='')

            if plaintext[i].islower():

                ascii = ord(plaintext[i])
                ascii -= 97

                char = chr( ( ( ascii + key ) % 26 ) + 97 )
                print(char, end='')

        else:
            print(plaintext[i], end='')

    print()





