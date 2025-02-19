#include "Cart.h"
#include "Product.h"
#include "Checkout.h"
#include<bits/stdc++.h>
using namespace std;

Cart::Cart(){
    totalValue=0.0;
}
void Cart:: addToCart(Product product){
    products.push_back(product);
    totalValue+=product.price*product.quantity;
}
void Cart::displayCart(){
    cout<<"Items in the cart are "<<endl;
    for(const auto &product:products){
        product.display();
    }
    cout<<"Total Cart Value: "<<totalValue<<endl;
}
void Cart::removeFromCart(const string& productName, int removeQuantity){
    for(auto it=products.begin();it!=products.end();++it){
        if(it->pname==productName){
            if(it->quantity>removeQuantity){
                it->quantity-=removeQuantity;
                totalValue-=it->price*removeQuantity;
            }
            else{
                totalValue-=it->price*it->quantity;
            }
            return;
        }
    }
    cout<<"Product not found in the cart.."<<endl;
}
void Cart::calculateTax(double taxRate){
    totalValue+=totalValue*(taxRate/100);
}
void Cart:: checkout(){
    cout<<"Click for checkout..(1/0)"<<endl;
    int option; cin>>option;
    if(option) Checkout checkoutProcess(totalValue);
}