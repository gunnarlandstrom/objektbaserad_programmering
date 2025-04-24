#include "linkedlist.h"

int main()
{
    srand(time(0));
    linked_list listOne;
    linked_list listTwo;
    linked_list listThree;

    // #1
    listOne.generateList(10);
    listOne.printList();

    std::cout << std::endl << "-------" << std::endl
              << std::endl;

    listTwo.generateList(10);

    listTwo.printList();

    std::cout << std::endl << "-------" << std::endl
              << std::endl;

    // #2 at
    double atOne = listOne.at(5);
    double atTwo = listTwo.at(5);

    if (atOne < atTwo)
    {
        listTwo.remove(5);
        listTwo.printList();
        listThree = listTwo;
    }
    else
    {

        listOne.remove(5);
        listOne.printList();
        listThree = listOne;
    }
    
    // remove
    
    std::cout << std::endl
    << "-------" << std::endl
    << std::endl;
    listThree.printList();
    
    std::cout << std::endl
    << "-------" << std::endl
    << std::endl;
    listThree = listThree;


    return 0;
}
