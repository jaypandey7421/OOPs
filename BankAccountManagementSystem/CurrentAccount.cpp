#include "CurrentAccount.h"
#include <iostream>
#include <string>
#include <utility>
using namespace std;

CurrentAccount::CurrentAccount(const long long accNo, string name, const double initialBalance, const double limit):
Account(accNo, std::move(name), initialBalance){
    overDraftLimit = limit;
}

void CurrentAccount::withdraw(const double amount) {
    if (amount > 0 && amount <= overDraftLimit+balance) {
        balance -= amount;
        cout<<"Remaining Balance: "<<balance<<endl;
    }
    else {
        cout<<"Insufficient Balance: "<<endl;
    }
}

void CurrentAccount::accountInfo() const {
    cout<<endl<<" Account Info"<<endl;
    cout<<" _____________________________________________"<<endl;
    cout<<"| Account Number: "<<accountNumber<<endl;
    cout<<"| Name: "<<name<<endl;
    cout<<"| Balance: "<<balance<<endl;
    cout<<"| Overdraft Limit: "<<overDraftLimit<<endl;
    cout<<"|_____________________________________________"<<endl;
}