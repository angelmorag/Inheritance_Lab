#include <iostream>
#include <vector>
#include "CheckingAccount.h"
#include "SavingsAccount.h"
using namespace std;




int main() {
    vector <BankAccount*> accounts;

    accounts.push_back(new CheckingAccount(101, "John - Checking", 1000.0, 10.0 ));
    accounts.push_back(new SavingsAccount(102, "Jane - Savings", 5000.0, 0.02));

    cout << "----- Initial Polymorphism Demo -----\n";
    cout << "Withdrawing $20 from all accounts...\n";
    for (BankAccount* acc : accounts) {
        acc->withdraw(20.0);
        BankAccount::printAccount(*acc);
    }
    cout << "-------------------------\n";

    int choice = 0;
    while (choice != 4) {
        cout << "\n----- Account Menu ----- \n";
        for (size_t i = 0; i < accounts.size(); ++i) {
            cout << "[" << i << "] ";
            BankAccount::printAccount(*accounts[i]);
        }

        int accIndex;
        cout << "Enter the index of the account you want to use (0-" << accounts.size() - 1 << "):";
        if (!(cin >> accIndex) || accIndex < 0 || accIndex >= accounts.size()) {
            cout << "Invalid account selection! Please try again.\n";
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        BankAccount* selectedAcc = accounts[accIndex];

        cout << "\n1. Deposit\n2. Withdraw\n3. View Details\n4. Exit\n Choice: ";
        if (!(cin >> choice)) {
            cout << "Invalid input. Please enter a number (1-4).\n";
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        switch (choice) {
            case 1: {
                double amount;
                cout << "Enter deposit amount: ";
                cin >> amount;
                *selectedAcc += amount;
                break;
            }
            case 2: {
                double amount;
                cout << "Enter withdrawal amount: ";
                cin >> amount;
                *selectedAcc -= amount;
                break;
            }
            case 3: {
                BankAccount::printAccount(*selectedAcc);
                break;
            }
            case 4: {
                cout << "Exiting now, goodbye!\n";
                break;
            }
            default: {
                cout << "Invalid input, please choose a number (1-4).\n";
                break;
            }
        }
    }
    cout << "\n Cleaning up Memory...\n";
    for (BankAccount* acc : accounts) {
        delete acc;
    }
    accounts.clear();

    return 0;
}