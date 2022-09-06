#include <stdio.h>
#include <cs50.h>

int calculate(int st, int ed);

int main(void)
{
      int startSize;
      int endSize;
      int years;
      do
      {
        startSize = get_int("Start size: ");
      }while(startSize < 8);
      do
      {
        endSize = get_int("End size: ");
      }while(endSize < startSize);
      years = calculate(startSize, endSize);
      printf("Years: %i\n", years);
}

int calculate(int st, int ed)
{
    int years = 0;
    do
    {
        st += (int)(st / 3) - (int)(st / 4);
        years++;
    }while(st < ed);
    return years;
}