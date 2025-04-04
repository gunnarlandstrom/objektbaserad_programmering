#ifndef ACCOUNT_H // Include guard.
#define ACCOUNT_H

#include <string>
#include <iostream>

class Account {

    
    private:
    std::string ownerName;
    int balance;
    
    
    
    
    public:
    // Constructors
    Account();
    explicit Account(int); // Typkonverteringskonstructor
    Account(std::string name, int amount);
    Account(const Account& sourceAccount); //Kopieringskonstruktor
    
    // DESTRUCtOR
    ~Account();


    // Kedjeoperator e = a = b = d. d tilldelas till b, b returneras, sen tilldelas till a etc..
    // Måste vara medlem till klassen.
    Account& operator=(const Account& accountCopy);
    
    int withdraw(int input);
    //Inline kopierar in definitionen direkt vid funktionsanropet.
    inline int getBalance() { return balance; }
    
};

std::ostream& operator<<(std::ostream& os, const Account& acc);








#endif