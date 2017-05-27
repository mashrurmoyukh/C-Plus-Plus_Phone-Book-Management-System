#include "Phone Book.h"
#include<string>

PhoneBook::PhoneBook() {
    TOA = 0;
}

PhoneBook::~PhoneBook() { }

void PhoneBook::Handle() {
    char c = 0;
    while(c != 'x') {
            cout<<endl;
            cout<<"...............................PHONE BOOK.........................."<<endl;
            cout<<"==================================================================="<<endl;
            cout<<"==================================================================="<<endl;
        cout<<endl<<endl;
        cout << "Press 1:                   To Add New Contact" << endl<<endl;
        cout << "Press 2:                   To Edit Name/Number" << endl<<endl;
        cout << "Press 3:                   To Delete Contact" <<endl<<endl;
        cout << "Press 4:         To Search Persons Number Based On Persons Name  " << endl<<endl;
        cout << "Press 5:         To Search Persons Name Based On Persons Number  " << endl<<endl;
        cout << "Press 6:              To Make Dial\Call From The Contact List     " << endl<<endl;
        cout << "Press 7:           To Send Text Message From The Contact List    " << endl<<endl;
        cout << "Press 8:             To Send Mail From The Contact List            " <<endl<<endl;
        cout << "Press 9:                  To Show Contact List" << endl<<endl;

        int choice = 0;
        cin >> choice;

        switch(choice) {
        case 1:
            addContact();
            break;

        case 2:
            editContact();
            break;

        case 3:
            delContact();
            break;

        case 4:
            searchNumber();
            break;

        case 5:
            searchName();
            break;
        case 6:
            call();
            break;
        case 7:
            sendTextMessage();
            break;
        case 8:
            sendEmail();
            break;
        case 9:
            show();
            break;



        default:
            cout << "Wrong Key Word, Press 1 To 9 Please" << endl;
            break;
        }
        cout<<endl;
        cout << "Press X To Exit From The Phone Book OR Press Any Key To Return Main Menu  ";
        cin >> c;
    }
}

void PhoneBook::addContact() {
    string n = "";
    string e="";
    int u=0;

    cout << "Enter Name: ";
    cin >> n;

    cout << "Enter Number: ";
    cin >> u;

    cout<< "Enter Email ID: ";
    cin>>e;



    ContactInfo info(n,e,u);

    CINFO[TOA] = info;
    TOA++;
}

void PhoneBook::editContact() {
    int choice = 0;
    string n = "";

    cout << "Press 1: To change Persons Name" << endl;
    cout<<endl;
    cout << "Press 2: To Change Persons Number" << endl;

    cin >> choice;

    switch(choice) {
    case 1: {
        cout << "Enter Name: ";
        cin >> n;

        if(Check(n)) {
            for(int i = 0; i < TOA; i++) {
                if(CINFO[i].getName() == n) {
                    cout << "Enter New name: ";
                    string na;
                    cin >> na;

                    CINFO[i].setName(na);
                }
            }
        }
    }
    break;

    case 2: {
        cout << "Enter Name: ";
        cin >> n;

        if(Check(n)) {
            for(int i = 0; i < TOA; i++) {
                if(CINFO[i].getName() ==n) {
                    cout << "Enter New Number: ";
                    int nu;
                    cin >>nu;

                    CINFO[i].setNumber(nu);
                }
            }
        }
    }
    break;


    default:
        cout << "Wrong Key Word" << endl;
        break;
    }
}

void PhoneBook::delContact() {
    int pos = 0;
    string n = "";

    cout << "Enter Name To Delete From The From Book: ";
    cin >> n;

    for(int i = 0; i < TOA; i++) {
        if(CINFO[i].getName() == n) {
            pos = i;
        }
    }

    for(int i = pos; i < TOA; i++) {
        CINFO[i] = CINFO[i + 1];
    }
    TOA--;
}

void PhoneBook::show() {
    string n;
    cout << "Enter Name: ";
    cin >> n;

    if(Check(n)) {
        for(int i = 0; i < TOA; i++) {
            if(CINFO[i].getName() == n) {
                CINFO[i].show();
            }
        }
    }
    else {
        cout << "No Matching Contacts Found!" << endl;
    }
}
void PhoneBook::searchNumber()
{
    string n;
    cout<<"Enter Name To Search Number "<<endl;
    cin>>n;
    if(Check(n)) {
        for(int i=0;i<TOA;i++) {
            if(CINFO[i].getName()==n) {
                cout<<CINFO[i].getNumber()<<endl;
            }
        }
    }
}

void PhoneBook::searchName()
{
    int nu;
    cout<<"Enter Number To Search Name "<<endl;
    cin>>nu;
    if(Check_n(nu)) {
        for(int i=0;i<TOA;i++) {
            if(CINFO[i].getNumber()==nu) {
                cout<<CINFO[i].getName()<<endl;
            }
        }
    }
}

void PhoneBook::sendTextMessage()
{
    string n;
    cout<<"Enter Name To Send Text Messages "<<endl;
    cin>>n;
    string t;
    if(Check(n)) {
        for(int i=0;i<TOA;i++) {
            if(CINFO[i].getName()==n) {
                cout<<"........................  MESSAGE BOX   ...................."<<endl<<endl;
                cout<<"Write New Message "<<endl;
                cout<<endl;
                cout<<"ME : \n" <<endl;
                cin>>t;

                cout<<"             Your Message Sent ....       " <<endl;
            }
        }
    }
}


void PhoneBook::call()
{
    string n;
    cout<<"Search Name To Call "<<endl;
    cin>>n;
    string y;

    if(Check(n)) {
        for(int i=0;i<TOA;i++) {
            if(CINFO[i].getName()==n) {
                cout<<"NUMBER : \n"<<CINFO[i].getNumber()<<endl;
                cout<<"Press Y/y To Dial Or Press N/n to Return Main Menu"<<endl;
                cin>>y;
                cout<<endl;
                cout<<"Dialing......." <<endl;

            }
        }
    }
}

void PhoneBook::sendEmail()
{
    string n;
    cout<<"Enter Name To Send Email "<<endl;
    cin>>n;
    string t;
    if(Check(n)) {
        for(int i=0;i<TOA;i++) {
            if(CINFO[i].getName()==n) {
                cout<<"EMAIL: \n"<<CINFO[i].getEmail()<<endl;

                cout<<"........................  EMAIL BOX   ...................."<<endl<<endl;
                cout<<"Compose New Message "<<endl;
                cout<<endl;
                cout<<"..........................EMAIL BODY...................... \n" <<endl;
                cin>>t;

                cout<<"             Your Mail Sent ....       " <<endl;
            }
        }
    }
}

bool PhoneBook::Check(string n) {
    for(int i = 0; i < TOA; i++) {
        if(CINFO[i].getName() == n) {
            return true;
        }
    }
    return false;
}
bool PhoneBook::Check_n(int nu) {
    for(int i = 0; i < TOA; i++) {
        if(CINFO[i].getNumber() == nu) {
            return true;
        }
    }
    return false;
}


