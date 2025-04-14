#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

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
    unsigned short amountOfPlayers = 0;
    double complexity{1};
    Ranking rank{};
};

std::ostream &operator<<(std::ostream &os, const BoardGame &bg)
{

    os << bg.title << ", " << bg.genre << ", " << bg.rank.overall;
    return os;
}

std::vector<BoardGame> getTopRankedGames(const std::vector<BoardGame> &boardgames, int limit)
{
    std::vector<BoardGame> ranked_bg_list;

    /*
    // INT BAD, SIZE_T GUUD
    for (size_t i = 0; i < boardgames.size(); i++)
    {
        if (boardgames[i].rank.overall <= limit)
        {
            ranked_bg_list.push_back(boardgames[i]);
        }
    }

    for (std::vector<BoardGame>::const_iterator it = boardgames.begin(); it != boardgames.end(); it++)
    {
        if ((*it).rank.overall <= limit)
        {
            ranked_bg_list.push_back(*it);
        }
    }

    // Bad auto
    for (auto bg : boardgames)
    {
        if (bg.rank.overall <= limit)
        {
            ranked_bg_list.push_back(bg);
        }
    }
    */

    // Correct use
    for (const BoardGame &bg : boardgames)
    {
        if (bg.rank.overall <= limit)
        {
            ranked_bg_list.push_back(bg);
        }
    }

    return ranked_bg_list;
}

bool isRankedHigher(const BoardGame &a, const BoardGame &b)
{
    if (a.rank.overall < b.rank.overall)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    std::vector<BoardGame> bg_list = {
        BoardGame{"Settlers of Catan", "Strategy", 5, 2.0, {149, 142}},
        BoardGame{"Terraforming Mars", "Strategy", 5, 3.24, {4, 5}},
        BoardGame{"Gloomhaven", "Thematic", 4, 3.86, {1, 1}}};

    BoardGame bg;

    if (bg.amountOfPlayers == 0)
    {
        std::cerr << "Zero players not allowed." << std::endl;
    }

    std::vector<BoardGame> bg_list_top100;

    bg_list_top100 = getTopRankedGames(bg_list, 100);

    std::sort(bg_list_top100.begin(), bg_list_top100.end(), isRankedHigher);

    for (auto &bg : bg_list_top100)
    {
        std::cout << bg << std::endl;
    }

    /* LAMBDA FUNCTION [](){}
    std::sort(bg_list_top100.begin(), bg_list_top100.end(), [](const BoardGame &a, const BoardGame &b)
              { return a.rank.overall < b.rank.overall; });

    */

    return 0;
}