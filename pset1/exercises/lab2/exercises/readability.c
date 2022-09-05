#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

void grade (string text);

int main (void)
{
    string text = get_string("Text: ");
    grade(text);
}

void grade (string text)
{
    int letters = 0;
    int words = 1;
    int sentences = 0;
    int grade;
    for(int i = 0, n = strlen(text); i < n; i++)
    {
        if(isalpha(text[i]))
        {
            letters++;
        }
        if(isspace(text[i]))
        {
            words++;
        }
        if(text[i] == 33 || text[i] == 63 || text[i] == 46)
        {
            sentences++;
        }
    }
    float L = ((float)letters / words) * 100;
    float S = ((float)sentences / words) * 100;
    grade = round((0.0588 * L) - (0.296 * S) - 15.8);
    if(grade < 1)
    {
        printf("Before Grade 1\n");
    }else if(grade > 16)
    {
        printf("Grade 16+\n");
    }else
    {
        printf("Grade %i\n", grade);
    }
}