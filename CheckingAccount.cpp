//
// Created by Angel Mora on 3/9/26.
//

#include "CheckingAccount.h"

CheckingAccount::CheckingAccount(int accNum, const string& name, double bal, double fee)
    : BankAccount(accNum, name, bal), transactionFee(fee){}

void CheckingAccount::withdraw(double amount) {
    BankAccount::withdraw(amount + transactionFee);
}