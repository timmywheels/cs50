#include <cs50.h>
#include <stdio.h>
#include <string.h>


int main(void)
{
    string dna = get_string("Enter string: ");

    switch (dna[0]) {
      case 'A':
        printf("AT\n");
        break;
      case 'T':
        printf("TA\n");
        break;
      case 'C':
        printf("CG\n");
        break;
      case 'G':
        printf("GC\n");
        break;
    }
}