#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    if(argc != 2)
    {
        printf("Please enter a key.\n");
        return 1;
    }
    else{

        string plaintext = get_string("plaintext: ");

        int k = atoi(argv[1]);

        printf("ciphertext: ");

        for (int i = 0, n = strlen(plaintext); i < n; i++)
        {
            // Check alphabetical
            if(isalpha(plaintext[i]))
            {
                // Check uppercase
                if(isupper(plaintext[i]))
                {
                    // Convert to alpha index
                    plaintext[i] -= 65;

                    // Add key to plaintext
                    // Mod by 26 to get alpha index of cipher
                    // Add 65 to convert back to ASCII
                    printf("%c", ((plaintext[i] + k) % 26) + 65);

                }

                if(islower(plaintext[i]))
                {
                    // Convert to alpha index
                    plaintext[i] -= 97;

                    // Add key to plaintext
                    // Mod by 26 to get alpha index of cipher
                    // Add 97 to convert back to ASCII
                    printf("%c", ((plaintext[i] + k) % 26) + 97);

                }
            }
            else
            {
                // Print non-alpha characters as normal
                printf("%c", plaintext[i]);
            }
        }
        // Add line break
        printf("\n");
    }

    return 0;
}