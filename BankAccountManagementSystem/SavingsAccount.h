#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

#include "Account.h"

class SavingsAccount final : public Account {
private:
    double interestRate;

public:
    SavingsAccount(long long accNo, string name, double initialBalance, double rate);
    void withdraw(double amount) override;
    void accountInfo() const override;
    void addInterest();
};

#endif
