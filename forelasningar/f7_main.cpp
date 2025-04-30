#include "exception.h";

int division(int a, int b) {
    if (b == 0){
        throw std::invalid_argument("Can't divide by 0");
    }
}


int main()
{

    std::vector<int> v = {1, 2, 3};

    try
    {
        std::cout << v.at(10) << std::endl;
    }
    catch (std::out_of_range& e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
        std::cerr << e.what() << '\n';
        //std::exit(EXIT_FAILURE);
    }

    std::cout << v[10] << std::endl;

    try
    {
        std::cout << division(10, 0) << std::endl;
    }
    catch(std::invalid_argument &ex)
    {
        std::cerr << "Exception caught: " << ex.what() << std::endl;
    }
    
    //assert(1 == 1);

    std::vector<int> v2 = {};
    v2.push_back(5);
    assert(v2.size() <= v2.capacity());

    

    return 0;
}