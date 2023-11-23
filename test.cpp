#include <iostream>
#include "vector.h"

int main()
{
    MyVector<int> vec = {1, 2, 3};

    vec.push_back(4);
    std::cout << vec << std::endl;
    return 0;
}
