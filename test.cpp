#include <iostream>
#include "vector.h"

int main()
{
    MyVector<bool> vec = {1, 0, 1, 1, 0};
    std::cout << vec[4] << std::endl;

    return 0;
}
