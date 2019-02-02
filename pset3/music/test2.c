// Helper functions for music

#include <cs50.h>
#include "helpers.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int duration(string fraction)
{
   // Get numerator
    int num = (int) fraction[0];

    // Get denominator
    int den = (int) fraction[2];

    // Convert to eighths
    int eighths = (num / den) * 8;


    return eighths;
}


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
            printf("this freq: %.2f\n",  freq);
            // offset = -9;
            break;

        case 'D':
            freq = pow(2, (-7 / (float) 12)) * 440; // D4
            // offset = -7;
            break;

         case 'E':
            freq = pow(2, (-5 / (float) 12)) * 440; // E4
            printf("this freq: %.2f\n",  freq);
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
                // octave += offset;
                eprintf("%f\n", freq);
                break;
            case '2':
                freq /= 4;
                // octave += offset;
                eprintf("%f\n", freq);
                break;

            case '3':
                freq /= 2;
                // octave += offset;
                eprintf("%f\n", freq);
                break;

            case '4':
                freq /= 1;
                // octave += offset;
                eprintf("%f\n", freq);
                break;

            case '5':
                freq *= 2;
                // octave += offset;
                eprintf("%f\n", freq);
                break;

            case '6':
                freq *= 4.0;
                // octave += offset;
                eprintf("%.2f\n", freq);
                break;

            case '7':
                freq *= 6.0;
                // octave += offset;
                eprintf("%f\n", freq);
                break;

            case '8':
                freq *= 8;
                // octave += offset;
                eprintf("%f\n", freq);
                break;

            default:
                return 0;
        }

    }

    // printf("%c", note[0]);
    // Return frequency value as an int
    int ret = round(freq);
    return ret;

    return 0;
}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    if(strncmp(s, "", 1))
    {
        return false;
    }
    else
    {
        return true;
    }

}

