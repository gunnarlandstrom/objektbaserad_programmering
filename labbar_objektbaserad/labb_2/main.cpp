#include "linkedlist.h"

int main()
{

    linked_list listobject;
    listobject.push_back(1);
    listobject.push_back(5);
    listobject.push_back(8);
    listobject.push_back(10);


    listobject.printList();

    return 0;
}