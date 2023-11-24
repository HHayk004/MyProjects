#include <iostream>
#include "vector.h"

int main()
{
    MyVector<bool> vec({0, 1, 1, 0, 1, 0, 1, 1, 0, 0});
    MyVector<bool> vec1(vec);
    
    vec1.push_back(1);
    vec.pop_back();

    std::cout << vec << std::endl;
    std::cout << vec1 << std::endl;

    vec.swap(vec1);
    
    std::cout << vec << std::endl;
    std::cout << vec1 << std::endl;

    return 0;
}
