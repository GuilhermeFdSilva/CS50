#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n;
    do
    {
        n = get_int("Size: ");
    }
    while(n < 1);

    for(int i = 0; i < n; i++)
    {
        printf("?");
    }
    printf("\n");
}