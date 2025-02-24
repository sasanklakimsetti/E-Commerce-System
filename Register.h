#ifndef REGISTER_H
#define REGISTER_H
#include "User.h"
#include<bits/stdc++.h>
using namespace std;
class Register{
    private:
        static const string fileName;
        static void saveUserToFile(const User &user, const string& fileName);
        static bool userExists(string email, const string &fileName);
        static int getCurrentYear();
    public:
        static bool validateAge(int year);
        static bool validatePassword(string password, string confirmPassword);
        static int calculateAge(int year);
        static bool checkLeapYear(int year);
        static bool validateDate(int date, int month, int year);
        static bool registerUser(string fname, string lname, string email, int date, int month, int year, string address, string password, string confirmPassword, string role, const string &fileName);
        static void getUserDetails();
};
#endif //REGISTER_H