#include <iostream>
#include "vector.h"

int main()
{
    MyVector<int> vec = {10, 2, 4, 5};
    
    vec.reserve(20);

    std::cout << vec.size() << ' ' << vec.capacity() << std::endl;
    std::cout << vec << std::endl;

    return 0;
}
