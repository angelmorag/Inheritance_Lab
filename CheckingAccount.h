//
// Created by Angel Mora on 3/9/26.
//

#ifndef INHERITANCE_LAB_CHECKINGACCOUNT_H
#define INHERITANCE_LAB_CHECKINGACCOUNT_H
#include "BankAccount.h"
using namespace std;


class CheckingAccount : public BankAccount {
private:
    double transactionFee;
public:
    CheckingAccount(int accNum, const string& name, double bal, double fee);

    void withdraw(double amount) override;

};
#endif //INHERITANCE_LAB_CHECKINGACCOUNT_H