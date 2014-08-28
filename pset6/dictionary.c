/****************************************************************************
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 6
 *
 * Implements a dictionary's functionality.
 ***************************************************************************/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "dictionary.h"

typedef struct node
{
    bool is_word;
    struct node* children[27];
}
node;

node* root;
int count = 0;
/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    // TODO
    int n = strlen(word);
    node* head = root;
    for (int i = 0; i < n; i++)
    {
        int j;
        if (word[i] == '\'') 
        {
            j = 'z' + 1;
        }
        else
        {
            j = tolower(word[i]) - 'a';
        }
        
        if (head -> children[j] == NULL)
        {
            return false;
        }
        else
        {
            head = head -> children[j];
        }
    }
    if (head -> is_word)
        return true;
        
    return false;
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
    // TODO
    root = malloc(sizeof(node));
    FILE* file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }
    char word[LENGTH+1];
    while (fscanf(file, "%s", word) > 0)
    {
        int i = 0;
        node* head = root;
        while (word[i] != '\0')
        {
            int j = word[i] - 97;
            if (head -> children[j] == NULL)
            {
                head -> children[j] = (node*)malloc(sizeof(node));
                head = head -> children[j];
            }
            else
            {
                head = head -> children[j];
            }
            i++;
        }
        head -> is_word = true;
        count++;
    }
    fclose(file);
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    // TODO
    return count;
}


/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */

bool rec(node* cursor)
{
    for (int i = 0; i < 27; i++)
    {
        if (cursor -> children[i] != NULL)
        {
            rec(cursor -> children[i]);
        }
    }
    free(cursor);
    return true;
}

bool unload(void)
{
    // TODO
    rec(root);
    return true;
}


