#include <stdio.h>
#include <cs50.h>

int Height(void);

void Pyramid(int n);

int main(void)
{
    int n = Height();
    Pyramid(n);
}

int Height(void)
{
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while(n < 1 || n > 8);
    return n;
}

void Pyramid (int n)
{
    int hash = n - (n - 1);
    int dot = n - 1;
    for(int k = 0; k < n; k++)
    {
        for(int i = 0; i < dot; i++)
        {
            printf(" ");
        }
        for(int i = 0; i < hash; i++)
        {
            printf("#");
        };
        hash++;
        dot--;
        printf("\n");
    }
}