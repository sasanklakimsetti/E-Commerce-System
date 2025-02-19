#ifndef USER_H
#define USER_H

#include <iostream>
using namespace std;

class User {
public:
    string fname, lname, email, dob, address, password;
    int date, month, year;

    User(string fname, string lname, string email, int date, int month, int year, string address, string password);

    void welcome();
    void display();
};

#endif // USER_H
