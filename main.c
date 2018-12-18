#include <stdio.h>
#include <stdlib.h>

#include "helper.h"

int main()
{

    Array arr;
    array_init(&arr);
    array_load(&arr, FILE_NAME);
    char key[81];

    while(true)
    {
        switch( selection_menu(1, 14))
        {
        case 1:
            add_contact(&arr);
            clear_screen();
            break;
        case 2:
            display_all(&arr);
            clear_screen();
            break;
        case 3:
            printf("Enter First Name: ");
            gets(key);
            display_search(&arr, key, FIRST_NAME);
            clear_screen();
            break;
        case 4:
            printf("Enter Last Name: ");
            gets(key);
            display_search(&arr, key, LAST_NAME);
            clear_screen();
            break;
        case 5:
            printf("Enter Phone Number: ");
            gets(key);
            display_search(&arr, key, PHONE_NUMBER);
            clear_screen();
            break;
        case 6:
            printf("Enter Email Address: ");
            gets(key);
            display_search(&arr, key, EMAIL_ADDRESS);
            clear_screen();
            break;
        case 7:
            printf("Enter First Name: ");
            gets(key);
            delete(&arr, key, FIRST_NAME);
            clear_screen();
            break;
        case 8:
            printf("Enter Last Name: ");
            gets(key);
            delete(&arr, key, LAST_NAME);
            clear_screen();
            break;
        case 9:
            printf("Enter Phone Name: ");
            gets(key);
            delete(&arr, key, PHONE_NUMBER);
            clear_screen();
            break;
        case 10:
            printf("Enter Email Address: ");
            gets(key);
            delete(&arr, key, EMAIL_ADDRESS);
            clear_screen();
            break;
        case 11:
            fprintf(stdout, "There are %d contacts on your contact list.\n", array_size(&arr));
            clear_screen();
            break;
        case 12:
            save_contact(&arr, FILE_NAME);
            clear_screen();
            break;
        case 13:
            save_contact(&arr, FILE_NAME);
            array_free(&arr);
            exit(0);
            break;
        case 14:
            array_free(&arr);
            exit(0);
            break;
        default:
            puts("Something is wrong.");
            array_free(&arr);
            exit(0);
            break;
        }
    }

    array_free(&arr);
    return 0;
}
