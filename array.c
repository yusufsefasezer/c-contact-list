#include "array.h"

bool array_init(Array *arr)
{
    arr->size = 0;
    arr->capacity = INITIAL_CAPACITY;
    arr->contacts = malloc(sizeof(Contact) * array_capacity(arr));
    return arr->contacts == NULL ? false : true;
}

bool array_add(Array *arr, Contact newContact)
{
    array_resize(arr);
    arr->contacts[arr->size++] = newContact;
    return true;
}

bool array_resize(Array *arr)
{
    if(!(array_size(arr) >= array_capacity(arr)))
        return false;

    arr->capacity *= 2;
    arr->contacts = realloc(arr->contacts, sizeof(Contact) * array_capacity(arr));
    return arr->contacts == NULL ? false : true;
}

Contact array_get(Array *arr, int index)
{
    return arr->contacts[index];
}

bool array_delete(Array *arr, int index)
{
    int i;
    int len = array_size(arr);

    for(i = index; i < len; i++)
        arr->contacts[i] = arr->contacts[i + 1];

    arr->size--;
    return true;
}

int array_size(Array *arr)
{
    return arr->size;
}

int array_capacity(Array *arr)
{
    return arr->capacity;
}

void array_free(Array *arr)
{
    free(arr->contacts);
}

bool array_load(Array *arr, char *FILENAME)
{
    FILE *readfile = fopen(FILENAME, "r");
    Contact current;

    if(readfile == NULL)
        return false;

    while(fread(&current, sizeof(Contact), 1, readfile) == 1)
    {
        array_add(arr, current);
    }

    fflush(readfile);
    fclose(readfile);
    return true;
}

bool array_save(Array *arr, char *FILENAME)
{
    int i;
    int len = array_size(arr);
    Contact current;
    FILE *writefile = fopen(FILENAME, "w");

    if(writefile == NULL)
        return false;

    for(i = 0; i < len; i++)
    {
        current = array_get(arr, i);
        fwrite(&current, sizeof(Contact), 1, writefile);
    }

    fflush(writefile);
    fclose(writefile);
    return true;
}
