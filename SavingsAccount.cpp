//
// Created by Angel Mora on 3/9/26.
//

#include "SavingsAccount.h"
using namespace std;

SavingsAccount::SavingsAccount(int accNum, const string& name, double bal, double rate)
    : BankAccount(accNum, name, bal), interestRate(rate){}

void SavingsAccount::caculateInterest() {
    double interest = getBalance() * interestRate;
    *this += interest;
}

