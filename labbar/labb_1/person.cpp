#include "person.h"

// Process file, divide to variables, create objects, save to vector, return it.
std::vector<Person> read_file(std::string filename)
{
    std::vector<Person> vectorOfPeople;
    Person personOne;
    std::ifstream inputFile;
    std::ofstream outputFile("test.txt");
    inputFile.open(filename);

    while (inputFile >> personOne)
    {
        vectorOfPeople.push_back(personOne);
    }

    return vectorOfPeople;
}

// Startmenu
void startMenu()
{
    bool wantsToSearch;
    std::string userChoice;
    std::cout << "This is a program that searches a file after parts of a name or a city" << std::endl;

    std::cout << "Do you want to search something?" << std::endl;
    std::cout << "[1] - Yes" << std::endl;
    std::cout << "[2] - No" << std::endl;
    std::cin >> userChoice;

    if (userChoice == "1")
    {
        wantsToSearch = true;
    }
    else
    {
        std::cout << "Exiting program." << std::endl;
        wantsToSearch = false;
    }

    while (wantsToSearch)
    {
        std::string wantedName;
        std::string wantedCity;
        std::vector<Person> personVector;
        personVector = read_file("names.txt");

        std::cout << std::endl;
        std::cout << "What do you want to search for?" << std::endl;
        std::cout << "[1] - a name." << std::endl;
        std::cout << "[2] - a city." << std::endl;
        std::cout << "[3] - Exit." << std::endl;
        std::cin >> userChoice;

        if (userChoice == "1")
        {
            std::cout << "What name or partial name do you want to search for?" << std::endl;
            std::cin >> wantedName;
            std::cout << std::endl;
            find_in_names(personVector, wantedName);
        }
        else if (userChoice == "2")
        {
            std::vector<Person> personsInCity;
            std::cout << "What city do you want to search for?" << std::endl;
            std::cin >> wantedCity;
            std::cout << std::endl;
            personsInCity = find_person_from_city(personVector, wantedCity);
            printArray(personsInCity);
        }
        else
        {
            std::cout << "Exiting program." << std::endl;
            wantsToSearch = false;
        }
    }
}

// Prints array
void printArray(std::vector<Person> array)
{

    for (int i = 0; i < array.size(); i++)
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

// Find names from object vector, return objects of matches, else empty
size_t find_in_names(const std::vector<Person> &haystack, std::string name_part)
{
    std::size_t temp = 0;

    for (int i = 0; i < name_part.length(); i++)
    {
        name_part.at(i) = tolower(name_part.at(i));
    }

    std::cout << name_part << std::endl;

    for (size_t i = 0; i < haystack.size(); i++)
    {
        std::string arrayName;
        arrayName = haystack[i].name;
        for (int j = 0; j < haystack[i].name.length(); j++)
        {
            arrayName.at(j) = tolower(arrayName.at(j));
        }
        if (arrayName.find(name_part) != std::string::npos)
            temp++;
    }

    std::cout << "Antal matchningar: " << temp << std::endl;
    return temp;
}

// Find city, return vector of matches, else empty
std::vector<Person> find_person_from_city(const std::vector<Person> &haystack, std::string city)
{
    std::vector<Person> personsInCity;

    for (int i = 0; i < city.length(); i++)
    {
        city.at(i) = toupper(city.at(i));
    }

    for (size_t i = 0; i < haystack.size(); i++)
    {
        if (haystack[i].location.city == city)
        {
            personsInCity.push_back(haystack[i]);
        }
    }

    return personsInCity;
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

    tempString = tempResidence.substr(1, 6);
    tempString.erase(3, 1);
    tempZip = std::stoi(tempString);
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
    p.location.city = realCity;

    return in;
}
