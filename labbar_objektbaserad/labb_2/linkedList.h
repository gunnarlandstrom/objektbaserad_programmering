#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <string>
#include <iostream>
#include <random>

class linked_list {

    public:
    linked_list();
    linked_list(const linked_list &src);

    ~linked_list();
    
    
    // added functions
    double randomNumber();
    void generateList(size_t size);
    

    linked_list& operator=(const linked_list &rhs);

    //appneds elements from rhs
    //linked_list& operator+=(const linked_list &rhs);

    //Inserting elements
    void insert(double value, size_t pos);
    void push_front(double value);
    void push_back(double value);

    //Accessing elements
    double front() const;
    double back() const;
    double at(size_t pos) const;

    //Removing elements
    void remove(size_t pos);
    double pop_front();
    double pop_back();

    //status
    size_t size() const;
    bool is_empty() const;

    //output
    void print() const;
    void print_reverse() const;

    private:
    struct node{
        node(double value);
        double value;
        node* next;
        node* prev;
    };
    node* headNode = nullptr;
    node* tailNode = nullptr;
};

// Globala grejer
linked_list merge(linked_list&, linked_list&);
void print_list(linked_list list);

#endif