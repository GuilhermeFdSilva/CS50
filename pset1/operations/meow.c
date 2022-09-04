#include <stdio.h>
#include <cs50.h>

void meow(int);

int get_positive_int(void);

int main(void)
{
    int n = get_positive_int();
    meow(n);
}

void meow(int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("Meow\n");
    }
}

int get_positive_int(void)
{
    int n;
    do
    {
        n = get_int("Positive number: ");
    }
    while(n < 1);
    return n;
}