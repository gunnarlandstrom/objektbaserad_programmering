#ifndef PERSON_H
#define PERSON_H
#include "address.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>


struct Person{

    //Variables
    std::string name;
    std::string id;
    Address location{};

};

//Functions
std::vector<Person> read_file(std::string filename);
std::vector<Person> find_person_from_city(const std::vector<Person>& haystack, std::string city);
size_t find_in_names(const std::vector<Person> & haystack, std::string name_part);
std::istream & operator >>( std::istream & in , Person & p);
void printArray(std::vector<Person> array);



#endif