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

        // Psuedocode
        // Open card file
        // Repeat until end of card
            // Read 512 bytes into a buffer
            // Start of new JPG?
                // yes
                // no
            // Already found a JPG?
                // no
                // yes
            // close any remaining files

        // Define buffer
        unsigned char buffer[512];
        // unsigned char new_buffer[512];


        // Keep count of files
        int img_count = 0;
        // int found_jpg = 0;
        // char* img_name = NULL;
        char img_name[8]; // 3 nums, dot, jpg, null terminator = 8 chars
        FILE *img = fopen(img_name, "w");

                int counter = 0;
                int counter2 = 0;
        while (fread (buffer, 512, 1, card) == 1)
        {
            if (buffer[0] == 0xff &&
                buffer[1] == 0xd8 &&
                buffer[2] == 0xff &&
                (buffer[3] & 0xf0) == 0xe0 &&
                img_count > 0)
                {
                    fclose(img);
                }
            // Check if it's a jpg
            if (buffer[0] == 0xff &&
                buffer[1] == 0xd8 &&
                buffer[2] == 0xff &&
                (buffer[3] & 0xf0) == 0xe0)
            {
                // img_name[8]; // 3 nums, dot, jpg, null terminator = 8 chars
                sprintf(img_name, "%03i.jpg", img_count++);
                img = fopen(img_name, "w");
                fwrite(buffer, 512, 1, img);
                counter++;


            }
            else if (img_count > 0)
            {
                fwrite(buffer, 512, 1, img);
                counter2++;
            }

        }
        printf("header check has ran: %i\n", counter);
        printf("block check has ran: %i\n", counter2);

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