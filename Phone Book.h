#ifndef PHONE_BOOK_H_INCLUDED
#define PHONE_BOOK_H_INCLUDED
#include "Contact Info.h"
class PhoneBook {
public:
    PhoneBook();
    ~PhoneBook();

    void Handle();
    void addContact();

    void delContact();
    void editContact();
    void searchNumber();
    void searchName();
    void sendTextMessage();
    void call();
    void sendEmail();
    void show();
    bool Check(string n);
    bool Check_n(int nu);

private:
    ContactInfo CINFO[10000];
    int TOA;
};



#endif // PHONE_BOOK_H_INCLUDED
