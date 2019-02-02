// Copies a BMP file

#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char *argv[])
{
    // ensure proper usage
    // Require 3 command line args
    if (argc != 4)
    {
        fprintf(stderr, "Usage: ./resize multiplier infile outfile\n");
        return 1;
    }

    // Create multiplier
    int multiplier = atoi(argv[1]);

    if (multiplier < 1 || multiplier > 100)
    {
        fprintf(stderr, "multiplier must be a positive integer less than or equal to 100\n");
        return 1;
    }


    // remember filenames
    char *infile = argv[2];
    char *outfile = argv[3];

    // open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }


    int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;


    BITMAPFILEHEADER x_bf = bf;
    BITMAPINFOHEADER x_bi = bi;

    x_bi.biWidth *= multiplier;
    x_bi.biHeight *= multiplier;

    int x_padding = (4 - (x_bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    x_bi.biSizeImage = (sizeof(RGBTRIPLE) * x_bi.biWidth + x_padding) * abs(x_bi.biHeight);
    x_bf.bfSize = x_bi.biSizeImage + sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);


    // Expand infile attributes
    // int xbiSize = bi.biSize * multiplier;
    // int xbiHeight = bi.biHeight * multiplier;
    // int xbiWidth = bi.biWidth * multiplier;
    // // determine padding for scanlines
    // printf("xpadding: %i\multiplier", xpadding);

    // bi.biSize = (xbiWidth * xpadding) * xbiHeight;

    // printf("bi.biHeight: %i xbiHeight: %i\multiplier", bi.biHeight, xbiHeight);
    // printf("bi.biWidth: %i xbiWidth: %i\multiplier", bi.biWidth, xbiWidth);
    // printf("xbiHeight: %i xbiWidth: %i xbiSize: %i\multiplier", xbiHeight, xbiWidth, xbiSize);

    // write outfile's BITMAPFILEHEADER
    fwrite(&x_bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&x_bi, sizeof(BITMAPINFOHEADER), 1, outptr);


    // iterate over infile's scanlines
    // for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)

    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {

        // int pixels;
        for (int pixels = 0; pixels < multiplier; pixels++)
        {
            // printf("biHeight: %i\multiplier", biHeight);
            // iterate over pixels in scanline
            // for (int j = 0; j < bi.biWidth; j++)
            for (int j = 0; j < bi.biWidth; j++)
            {
                // temporary storage
                RGBTRIPLE triple;



                // read RGB triple from infile
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

                for (int x = 0; x < multiplier; x++)
                {
                    // write RGB triple to outfile
                    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                }



            }

            // skip over padding, if any
            fseek(inptr, padding, SEEK_CUR);

            // then add it back (to demonstrate how)
            for (int k = 0; k < x_padding; k++)
            {
                fputc(0x00, outptr);
            }

            if (pixels < multiplier - 1)
            {
                fseek(inptr, -(bi.biWidth * 3 + padding), SEEK_CUR);
            }
        }
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // success
    return 0;
}
