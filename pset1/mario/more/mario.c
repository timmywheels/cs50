#include <stdio.h>
#include <cs50.h>


int main(void)
{
    // Initialize height variable
    int height;

    // Prompt user for height
    do
    {
        height = get_int("Height: ");
    }
    // Keep prompting user if height value doesn't meet spec
    while(height < 0 || height > 23);

        for(int i = 1; i <= height; i++)
        {
            // Print spaces
            for(int j = 0; j < (height - i); j++)
            {
                printf(" ");
            }

            // Print left blocks
            for(int k = 0; k < i; k++)
            {
                printf("#");
            }

            // Print gap
            printf("  ");

            // Print right blocks
            for(int k = 0; k < i; k++)
            {
                printf("#");
            }

            // Print new lines
            printf("\n");
        }

        return 0;
}




