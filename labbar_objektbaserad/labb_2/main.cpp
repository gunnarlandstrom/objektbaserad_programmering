#include "linkedlist.h"

int main()
{
    srand(time(0));
    linked_list listOne;
    linked_list listTwo;
    linked_list listThree;

    // #1
    listOne.generateList(10);

    //std::cout << std::endl << "-------" << std::endl << std::endl;
    
    /*
    listTwo.generateList();
    listTwo.printList();
    */
   
   // #2 at
   //double atNumber = listOne.at(5);
   //double atNumberTwo = listTwo.at(11);
   
   //remove
   listThree.generateList(3);
   listThree.printList();
   
   std::cout << std::endl << "-------" << std::endl << std::endl;
   
   listThree.remove(0);
   listThree.remove(0);
   listThree.remove(0);
   
   listThree.printList();


    return 0;
}

