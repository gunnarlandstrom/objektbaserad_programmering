#include "address.h"


// Constructor

Address::Address(){

}


Address::Address(std::string streetInput, std::string cityInput, int zipInput){

    street = streetInput;
    city = cityInput;
    zip = zipInput;


}

// Getters
std::string Address::getStreet(){
    return street;
}

std::string Address::getCity(){
    return city;
}

int Address::getZip(){
    return zip;
}

// Setters
void Address::setStreet(std::string input) {
    street = input;
}

void Address::setCity(std::string input) {
    city = input;
}

void Address::setZip(int input) {
    zip = input;
}

