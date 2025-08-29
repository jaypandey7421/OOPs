#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
#include <vector>

#include "Transaction.h"
using namespace std;

class Account{
protected:
    long long accountNumber;
    string name;
    double balance;
    vector<Transaction> history;
public:
    Account(long long a, string n, double initialBalance);
    virtual ~Account()= default;

    [[nodiscard]] long long getAccountNumber () const;
    void showHistory() const;

    virtual void deposit(double amount);
    virtual void withdraw(double amount) = 0;
    virtual void accountInfo() const = 0;
    [[nodiscard]] virtual double checkBalance() const;
};

#endif