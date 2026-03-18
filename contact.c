#include "contact.h"
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
//main one to submit
 /*
 1.take addressbook contacts =0
 2.open the file
 3.check whether it is open
 4.if open read all the info to addressbook temporarily to make modifications until it reaches eof
 5.and make to read all
 6.close the file
 */
void initialize(AddressBook *addressBook)
{
    addressBook->contactCount = 0;

    FILE *fptr = fopen("contacts.txt","r");

    if(fptr == NULL)
        return;

    while(!feof(fptr))
    {
        fscanf(fptr,"%[^,],%[^,],%[^\n]\n",
        addressBook->contacts[addressBook->contactCount].name,
        addressBook->contacts[addressBook->contactCount].phone,
        addressBook->contacts[addressBook->contactCount].email);
    
        addressBook->contactCount++;
    }

    fclose(fptr);
}
//Printing all them addressBook
/*
1.print all the details to addressbook until to u get contactcount
2. */
void listContacts(AddressBook *addressBook)
{
    printf("--------------------------------------------------------------------------------------------\n");
    printf("SI                  NAME                   PHONE                        MAIL\n");
    printf("---------------------------------------------------------------------------------------------\n");

    for(int i=0;i<addressBook->contactCount;i++)
    {
        printf("%d %25s %20s %30s\n",
        i+1,
        addressBook->contacts[i].name,
        addressBook->contacts[i].phone,
        addressBook->contacts[i].email);
    }
}


//createing contact to the addressBook

/*
1.take some temparary variablesto check
2.to give chances to user take count
3.take a loop until user entered the valid ones or it reaches chances
4. call functions is it present or not previous if it present print 
5.call another function if it is not present whether it has only alphabets
6 based on the return valid or not and go to step 3
7.check this all for phone ,email from 2
8.if all are valid then copy that info to addressbook
*/
void createContact(AddressBook *addressBook)
{
    char temp_name[20],temp_phone[20],temp_email[20];
    int count=0;
    while(count<3)
    {
        printf("Enter the name\n");
        scanf(" %[^\n]",temp_name);
        getchar();
        int x=validate_name(temp_name,addressBook);
        
        if(x==0)
        {//printf("s");
            printf("It is already present\n");
            count++;
            continue;
        }
        int a=valid_nameadd(temp_name);
        if(a==0)
        {
            printf("It is Invalid\n");
            count++;
            continue;
        }
        printf("Valid name\n");
        break;
    }
    if(count == 3)
    {
        printf("No more chances.TRY LATER");
        return;
    }

    count=0;
    while(count<3)
    {
        printf("Enter the phone\n");
        scanf(" %[^\n]",temp_phone);
        getchar();
        int x=validate_phone(temp_phone,addressBook);
        
        if(x==0)
        {//printf("s");
            printf("It is already present\n");
            count++;
            continue;
        }
        int a=valid_phoneadd(temp_phone);
        if(a == 0)
        {
            printf("It is Invalid\n");
            count++;
            continue;
        }
        printf("Valid number\n");
        break;
    }
    if(count == 3)
    {
        printf("No more chances.TRY LATER");
        return;
    }


    count=0;
    while(count<3)
    {
        printf("Enter the email\n");
        scanf(" %[^\n]",temp_email);
        getchar();
        int x=validate_email(temp_email,addressBook);
        if(x==0)
        {
            printf("It is already present\n");
            count++;
            continue;
        }
        int a=valid_emailadd(temp_email);
        if(a == 0)
        {
            printf("It is Invalid\n");
            count++;
            continue;
        }
        printf("Valid email\n");
        break;
    }
    if(count == 3)
    {
        printf("No more chances.TRY LATER");
        return;
    }


    //after all validation getting correct info copying to the addressBook
    printf("Contact saved successfully\n");
    strcpy(addressBook->contacts[addressBook->contactCount].name,temp_name);
    strcpy(addressBook->contacts[addressBook->contactCount].phone,temp_phone);
    strcpy(addressBook->contacts[addressBook->contactCount].email,temp_email);
    addressBook->contactCount++;
}

//checking of addressBook with enetered name

/*
1.take a loop to check whether it is present or nat
2.check it is present or not
3.based on that return valid value
*/
int validate_name(char *temp_name,AddressBook *addressBook)
{
    for(int i=0;i<addressBook->contactCount;i++)
    {
        char *x=strcasestr(addressBook->contacts[i].name,temp_name);
        if(x)
        {
            return 0;
        }

    }
    return 1;
}

//validation of entered name
/*
1.take one loop to check whether it is valid
2.check all the things are alphabet
3.if yes return 0
4.if not means return 1
*/
int valid_nameadd(char *name)
{
    for(int i=0;i<name[i]!='\0';i++)
    {
        if(!isalpha(name[i]) && name[0] !=' ')
        {
            return 0;
        }
    }
    return 1;
}

//checking of entered number in addressbook

/*
1.take a loop to check whether it is present or nat
2.check it is present or not
3.based on that return valid value
*/
int validate_phone(char *temp_phone,AddressBook *addressBook)
{
    for(int i=0;i<addressBook->contactCount;i++)
    {
        int x=strcmp(addressBook->contacts[i].phone,temp_phone);
        if(!x)
        {
            return 0;
        }

    }
    return 1;
}

/*
1.take one loop to check whether it is valid
2.check all the things are digits
3.if yes return 0
4.if not means return 1
*/
//validation of phonenumber
int valid_phoneadd(char *phone)
{
    if(strlen(phone) != 10)
    {
        return 0;
    }
    for(int i=0;i<phone[i]!='\0';i++)
    {
        if(!isdigit(phone[i]))
        {
            return 0;
        }
    }

    return 1;
}

//checking whether the email is in addressbook or not

/*
1.take a loop to check whether it is present or nat
2.check it is present or not
3.based on that return valid value
*/
int validate_email(char *temp_email,AddressBook *addressBook)
{
    for(int i=0;i<addressBook->contactCount;i++)
    {
        int x=strcasecmp(addressBook->contacts[i].email,temp_email);
        if(x == 0)
        {
            return 0;
        }
    }
    return 1;
}


//validation of emailid


/*
1.take one loop to check whether it is valid
2.check all the things are it has .com 
3.check the return value of .com in email from there to 4 th one \0 or not
4.check before . is @ or not
5.check it has 1 @,all are alphabets other than @ and .
6 .based all conditions  return valid values
*/
int valid_emailadd(char *email)
{
    char *cptr = strcasestr(email,".com");
    if(cptr == NULL)
    {
        return 0;
    }
    if(cptr[4]!='\0')
    {
        return 0;
    }
    if(cptr[-1]=='@')
    {
        return 0;
    }
    int count =0;
    for(int i=0;email[i]!='\0';i++)
    {
        if(email[i]=='@')
        {
            count++;
        }
        if(((email[i]>='A')&&(email[i]<='Z'))||((email[i]>='a')&&(email[i]<='z'))||email[i]=='@'||email[i]=='.')
        {
            continue;
        }
        else
        return 0;
    }
    if(count!=1)
    {
        return 0;
    }
    return 1;
}


//searching contact in addressBook

/*
1.give options by what user wants search
2.if it is name call a function which deals with name
3.if it is phone call a function which deals with phone
4.if it is email call a function which deals with email
*/
void searchContact(AddressBook *addressBook)
{
    printf("BY WHAT YOU WANT TO SEARCH : \n");
    printf("1.NAME\n");
    printf("2.PHONE\n");
    printf("3.MAIL\n");
    printf("4.exit\n");
    printf("enter option\n");
    int option;
    scanf("%d",&option);
    switch (option)
    {
    case 1:
        printf("enter the name you want to search :\n");
        char name[10];
        scanf("%s",name);
        search_inname(name,addressBook);
        break;
    case 2:
        printf("enter the phone you want to search :\n");
        char phone[20];
        scanf("%s",phone);
        search_inphone(phone,addressBook);
        break;
    case 3:
        printf("enter the email you want to search :\n");
        char email[10];
        scanf("%s",email);
        search_inemail(email,addressBook);
        break;

    
    default:
        break;
    }
}

//searching using name
/*
1.take found =0 it indicates the what i search for, is there or not
2.search the name you want store that in pointer
3.if that is null means it is not present
4.if that is not null it is there and print that info
5.based on that return valid value
6.if found = 0 it is not present
*/
void search_inname(char *str,AddressBook *addressBook)
{
    int found=0;
    char *x;
    for(int i=0;i<addressBook->contactCount;i++)
    {
        x=strcasestr(addressBook->contacts[i].name,str);
    
      if(x)
       {
        found =1;
        printf("%s %s %s ",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
        printf("\n");
        }
    }
    if(found == 0)
    printf("Not found\n");
    
}


//searching using phone number

/*
1.take found =0 it indicates the what i search for, is there or not
2.search the phone you want store that in pointer
3.if that is null means it is not present
4.if that is not null it is there and print that info
5.based on that return valid value
6.if found = 0 it is not present
*/
void search_inphone(char *str,AddressBook *addressBook)
{
    int found=0;
    char *x;
    for(int i=0;i<addressBook->contactCount;i++)
    {
        char *x=strstr(addressBook->contacts[i].phone,str);
    
      if(x)
       {
        found =1;
          printf("%s %s %s ",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
          printf("\n");
        }
    }
    if(found == 0)
    printf("Not found\n");
    
}



//searching using email
/*
1.take found =0 it indicates the what i search for, is there or not
2.search the email you want store that in pointer
3.if that is null means it is not present
4.if that is not null it is there and print that info
5.based on that return valid value
6.if found = 0 it is not present
*/
void search_inemail(char *str,AddressBook *addressBook)
{
    int found=0;
    char *x;
    for(int i=0;i<addressBook->contactCount;i++)
    {
        char *x=strstr(addressBook->contacts[i].email,str);
    
      if(x)
        {
          found =1;
          printf("%s %s %s ",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
        }
    }
    if(found == 0)
    printf("Not found\n");
    
}


//make changes after it is saved as incoorect


/*
1.take a name which you want to edit 
2.take choice based name what you want to edit
3.after taking choices check each and everyone with validation functions 
4.it returns 1 means make a change 
5 replace that with new data 
*/
void editContact(AddressBook *addressBook)
{
    printf("enter the name you want to change\n");
    char name[50];
    int found =0;
    int choice;
    scanf("%s",name);
    for(int i=0;i<addressBook->contactCount;i++)
    {
        char *x = strcasestr(addressBook->contacts[i].name,name);
        if(x)
        {
            found = 1;
            printf("menu to what you want change about the address the person:\n");
            printf("1.NAME\n2.PHONE\n3.MAIL\n4.EXIT");
            printf("enter your choice :\n");
            scanf("%d",&choice);
            switch (choice)
            {
            case 1:
                edit_name(addressBook,i);
                break;
            case 2:
                edit_phone(addressBook,i);
               break;
            case 3:
                edit_email(addressBook,i);
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("you didn't select valid option\n");
                break;
            }
        }
    }
    if(!found)
    printf("contact not found\n");
}


//accidentally entered by wrong name edit

/*
1.take a name 
2.check if it is already in addressBook
3.if it is ,call function for validation
4.based on validation make changes
5.else return to 0
*/


void edit_name(AddressBook *addressBook,int index)
{
    printf("new name:\n");
    char new_name[50];
    scanf("%s",new_name);
    if( validate_name(new_name,addressBook) == 0)
    {
        printf("it is already presnt\n");
        exit(0); 
    }
    if(valid_nameadd(new_name))
    {
        strcpy(addressBook->contacts[index].name,new_name);
        printf("%s name edited successfully",new_name);
    }
    else
    printf("Invalid name\n");
}


//saved wrong number or not useable number changing into correct

/*
1.take a phone 
2.check if it is already in addressBook
3.if it is ,call function for validation
4.based on validation make changes
5.else return to 0
*/
void edit_phone(AddressBook *addressBook,int index)
{
    printf("new phone:\n");
    char new_phone[20];
    scanf("%s",new_phone);
    if( validate_phone(new_phone,addressBook) == 0)
    {
        printf("it is already presnt\n");
        exit(0); 
    }
    if(valid_phoneadd(new_phone))
    {
        strcpy(addressBook->contacts[index].phone,new_phone);
        printf("%s phone number edited successfully",new_phone);
    }
    else
    printf("Invalid phone number\n");
}


//editting email after knowing that is wrong

/*
1.take a email 
2.check if it is already in addressBook
3.if it is not present ,call function for validation
4.based on validation make changes
5.else return to 0
*/
void edit_email(AddressBook *addressBook,int index)
{
    printf("new email:\n");
    char new_email[50];
    scanf("%s",new_email);
    if( validate_email(new_email,addressBook) == 0)
    {
        printf("it is already presnt\n");
        exit(0); 
    }
    if(valid_emailadd(new_email))
    {
        strcpy(addressBook->contacts[index].email,new_email);
        printf("%s email edited successfully",new_email);
    }
    else
    printf("Invalid email\n");
}
//algorithm to delete contact
/*
  1.read name
  2.take one flag to check if it exists
  3.find index where name is present
      1.make flag = 1
      2.run a loop to check in addressBook
          1.check with strcasestr 
          2.run a loop if found
          3.replace everything with next _contact
      4.decrement contactCount
      5.print message if found ->use break statement
  3.enter if condition if not found
  4.printf ->not found
  */
void deleteContact(AddressBook *addressBook)
{
    printf("enter name who you want to delete \n");
    char name[50];
    int found =0;
    scanf("%s",name);
    for(int i=0;i<addressBook->contactCount;i++)
    {
        char *x = strcasestr(addressBook->contacts[i].name,name);
    if(x)
    {
        printf("Found");
        found = 1;
        for(int j=i;j<addressBook->contactCount;j++)
        {
            addressBook->contacts[j] = addressBook->contacts[j+1];
        }
        addressBook->contactCount--;
        printf("contact deleted successfully\n");
        break;
    }
    }
    if(found == 0)
    {
        printf("%s not found\n",name);
    }
}


//saving all contacts to the file so they don't miss


/*
1.open the file in write mode
2.check if present/opened or not
3.print all info into file
4.close the file after use
*/
void saveContacts(AddressBook *addressBook)
{
    FILE *fptr = fopen("contacts.txt","w");

    if(fptr == NULL)
    {
        printf("File open failed\n");
        return;
    }

    for(int i=0;i<addressBook->contactCount;i++)
    {
        fprintf(fptr,"%s",addressBook->contacts[i].name);
        fprintf(fptr,",");
        fprintf(fptr,"%s",addressBook->contacts[i].phone);
        fprintf(fptr,",");
        fprintf(fptr,"%s",addressBook->contacts[i].email);
        fprintf(fptr,"\n");
    }

    fclose(fptr);

    printf("Contacts saved successfully\n");
}