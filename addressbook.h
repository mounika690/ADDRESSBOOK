#ifndef CONTACT_H
#define CONTACT_H

#define MAX_CONTACTS 100

typedef struct {
    char name[50];
    char phone[20];
    char email[50];
} Contact;

typedef struct {
    Contact contacts[MAX_CONTACTS];
    int contactCount;
} AddressBook;

void initialize(AddressBook *addressBook);
void createContact(AddressBook *addressBook);
int validate_name(char *temp_name,AddressBook *addressBook);
int valid_nameadd(char *name);
int validate_phone(char *temp_phone,AddressBook *addressBook);
int valid_phoneadd(char *phone);
int validate_email(char *temp_email,AddressBook *addressBook);
int valid_emailadd(char *email);
void searchContact(AddressBook *addressBook);
void search_inname(char *str,AddressBook *addressBook);
void search_inphone(char *str,AddressBook *addressBook);
void search_inemail(char *str,AddressBook *addressBook);
void editContact(AddressBook *addressBook);
void edit_name(AddressBook *addressBook,int index);
void edit_phone(AddressBook *addressBook,int index);
void edit_email(AddressBook *addressBook,int index);
void deleteContact(AddressBook *addressBook);
void listContacts(AddressBook *addressBook);
void saveContacts(AddressBook *AddressBook);

#endif
