#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include <ctime>
using namespace std;

class Transaction {
    private:
        string transactionType;
        double transactionAmount;
        double balance;
        string timeStamp;

        static string getCurrentTime() ;
    public:
    Transaction(string type, double a, double b);
    void display() const;
};

#endif