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
   double atOne = listOne.at(5);
   double atTwo = listTwo.at(5);

   if (atOne < atTwo){
    listTwo.remove(5);
   } else {
    listOne.remove(5);
   }
   
   //remove
   listThree.generateList(10);
   for (size_t i = 0; i < 11; i++)
   {
    listThree.remove(0);
   }
   
   listThree.printList();
   
   


    return 0;
}

