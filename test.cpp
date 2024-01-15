#include <iostream>
#include "vector.h"

int main()
{
    Vector<bool> vec(5, 1);

    vec.push_back(0);

    std::cout << vec << std::endl;

    return 0;
}
