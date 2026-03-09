//
// Created by Angel Mora on 3/9/26.
//

#ifndef INHERITANCE_LAB_SAVINGSACCOUNT_H
#define INHERITANCE_LAB_SAVINGSACCOUNT_H
#include "BankAccount.h"
using namespace std;

class SavingsAccount : public BankAccount{
private: double interestRate;

public:
    SavingsAccount(int accNum, const string& name, double bal, double rate);

    void caculateInterest();

};
#endif //INHERITANCE_LAB_SAVINGSACCOUNT_H