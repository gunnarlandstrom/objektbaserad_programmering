#include "person.h"
#include "address.h"
#include <iostream>
#include <vector>

int main()
{

    std::string filename;
    std::vector<Person> personVector;


    std::cout << "What file do you want to search?";
    std::cin >> filename;


    // Constructor
    Person program;

   personVector = program.read_file("names.txt");

    

    return 0;
}