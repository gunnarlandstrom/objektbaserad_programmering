#ifndef ADDRESS_H
#define ADDRESS_H

#include <string>

struct Address {

    Address();
    Address(std::string street, std::string city, int zip);

    std::string street;
    std::string city;
    int zip;
    
    
    std::string getStreet();
    std::string getCity();
    int getZip();

    void setStreet(std::string input);
    void setCity(std::string input);
    void setZip(int input);

};


#endif