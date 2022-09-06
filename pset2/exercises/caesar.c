#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

int main(int argc, string argv[])
{
    if(argc == 2)
    {
        bool areNumbers = 1;
        string arg = argv[1];
        for(int i = 0, n = strlen(arg); i < n; i++)
        {
            if(isalnum(arg[i]))
            {
                areNumbers = 1;
            }
            else
            {
                areNumbers = 0;
            }
        }
        if (areNumbers)
        {
            int key = 0;
            for(int i = 0, n = strlen(arg); i < n; i++)
            {
                char number = arg[i];
                key = key * 10;
                key += (int)number;
            }
            string plaintext = get_string("plaintext: ");
            string ciphertext = "";
            for(int i = 0, n = strlen(plaintext); i < n; i++)
            {
                int letter = plaintext[i];
                char cipherLetter;
                if(isalpha(letter))
                {
                    if(isupper(letter))
                    {
                        for(int j = 0; j < key; j++)
                        {
                            letter++;
                            if(letter > 90)
                            {
                                letter = 65;
                            }
                        }
                        cipherLetter = letter;
                    }
                    if(islower(letter))
                    {
                        for(int j = 0; j < key; j++)
                        {
                            letter++;
                            if(letter > 122)
                            {
                                letter = 97;
                            }
                        }
                        cipherLetter = letter;
                    }
                }
                if(isdigit(letter))
                {
                    for(int j = 0; j < key; j++)
                    {
                        letter++;
                        if(letter > 126)
                        {
                            letter = 32;
                        }
                    }
                    cipherLetter = letter;
                }
                ciphertext += cipherLetter;
            }
            printf("ciphertext: %s\n", ciphertext);
        }
        else
        {
            printf("Usage: ./caesar key\n");
        }
    }
    else
    {
        printf("Usage: ./caesar key\n");
    }
}