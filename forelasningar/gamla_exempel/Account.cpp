#include "Account.h"



Account::Account(){
    this->ownerName = "";
    this->balance = 0;
}

// DESTRUCTOOOOR
Account::~Account(){
}

explicit Account::Account(int balance){
    ownerName = "No one";
    this->balance = balance;
}

Account::Account(std::string name, int balance){
    this->ownerName = name;
    this->balance = balance;
}

Account& Account::operator=(const Account& accountCopy){
    balance = accountCopy.balance;
    ownerName = accountCopy.ownerName;

    return *this;
}

Account::Account(const Account& sourceAccount){
    ownerName = sourceAccount.ownerName;
    balance = sourceAccount.balance;
}

int Account::withdraw(int amount){
    int money;

    if (amount <= this->balance){
        std::cout << "Withdrawn balance: " << amount << std::endl;
        balance -= amount;
    }else {
        std::cout << "Not enough balance to withdraw: " << amount << std::endl;
    }



    return money;
}

std::ostream& operator<<(std::ostream& os, const Account& acc){
    std::cout << "Your balance is: " << acc.getBalance() << std::endl;

    return os;
}