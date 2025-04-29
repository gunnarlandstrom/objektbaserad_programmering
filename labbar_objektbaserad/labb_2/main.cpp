#include "linkedlist.h"

int main()
{
    srand(time(0));
    linked_list listOne;
    linked_list listTwo;
    linked_list listThree;

    // #1
    std::cout << "First list!" << std::endl;
    listOne.generateList(10);
    listOne.print();

    std::cout << std::endl
              << "-------" << std::endl
              << std::endl;

    std::cout << "Second list!" << std::endl;
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
    if (atOne < atTwo)
    {
        for (size_t i = 0; i < 5; i++)
        {
            listOne.pop_back();
            listOne.push_front(listOne.pop_back());
        }
        listOne.print();
    }
    else
    {
        for (size_t i = 0; i < 5; i++)
        {
            listTwo.pop_back();
            listTwo.push_front(listTwo.pop_back());
        }
        listTwo.print();
    }

    std::cout << std::endl
              << "-------" << std::endl
              << std::endl;

    std::cout << "This is the global print! " << std::endl;
    // #5 Print_list Global
    if (atOne < atTwo)
    {
        print_list(listOne);
    }
    else
    {
        print_list(listTwo);
    }
    for (size_t i = 0; i < 20; i++)
    {
        std::cout << " \n";
    }

    std::cout << "List One! " << std::endl;
    listOne.print();
    std::cout << "List Two! " << std::endl;
    listTwo.print();
    linked_list mergedList = merge(listOne, listTwo);

    std::cout << std::endl
              << "-------" << std::endl
              << std::endl;

    std::cout << "This is the mergedList: " << std::endl;
    mergedList.print();

    isSorted(mergedList);

    std::cout << std::endl
              << "-------" << std::endl
              << std::endl;

    mergedList.push_back(2);
    isSorted(mergedList);

    linked_list pushFront;
    pushFront.generateList(10);

    std::cout << std::endl
              << "-------" << std::endl
              << std::endl;
    for (int i = 0; i < 10; i++)
    {
        pushFront.push_back(pushFront.at(9));
        pushFront.pop_front();
    }
    pushFront.print();

    std::cout << "Big to small: " << std::endl;
    isSorted(pushFront);

    return 0;
}
