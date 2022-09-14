// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <math.h>

#include "dictionary.h"

// make count_words a global variable
// it may be called in size();
unsigned int count_words = 0;

// Prototypes
unsigned int size(void);

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;
const unsigned int N = 20000;
bool check(const char *word)
{
    int word_index = hash(word);
    node *cursor = table[word_index];
    while (cursor != NULL)
    {
        if (strcasecmp(word, cursor->word) == 0)
        {
            return true;
        }
        cursor = cursor->next;
    }
    return false;
}
unsigned int hash(const char *word)
{
    unsigned int roll_sum = 0;
    unsigned int squared = 0;
    for (int i = 0; i < strlen(word); i++)
    {
        squared = pow(toupper(word[i]), 2);
        if (i == round(strlen(word) / 2))
        {
            roll_sum = roll_sum + round(sqrt(roll_sum)) + 17;
        }
        roll_sum = squared + roll_sum + 47;
    }
    return roll_sum % N;
}
bool load(const char *dictionary)
{
    FILE *dict_open = fopen(dictionary, "r");
    if (dict_open == NULL)
    {
        printf("Could not open the dictionary file.\n");
        return false;
    }
    else if (dict_open != NULL)
    {
        char buffer[LENGTH + 1];
        int hash_index = 0;
        while (fscanf(dict_open, "%s", buffer) != EOF)
        {
            node *n = malloc(sizeof(node));
            if (n == NULL)
            {
                return false;
                break;
            }
            else if (n != NULL)
            {
                strcpy(n->word, buffer);
                n->next = NULL;
                hash_index = hash(buffer);
                if (table[hash_index] == NULL)
                {
                    table[hash_index] = n;
                }
                else if (table[hash_index] != NULL)
                {
                    n->next = table[hash_index];
                    table[hash_index] = n;
                }
                count_words++;
            }
        }
        fclose(dict_open);
        return true;
    }
    else
    {
        return false;
    }
}
unsigned int size(void)
{
    return count_words;
}
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        node *temp = table[i];
        node *cursor = table[i];
        while (temp != NULL)
        {
            cursor = cursor->next;
            free(temp);
            temp = cursor;
        }
    }
    return true;
}