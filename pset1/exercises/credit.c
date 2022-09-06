#include <stdio.h>
#include <cs50.h>

void validateCard(long n);

int main(void)
{
    long card = get_long("Number of card: ");
    validateCard(card);
}

bool countNumbers(long n)
{
    long number = n;
    long count = 0;
    do
    {
        number = number / 10;
        count++;
    }while(number != 0);
    if(count == 13 || count == 15 || count == 16)
    {
        return true;
    }else
    {
        return false;
    }
}

string typeCard(long n)
{
    if(n == 34 || n == 37)
    {
        return "AMEX\n";
    }else if(n >= 51 && n <= 55)
    {
        return "MASTERCARD\n";
    }else if(n >= 40 && n <= 49)
    {
        return "VISA\n";
    }else
    {
        return "INVALID\n";
    }
}

void validateCard(long n)
{
    long number = n;
    int sum = 0;
    string type = "INVALID\n";
    if(countNumbers(number))
    {
        bool in = 1;
        bool dou = 0;
        do
        {
            if(in && number > 10)
            {
                sum += number % 10;
                number = (long)number / 10;
                in = 0;
                dou = 1;
            }
            if(number < 100 && number > 10)
            {
                type = typeCard(number);
            }
            if(dou && number > 10)
            {
                int sum1 = (number % 10) * 2;
                if(sum1 > 10)
                {
                    sum += sum1 % 10;
                    sum += (long)sum1 / 10;
                }else
                {
                    sum += sum1;
                }
                number = number / 10;
                in = 1;
                dou = 0;
            }
            if(number < 100 && number > 10)
            {
                type = typeCard(number);
            }
        }while(number > 10);
        if(in)
        {
            sum += number;
            int total = sum % 10;
            if(total == 0)
            {
                printf("%s", type);
            }else
            {
                printf("INVALID\n");
            }
        }
        if(dou)
        {
            sum += number * 2;
            int total = sum % 10;
            if(total == 0)
            {
                printf("%s", type);
            }else
            {
                printf("INVALID\n");
            }
        }
    }else
    {
        printf("INVALID\n");
    }
}