#include "person.h"
#include <iostream>
#include <vector>

int main()
{

    std::vector<Person> personVector;
    int userChoice;

    std::cout << "This is a program that searches a file after parts of a name or a city" << std::endl;

    std::cout << "Do you want to search something?";
    std::cin >> userChoice;

    while (userChoice){
        // Constructor
        Person program;
        personVector = read_file("names.txt");

        std::cout << "What do you want to search for?" << std::endl;
        std::cout << "[1] - a name." << std::endl;
        std::cout << "[2] - a city." << std::endl;
        
    }
    
    //printArray(personVector);
    return 0;
}