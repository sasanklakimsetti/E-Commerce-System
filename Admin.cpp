#include "Admin.h"
#include<bits/stdc++.h>
using namespace std;
Admin::Admin(){
    showServices();
}
void Admin::showServices(){
    cout<<"Admin Services.\n";
    cout<<"1. Manage Users\n";
    cout<<"2. Manage Products\n";
    cout<<"3. View Transaction\n";
}