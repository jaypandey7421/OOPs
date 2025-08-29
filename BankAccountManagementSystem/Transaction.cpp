#include <iostream>
#include <string>
#include <iomanip>
#include "Transaction.h"

using namespace std;

Transaction::Transaction(string type, const double a, const double b) {
    transactionType = std::move(type);
    transactionAmount = a;
    balance = b;
    timeStamp = getCurrentTime();
}

string Transaction::getCurrentTime() {
    const time_t now = time(nullptr);
    const tm *ltm = localtime(&now);

    char buf[30];
    strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", ltm);
    return string{buf};
}

void Transaction::display() const{
    cout<<left<<setw(18)<<transactionType<<" | "
        <<setw(12)<<transactionAmount<< " | "
        <<setw(12)<<balance<<" | "
        <<setw(12)<<timeStamp<<" |"
        <<endl;
}

