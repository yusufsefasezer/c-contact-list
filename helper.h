#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "array.h"

#ifndef HELPER_H_INCLUDED
#define HELPER_H_INCLUDED

#define FILE_NAME "list.dat"

// General
int selection_menu(int, int);
void clear_screen();
char* str_lower(char*);

// Add Contact
void add_contact(Array*);

// Display
void display_all(Array*);
void display_contact(Contact*);
void display_search(Array *, char *, SEARCH_TYPE);

// Search
int search(Array*, char*, SEARCH_TYPE);
int search_first_name(Array*, char*);
int search_last_name(Array*, char*);
int search_last_name(Array*, char*);
int search_phone_number(Array*, char*);
int search_email_address(Array*, char*);

// Delete
void delete(Array*, char*, SEARCH_TYPE);

// Save Contact
bool save_contact(Array*, char*);

#endif // HELPER_H_INCLUDED
