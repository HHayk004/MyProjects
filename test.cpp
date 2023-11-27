#include <iostream>
#include "vector.h"

int main()
{
    MyVector<int> vec = {1, 0, 1, 1, 0};
   
    vec.erase(1, 4);

    std::cout << vec << std::endl;

    return 0;
}
