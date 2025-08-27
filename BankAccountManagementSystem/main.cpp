#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include "Account.h"
#include "SavingsAccount.h"
#include "CurrentAccount.h"
using namespace std;

Account* findAccount(const vector<Account*>& accounts, const long long accountNumber) {
    for (const auto account : accounts) {
        if (account->getAccountNumber() == accountNumber) {
            return account;
        }
    }
    return nullptr;
}

int main(){
    vector<Account*> accounts;

    int choice = 0;
    cout<<"1 Create a Saving Account."<<endl;
    cout<<"2 Create a Current Account."<<endl;
    cout<<"3 Account Info."<<endl;
    cout<<"4 Deposit."<<endl;
    cout<<"5 Withdraw."<<endl;
    cout<<"6 Add Interest to the Account Balance. (Only for Savings Accounts)"<<endl;
    cout<<"7 Exit."<<endl;
    do {
        cout<<"Enter your choice: ";
        cin>>choice;

        if (cin.fail()) {
            cout << "Invalid input. Please enter a number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch(choice) {
            case 1: {
                long long accountNumber;
                string name;
                double initialBalance, rate;

                cout<<"Enter your 9 digit account number: ";
                cin>>accountNumber;
                cout<<"Enter your name: ";
                cin.ignore();
                getline(cin, name);
                cout<<"Enter your initial balance: ";
                cin>>initialBalance;
                cout<<"Enter the Interest Rate: ";
                cin>>rate;
                accounts.push_back(new SavingsAccount(accountNumber, name, initialBalance, rate));
                cout<<"Account created successfully!"<<endl;
                break;
            }
            case 2: {
                long long accountNumber;
                string name;
                double initialBalance, limit;

                cout<<"Enter your 9 digit account number: ";
                cin>>accountNumber;
                cout<<"Enter your name: ";
                cin.ignore();
                getline(cin, name);
                cout<<"Enter your initial balance: ";
                cin>>initialBalance;
                cout<<"Enter the Overdraft Limit: ";
                cin>>limit;
                accounts.push_back(new CurrentAccount(accountNumber, name, initialBalance, limit));
                cout<<"Account created successfully!"<<endl;
                break;
            }
            case 3: {
                long long accountNumber;
                const Account* accountDetails = nullptr;
                cout<<"Enter your 9 digit account number: ";
                cin>>accountNumber;

                accountDetails = findAccount(accounts, accountNumber);
                if(accountDetails != nullptr) {
                    accountDetails->accountInfo();
                }else {
                    cout<<"Account not found."<<endl;
                }
                break;
            }
            case 4: {
                long long accountNumber;
                Account* accountDetails = nullptr;
                cout<<"Enter your 9 digit account number: ";
                cin>>accountNumber;

                accountDetails = findAccount(accounts, accountNumber);
                if(accountDetails != nullptr) {
                    double amount;
                    cout<<"Enter the amount to deposit: ";
                    cin>>amount;
                    accountDetails->deposit(amount);
                }else {
                    cout<<"Account not found."<<endl;
                }
                break;
            }
            case 5: {
                long long accountNumber;
                Account* accountDetails = nullptr;
                cout<<"Enter your 9 digit account number: ";
                cin>>accountNumber;

                accountDetails = findAccount(accounts, accountNumber);
                if(accountDetails != nullptr) {
                    double amount;
                    cout<<"Enter the amount to withdraw: ";
                    cin>>amount;
                    accountDetails->withdraw(amount);
                }else {
                    cout<<"Account not found."<<endl;
                }
                break;
            }
            case 6: {
                long long accountNumber;
                Account* accountDetails = nullptr;
                SavingsAccount* svgAcc = nullptr;
                cout<<"Enter your 9 digit account number: ";
                cin>>accountNumber;

                accountDetails = findAccount(accounts, accountNumber);
                svgAcc = dynamic_cast<SavingsAccount*>(accountDetails);
                if(svgAcc != nullptr) {
                    svgAcc->addInterest();
                }
                else {
                    cout<<"Not a Saving Account!"<<endl;
                }
                break;
            }
            case 7: {
                cout<<"Exiting system, good by!"<<endl;
                break;
            }
            default: {
                cout<<"Invalid choice. Try agin!"<<endl;
            }
        }


    }while (choice != 7);


    return 0;
}