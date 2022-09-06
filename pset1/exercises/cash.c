#include <stdio.h>
#include <cs50.h>

float change(void);

void coins (float n);

int main(void)
{
    float n = change();
    coins(n);
}

float change(void)
{
    float n;
    do
    {
        n = get_float("Right change: ");
    }
    while(n < 0);
    return n;
}

void coins (float n)
{
    int coin = (int) (n * 100);
    int coins = 0;
    while(coin - 25 >= 0)
    {
        coin -= 25;
        coins++;
    }
    while(coin - 10 >= 0)
    {
        coin -= 10;
        coins++;
    }
    while(coin - 5 >= 0)
    {
        coin -= 5;
        coins++;
    }
    while(coin - 1 >= 0)
    {
        coin -= 1;
        coins++;
    }
    printf("%i\n", coins);
}