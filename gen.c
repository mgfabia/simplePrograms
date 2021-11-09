#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * This program will ask the user to enter a list of Names, then the names will be entered into an array/linked list data structure by using a hash function.
 **/
#define hashSize 10
int size = 0;
struct NameStruct *hashArray[hashSize];

struct NameStruct
{
    int key;
    char name[20];
    int age;
};

int hashFunction(char *name)
{
    int key = 0;
    int i = 0;
    while (i <= strlen(name))
    {
        key = key + name[i];
        i++;
    }

    printf("check 1: %d\n", key);
    printf("check 2: %d\n\n", (key % hashSize));
    return (key % hashSize);
}

void insertName(char *name)
{

    struct NameStruct *Name = (struct NameStruct *)malloc(sizeof(struct NameStruct));

    //hashes key

    int index = hashFunction(name);
    //populates struct object
    Name->key = index;
    strcpy(Name->name, name);

    //entering hash into hashtable
    while (hashArray[index] != NULL)
    {
        //traverses through array to find a spot for Name
        index++;
        index %= hashSize;
    }
    hashArray[index] = Name;
    printf("%s\n", Name->name);
    printf("index is: %d", index);
}

struct NameStruct *searchName(char *name)
{
    int index = hashFunction(name);
    if (strcmp(hashArray[index]->name, name) == 0)
    {
        return hashArray[index];
    }
    printf("Name does not exist in map.\n");
    return NULL;
}

void display()
{

    for (int i = 0; i < hashSize; i++)
    {
        if (hashArray[i] != NULL)
            printf(" (%d,%s)\n", hashArray[i]->key, hashArray[i]->name);
    }

    printf("\n");
}

int main()
{

    char name[20];
    int choice = 1;
    int iterator = 0;
    printf("Welcome to the Name dictionary\nHow many names would you like to enter in the dictionary?\n");
    scanf("%d", &size);
    printf("%d", size);

    while (choice)
    {
        if (iterator == size)
        {
            printf("Sorry, you cannot add any more names.\n");
            break;
        }
        printf("Please enter a Name to be added to the list.");
        scanf("%s", name);

        insertName(name);
        iterator++;
        printf("Would you like to enter another name?\nEnter 1 to enter another name, or enter 0 to search list.\n");
        scanf("%d", &choice);
    }
    display();
    int key = 0;
    printf("Enter the key associated with the name you would like to retrieve:\n");

    //print table
    scanf("%d", &key);

    struct NameStruct *retrieval = searchName(name);

    printf("The name retrieved is: %s\n", retrieval->name);
    printf("The key retrieved is %d\n", retrieval->key);

    printf("program successful!\n");

    return 0;
}