#ifndef CONTACT_H_INCLUDED
#define CONTACT_H_INCLUDED

typedef struct contact
{
    char firstName[40];
    char lastName[40];
    char phoneNumber[20];
    char emailAdress[40];
    char address[80];
    char note[80];
} Contact;

typedef enum FIELD {FIRST_NAME, LAST_NAME, PHONE_NUMBER, EMAIL_ADDRESS} SEARCH_TYPE;

#endif // CONTACT_H_INCLUDED
