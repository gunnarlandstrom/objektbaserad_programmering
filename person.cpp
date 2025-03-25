#include "person.h"


// Constructor

Person::Person(){

}

Person::Person(std::string name, std::string id, Address location){


}


// Process file, divide to variables, create objects, save to vector, return it.
std::vector<Person> Person::read_file(std::string filename){
    std::vector<Person> vectorOfPeeople;

    std::string inputOne;
    std::string inputTwo;
    std::string inputThree;
    std::string inputFour;
    std::ifstream inputFile;
    inputFile.open(filename);

    while (!inputFile.eof()){

        inputFile >> inputOne;
     
        std::cout << inputOne;
        
    }

    return vectorOfPeeople;

}

// Find names from object vector, return objects of matches, else empty
size_t Person::find_in_names(const std::vector<Person> & haystack, std::string name_part){


    std::size_t temp;

    return temp;
}

// Find city, return vector of matches, else empty
std::vector<Person> Person::find_person_from_city(const std::vector<Person>& haystack, std::string city){




    return haystack;
}


/*
std::istream & operator >>( std::istream & in , Person & p){
}
*/