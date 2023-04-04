#include "helper.h"

// General
int selection_menu(int min, int max)
{
    int choice = -1;

    puts("############ Menu ############");
    puts("1. Add New");
    puts("2. Display All");
    puts("3. Search by First Name");
    puts("4. Search by Last Name");
    puts("5. Search by Phone Number");
    puts("6. Search by Email Address");
    puts("7. Delete by First Name");
    puts("8. Delete by Last Name");
    puts("9. Delete by Phone Number");
    puts("10. Delete by Email Address");
    puts("11. Information");
    puts("12. Save");
    puts("13. Save & Exit");
    puts("14. Exit");

    do
    {
        printf("Enter your choice: ");
        scanf("%d%*c", &choice);
    }
    while(choice < min || choice > max);

    return choice;
}

void clear_screen()
{
    char x;
    scanf("%c", &x);
    system("@cls||clear");
}

char* str_lower(char *str)
{
    int i = 0;
    int len = strlen(str);

    for(i = 0; i < len; i++)
        str[i] = tolower(str[i]);

    return str;
}

// Add Contact
void add_contact(Array *arr)
{
    Contact newContact;

    printf("Enter First Name: ");
    gets(newContact.firstName);

    printf("Enter Last Name: ");
    gets(newContact.lastName);

    printf("Enter Phone Number: ");
    gets(newContact.phoneNumber);

    printf("Enter Email Address: ");
    gets(newContact.emailAdress);

    printf("Enter Address: ");
    gets(newContact.address);

    printf("Enter Note: ");
    gets(newContact.note);

    if(array_add(arr, newContact))
        puts("Added successfully.");
    else
        puts("Something is wrong.");
}

// Display
void display_all(Array *arr)
{
    int i = 0;
    int len  = array_size(arr);;
    Contact current;

    for(i = 0; i < len; i++)
    {
        current = array_get(arr, i);
        printf("############ %d ############\n", i + 1);
        display_contact(&current);
    }
}

void display_contact(Contact *contact)
{
    printf("First Name: %s\n", contact->firstName);
    printf("Last Name: %s\n", contact->lastName);
    printf("Phone Number: %s\n", contact->phoneNumber);
    printf("Email Address: %s\n", contact->emailAdress);
    printf("Address: %s\n", contact->address);
    printf("Note: %s\n", contact->note);
}

void display_search(Array *arr, char *key, SEARCH_TYPE field)
{
    int search_result = search(arr, key, field);

    if(search_result != -1)
    {
        Contact current = array_get(arr, search_result );
        display_contact(&current);
    }
    else
    {
        puts("Not found!");
    }

}

// Search
int search(Array *arr, char *key, SEARCH_TYPE field)
{
    switch(field)
    {
    case FIRST_NAME:
        return search_first_name(arr, str_lower(key));
        break;
    case LAST_NAME:
        return search_last_name(arr, str_lower(key));
        break;
    case PHONE_NUMBER:
        return search_phone_number(arr, str_lower(key));
        break;
    case EMAIL_ADDRESS:
        return search_email_address(arr, str_lower(key));
        break;
    default:
        return -1;
        break;
    }

    return -1;
}

int search_first_name(Array *arr, char *key)
{
    int i = 0;
    int len = array_size(arr);
    char value[41];
    Contact current;

    for(i = 0; i < len; i++)
    {
        current = array_get(arr, i);
        strcpy(value, current.firstName);
        str_lower(value);
        if(strcmp(value, key) == 0)
            return i;
    }

    return -1;
}

int search_last_name(Array *arr, char *key)
{
    int i = 0;
    int len = array_size(arr);
    char value[41];
    Contact current;

    for(i = 0; i < len; i++)
    {
        current = array_get(arr, i);
        strcpy(value, current.lastName);
        str_lower(value);
        if(strcmp(value, key) == 0)
            return i;
    }

    return -1;
}

int search_phone_number(Array *arr, char *key)
{
    int i;
    int len = array_size(arr);
    char value[21];
    Contact current;

    for(i = 0; i < len; i++)
    {
        current = array_get(arr, i);
        if(strcmp(current.lastName, key) == 0)
            return i;
    }

    return -1;
}

int search_email_address(Array *arr, char *key)
{
    int i;
    int len = array_size(arr);
    char value[41];
    Contact current;

    for(i = 0; i < len; i++)
    {
        current = array_get(arr, i);
        strcpy(value, current.emailAdress);
        str_lower(value);
        if(strcmp(value, key) == 0)
            return i;
    }

    return -1;
}

// Delete
void delete(Array *arr, char *key, SEARCH_TYPE field)
{
    int search_result  = search(arr, key, field);

    if(search_result != -1)
    {
        array_delete(arr, search_result);
        strcat(key, " was deleted.");
        puts(key);
    }
    else
    {
        puts("Not found!");
    }
}

bool save_contact(Array *arr, char *FILENAME)
{
    return array_save(arr, FILENAME);
}
