#include "pekare.h"

int main()
{

    /*
    int* l;
    *j = 7;

    */
    int *j;
    j = new int(5);
    
    //j = nullptr;
    std::cout << "J IS : " << j << std::endl;

    int *k; // wild pointer

    k = j;

    // k och j dangling pointers
    delete j;
    std::cout << "Address to j: " << j << std::endl;
    
    if (j != nullptr) {
        std::cout << *j << std::endl;
    }

    int number = 10;
    int* arr = new int[number];
    arr[0] = 55;
    arr[1] = 44;
    arr[2] = 33;
    arr[3] = 22;
    arr[4] = 11;
    arr[5] = 00;

    /*
    Får ej ändra värdet som pekaren pekar på pga const.
    const int* p = new int(3);
    p = 5;
    p = k;
    */

    /*
    Får ej ändra på pekarens adress pga const.
    int* const pp = new int(3);
    *pp = 5;
    pp = k;
    */

    /* Får ej ändra på varken värdet pekaren pekar på, eller pekaren själv.
    const int* const ppp = new int(3);
    *ppp = 5;
    ppp = k;
    */


    return 0;
}