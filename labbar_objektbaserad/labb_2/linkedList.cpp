#include "linkedlist.h"

// Constructors
linked_list::linked_list()
{
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

void linked_list::push_back(double value)
{
    node *newNode = new node(value);

    if (isEmpty())
    {
        headNode = newNode;
        tailNode = newNode;
    }
    else
    {
        node *tempNode = tailNode;
        tailNode = newNode;
        newNode->prev = tempNode;
        tempNode->next = newNode;
    }
}

// Checks if linked list is empty
bool linked_list::isEmpty()
{
    if (headNode == nullptr && tailNode == nullptr)
    {
        return true;
    }
    else
    {

        return false;
    }
}

// Prints linked_list
void linked_list::printList()
{
    node *tempNode;
    tempNode = headNode;

    if (isEmpty())
    {
        std::cout << "List is empty!" << std::endl;
        return;
    }

    do
    {

        std::cout << tempNode->value << std::endl;
        tempNode = tempNode->next;
    } while (tempNode != nullptr);
}

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
void linked_list::print() const
{
}

void linked_list::print_reverse() const {}

double linked_list::randomNumber()
{
    double randomNumber = 0.0;
    double temp = 0.0;
    double tempTwo = 0.0;

    while (temp == 0)
    {
        srand(time(0));
        temp = rand() % 11;
        randomNumber = rand() % 10;

        tempTwo = +(randomNumber / 10);

        temp = temp + tempTwo;
    }

    return randomNumber;
}

linked_list::node::node(double value)
{
    this->value = value;
    this->next = nullptr;
    this->prev = nullptr;
}