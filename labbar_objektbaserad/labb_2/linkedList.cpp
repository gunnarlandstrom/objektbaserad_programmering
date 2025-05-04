#include "linkedlist.h"

// Constructors
linked_list::linked_list()
{
    this->headNode = nullptr;
    this->tailNode = nullptr;
}

linked_list::linked_list(const linked_list &src)
{
    this->headNode = nullptr;
    this->tailNode = nullptr;
    node *tempNode = src.headNode;
    while (tempNode != nullptr)
    {
        this->push_back(tempNode->value);
        tempNode = tempNode->next;
    }
}

// destructor
linked_list::~linked_list()
{
    while (this->headNode != nullptr)
    {
        remove(0);
    }
}

//
linked_list &linked_list::operator=(const linked_list &rhs)
{

    node *tempNode = rhs.headNode;
    if (this != &rhs)
    {
        while (this->headNode != nullptr)
        {
            this->remove(0);
        }
        while (tempNode != nullptr)
        {
            this->push_back(tempNode->value);
            tempNode = tempNode->next;
        }
    }
    return *this;
}

// appends elements from rhs
linked_list &linked_list::operator+=(const linked_list &rhs)
{

    size_t size = rhs.size();
    std::cout << "SIZE YAO:" << size << std::endl;
    node *tempNode = rhs.headNode;
    for (size_t i = 0; i < size; i++)
    {
        this->push_back(tempNode->value);
        tempNode = tempNode->next;
    }
    return *this;
}

// Inserting elements
void linked_list::insert(double value, size_t pos)
{
    size_t counter = 0;
    node *tempNode = headNode;

    node *insertNode = new node(value);

    while (counter != pos)
    {
        if (tempNode->next == nullptr)
        {
            std::cout << "Error: Position out of scope!" << std::endl;
            return;
        }
        tempNode = tempNode->next;
        counter++;
    }
    if (tempNode == headNode)
    {
        insertNode = headNode;
        insertNode->next = tempNode;
        insertNode->prev = nullptr;
    }
    else if (tempNode == tailNode)
    {
        insertNode = tailNode;
        insertNode->prev = tempNode;
        insertNode->next = nullptr;
    }
    else if (tempNode == tailNode && tempNode == headNode)
    {
        push_front(insertNode->value);
    }
    else {
        
    }
}

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

// Accessing elements
double linked_list::front() const
{
    double counter = 0;
    node *tempNode = this->headNode;

    if (tempNode == nullptr)
    {
        std::cout << "Error: Cannot access the front of an empty list!" << std::endl;
        return -1;
    }
    else
    {
        return this->headNode->value;
    }
}
double linked_list::back() const
{
    double counter = 0;
    node *tempNode = this->headNode;

    if (tempNode == nullptr)
    {
        std::cout << "Error: Cannot access the back of an empty list." << std::endl;
        return -1;
    }
    else
    {
        do
        {
            counter++;
            tempNode = tempNode->next;
        } while (tempNode->next != nullptr);
    }
    return tempNode->value;
}

// Done.
double linked_list::at(size_t pos) const
{
    size_t counter = 0;

    if (is_empty())
    {
        std::cout << "Unable to find an element at index: " << pos << ", the list is empty." << std::endl;
        return -1;
    }

    node *tempNode;
    tempNode = headNode;

    while (counter != pos)
    {
        if (tempNode == nullptr)
        {
            std::cout << "Position out of scope at index: " << counter << " " << pos << std::endl;
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
        std::cout << "Unable to remove an element at index: " << pos << ", from an empty list." << std::endl;
        return;
    }

    node *target;
    target = this->headNode;

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
    if (target == headNode && target == tailNode)
    {
        headNode = nullptr;
        tailNode = nullptr;
    }
    else if (target == headNode)
    {
        headNode = target->next;
        target->next->prev = nullptr;
    }
    else if (target == tailNode)
    {
        tailNode = target->prev;
        target->prev->next = nullptr;
    }
    else
    {
        target->prev->next = target->next;
        target->next->prev = target->prev;
    }
    delete target;
}

double linked_list::pop_front()
{

    node *tempNode = headNode;
    if (tempNode->next == nullptr)
    {
        headNode = nullptr;
        tailNode = nullptr;
        return tempNode->value;
    }
    headNode = tempNode->next;
    headNode->prev = nullptr;

    return tempNode->value;
}
double linked_list::pop_back()
{
    node *tempNode = tailNode;
    tailNode = tempNode->prev;
    tailNode->next = nullptr;
    return tempNode->value;
}

// Status
size_t linked_list::size() const
{
    size_t listSize = 0;

    node *tempNode = this->headNode;
    if (tempNode == nullptr)
    {
        std::cout << "List has no size, because it is empty! " << std::endl;
        return -1;
    }
    while (tempNode != nullptr)
    {
        listSize++;
        tempNode = tempNode->next;
    }

    return listSize;
}

bool linked_list::is_empty() const
{
    return (this->headNode == nullptr && this->tailNode == nullptr);
}

// Output
void linked_list::print() const
{
    node *tempNode;
    tempNode = this->headNode;

    if (is_empty())
    {
        std::cout << "Error: Cannot print an empty list!" << std::endl;
        return;
    }
    while (tempNode != nullptr)
    {
        std::cout << tempNode->value << std::endl;
        tempNode = tempNode->next;
    }
}

void linked_list::print_reverse() const
{
    node *tempNode;
    tempNode = tailNode;

    if (is_empty())
    {
        std::cout << "Error: Cannot print an empty list!" << std::endl;
        return;
    }
    do
    {
        std::cout << tempNode->value << std::endl;
        tempNode = tempNode->prev;
    } while (tempNode != nullptr);
}

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
