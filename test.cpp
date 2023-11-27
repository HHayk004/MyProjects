#include <iostream>
#include "vector.h"

int main()
{
    MyVector<int> vec = {10, 2, 4, 5};
    
    vec.push_back(1);
    vec.insert(1, 8);
    vec.insert(0, 0);
    vec.insert(7, 100);

    std::cout << vec << std::endl;

    vec.erase(7);
    vec.erase(0);
    vec.erase(1);

    std::cout << vec << std::endl;

    return 0;
}
