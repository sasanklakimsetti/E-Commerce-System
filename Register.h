#ifndef REGISTER_H
#define REGISTER_H
#include "User.h"
#include<bits/stdc++.h>
using namespace std;
class Register{
    private:
        const string userFile="users.csv";
        void saveUserToFile(const User &user);
        bool userExists(string email);
        int getCurrentYear();
    public:
        bool validateAge(int year);
        bool validatePassword(string password, string confirmPassword);
        int calculateAge(int year);
        bool checkLeapYear(int year);
        bool validateDate(int date, int month, int year);
        bool registerUser(string fname, string lname, string email, int date, int month, int year, string address, string password, string confirmPassword, string role);
        void getUserDetails();
};
#endif //REGISTER_H