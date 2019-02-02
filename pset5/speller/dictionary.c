// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include "dictionary.h"


// Node struct
// https://cs50.stackexchange.com/a/12432
typedef struct node
{
    char word[LENGTH + 1];
    struct node* next;
}node;


// Create hashtable
node* hashtable[HASHTABLE_SIZE];

// Create pointers size of large dictionary
node* pointers[143091];

// Initialize pointers index
unsigned int pointers_index = 0;

// Initialize word counter
unsigned int counter = 0;

// Initialize dictionary file is_loaded to false
bool is_loaded = false;

// Hashtable
int hash_word(const char* word)
{
    unsigned int hash = 0;
    for (int i = 0; i < strlen(word); ++i)
    {
        hash = 31 * hash + toupper(word[i]);
    }
    return hash % HASHTABLE_SIZE;
}

// // Returns true if word is in dictionary else false
bool check(const char *word)
{
    node* cursor = hashtable[hash_word(word)];

    while (cursor != NULL)
    {
        if (strcasecmp(word, cursor -> word) == 0)
        {
            return true;
        }
        cursor = cursor -> next;
    }

    // printf("word: %s\n", word);
    return false;
}

// // Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    FILE *file = fopen (dictionary, "r");
    char word[LENGTH + 1];
    int index = 0;

    // If file can't be opened
    if (file == NULL)
    {
        printf("Could not open dictionary\n");
        unload();
        return 1;
    }

    // Scan every word until it hits EOF
    while(fscanf(file, "%s", word) != EOF)
    {

        // Allocate memory for each new word
        node *new_node = malloc(sizeof(node));

        if(new_node == NULL)
        {
          return false;
        }

        strcpy(new_node->word, word);
        index = hash_word(word);
        new_node->next = hashtable[index];
        hashtable[index] = new_node;
        pointers[pointers_index++] = new_node;
        counter++;

    }

    fclose(file);
    is_loaded = true;
    return true;

}

// // Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // Returns # of words in dictionary
    if (is_loaded)
    {
        return counter;
    }
    else
    {
        return 0;
    }
}

// // Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    for (int i = 0; i < pointers_index; i++)
    {
        free(pointers[i]);
    }
    // printf("counter: %i\n", counter);
    is_loaded = false;
    return true;
}