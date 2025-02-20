#include "Users.h"
#include<bits/stdc++.h>
using namespace std;
Users::Users(){
    showServices();
}
void Users::showServices(){
    cout << "\nUser Services\n";
    cout << "1. Browse Products\n";
    cout << "2. Buy Products\n";
    cout << "3. Cancel Orders\n";
    cout<<"4. View Cart\n";
}