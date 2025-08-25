#include "Account.h"
#include <iostream>
#include <utility>
using namespace std;

Account::Account(const long long a, string n, const double b) {
    accountNumber = a;
    name = std::move(n);
    balance = b;
}

void Account::deposit(const double b) {
    if(b < 1){
        cout<<"Add valid amount!"<<endl;
        return;
    }
    balance += b;
    cout<<"Total balance: "<<balance<<endl;
}

void Account::withdraw(const double amount) {
    if(amount > balance){
        cout<<"Not sufficient balance!"<<endl;
        return;
    }else if(amount < 1){
        cout<<"Invalid amount to withdraw!"<<endl;
        return;
    }

    balance -= amount;
    cout<<"Remaining balance: "<<balance<<endl;
}

[[nodiscard]] long long Account::getAccountNumber () const {
    return accountNumber;
}

void Account::accountInfo() const {
    cout<<endl<<" Account Info"<<endl;
    cout<<" _____________________________________________"<<endl;
    cout<<"| Account Number: "<<accountNumber<<endl;
    cout<<"| Name: "<<name<<endl;
    cout<<"| Balance: "<<balance<<endl;
    cout<<"|_____________________________________________"<<endl;
}

[[nodiscard]] double Account::checkBalance() const {
    return balance;
}
