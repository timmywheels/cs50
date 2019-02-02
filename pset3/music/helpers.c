// Helper functions for music

#include <cs50.h>
#include "helpers.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Get the note duration
int duration(string fraction)
{
    if(fraction[0] == '1')
    {
        // 1/8 => 1/8
        if(fraction[2] == '8')
        {
            return 1;
        }
        // 1/4 => 2/8
        else if(fraction[2] == '4')
        {
            return 2;
        }

        // 1/2 => 4/8
        else if(fraction[2] == '2')
        {
            return 4;
        }
        // 1/1 => 8/8
        else if(fraction[2] == '1')
        {
            return 8;
        }
    }
    // 3/8 => 3/8
    else if(fraction[0] == '3' && fraction[2] == '8')
    {
        return 3;
    }
    else
    {
        return 0;
    }
    return 0;
}


// Calculates the frequency of the given note
int frequency(string note)
{
    double freq = 0.0;

    int semitone = 0;

    // Check for an accidental
    // Increment semitone if need be
    if(note[1] == '#')
    {
        semitone = 1;
    }
    else if(note[1] == 'b')
    {
        semitone = -1;
    }

    switch(note[0])
    {
        case 'C':
            semitone += -9;
            freq = pow(2, (semitone / (float) 12)) * 440; // C4
            break;

        case 'D':
            semitone += -7;
            freq = pow(2, (semitone / (float) 12)) * 440; // D4
            break;

         case 'E':
            semitone += -5;
            freq = pow(2, (semitone / (float) 12)) * 440; // E4
            break;

        case 'F':
            semitone += -4;
            freq = pow(2, (semitone / (float) 12)) * 440; // F4
            break;

        case 'G':
            semitone += -2;
            freq = pow(2, (semitone / (float) 12)) * 440; // G4
            break;

        case 'A':
            semitone += 0;
            freq = pow(2, (semitone / (float) 12)) * 440; // A4
            break;

        case 'B':
            semitone += 2;
            freq = pow(2, (semitone / (float) 12)) * 440; // B4
            break;
    }

    // If note is 3 characters
    // Check octave at note[2]
    if(strlen(note) == 3)
    {
        switch(note[2])
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

    // If note is 2 characters
    // Check octave at note[1]
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

    // Return freq as int
    int return_note = round(freq);
    return return_note;
    // return 0;
}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    return !strlen(s);
}