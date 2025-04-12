#include "linkedlist.h"

// Constructors
linked_list::linked_list()
{
        node nodeOne(linked_list::randomNumber());
        nodeOne.prev = head;
        nodeOne.next = tail;
        node nodeTwo(linked_list::randomNumber());
        nodeOne.prev = nodeOne.prev;
        nodeOne.next = tail;
        node nodeThree(linked_list::randomNumber());
        nodeOne.prev = nodeTwo.prev;
        nodeOne.next = tail;
        node nodeFour(linked_list::randomNumber());
        nodeOne.prev = nodeThree.prev;
        nodeOne.next = tail;
        node nodeFive(linked_list::randomNumber());
        nodeOne.prev = nodeFour.prev;
        nodeOne.next = tail;
        node nodeSix(linked_list::randomNumber());
        nodeOne.prev = nodeFive.prev;
        nodeOne.next = tail;
        node nodeSeven(linked_list::randomNumber());
        nodeOne.prev = nodeSix.prev;
        nodeOne.next = tail;
        node nodeEight(linked_list::randomNumber());
        nodeOne.prev = nodeSeven.prev;
        nodeOne.next = tail;
        node nodeNine(linked_list::randomNumber());
        nodeOne.prev = nodeEight.prev;
        nodeOne.next = tail;
        node nodeTen(linked_list::randomNumber());
        nodeOne.prev = nodeNine.prev;
        nodeOne.next = tail;

}

linked_list::linked_list(const linked_list &src)
{
    // TBD
}

// destructor?
linked_list::~linked_list()
{
}

/*
//appends elements from rhs
linked_list& linked_list::operator=(const linked_list &rhs){

linked_list tempListOne = rhs;
return tempListOne;
}

linked_list& linked_list::operator+=(const linked_list &rhs){

linked_list tempListTwo = rhs;
return tempListTwo;
}
*/

// Inserting elements
void linked_list::insert(double value, size_t pos) {}

void linked_list::push_front(double value) {}

void linked_list::push_back(double value) {}

// Accessing elements
double linked_list::front() const
{
    return 1.0;
}
double linked_list::back() const
{
    return 1.0;
}
double linked_list::at(size_t pos) const
{
    return 1.0;
}

// Removing elements
void linked_list::remove(size_t pos) {}
double linked_list::pop_front()
{
    return 2.0;
}
double linked_list::pop_back()
{
    return 2.0;
}

// Status
size_t linked_list::size() const
{
    size_t temp = 0;

    return temp;
}

bool linked_list::is_empty() const
{
    return true;
}

// Output
void linked_list::print() const {

}


void linked_list::print_reverse() const {}

double linked_list::randomNumber()
{
    double randomNumber = 0.0;
    double temp = 0.0;
    double tempTwo = 0.0;

    while (temp == 0){
    srand(time(0));
    temp = rand() % 11;
    randomNumber = rand() % 10;

    tempTwo =+ (randomNumber / 10);

    temp = temp + tempTwo;
    }

    return randomNumber;
}

linked_list::node::node(double value)
{
    this->value = value;
}