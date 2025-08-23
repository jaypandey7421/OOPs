#include <iostream>
#include <string>
#include <utility>
using namespace std;

class Account{
private:
    long long accountNumber;
    string name;
    int balance;
public:
    Account(const long long a, string n, const int b): accountNumber(a), name(std::move(n)), balance(b){}

    void add(const int b){
        if(b < 1){
            cout<<"Add valid amount!"<<endl;
            return;
        }

        balance += b;
    }

    void withdraw(const int amount){
        if(amount > balance){
            cout<<"Not sufficient balance!"<<endl;
            return;
        }else if(amount < 1){
            cout<<"Invalid amount to withdraw!"<<endl;
            return;
        }

        balance -= amount;
    }

    void accountInfo() const{
        cout<<endl<<" Account Info"<<endl;
        cout<<" _____________________________________________"<<endl;
        cout<<"| Account Number: "<<accountNumber<<endl;
        cout<<"| Name: "<<name<<endl;
        cout<<"| Balance: "<<balance<<endl;
        cout<<"|_____________________________________________"<<endl;
    }

    [[nodiscard]] int checkBalance() const{
        return balance;
    }

};

int main(){
    Account a(1113912710003, "Batman of Gotham", 100);

    a.accountInfo();
    cout<<"Balance: $"<<a.checkBalance()<<endl;
    a.add(50);
    cout<<"Balance: $"<<a.checkBalance()<<endl;
    a.withdraw(-20);
    cout<<"Balance: $"<<a.checkBalance()<<endl;
    a.withdraw(200);
    cout<<"Balance: $"<<a.checkBalance()<<endl;
    a.withdraw(20);
    cout<<"Balance: $"<<a.checkBalance()<<endl;
    a.add(30);
    cout<<"Balance: $"<<a.checkBalance()<<endl;


    return 0;
}