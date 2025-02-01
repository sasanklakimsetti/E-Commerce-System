#include <iostream>
#include <string>
#include <regex>
#include <limits>
#include <ctime>
#include <chrono>
using namespace std;
class User{
    public:
    string fname, lname, email, dob, address, password;
    int date, month, year;
    User(string fname, string lname, string email, int date, int month, int year, string address, string password){
        this->fname=fname;
        this->lname=lname;
        this->email=email;
        this->date=date;
        this->month=month;
        this->year=year;
        this->address=address;
        this->password=password;

        dob+=to_string(date)+'-'+to_string(month)+'-'+to_string(year);

    }
    void welcome(){
        cout<<"Hello, "<<fname<<"!"<<endl;
    }
    void display(){
        cout<<"Email: "<<email<<endl;
        cout<<"Date Of Birth: "<<dob<<endl;
        cout<<"Address: "<<address<<endl;
    }
};
class Register{
    public:
    bool validateAge(int year){
        int currentYear=2025;
        int birthYear=year;
        int age=currentYear-birthYear;
        return age>=18;
    }
    bool validatePassword(string password, string confirmPassword){
        return password==confirmPassword;
    }
    int calculateAge(int year){
        return 2025-year;
    }
    bool checkLeapYear(int year){
        if (year % 400 == 0) return true;
        // not a leap year if divisible by 100
        // but not divisible by 400
        else if (year % 100 == 0) return false;
        // leap year if not divisible by 100
        // but divisible by 4
        else if (year % 4 == 0) return true;
        // all other years are not leap years
        return false;
    }
    bool registerUser(string fname, string lname, string email, int date, int month, int year, string address, string password, string confirmPassword){
        if(year>2025) cout<<"Year must be less than or equal to 2025"<<endl;
        if(month==2){
            if(!checkLeapYear(year)&&date>=29) {
                cout<<"In February, day can't be more than 28"<<endl; return false;
            }
            else if(checkLeapYear(year)&&date>29){
                cout<<"In February, day can't be greater than 29"<<endl;
                return false;
            }
        }
        if(!(month==1||month==3||month==5||month==7||month==8||month==10||month==12)){
            if(date>31){
                cout<<"In this month, day can't be greater than 30";
                return false;
            }
        }
        if(!validateAge(year)) {
            cout<<"User must be atleast 18 years old"<<endl;
            return false;
        }
        if(!validatePassword(password,confirmPassword)) {
            cout<<"Passwords must be same"<<endl;
            return false;
        }
        User newUser(fname, lname, email,date,month,year,address,password);
        newUser.welcome();
        newUser.display();
        // add this to database
        return true;
    }
};
class Login{
    public:
    string email, password;
    Login(string email, string password){
        this->email=email;
        this->password=password;
    }
    bool authenticateUser(){
        // search in the database
        return true;
    }
};
class Product{
    public:
    int PID;
    string pname, category, seller;
    double price;
    int quantity;
    Product(int PID, string pname, string category, string seller, double price, int quantity){
        this->PID=PID;
        this->pname=pname;
        this->category=category;
        this->seller=seller;
        this->price=price;
        this->quantity=quantity;
    }
    void display(){
        cout<<"Name: "<<pname<<endl;
        cout<<"Category: "<<category<<endl;
        cout<<"Seller: "<<seller<<endl;
        cout<<"Price: "<<price<<endl;
        cout<<"Quantity: "<<quantity<<endl;
    }
    // register this product in the database
    void registerProduct(){
    }
};
class Category{
    public:
    int CID;
    string cname;
    double discount, tax;
    Category(int CID, string cname, double discount, double tax){
        this->CID=CID;
        this->cname=cname;
        this->discount=discount;
        this->tax=tax;
    }
    void display(){
        cout<<"Name: "<<cname<<endl;
        cout<<"Discount: "<<discount<<"%"<<endl;
        cout<<"Tax: "<<tax<<"%"<<endl;
    }
};
class Cart{
    public:
    vector<Product>products;
    double totalValue;
    Cart(){
        totalValue=0.0;
    }
    void addToCart(Product product){
        products.push_back(product);
        totalValue+=product.price*product.quantity;
    }
    void displayCart(){
        cout<<"Items in cart: "<<endl;
        for(const auto &product:products){
            product.display();
        }
        cout<<"Total Cart Value: "<<totalValue<<endl;
    }
    void calculateTax(double taxRate){
        totalValue+=totalValue*(taxRate/100);
    }
};
class Checkout {
private:
    int getYear(){
        time_t now=time(nullptr);
        tm* localTime=localtime(&now);
        return 1900+localTime->tm_year;
    }
    bool validateCardDetails(string& cardNumber, int& expiryMonth, int& expiryYear, string& cvv, bool isAmex) {
        int cardLength = isAmex ? 15 : 16;
        int cvvLength = isAmex ? 4 : 3;

        if (cardNumber.length() != cardLength) {
            cout << "Invalid Card Number! It should be " << cardLength << " digits.\n";
            return false;
        }
        if (expiryMonth < 1 || expiryMonth > 12) {
            cout << "Invalid Expiry Month! It should be between 1 and 12.\n";
            return false;
        }
        int currentYear = getYear();

        if (expiryYear < currentYear) {
            cout << "Card Expired! Expiry Year should be " << currentYear << " or later.\n";
            return false;
        }
        if (cvv.length() != cvvLength) {
            cout << "Invalid CVV! It should be " << cvvLength << " digits.\n";
            return false;
        }

        return true;
    }

    void processCardPayment(const string& cardType, int cardCategory) {
        string cardNumber, cvv;
        int expiryMonth, expiryYear;
        bool isAmex = (cardType == "American Express");

        cout << "Enter Card Number: ";
        cin >> cardNumber;
        cout << "Enter Expiry Month (MM): ";
        cin >> expiryMonth;
        cout << "Enter Expiry Year (YYYY): ";
        cin >> expiryYear;
        cout << "Enter CVV: ";
        cin >> cvv; 

        if (validateCardDetails(cardNumber, expiryMonth, expiryYear, cvv, isAmex)) {
            processPayment(cardType, "****", cardCategory);
        } else {
            cout << "Payment Denied!\n";
        }
    }

    void payThroughCards() {
        while (true) {
            cout << "0. Quit\n1. Credit Card\n2. Debit Card\nSelect an option: ";
            int option;
            if (!(cin >> option)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input! Please enter a number.\n";
                continue;
            }
            if (option == 0) return;
            else if (option == 1 || option == 2) payThroughCardVariant(option);
            else cout << "Invalid option. Try again!\n";
        }
    }

    void payThroughCardVariant(int cardType) {
        string cardVariants[] = {"Visa", "MasterCard", "RuPay", "American Express"};

        while (true) {
            cout << "0. Quit\n1. Visa\n2. MasterCard\n3. RuPay\n4. American Express\nSelect a variant: ";
            int option;
            if (!(cin >> option) || option < 0 || option > 4) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input! Try again.\n";
                continue;
            }
            if (option == 0) return;
            processCardPayment(cardVariants[option - 1], cardType);
            return;
        }
    }

    void payThroughUPI() {
        while (true) {
            cout << "0. Quit\n1. Google Pay\n2. PhonePe\n3. Paytm\n4. Amazon Pay\nSelect an option: ";
            int option;
            if (!(cin >> option) || option < 0 || option > 4) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input! Try again.\n";
                continue;
            }
            if (option == 0) return;

            string UPIID;
            cout << "Enter UPI ID: ";
            cin >> UPIID;

            regex upiRegex("^[a-zA-Z0-9][a-zA-Z0-9._-]*@[a-zA-Z0-9.-]+$");

            if (regex_match(UPIID, upiRegex)) {
                string paymentMethod = (option == 1) ? "Google Pay" : (option == 2) ? "PhonePe" : (option == 3) ? "Paytm" : "Amazon Pay";
                processPayment(paymentMethod, UPIID, 3);
                return;
            } else {
                cout << "Invalid UPI ID! Try again.\n";
            }
        }
    }

    void processPayment(string merchant, string identifier, int type) {
        cout << "Payment successfully done through " << merchant;
        if (type == 1) cout << " credit card\n";
        else if (type == 2) cout << " debit card\n";
        else cout << " UPI\n";

        cout << "Have a nice day!\n";
    }

public:
    double totalPrice;

    Checkout(double totalPrice) {
        this->totalPrice = totalPrice;
        cout << "Total price: " << totalPrice << endl;
        cout << "Do you want to proceed? (0/1): ";
        int option;
        if (!(cin >> option) || option < 0 || option > 1) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Exiting checkout.\n";
            return;
        }
        if (option == 1) displayPaymentMethods();
    }

    void displayPaymentMethods() {
        while (true) {
            cout << "0. Quit\n1. Credit/Debit Card\n2. UPI\nSelect a payment method: ";
            int option;
            if (!(cin >> option)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input! Try again.\n";
                continue;
            }
            if (option == 0) {
                cout << "Exiting payment process.\n";
                return;
            }
            if (option == 1) payThroughCards();
            else if (option == 2) payThroughUPI();
            else cout << "Invalid option. Try again.\n";
        }
    }
};
int main(){
    
}