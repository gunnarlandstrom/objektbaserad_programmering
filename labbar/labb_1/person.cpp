#include "person.h"

// Process file, divide to variables, create objects, save to vector, return it.
std::vector<Person> read_file(std::string filename)
{
    std::vector<Person> vectorOfPeople;
    Person personOne;
    std::ifstream inputFile;
    std::ofstream outputFile("test.txt");
    inputFile.open(filename);

    while (!inputFile.eof())
    {

        inputFile >> personOne;
        vectorOfPeople.push_back(personOne);
    }

    return vectorOfPeople;
}

void printArray(std::vector<Person> array)
{

    for (int i = 0; i < array.size() - 1; i++)
    {

        Person tempPerson = array[i];
        Address tempAd = tempPerson.location;

        std::cout << tempPerson.name << std::endl;
        std::cout << tempPerson.id << std::endl;
        std::cout << tempAd.street << std::endl;
        std::cout << tempAd.zip << std::endl;
        std::cout << tempAd.city << std::endl;
    }
}

bool wantsToSearch(int input)
{
    if (input == 1)
    {

        return true;
    }
    else
    {
        return false;
    }
}

// Find names from object vector, return objects of matches, else empty
size_t find_in_names(const std::vector<Person> &haystack, std::string name_part)
{
    std::size_t temp;

    return temp;
}

// Find city, return vector of matches, else empty
std::vector<Person> find_person_from_city(const std::vector<Person> &haystack, std::string city)
{
    return haystack;
}

std::istream &operator>>(std::istream &in, Person &p)
{
    Address a;
    std::string tempName;
    std::string tempId;
    std::string tempAddress;
    std::string tempResidence;
    std::string tempString;
    std::string tempCity;
    std::string realCity;
    int tempZip;

    std::getline(in, tempName);

    if (tempName == "")
    {
        return in;
    }

    std::getline(in, tempId);
    std::getline(in, tempAddress, ',');
    std::getline(in, tempResidence);

    std::cout << tempName << std::endl;
    std::cout << tempId << std::endl;
    std::cout << tempAddress << std::endl;
    std::cout << tempResidence << std::endl;

    tempString = tempResidence.substr(1, 6);
    tempString.erase(3, 1);
    tempCity = tempResidence.substr(9);

    for (int i = tempCity.length() - 1; i > 0;)
    {

        // tempcity.length -1, reading from the back puts the index at the carriage return.
        if (tempCity[i] == char(13))
        {
            i--;
        }
        else if (tempCity[i] == char(32))
        {
            i--;
        }
        else
        {
            i++;
            realCity = tempCity.substr(0, i);
            break;
        }
    }

    p.name = tempName;
    p.id = tempId;
    p.location.zip = tempZip;
    p.location.street = tempAddress;
    p.location.city = tempCity;

    return in;
}
