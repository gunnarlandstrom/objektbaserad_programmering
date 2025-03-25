#include "person.h"
#include <string>
#include <vector>


// Constructor
Person::Person(){


}


// Process file, divide to variables, create objects, save to vector, return it.
std::vector<Person> Person::read_file(std::string filename){

    std::vector<Person> vectorOfPeeople;



    return vectorOfPeeople;

}

// Find names from object vector, return objects of matches, else empty
size_t Person::find_in_names(const std::vector<Person> & haystack, std::string name_part){





}

// Find city, return vector of matches, else empty
std::vector<Person> Person::find_person_from_city(const std::vector<Person>& haystack, std::string city){





}


/*
std::istream & operator >>( std::istream & in , Person & p){
}
*/