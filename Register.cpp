#include "Register.h"
#include "User.h"
#include<bits/stdc++.h>
using namespace std;
//const string Register::fileName = "users.csv";
void Register::saveUserToFile(const User& user, const string &fileName){
    ofstream file(fileName, ios::app);
    if(!file){
        cout<<"Error: Unable to open the file for saving the user data."<<endl;
        return;
    }
    file<<user.fname<<","<<user.lname<<","<<user.email<<","<<user.date<<","<<user.month<<","<<user.year<<","<<user.address<<","<<user.password<<","<<user.role<<"\n";
    file.close();
}
bool Register::userExists(string email, const string &fileName){
    ifstream file(fileName);
    if(!file) return false;
    string line, storedEmail;
    while(getline(file,line)){
        stringstream ss(line);
        vector<string>userDetails;
        string field;
        while(getline(ss,field,',')){
            userDetails.push_back(field);
        }
        if(userDetails.size()>2){
            storedEmail=userDetails[2];
            if(storedEmail==email){
                file.close();
                return true;
            }
        }
    }
    file.close();
    return false;
}
int Register::getCurrentYear(){
    time_t now=time(0);
    tm*lm=localtime(&now);
    int currentYear=1900+lm->tm_year;
    return currentYear;
}
bool Register::validateAge(int year){
    return getCurrentYear()-year>=18;
}
bool Register::validatePassword(string password, string confirmPassword){
    if(password!=confirmPassword) {
        cout<<"Passwords do not match. Please try again."<<endl;
        return false;
    }
    if(password.length()<6){
        cout<<"Password must be atleast 6 characters long"<<endl;
        return false;
    }
    return true;
}
int Register::calculateAge(int year){
    return getCurrentYear()-year;
}
bool Register::checkLeapYear(int year){
    return (year%400==0)||(year%100!=0&&year%4==0);
}
bool Register::validateDate(int date, int month, int year){
    if(month<1||month>12) return false;
    int daysInMonth;
    if (month == 2) daysInMonth = checkLeapYear(year) ? 29 : 28;
    else if (month == 4 || month == 6 || month == 9 || month == 11) daysInMonth = 30;
    else daysInMonth = 31;
    return date>=1&&date<=daysInMonth;
}
bool Register::registerUser(string fname, string lname, string email, int date, int month, int year, string address, string password, string confirmPassword, string role, const string &fileName){
    if(userExists(email, fileName)){
        cout<<"User with this email already exists!"<<endl;
        return false;
    }
    if(year>getCurrentYear()){
        cout<<"Year must be less than or equal to 2025"<<endl;
        return false;
    }
    if(!validateDate(date, month, year)){
        cout<<"Invalid date! Please enter a valid date for the given month and year."<<endl;
        return false;
    }
    if(!validateAge(year)) {
        cout<<"User must be atleast 18 years old to register."<<endl;
        return false;
    }
    if(!validatePassword(password,confirmPassword)) {
        cout<<"Passwords must be same. Please try again."<<endl;
        return false;
    }
    User newUser(fname, lname, email,date,month,year,address,password, role);
    saveUserToFile(newUser, fileName);
    cout<<"User registered successfully"<<endl;
    newUser.welcome();
    newUser.display();
    return true;
}

void Register::getUserDetails(){
    string fname, lname, email, address, password, confirmPassword, role;
    int date, month, year;
    cin.ignore();
    cout << "Enter First Name: "; getline(cin,fname);
    cout << "Enter Last Name: "; getline(cin,lname);
    cout << "Enter Email: "; getline(cin,email);
    cout << "Enter Date of Birth (DD MM YYYY): "; cin >> date >> month >> year;
    cin.ignore();
    cout << "Enter Address: "; getline(cin, address);
    while(true){
        cout<<"Select Role (User/ Seller): "; cin>>role;
        transform(role.begin(), role.end(), role.begin(), ::tolower);
        if(role=="seller"||role=="user") break;
        else cout<<"Invalid role! Please enter 'User' or 'Seller'.\n";
    }
    cout << "Enter Password: "; cin >> password;
    cout << "Confirm Password: "; cin >> confirmPassword;
    registerUser(fname, lname, email, date, month, year, address, password, confirmPassword, role,"users.csv");
}