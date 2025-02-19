#include "Category.h"
#include<bits/stdc++.h>
using namespace std;

Category::Category(int CID, string cname, double discount, double tax){
    this->CID=CID;
    this->cname=cname;
    this->discount=discount;
    this->tax=tax;
}
void Category::display(){
    cout<<"Name: "<<cname<<endl;
    cout<<"Discount: "<<discount<<"%"<<endl;
    cout<<"Tax: "<<tax<<"%"<<endl;
}