#include "cool_list.h"

int main(){


    cool_list amazingList;

    amazingList.push_back(2.3);
    amazingList.push_back(5.5);
    amazingList.push_back(7.1);
    amazingList.push_back(9.9);
    amazingList.push_back(0.2);

    amazingList.print_list();

    cool_list d;

    d.push_back(10);
    d.push_back(15);
    d.push_back(20);
    d.push_back(25);

    if (amazingList.size() > d.size()){
        amazingList.push_back(99);
        amazingList.push_back(89);
        amazingList.push_back(79);


    } else {

        d.push_back(11);
        d.push_back(21);
        d.push_back(31);
    }

    cool_list* big_list = &d;

    for (int i = 20; i <=40; i+=10){
        big_list->push_back(i);
    }



    return 0;
}