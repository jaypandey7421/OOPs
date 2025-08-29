#include "Account.h"
#include <iostream>
#include <utility>
using namespace std;

Account::Account(const long long a, string n, const double initialBalance) {
    accountNumber = a;
    name = std::move(n);
    balance = initialBalance;

    history.emplace_back("Account Opened", initialBalance, balance);
}

void Account::deposit(const double amount) {
    if(amount < 1){
        cout<<"Add valid amount!"<<endl;
        return;
    }
    balance += amount;
    history.emplace_back("Deposit", amount, balance);
    cout<<"Total balance: "<<balance<<endl;
}

[[nodiscard]] long long Account::getAccountNumber () const {
    return accountNumber;
}

[[nodiscard]] double Account::checkBalance() const {
    return balance;
}

void Account::showHistory() const {
    cout<<"==========================================================================="<<endl;
    cout<<"Transaction history:"<<endl;
    cout<<"Name: "<<name<<endl;
    cout<<"AccountNumber: "<<accountNumber<<endl;
    cout<<"==========================================================================="<<endl;
    cout<<"       TYPE        | "<<"   AMOUNT    | "<<"   BALANCE   | "<<"    DATE    "<<endl;
    cout<<"---------------------------------------------------------------------------"<<endl;
    for (const Transaction& h : history) {
        h.display();
    }
    cout<<"============================================================================"<<endl;
}
