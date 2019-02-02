#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


 int main(int argc, string argv[])
 {
    // If not exactly two args, throw err
    if (argc != 2)
    {
        printf("Usage: ./vigenere k\n");
        return 1;
    }

    // check if alpha
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (!isalpha(argv[1][i]))
        {
            printf("Usage: ./vigenere k\n");
            return 1;
        }
    }

    // prompt user for key
    string k = get_string("plaintext: ");
    int j = 0;

    printf("ciphertext: ");

    // loop through through key
    for (int i = 0, n = strlen(k); i < n; i++)
    {
        //
        j = j % strlen(argv[1]);

        // check if alpha
        if (isalpha(k[i]))
        {
            // print char according to case
            if (islower(k[i]) && islower(argv[1][j]))
                printf("%c", (((k[i] - 97) + (argv[1][j] - 97)) % 26) + 97);
            else if (isupper(k[i]) && islower(argv[1][j]))
                printf("%c", (((k[i] - 65) + (argv[1][j] - 97)) % 26) + 65);
            else if (islower(k[i]) && isupper(argv[1][j]))
                printf("%c", (((k[i] - 97) + (argv[1][j] - 65)) % 26) + 97);
            else if (isupper(k[i]) && isupper(argv[1][j]))
                printf("%c", (((k[i] - 65) + (argv[1][j] - 65)) % 26) + 65);
            j++;
        }
        // otherwise print k
        else
        {
            printf("%c", k[i]);
        }
    }
    printf("\n");
 }

// $ ./vigenere 13
// Usage: ./vigenere k

// $ ./vigenere
// Usage: ./vigenere k

// $ ./vigenere bacon and eggs
// Usage: ./vigenere k

// $ ./vigenere bacon
// plaintext: Meet me at the park at eleven am
// ciphertext: Negh zf av huf pcfx bt gzrwep oz