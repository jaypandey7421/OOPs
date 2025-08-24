#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <limits>

using namespace std;

class Account{
private:
    long long accountNumber;
    string name;
    double balance;
public:
    Account(const long long a, string n, const double b): accountNumber(a), name(std::move(n)), balance(b){}

    void deposit(const double b){
        if(b < 1){
            cout<<"Add valid amount!"<<endl;
            return;
        }
        balance += b;
        cout<<"Total balance: "<<balance<<endl;
    }

    void withdraw(const double amount){
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

    [[nodiscard]] long long getAccountNumber() const{
        return accountNumber;
    }

    void accountInfo() const{
        cout<<endl<<" Account Info"<<endl;
        cout<<" _____________________________________________"<<endl;
        cout<<"| Account Number: "<<accountNumber<<endl;
        cout<<"| Name: "<<name<<endl;
        cout<<"| Balance: "<<balance<<endl;
        cout<<"|_____________________________________________"<<endl;
    }

    [[nodiscard]] double checkBalance() const{
        return balance;
    }

};

Account* findAccount(vector<Account>& accounts, long long accountNumber) {
    for (auto& account : accounts) {
        if (account.getAccountNumber() == accountNumber) {
            return &account;
        }
    }
    return nullptr;
}

int main(){
    vector<Account> accounts;

    int choice = 0;
    cout<<"1 Create an account."<<endl;
    cout<<"2 Check balance."<<endl;
    cout<<"3 Deposit."<<endl;
    cout<<"4 Withdraw."<<endl;
    cout<<"5 Exit."<<endl;
    do {
        cout<<"Enter your choice: ";
        cin>>choice;
        cout<<endl;

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
                double initialBalance;

                cout<<"Enter your 9 digit account number: ";
                cin>>accountNumber;
                cout<<endl<<"Enter your name: ";
                cin.ignore();
                getline(cin, name);
                cout<<"Enter your initial balance: ";
                cin>>initialBalance;
                cout<<endl;
                accounts.emplace_back(accountNumber, name, initialBalance);
                cout<<"Account created successfully!"<<endl;
                break;
            }
            case 2: {
                long long accountNumber;
                const Account* accountDetails = nullptr;
                cout<<"Enter your 9 digit account number: ";
                cin>>accountNumber;
                cout<<endl;

                accountDetails = findAccount(accounts, accountNumber);
                if(accountDetails != nullptr) {
                    accountDetails->accountInfo();
                    break;
                }else {
                    cout<<"Account not found."<<endl;
                    break;
                }
            }
            case 3: {
                long long accountNumber;
                Account* accountDetails = nullptr;
                cout<<"Enter your 9 digit account number: ";
                cin>>accountNumber;
                cout<<endl;

                accountDetails = findAccount(accounts, accountNumber);
                if(accountDetails != nullptr) {
                    double amount;
                    cout<<"Enter the amount to deposit: ";
                    cin>>amount;
                    accountDetails->deposit(amount);
                    break;
                }else {
                    cout<<"Account not found."<<endl;
                    break;
                }
            }
            case 4: {
                long long accountNumber;
                Account* accountDetails = nullptr;
                cout<<"Enter your 9 digit account number: ";
                cin>>accountNumber;
                cout<<endl;

                accountDetails = findAccount(accounts, accountNumber);
                if(accountDetails != nullptr) {
                    double amount;
                    cout<<"Enter the amount to withdraw: ";
                    cin>>amount;
                    accountDetails->withdraw(amount);
                    break;
                }else {
                    cout<<"Account not found."<<endl;
                    break;
                }
            }
            case 5: {
                cout<<"Exited Successfully!."<<endl;
                break;
            }
            default: {
                cout<<"Invalid choice. Try agin!"<<endl;
            }
        }


    }while (choice != 5);


    return 0;
}