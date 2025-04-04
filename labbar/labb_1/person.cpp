#include "person.h"

// Process file, divide to variables, create objects, save to vector, return it.
std::vector<Person> read_file(std::string filename)
{
    std::vector<Person> vectorOfPeople;
    Person personOne;
    std::ifstream inputFile;
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
    std::vector<Person> personVector;
    personVector = read_file("names.txt");
    bool wantsToSearch;
    std::string userChoice;
    std::cout << "This is a program that searches a file after parts of a name or a city" << '\n';

    std::cout << "Do you want to search something?" << '\n';
    std::cout << "Input:> ";
    std::cout << "[1] - Yes" << '\n';
    std::cout << "[2] - No" << '\n';
    std::getline(std::cin, userChoice);

    if (userChoice == "1")
    {
        wantsToSearch = true;
    }
    else
    {
        std::cout << "Exiting program." << '\n';
        wantsToSearch = false;
    }

    while (wantsToSearch)
    {
        std::string wantedName;
        std::string wantedCity;

        std::cout << '\n';
        std::cout << "What do you want to search for?" << '\n';
        std::cout << "[1] - a name." << '\n';
        std::cout << "[2] - a city." << '\n';
        std::cout << "[3] - Exit." << '\n';
        std::cout << "Input:> ";
        std::getline(std::cin, userChoice);

        if (userChoice == "1")
        {
            std::string tempTrash;
            std::cout << "What name or partial name do you want to search for?" << '\n';
            std::cout << "Input:> ";
            std::getline(std::cin, wantedName);

            find_in_names(personVector, wantedName);
        }
        else if (userChoice == "2")
        {
            std::vector<Person> personsInCity;
            std::cout << "What city do you want to search for?" << '\n';
            std::cout << "Input:> ";
            std::getline(std::cin, wantedCity);
            personsInCity = find_person_from_city(personVector, wantedCity);
            std::cout << "\n";
            printArray(personsInCity);
        }
        else
        {
            std::cout << "Exiting program." << '\n';
            wantsToSearch = false;
        }
    }
}

// Prints array of Person
void printArray(std::vector<Person> &array)
{
    for (size_t i = 0; i < array.size(); i++)
    {
        Person tempPerson = array[i];

        std::cout << array[i].id << std::endl;
        std::cout << array[i].name << std::endl;
        std::cout << array[i].location.zip << std::endl;
        std::cout << array[i].location.city << std::endl
                  << std::endl;
    }

    /*
    for (size_t j = 0; j < array.size(); j++)
    {

    std::string wot = ", ";
    std::cout << array[j].id << wot << array[j].name << wot << array[j].location.zip << wot << array[j].location.city << std::endl;
}
*/
}

// Find names from object vector, return objects of matches, else empty
size_t find_in_names(const std::vector<Person> &haystack, std::string name_part)
{
    std::size_t temp = 0;

    for (int i = 0; i < name_part.length(); i++)
    {
        name_part.at(i) = tolower(name_part.at(i));
    }

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
