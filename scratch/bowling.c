#include <cs50.h>
#include <stdio.h>
#include <assert.h>

void tests(void);
void bowlGameInit(void);
void bowlGameRoll(int pins);
int bowlGameScore();


int main(void)
{
    tests();
}

void tests(void)
{
    bowlGameInit();
    for (int i = 0; i < 20; i++)
    {
        bowlGameRoll(0);
    }

    assert(bowlGameScore() == 0 && "Gutter game should result in 0");

    bowlGameInit();
    for (int i = 0; i < 20; i++)
    {
        bowlGameRoll(1);
    }

    assert(bowlGameScore() == 20 && "All ones game should result in 20");

}

void bowlGameInit(void)
{
    int score = 0;
}

void bowlGameRoll(int pins)
{

}

int bowlGameScore()
{
    return 0;
}