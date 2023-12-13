#include <iostream>
#include "vector.h"

int main()
{
    MyVector<int> vec = {1, 2, 3, 4, 5, 6};
    for (MyVector<int>::Iterator it = vec.begin(); it != vec.end(); ++it)
	{
		std::cout << *it << ' ';
	}
	std::cout << std::endl;

    return 0;
}
