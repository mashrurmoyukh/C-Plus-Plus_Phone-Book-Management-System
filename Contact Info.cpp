#include "Contact info.h"

ContactInfo::ContactInfo() {
    name="";
    email="";
    number=0;
}

ContactInfo::ContactInfo(string n,string e, int u) {
    name = n;
    email=e;
    number=u;
}

ContactInfo::~ContactInfo() { }

void ContactInfo::setName(string n) {
    name = n;
}

string ContactInfo::getName() {
    return name;
}


void ContactInfo::setEmail(string e) {
    email = e;
}

string ContactInfo::getEmail() {
    return email;
}


void ContactInfo::setNumber(int u) {
    number = u;
}

int ContactInfo::getNumber() {
    return number;
}

void ContactInfo::show() {
    cout << "NAME: " << name << endl;

    cout << "NUMBER: " << number << endl;

    cout<< "EMAIL ID: " <<email<<endl;
}
