#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
using namespace std;

class Account{
private:
    long long accountNumber;
    string name;
    double balance;
public:
    Account(long long a, string n, double b);

    void deposit(double b);
    void withdraw(double amount);
    [[nodiscard]] long long getAccountNumber () const;
    void accountInfo() const;
    [[nodiscard]] double checkBalance() const;
};

#endif