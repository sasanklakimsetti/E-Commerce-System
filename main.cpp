#include <iostream>
#include "Register.h"
#include "Login.h"

int main() {
    Register reg;
    Login  log;
    int choice;

    while (true) {
        cout << "\n1. Register New User\n2. Login\n3. Exit\nEnter your choice: ";
        cin >> choice;

        if (choice == 1) reg.getUserDetails();
        else if (choice == 2) log.getUserDetails();
        else if (choice == 3) {
            cout << "Exiting program..." << endl;
            break;
        } 
        else cout << "Invalid choice! Try again.\n";
    }
    return 0;
}