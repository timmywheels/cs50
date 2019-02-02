#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

int main (int argc, string argv[])
{
    if (argc == 2)
    {

        char* file = argv[1];
        FILE* card = fopen(file, "r");

        if(!card)
        {
            printf("File not found\n");
            fclose(card);
            return 1;
        }

        // Define buffer
        unsigned char buffer[512];
        // Keep count of files
        int img_count = 0;

        while (fread (buffer, 512, 1, card) == 1)
        {
            if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
            // Check if it's a jpg
            {
                img_count++;
            }
        }
        printf("Total number of JPG images in file: %i\n", img_count);
        fclose(card);
        return 0;
        }
        else
        {
            printf("Usage: ./get_jpg <filename>\n");
            return 1;
        }

}