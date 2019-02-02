#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int split(char *original,int offset,char **s1,char **s2)
{
    int len;

    len = strlen(original);
    if(offset > len)
        return(0);
    *s1 = (char *)malloc(sizeof(char) * offset+1);
    *s2 = (char *)malloc(sizeof(char) * len-offset+1);
    if( s1==NULL || s2==NULL )
        return(0);
    strncpy(*s1,original,offset);
    strncpy(*s2,original+offset,len-offset);
    return(1);
}

int main()
{
    char string[] = "We shall attempt, to split this string";
    char comma = ',';
    char *first,*second;
    int r;

    r = split(string,comma,&first,&second);
    if(r==1)
    {
        printf("Split successful\n");
        printf("'%s' split into:\n",string);
        printf("'%s'\n",first);
        printf("'%s'\n",second);
    }
    else
    {
        puts("The function was unable to split the string");
    }

    return(0);
}