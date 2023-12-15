#include <iostream>
#include "vector.h"

int main()
{
    MyVector<int> vec = {1, 2, 3, 4, 5, 6};
    MyVector<int>::Iterator it = vec.begin();

	for (int i = 0; i < vec.size(); ++i)
	{
		it[i] += 2;
	}

	for (auto it = vec.begin(); it != vec.end(); ++it)
	{
		std::cout << *it << ' ';
	}
	std::cout << *it << std::endl;

    return 0;
}
