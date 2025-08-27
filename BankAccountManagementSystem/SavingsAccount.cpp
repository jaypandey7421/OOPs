#include "SavingsAccount.h"
#include <iostream>
#include <string>
#include <utility>
using namespace std;

SavingsAccount::SavingsAccount(const long long accNo, string name, const double initialBalance, const double rate):
Account(accNo, std::move(name), initialBalance){
    interestRate = rate;
}

void SavingsAccount::withdraw(const double amount) {
    if (amount > 0 && amount <= balance) {
        balance -= amount;
        cout<<"Remaining Balance: "<<balance<<endl;
    }
    else {
        cout<<"Not sufficient balance!"<<endl;
    }
}

void SavingsAccount::addInterest() {
    const double interest = balance * interestRate/100;
    balance += interest;
    cout<<"Total Balance: "<<balance<<endl;
}

void SavingsAccount::accountInfo() const {
    cout<<endl<<" Account Info"<<endl;
    cout<<" _____________________________________________"<<endl;
    cout<<"| Account Number: "<<accountNumber<<endl;
    cout<<"| Name: "<<name<<endl;
    cout<<"| Balance: "<<balance<<endl;
    cout<<"| Interest Rate: "<<interestRate<<endl;
    cout<<"|_____________________________________________"<<endl;
}