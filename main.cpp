#include<bits/stdc++.h>
#include<ctime>
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
class Checkout{
    public:
    double totalPrice;
    string paymentMethod;
    Checkout(double totalPrice){
        this->totalPrice=totalPrice;
    }
    void displayPaymentMethods(){
        cout<<"Select any payment method: "<<endl;
        cout<<"1. Credit/ Debit Card"<<endl;
        cout<<"2. UPI/ Wallet"<<endl;
    }
    void processPayment(int option){
        if(option==1){
            cout<<"Select any one"<<endl;
            cout<<"1. Credit Card"<<endl;
            cout<<"2. Debit Card"<<endl;
            int option2; cin>>option2;
            if(option2==1){
                cout<<"Select any one variant"<<endl;
                cout<<"1. Visa"<<endl;
                cout<<"2. Mastercard"<<endl;
                cout<<"3. Rupay"<<endl;
                cout<<"4. American Express"<<endl;
                int option3; cin>>option3;
                if(option3==1){
                    cout<<"Enter your visa card details";
                    string cardNumber;
                    int expiryMonth, expiryYear;
                    string cvv;
                    cout<<"Enter Credit Card Number: ";
                    do{
                        cin>>cardNumber;
                        fflush(stdin);
                        if(cardNumber.size()>16||cardNumber.size()<16){
                            cout<<"Card number can't be greater than 16 digits"<<endl;
                            cout<<"Enter the card number again: ";
                        }
                    }while(cardNumber.size()>16||cardNumber.size()<16);
                    cout<<"Enter Expiry Month: ";
                    do{ 
                        cin>>expiryMonth;
                        if(expiryMonth<1||expiryMonth>12){
                            cout<<"Invalid month input"<<endl;
                            cout<<"Enter the expiry month again: ";
                        }
                    } while(expiryMonth<2025);
                    cout << "Enter the expiry year: ";
                    do {
                        cin >> expiryYear;
                        if (expiryYear < 2025) 
                        {
                            cout << "Expiry year can't be earlier than the current year" << endl;
                            cout << "Please enter a valid expiry year: ";
                        }
                    } while (expiryYear < 2025);
                    cout<<"Enter the CVV: ";
                    do{
                        cin>>cvv;
                        if(cvv.size()>3||cvv.size()<3){
                            cout<<"CVV can't be more than 3 digits"<<endl;
                            cout<<"Enter the CVV again: ";
                        }
                    }while(cvv.size()>3||cvv.size()<3);
                    cout<<"Payment Processing....."<<endl;
                }
                else if(option3==2){
                    cout<<"Enter your Mastercard card details"<<endl;
                    string cardNumber;
                    int expiryMonth, expiryYear;
                    string cvv;
                    cout<<"Enter Credit Card Number: ";
                    do{
                        cin>>cardNumber;
                        fflush(stdin);
                        if(cardNumber.size()>16||cardNumber.size()<16){
                            cout<<"Card number can't be greater than 16 digits"<<endl;
                            cout<<"Enter the card number again: ";
                        }
                    }while(cardNumber.size()>16||cardNumber.size()<16);
                    cout<<"Enter Expiry Month: ";
                    do{
                        cin>>expiryMonth;
                        if(expiryMonth<1||expiryMonth>12){
                            cout<<"Invalid month input"<<endl;
                            cout<<"Enter the expiry month again: ";
                        }
                    } while(expiryMonth<2025);
                    cout << "Enter the expiry year: ";
                    do {
                        cin >> expiryYear;
                        if (expiryYear < 2025) 
                        {
                            cout << "Expiry year can't be earlier than the current year" << endl;
                            cout << "Please enter a valid expiry year: ";
                        }
                    } while (expiryYear < 2025);
                    cout<<"Enter the CVV: ";
                    do {
                        cin>>cvv;
                        if(cvv.size()>3||cvv.size()<3){
                            cout<<"CVV can't be more than 3 digits"<<endl;
                            cout<<"Enter the CVV again: ";
                        }
                    }while(cvv.size()>3||cvv.size()<3);
                    cout<<"Payment Processing....."<<endl;
                }
                else if(option3==3){
                    cout<<"Enter your Rupay card details"<<endl;
                    string cardNumber;
                    int expiryMonth, expiryYear;
                    string cvv;
                    cout<<"Enter Credit Card Number: ";
                    do{
                        cin>>cardNumber;
                        fflush(stdin);
                        if(cardNumber.size()>16||cardNumber.size()<16){
                            cout<<"Card number can't be greater than 16 digits"<<endl;
                            cout<<"Enter the card number again: ";
                        }
                    }while(cardNumber.size()>16||cardNumber.size()<16);
                    cout<<"Enter Expiry Month: ";
                    do{
                        cin>>expiryMonth;
                        if(expiryMonth<1||expiryMonth>12){
                            cout<<"Invalid month input"<<endl;
                            cout<<"Enter the expiry month again: ";
                        }
                    } while(expiryMonth<2025);
                    cout << "Enter the expiry year: ";
                    do {
                        cin >> expiryYear;
                        if (expiryYear < 2025) 
                        {
                            cout << "Expiry year can't be earlier than the current year" << endl;
                            cout << "Please enter a valid expiry year: ";
                        }
                    } while (expiryYear < 2025);
                    cout<<"Enter the CVV: ";
                    do{
                        cin>>cvv;
                        if(cvv.size()>3||cvv.size()<3){
                            cout<<"CVV can't be more than 3 digits"<<endl;
                            cout<<"Enter the CVV again: ";
                        }
                    }while(cvv.size()>3||cvv.size()<3);
                    cout<<"Payment Processing....."<<endl;
                }
                else if(option3==4){
                    cout<<"Enter your American Express card details"<<endl;
                    string cardNumber;
                    int expiryMonth, expiryYear;
                    string cvv;
                    cout<<"Enter Credit Card Number: ";
                    do{
                        cin>>cardNumber;
                        fflush(stdin);
                        if(cardNumber.size()>15||cardNumber.size()<15){
                            cout<<"Card number can't be greater than 15 digits"<<endl;
                            cout<<"Enter the card number again: ";
                        }
                    }while(cardNumber.size()>15||cardNumber.size()<15);
                    cout<<"Enter Expiry Month: ";
                    do{
                        cin>>expiryMonth;
                        if(expiryMonth<1||expiryMonth>12){
                            cout<<"Invalid month input"<<endl;
                            cout<<"Enter the expiry month again: ";
                        }
                    } while(expiryMonth<2025);
                    cout << "Enter the expiry year: ";
                    do {
                        cin >> expiryYear;
                        if (expiryYear < 2025) 
                        {
                            cout << "Expiry year can't be earlier than the current year" << endl;
                            cout << "Please enter a valid expiry year: ";
                        }
                    } while (expiryYear < 2025);
                    cout<<"Enter the CVV: ";
                    do{
                        cin>>cvv;
                        if(cvv.size()>4||cvv.size()<4){
                            cout<<"CVV can't be more than 4 digits"<<endl;
                            cout<<"Enter the CVV again: ";
                        }
                    }while(cvv.size()>4||cvv.size()<4);
                    cout<<"Payment Processing....."<<endl;
                }
            }
        }
    }
};