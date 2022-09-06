#include <stdio.h>
#include <cs50.h>
#include <string.h>
#define MAX 9

typedef struct
{
     string name;
     int votes;
}
candidate;

candidate candidates[MAX];

int candidateCount;

bool vote (string name);

void print_winner(void);

int main(int argc, string argv[])
{
    if(argc < 2)
    {
        printf("Usage: ./plurality candidate, ...\n");
        return 1;
    }
    candidateCount = argc - 1;
     if (candidateCount > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for(int i = 0; i < candidateCount; i++)
    {
        candidates[i].name = argv[i +  1];
        candidates[i].votes = 0;
    }
    int voters = get_int("Number of voters: ");
    for(int i = 0; i < voters; i++)
    {
        string name = get_string("Vote: ");
        if(!vote(name))
        {
            printf("Invalid vote.\n");
            i--;
        }
    }
    print_winner();
}

bool vote (string name)
{
    for(int i = 0; i < candidateCount; i++)
    {
        if(strcmp(candidates[i].name, name) == 0)
        {
            candidates[i].votes++;
            return true;
        }
    }
    return false;
}

void print_winner(void)
{
    int maximumVote = 0;
    for(int i = 0; i < candidateCount; i++)
    {
        if(candidates[i].votes > maximumVote)
        {
            maximumVote = candidates[i].votes;
        }
    }
    for(int i = 0; i < candidateCount; i++)
    {
        if(candidates[i].votes == maximumVote)
        {
            printf("%s\n", candidates[i].name);
        }
    }
}