// In God we trust
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct node
{
    char name[40];
    struct node *next[10];
}
node;

node *append(node *ptr)
{
    // Assigns a new node to a pointer
    node *new = malloc(sizeof(node));
    for (int i = 0; i < 10; i++)
    {
        new->next[i] = NULL;
    }

    strcpy(new->name, "");

    // Checks whether the given pointer is NULL or not
    if (ptr == NULL)
    {
        ptr = new;
        return ptr;
    }
    else
    {
        return ptr;
    }
}

node *delete(node *ptr, char date[4], int i)
{
    
    // deletes a member of trie
    node *tmp = ptr;
    int place = date[i] - 48;
    
    if (ptr == NULL)
    {
        return NULL;
    }

    // checks if the given pointer is NULL
    if (tmp->next[place] == NULL)
    {
        return NULL;
    }

    // checks if the requested data is reached
    if (i == 3)
    {
        free(tmp->next[place]);
        tmp->next[place] = NULL;
    }
    else
    {
        tmp->next[place] = delete(tmp->next[place], date, i + 1);
    }

    if (tmp->next[place] == NULL)
    {
        for (int j = 0; j < 10; j++)
        {
            if (tmp->next[j] != NULL)
            {
                return tmp;
            }
        }
        free(tmp);
        return NULL;
    }

    return tmp;
    

}

int main(void)
{
    char word[40];
    char date[5];
    node *trie = NULL;
    trie = append(trie);
    node *tmp = trie;

    printf("Trie\n");
    printf("Please enter the name of person and year of birth in four digits(type \"end\" to finish input)\n");

    while (1)
    {
        printf("Word: ");
        scanf("%s", word);
        if (strcmp(word, "end") == 0)
        {
            break;
        }

        while (1)
        {
            // Gets and handles the errors with it
            printf("Date: ");
            scanf("%s", date);
            if (strcmp(date, "end") == 0)
            {
                break;
            }

            if (!isdigit(date[0]) && !isdigit(date[1]) && !isdigit(date[2]) && !isdigit(date[3]))
            {
                printf("Please enter a number!\n");
                continue;
            }
            else
            {
                break;
            }
            
        }
        if (strcmp(date, "end") == 0)
        {
            break;
        }
        
        tmp = trie;
        for (int i = 0; i < 4; i++)
        {
            // Adds the name to trie
            int place = date[i] - 48;
            tmp->next[place] = append(tmp->next[place]);
            tmp = tmp->next[place];
        }
        strcpy(tmp->name, word);
    }

    printf("Please enter the date you want to delete!\n");
    while (1)
    {
        printf("Date: ") ;
        scanf("%s", date);
        if (strcmp(date,"end") == 0)
        {
            break;
        }
        trie = delete(trie, date, 0);
    }

    printf("Now enter the Date to search(type \"end\" to finish search)\n");

    while (1)
    {
        char date[5];
        while (1)
        {
            // Gets and handles the errors with an int
            printf("Date: ");
            scanf("%s", date);
            if (strcmp(date, "end") == 0)
            {
                break;
            }

            if (!isdigit(date[0]) && !isdigit(date[1]) && !isdigit(date[2]) && !isdigit(date[3]))
            {
                printf("Please enter a number!\n");
                continue;
            }
            else
            {
                break;
            }
            
        }
        if (strcmp(date, "end") == 0)
        {
            break;
        }

        // searches and prints the result
        tmp = trie;
        char result[40];
        
        // checks if the pointer is NULL
        if (tmp == NULL)
        {
            printf("Not found!\n");
            continue;
        }

        for (int i = 0; i < 4; i++)
        {
            int place = date[i] - 48;
            if (tmp->next[place] == NULL)
            {
                printf("Not found!\n");
                break;
            }
            tmp = tmp->next[place];
        }

        if (tmp->name == NULL)
        {
            printf("Not found!\n");
            continue;
        }
        else
        {
            strcpy(result, tmp->name);
            printf("Result: %s\n", result);
        }

    }

}