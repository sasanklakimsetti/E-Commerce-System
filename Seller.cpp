#include "Seller.h"
#include<bits/stdc++.h>
using namespace std;
Seller::Seller(){
    showServices();
}
void Seller::showServices(){
    cout << "\nSeller Services\n";
    cout << "1. Add\n";
    cout<<"2. Remove Products\n";
    cout << "3. View Inventory\n";
}