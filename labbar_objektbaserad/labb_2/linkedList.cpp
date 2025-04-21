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

// Done
void linked_list::push_front(double value)
{
    node *newNode = new node(value);
    if (is_empty())
    {
        headNode = newNode;
        tailNode = newNode;
    }
    else
    {
        node *tempNode = headNode;
        headNode = newNode;
        newNode->next = tempNode;
        tempNode->prev = newNode;
    }
}

// Done
void linked_list::push_back(double value)
{
    node *newNode = new node(value);

    if (is_empty())
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

// Prints linked_list
void linked_list::printList()
{
    node *tempNode;
    tempNode = headNode;

    if (is_empty())
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

// Done.
double linked_list::at(size_t pos) const
{
    size_t counter = 0;

    if (is_empty())
    {
        std::cout << "The list is empty." << std::endl;
        return -1;
    }

    node *tempNode;
    tempNode = headNode;

    while (counter != pos)
    {
        if (tempNode->next == nullptr)
        {
            std::cout << "Position out of scope at index: " << counter << std::endl;
            return -1;
        }
        tempNode = tempNode->next;
        counter++;
    }
    return tempNode->value;
}

// Removing elements
void linked_list::remove(size_t pos)
{

    size_t counter = 0;

    if (is_empty())
    {
        std::cout << "The list is empty." << std::endl;
        return;
    }

    node *target;
    target = headNode;

    while (counter != pos)
    {
        if (target->next == nullptr)
        {
            std::cout << "Error: position out of scope!" << counter << std::endl;
            return;
        }
        target = target->next;
        counter++;
    }
    if (target == headNode)
    {
        target->next = headNode;
        target->next->prev = nullptr;
    }
    else if (target == tailNode)
    {
        target->prev = tailNode;
        target->prev->next = nullptr;
    }
    else
    {
        target->prev->next = target->next;
        target->next->prev = target->prev;
    }
    delete target;
}

/*
}
if (tempNode->prev == nullptr)
{
    tempNode->next = headNode;
    delete tempNode;
}
else if (tempNode->next == nullptr)
{
    tempNode->prev = tailNode;
    delete tempNode;
}
else
{
    tempNode->next->prev = tempNode->prev;
    tempNode->prev->next = tempNode->next;
    delete tempNode;
*/

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
    if (headNode == nullptr && tailNode == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
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

    if (is_empty())
    {
        return 0.0;
    }

    temp = rand() % 11;
    /*if (temp == 10)
    {
        return temp;
    }
    randomNumber = rand() % 10;

    tempTwo = +(randomNumber / 10);

    temp = temp + tempTwo;
    */
    return temp;
}

linked_list::node::node(double value)
{
    this->value = value;
    this->next = nullptr;
    this->prev = nullptr;
}

void linked_list::generateList(size_t size)
{
    double number = 0;
    for (size_t i = 0; i < size; i++)
    {
        double tempNumber = this->randomNumber();
        number += tempNumber;
        this->push_back(number);
    }
}