#include <cs50.h>
#include <stdio.h>

int main(void)
{
    char c = get_char("Answer: ");

    switch(c)
    {
        // Check answer
        case 'Y':
        case 'y':
            printf("Yes\n");
            break;
        case 'N':
        case 'n':
            printf("No\n");
            break;
    }
}