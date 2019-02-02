#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    char *s = get_string("s: ");
    char *t = get_string("t: ");

    // if (s == t) // will not accurately compare two strings
    // {
    //     printf("same\n");
    // }
    // if (strcmp(s, t) == 0) // does accurately compare
    //  {
    //      printf("same\n");
    //  }
    int answer = strcmp(s, t);

    if (answer == 0)
    {
        printf("same\n");
        printf("answer is %i\n", answer);
    }
    else
    {
        printf("different\n");
        printf("answer is %i\n", answer);
    }
}

// Notes:
// If you compare two strings using ==, it will say they're
// different, because it's comparing their address, not the
// actual string.
// Instead, you need to use strcmp to compare the string literal

// char * will store the initial address of the first char
// and it will go until it finds the null terminator \0
