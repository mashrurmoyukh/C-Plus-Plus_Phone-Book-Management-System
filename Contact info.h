#ifndef CONTACT_INFO_H_INCLUDED
#define CONTACT_INFO_H_INCLUDED

#include <iostream>
#include <string>
using namespace std;

class ContactInfo {
public:
    ContactInfo();
    ContactInfo(string n,string e, int u);
    ~ContactInfo();

    void setName(string n);
    string getName();

    void setNumber(int n);
    int getNumber();

    void setEmail(string e);
    string getEmail();

    void show();




private:
    string name;
    string email;
    int number;
};



#endif // CONTACT_INFO_H_INCLUDED
