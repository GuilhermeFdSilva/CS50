#include <stdio.h>
#include <cs50.h>

int main(void)
{
    char c = get_char("You agree? ");

    if(c == 'y' || c == 'Y')
    {
        printf("Agree.\n");
    }
    else if(c == 'n' || c == 'N')
    {
        printf("Not agree.\n");
    }
}