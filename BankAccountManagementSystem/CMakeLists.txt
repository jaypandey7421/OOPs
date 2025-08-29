cmake_minimum_required(VERSION 4.0)
project(BankAccountManagementSystem)

set(CMAKE_CXX_STANDARD 20)

add_executable(BankAccountManagementSystem main.cpp
        Account.cpp
        CurrentAccount.cpp
        SavingsAccount.cpp
        Transaction.cpp)
