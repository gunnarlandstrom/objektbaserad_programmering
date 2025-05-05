#include "linkedlist.h"

// Globala grejer
void print_list(linked_list list);
linked_list merge(linked_list &refOne, linked_list &refTwo);
bool isSorted(linked_list &list);

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
    double atOne = listOne.at(4);
    double atTwo = listTwo.at(4);

    if (atOne < atTwo)
    {
        listTwo.remove(4);
        listTwo.print();
        listThree = listTwo;
    }
    else
    {

        listOne.remove(4);
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
    mergedList.print();
    isSorted(mergedList);

    linked_list scrambleList;
    scrambleList.generateList(10);

    std::cout << std::endl
              << "-------" << std::endl
              << std::endl;
    for (int i = 9; i > 0; i--)
    {
        scrambleList.push_front(scrambleList.at(i));
        scrambleList.pop_back();
    }
    scrambleList.print();

    isSorted(scrambleList);

    std::cout << std::endl
              << "-------" << std::endl
              << std::endl;

    linked_list pushFront;
    pushFront.push_back(50);
    pushFront.push_back(40);
    pushFront.push_back(30);
    pushFront.push_back(20);
    pushFront.push_back(10);
    pushFront.push_back(5);
    pushFront.push_back(0);
    pushFront.insert(25, 3);

    pushFront.print();

    isSorted(pushFront);

    pushFront += pushFront;
    pushFront.print();

    return 0;
}

// Global function isSorted
bool isSorted(linked_list &list)
{

    int counter = 0;
    if (list.is_empty())
    {
        std::cout << "Empty lists are always sorted." << std::endl;
        return true;
    }
    else
    {
        if (list.front() < list.back())
        {
            for (size_t i = 1; i < list.size(); i++)
            {
                if (list.at(counter) > list.at(i))
                {
                    std::cout << "List is not sorted!" << std::endl;
                    return false;
                }
                counter++;
            }
            std::cout << "List is sorted from small to large numbers!" << std::endl;
        }
        else if (list.front() > list.back())
        {
            for (size_t i = 1; i < list.size(); i++)
            {
                if (list.at(counter) < list.at(i))
                {
                    std::cout << "List is not sorted!" << std::endl;
                    return false;
                }
                counter++;
            }
            std::cout << "List is sorted from large to small numbers!" << std::endl;
        }
    }
    return true;
}

// Global function merge
linked_list merge(linked_list &refOne, linked_list &refTwo)
{

    linked_list mergedList;
    if (refOne.is_empty() && refTwo.is_empty())
    {
        return mergedList;
    }
    while (!refOne.is_empty() || !refTwo.is_empty())
    {
        if (refOne.is_empty())
        {
            while (!refTwo.is_empty())
            {
                mergedList.push_back(refTwo.front());
                refTwo.pop_front();
            }
            return mergedList;
        }
        else if (refTwo.is_empty())
        {
            while (!refOne.is_empty())
            {
                mergedList.push_back(refOne.front());
                refOne.pop_front();
            }
            return mergedList;
        }
        else
        {
            if (refOne.front() <= refTwo.front())
            {
                mergedList.push_back(refOne.front());
                refOne.pop_front();
            }
            else if (refTwo.front() < refOne.front())
            {
                mergedList.push_back(refTwo.front());
                refTwo.pop_front();
            }
        }
    }
    /*
    if (!refOne.is_empty()){
        mergedList += refOne;
    } else if (!refTwo.is_empty()){
        mergedList += refTwo;
    }
    */

    return mergedList;
}

// Global function print
void print_list(linked_list list)
{
    list.print();
}

