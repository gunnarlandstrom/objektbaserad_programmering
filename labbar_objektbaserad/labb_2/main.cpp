#include "linkedlist.h"

int main()
{
    srand(time(0));
    linked_list listOne;
    linked_list listTwo;
    linked_list listThree;

    // #1
    listOne.generateList(10);
    listOne.print();

    std::cout << std::endl
              << "-------" << std::endl
              << std::endl;

    listTwo.generateList(10);

    listTwo.print();

    std::cout << std::endl
              << "-------" << std::endl
              << std::endl;

    // #2 at(), remove() and #3 a = a
    double atOne = listOne.at(5);
    double atTwo = listTwo.at(5);

    if (atOne < atTwo)
    {
        listTwo.remove(5);
        listTwo.print();
        listThree = listTwo;
    }
    else
    {

        listOne.remove(5);
        listOne.print();
        listThree = listOne;
    }

    std::cout << std::endl;
    listThree = listThree;

    std::cout << std::endl
              << "-------" << std::endl
              << std::endl;

    std::cout << "This is reverse print!" << std::endl;
    listThree.print_reverse();

    std::cout << std::endl
    << "-------" << std::endl
    << std::endl;
    

    // #4 pop_back, push_front
    if (atOne > atTwo)
    {
        for (size_t i = 0; i < 5; i++)
        {
            listTwo.pop_back();
            listTwo.push_front(listTwo.pop_back());
        }
        listTwo.print();
    }
    else
    {
        for (size_t i = 0; i < 5; i++)
        {
            listOne.pop_back();
            listOne.push_front(listOne.pop_back());
        }
        listOne.print();
    }

    std::cout << std::endl
              << "-------" << std::endl
              << std::endl;

    std::cout << "This is the global print! " << std::endl;
    // #5 Print_list Global
    if (atOne > atTwo)
    {
        print_list(listTwo);
    }
    else
    {
        print_list(listOne);
    }

    return 0;
}

// Global print
void print_list(linked_list list)
{
    list.print();
}
