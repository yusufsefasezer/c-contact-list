#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "contact.h"

#ifndef ARRAY_H_INCLUDED
#define ARRAY_H_INCLUDED
#define INITIAL_CAPACITY 2

typedef struct array
{
    int capacity;
    int size;
    Contact *contacts;
} Array;

bool array_init(Array*);
bool array_add(Array*, Contact);
bool array_resize(Array*);
Contact array_get(Array*, int);
bool array_delete(Array*, int);

int array_size(Array*);
int array_capacity(Array*);
void array_free(Array*);

bool array_save(Array*, char*);
bool array_load(Array*, char*);

#endif // ARRAY_H_INCLUDED
