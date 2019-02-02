#include <stdio.h>
#include <cs50.h>

#define LENGTH 100

int main(int argc, string argv[])
{
   printf("argc length: %i\n", argc);
   for (int i=0; i<LENGTH; i++)
   {
       printf("argv[%i] = %s\n", i, argv[i]);
   }
}