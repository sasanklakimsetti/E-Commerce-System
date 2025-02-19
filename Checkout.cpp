#include "Checkout.h"
#include<bits/stdc++.h>
using namespace std;

int Checkout::getYear(){
    time_t now=time(nullptr);
    tm* localTime=localtime(&now);
    return 1900+localTime->tm_year;
}
bool Checkout::validateCardDetails(string& cardNumber, int& expiryMonth, int& expiryYear, string& cvv, bool isAmex) {
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

void Checkout::processCardPayment(const string& cardType, int cardCategory) {
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

void Checkout::payThroughCards() {
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

void Checkout::payThroughCardVariant(int cardType) {
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

void Checkout::payThroughUPI() {
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

void Checkout::processPayment(string merchant, string identifier, int type) {
    cout << "Payment successfully done through " << merchant;
    if (type == 1) cout << " credit card\n";
    else if (type == 2) cout << " debit card\n";
    else cout << " UPI\n";

    cout << "Have a nice day!\n";
}

Checkout::Checkout(double totalPrice) {
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

void Checkout::displayPaymentMethods() {
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