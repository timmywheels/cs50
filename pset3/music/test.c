#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include "helpers.h"
#include "wav.h"
#include <math.h>


// Calculates the frequency of the given note
int frequency(string note)
{
    double freq = 0.0;

    // int offset = 2;
    // int adj = 2;

    int octave = note[strlen(note) - 1];
    octave -= 48; // Adjust Ascii to int value
    eprintf("octave: %i\n", octave);


    // TODO
    switch(note[0])
    {

        case 'C':
            freq = pow(2, (-9 / (float) 12)) * 440; // C4
            // printf("this freq: %.2f\n",  freq);
            // offset = -9;
            break;

        case 'D':
            freq = pow(2, (-7 / (float) 12)) * 440; // D4
            // offset = -7;
            break;

         case 'E':
            freq = pow(2, (-5 / (float) 12)) * 440; // E4
            // printf("this freq: %.2f\n",  freq);
            // offset = -5;
            break;

        case 'F':
            freq = pow(2, (-4 / (float) 12)) * 440; // F4
            // offset = -4;
            break;

        case 'G':
            freq = pow(2, (-2 / (float) 12)) * 440; // G4
            // offset = -2;
            break;

        case 'A':
            freq = 440; // A4
            // offset = 0;
            break;

        case 'B':
            freq = pow(2, (2 / (float) 12)) * 440; // B4
            // offset = 2;
            // octave += offset;
            break;
    }

    if(strlen(note) == 2)
    {

        switch(note[1])
        {
            case '1':
                freq /= 8;
                break;
            case '2':
                freq /= 4;
                break;

            case '3':
                freq /= 2;
                break;

            case '4':
                freq /= 1;
                break;

            case '5':
                freq *= 2;
                break;

            case '6':
                freq *= 4.0;
                break;

            case '7':
                freq *= 6.0;
                break;

            case '8':
                freq *= 8;
                break;

            default:
                return 0;
        }

    }
    return 0;
}



int main(void)
{

    frequency("C6");


}

