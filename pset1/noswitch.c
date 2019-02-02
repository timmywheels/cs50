#include <cs50.h>
#include <stdio.h>

int main(void)
{
    char c = get_char("Answer: ");

    if(c == 'Y' || c == 'y')
    {
        printf("Yes\n");
    }
    else if(c == 'N' || c == 'n')
    {
        printf("No\n");
    }
    else
    {
        printf("Please enter 'Y' or 'N'\n");
    }
}