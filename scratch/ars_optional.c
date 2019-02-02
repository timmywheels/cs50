#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


 int main(int argc, string argv[])
 {
    // If not exactly two args, throw err
    if (argc == 2)
    {
        printf("Usage: <int>\n");
        // return 1;
        int res = atoi(argv[1]) + 2;
        printf("%i\n", res);
    }


}

