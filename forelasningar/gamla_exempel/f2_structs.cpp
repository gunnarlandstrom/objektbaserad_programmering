#include <iostream>
#include <string>
#include <vector>
#include <fstream>

// Datatyp Ranking
struct Ranking
{
    int overall;
    int in_genre;
};

// Tillverkar en egen datatyp BoardGame.
struct BoardGame
{
    std::string title;
    std::string genre;
    unsigned short amountOfPlayers;
    double complexity;
    Ranking rank{};
};


std::ostream& operator<<(std::ostream& os, BoardGame& bg){

    os << bg.title;
    os << bg.genre;
    os << bg.amountOfPlayers;
    os << bg.complexity;
    os << bg.rank.in_genre;
    os << bg.rank.overall;

    return os;
    
}


std::istream& operator>>(std::istream& in, BoardGame& b){

    std::string tempString;
    std::getline(in, b.title);
    std::getline(in, b.genre);
    std::getline(in, tempString);
    b.amountOfPlayers = std::stoi(tempString.substr(0,1));
    std::getline(in, tempString, ' ');
    b.complexity = std::stod(tempString);
    std::getline(in, tempString);
    std::getline(in, tempString);
    std::getline(in, tempString);





    return in;
}

int main()
{
    // Datatypen initieras med ett namn.
    BoardGame bg1;
    bg1.title = "Puerto Rico";
    bg1.genre = "Strategy";
    bg1.amountOfPlayers = 5;
    bg1.complexity = 3.2;
    bg1.rank.in_genre = 25;
    bg1.rank.overall = 28;

    BoardGame bg2 = bg1;

    BoardGame bg3{"Settlers of Catan", "Strategy", 5, 1.5, {143, 142}};

    std::vector<BoardGame> bg_list;
    bg_list.push_back(bg1);
    bg_list.push_back(bg3);





    std::cout << bg1 << std::endl;

    std::ifstream file("boardgames.txt");

    BoardGame tempBG;


    while(file >> tempBG){
        bg_list.push_back(tempBG);   
    }

    for (BoardGame b : bg_list){
        std::cout << b << std::endl;
    }

    return 0;
}