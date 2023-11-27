#include <iostream>
#include "vector.h"

int main()
{
    MyVector<bool> vec = {1, 0, 1, 1, 0};
   
    vec.reserve(10);

    std::cout << vec.size() << ' ' << vec.capacity() << std::endl;
    std::cout << vec << std::endl;

    return 0;
}
