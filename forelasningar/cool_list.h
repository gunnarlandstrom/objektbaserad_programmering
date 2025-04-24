#ifndef COOL_LIST_H // Include guard.
#define COOL_LIST_H

#include <iostream>

class cool_list
{
public:
    cool_list();

    //Copyconstructor
    cool_list(const cool_list& src);

    cool_list& operator=(const cool_list& rhs);

    //Destructor
    ~cool_list();
    void push_back(double value);
    void print_list();

    //Inline funktion anropas direkt
    inline bool isEmpty() { return head == nullptr; };

private:
    struct node
    {
        double value;
        node *next;
        //        node* prev;
    };
    node *head;
    //    node* tail;
};
#endif