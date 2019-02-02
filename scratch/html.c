#include <cs50.h>
#include <stdio.h>
#include <string.h>


int main(void)
{

    string html = get_string("Enter string: ");

    for(int i = 0; i < strlen(html); i++)
    {
        switch (html[i]) {
          case '&':
            html[i] = "&amp;";
            // printf("&amp;");
            break;
          case '<':
            printf("&lt;");
            break;
          case '>':
            printf("&gt;");
            break;
          case '"':
            printf("&quot;");
            break;
          case '\'':
            printf("&apos;");
            break;
        }

        printf("%c", html[i]);
    }

}