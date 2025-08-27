#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
using namespace std;

class Account{
protected:
    long long accountNumber;
    string name;
    double balance;
public:
    Account(long long a, string n, double b);
    virtual ~Account()= default;

    [[nodiscard]] long long getAccountNumber () const;

    virtual void deposit(double b);
    virtual void withdraw(double amount) = 0;
    virtual void accountInfo() const = 0;
    [[nodiscard]] virtual double checkBalance() const;
};

#endif