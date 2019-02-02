# include <cs50.h>
# include <ctype.h>
# include <stdio.h>
# include <string.h>

int main(void)
{
    string name = get_string("Name: ");

    char initials[4];

    int counter = 0;

    for(int i = 0; i < strlen(name); i++)
    {
        if(isupper(name[i])) // If initial is uppercase
        {
            initials[counter] = name[i]; // Add uppercase initial to array
            counter++; // Increment counter

        }
    }
    initials[counter] = '\0';
    printf("%s\n", initials);

}