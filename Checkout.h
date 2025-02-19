#ifndef CHECKOUT_H
#define CHECKOUT_H
#include<bits/stdc++.h>
using namespace std;
class Checkout {
    private:
        int getYear();
        bool validateCardDetails(string& cardNumber, int& expiryMonth, int& expiryYear, string& cvv, bool isAmex);
        void processCardPayment(const string& cardType, int cardCategory);
        void payThroughCards();
        void payThroughCardVariant(int cardType);
        void payThroughUPI();
        void processPayment(string merchant, string identifier, int type);
    public:
        double totalPrice;
        Checkout(double totalPrice);
        void displayPaymentMethods();
};
#endif