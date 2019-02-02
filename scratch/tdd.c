//https://stackoverflow.com/questions/13399594/how-to-extract-numbers-from-string-in-c

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>


void tests(void);

int main(void)
{
    tests();
}

bool hasComma(string str)
{
    return strchr(str, ',');
}

bool hasNewline(string str)
{
    return strchr(str, '\n');
}

int addNums(string digitString)
{
    char *str = digitString, *p = str;
    long val = 0;
    while (*p) {
        if (isdigit(*p)) {
            val += strtol(p, &p, 10);
        } else {
            p++;
        }
    }
    return(val);
}

int stringCalc(string str)
{
    if (hasComma(str) || hasNewline(str))
    {
        return addNums(str);
    }
    if (str && atoi(str) <= 1000)
    {
        return atoi(str);
    }

    return 0;
}

void testEmptyString()
{
    assert(stringCalc("") == 0 && "an empty string should return zero");
}

void testStringOne()
{
    assert(stringCalc("1") == 1 && "string of one should return one");
}

void testTwoNumsComma()
{
    assert(stringCalc("1,2") == 3 && "string of two and comma delimited should return the sum");
}

void testTwoNumsNewline()
{
    assert(stringCalc("1\n2") == 3 && "string of two and newline delimited should return the sum");
}

void testThreeNumsComma()
{
    assert(stringCalc("1,2,3") == 6 && "string of three and comma delimited should return the sum");
}

void testThreeNumsNewline()
{
    assert(stringCalc("1\n2\n3") == 6 && "string of three and comma delimited should return the sum");
}

void testThreeNumsBoth()
{
    assert(stringCalc("1\n2,3") == 6 && "string of three and comma delimited should return the sum");
}

void testIgnoreOverThousand()
{
    assert(stringCalc("1001") == 0 && "strings greater than 1000 are ignored");
}

void tests(void)
{
    testEmptyString();
    testStringOne();
    testTwoNumsComma();
    testTwoNumsNewline();
    testThreeNumsComma();
    testThreeNumsNewline();
    testThreeNumsBoth();
    testIgnoreOverThousand();
}