#include <iostream>
#include "vector.h"

int main()
{
    MyVector<int> vec = {1, 2, 3, 4, 5, 6};
    MyVector<int>::BidirectionalIterator it = vec.end();
	--it; 
	for (;it != vec.begin(); --it)
	{
		std::cout << *it << ' ';
	}
	std::cout << *it;
	std::cout << std::endl;

    return 0;
}
