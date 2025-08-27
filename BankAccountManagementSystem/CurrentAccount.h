#ifndef CURRENTACCOUNT_H
#define CURRENTACCOUNT_H

#include "Account.h"

class CurrentAccount final: public Account {
private:
    double overDraftLimit;

public:
    CurrentAccount(long long accNo, string name, double initialBalance, double limit);
    void withdraw(double amount) override;
    void accountInfo() const override;
};

#endif