#include "Login.h"
#include "Admin.h"
#include "Seller.h"
#include "Users.h"
#include<bits/stdc++.h>
using namespace std;

Login::Login(){}

bool Login::authenticateUser() {
    string firstName, lastName, storedEmail, storedPassword;

    // Admin Authentication
    if (isAdmin(email)) {
        ifstream adminFile("admins.csv");
        if (!adminFile) {
            cout << "Error: Could not open admin records.\n";
            return false;
        }
        string line;
        while (getline(adminFile, line)) {
            stringstream ss(line);
            vector<string> adminDetails;
            string field;
            while (getline(ss, field, ',')) adminDetails.push_back(field);
            if (adminDetails.size() >= 8) {
                firstName = adminDetails[0];
                lastName = adminDetails[1];
                storedEmail = adminDetails[2];
                storedPassword = adminDetails[7];
                storedEmail.erase(remove_if(storedEmail.begin(), storedEmail.end(), ::isspace), storedEmail.end());
                storedPassword.erase(remove_if(storedPassword.begin(), storedPassword.end(), ::isspace), storedPassword.end());

                if (storedEmail == email && storedPassword == password) {
                    cout << "\nAdmin login successful..\nWelcome, " << firstName << " " << lastName << endl;
                    adminFile.close();
                    Admin adminRole;
                    return true;
                }
            }
        }
        adminFile.close();
    }

    // User Authentication
    ifstream userFile("users.csv");
    if (!userFile) {
        cout << "Could not open user records." << endl;
        return false;
    }
    string line, storedRole;
    while (getline(userFile, line)) {
        stringstream ss(line);
        vector<string> userDetails;
        string field;
        while (getline(ss, field, ',')) userDetails.push_back(field);
        if (userDetails.size() > 8) {
            firstName = userDetails[0];
            lastName = userDetails[1];
            storedEmail = userDetails[2];
            storedPassword = userDetails[7];
            storedRole = userDetails[8];
            storedEmail.erase(remove_if(storedEmail.begin(), storedEmail.end(), ::isspace), storedEmail.end());
            storedPassword.erase(remove_if(storedPassword.begin(), storedPassword.end(), ::isspace), storedPassword.end());

            if (storedEmail == email && storedPassword == password) {
                cout << "\nLogin successful! Welcome, " << firstName << " " << lastName << endl;
                userFile.close();
                if (storedRole == "seller") Seller sellerRole;
                else if (storedRole == "user") Users userRole;
                return true;
            }
        }
    }
    userFile.close();
    cout << "Invalid email or password!" << endl;
    return false;
}

void Login::getUserDetails() {
    string email, password;
    cin.ignore();
    cout << "Enter email: "; getline(cin, this->email);
    cout << "Enter Password: "; cin >> this->password;
    authenticateUser();
}

bool Login::isAdmin(string email) {
    ifstream file("admins.csv");
    if (!file) {
        cout << "Error: Could not open admin records.\n";
        return false;
    }
    string line, storedEmail;
    while (getline(file, line)) {
        stringstream ss(line);
        vector<string> adminDetails;
        string field;
        while (getline(ss, field, ',')) adminDetails.push_back(field);
        if (adminDetails.size() >= 3) {
            storedEmail = adminDetails[2];
            storedEmail.erase(remove_if(storedEmail.begin(), storedEmail.end(), ::isspace), storedEmail.end());
            email.erase(remove_if(email.begin(), email.end(), ::isspace), email.end());
            if (storedEmail == email) {
                file.close();
                return true;
            }
        }
    }
    file.close();
    return false;
}