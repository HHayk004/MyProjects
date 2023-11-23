#include <iostream>
#include "vector.h"

int main()
{
    MyVector<bool> vec = {0, 1, 1, 0, 1, 0, 1, 1, 0, 0};
    vec.push_back(0);
    vec.push_back(1);

    std::cout << vec << std::endl;
    return 0;
}
