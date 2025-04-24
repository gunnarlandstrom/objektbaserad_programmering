#include "cool_list.h"

cool_list::cool_list()
{

    this->head = nullptr;
}

void cool_list::push_back(double value)
{
    node *n = new node;
    n->value = value;
    n->next = nullptr;

    if (isEmpty())
    {
        head = n;
    }
    else
    {
        node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = n;
    }
}

cool_list::~cool_list(){

    // Iterera pop_front() eller liknande tills alla noder tagits bort.

}

// Kopieringskonstruktorn
cool_list::cool_list(const cool_list& src){
head = nullptr;

//head = src.head; //Shallow copy

//Loopa push_back(...) över src för deep copy

}

// CHECK OUT *COPY AND SWAP*
cool_list& cool_list::operator=(const cool_list& rhs){
    
    if (this != &rhs)
    /*
     1. Edge case, tilldela lista till sig själv.
        Kontroll mot self asignment.
     */

    // 2. Töm this.
    // 3. Lägg till element från rhs till this


    return *this;
}

void cool_list::print_list()
{

    for (node *pt = head; pt != nullptr; pt = pt->next)
    {

        std::cout << pt->value << " ";
    }
    std::cout << std::endl;
}


